#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <stdio.h>
#include <queue>
#include <set>
#include <list>
#include <cmath>
#include <assert.h>
#include <bitset>
#include <cstring>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip> //cout << setprecision(node) << fixed << num
#include <stack>
#include <sstream>


#define MAX(a,b) ((a)>(b)?(a):(b))
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << endl;
#define debug(x) cout << x << endl;
#define debug2(x,y) cout << x << " " << y << endl;
typedef long long int ll;
typedef long double ld;
typedef unsigned long long int ull;
typedef std::pair <int, int> ii;
typedef std::vector <int> vi;
typedef std::vector <ll> vll;
typedef std::vector <ld> vld;

const int INF = int(1e9);
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
using namespace std;

const int maxn = (int)5e5+10;

ll A[maxn], dp[maxn];
int B[maxn][2];

struct node {
    ll suffix, prefix, val, all;
    node (ll a = 0, ll b = 0, ll c = 0, ll d = 0) {
        suffix = a;
        prefix = b;
        val = c;
        all = d;
    }
};

node tree[4*maxn][2];

int N, Q, L, R;

inline int left(int i) { return i << 1; }
inline int right(int i ) { return (i << 1) + 1; }

node merge (node l, node r) {
    if (l.val == -1)
        return r;
    if (r.val == -1)
        return l;
    node ret;
    ret.prefix = l.prefix;
    if (l.all)
        ret.prefix += r.prefix;
    ret.suffix = r.suffix;
    if (r.all)
        ret.suffix += l.suffix;
    if (l.all && r.all)
        ret.all = l.all + r.all;
    else
        ret.all = 0;
    ret.val = l.suffix * r.prefix + l.val + r.val;
    return ret;
}

void build (int i, int L, int R, int t) {
    if (L == R) {
        if (B[L][t] == 0) {
            tree[i][t].suffix = tree[i][t].prefix = tree[i][t].all = tree[i][t].val = 1;
        }
        else {
            tree[i][t].suffix = tree[i][t].prefix = tree[i][t].all = tree[i][t].val = 0;
        }
    }
    else {
        int mid = (L+R)/2;
        build(left(i), L, mid, t);
        build(right(i), mid+1, R, t);
        tree[i][t] = merge(tree[left(i)][t], tree[right(i)][t]);
    }
}

void update (int i, int L, int R, int idx, int val, int t) {
    if (L == R) {
        assert(L == idx);
        B[L][t] = val;
        if (B[L][t] == 0) {
            tree[i][t].suffix = tree[i][t].prefix = tree[i][t].all = tree[i][t].val = 1;
        }
        else {
            tree[i][t].suffix = tree[i][t].prefix = tree[i][t].all = tree[i][t].val = 0;
        }
    }
    else {
        int mid = (L+R)/2;
        if (mid >= idx) {
            update(left(i), L, mid, idx, val, t);
        }
        else {
            update(right(i), mid+1, R, idx, val, t);
        }
        tree[i][t] = merge(tree[left(i)][t], tree[right(i)][t]);
    }
}
//1 0 2 0 1 0 1
node query (int i, int L, int R, int li, int ri, int t) {
    if (ri < L || li > R) {
        return node (-1, -1, -1, -1);
    }
    if (li <= L && ri >= R) {
        return tree[i][t];
    }
    int mid = (L+R)/2;
    return merge(query(left(i), L, mid, li, ri, t), query(right(i), mid+1, R, li, ri, t));
}

ll brute(int li, int ri) {
    for (int i = 1; i <= N; i++) dp[i] = 0;
    ll ret = 0, cnt = 0;
    for (int i = li; i <= ri; i++) {
        if (A[i] >= L && A[i] <= R)
            dp[i] = dp[i-1] + 1;
        else if (A[i] <= R)
            dp[i] = dp[i-1];
        else
            dp[i] = 0;
        if (A[i] >= L && A[i] <= R)
            dp[i] += cnt;
        ret += dp[i];
        if (A[i] < L)
            cnt++;
        else
            cnt = 0;
    }
    return ret;
}

int main() {


    scanf("%d %d %d %d", &N, &Q, &L, &R);
    int type, i, li, ri;
    ll rep;
    for (int j = 1; j <= N; j++) {
        B[j][0] = B[j][1] = 0;
    }
    build(1, 1, N, 0);
    build(1, 1, N, 1);

    while (Q--) {
        scanf("%d", &type);
        if (type == 1) {
            //i = (rand() % N) + 1; rep = ((rand()) % (2 * R)) + 1; cout << type << " " << i << " " << rep << endl;
            scanf("%d %lld", &i, &rep);
            if (rep < L)
                update(1, 1, N, i, 0, 0);
            else
                update(1, 1, N, i, 1, 0);

            if (rep <= R)
                update(1, 1, N, i, 0, 1);
            else
                update(1, 1, N, i, 1, 1);
            A[i] = rep;
        }
        else {
            //li = (rand() % N) + 1; ri = (rand() % N) + 1; if (li > ri) swap(li, ri); cout << type << " " << li << " " << ri << endl;
            scanf("%d %d", &li, &ri);
            node n1 = query(1, 1, N, li, ri, 0);
            node n2 = query(1, 1, N, li, ri, 1);
            ll ans = n2.val - n1.val;
            //printf("AC  : %lld\n", brute(li, ri));
            //printf("Mine: %lld\n", ans);
            //assert(ans == brute(li, ri));
            printf("%lld\n", ans);
        }
    }
}
