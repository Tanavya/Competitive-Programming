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
#define fi first
#define se second
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << endl;
#define debug(x) cout << x << endl;
#define debug2(x,y) cout << x << " " << y << endl;
#define debug3(x,y,z) cout << x << " " << y << " " << z << endl;
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


struct node {
    ll centre, left, right, sum;
    node (ll a = 0, ll b = 0, ll c = 0, ll d = 0) {
        centre = a;
        left = b;
        right = c;
        sum = d;
    }
};

const int maxn = 10007;
node tree[4*maxn];
ll A[maxn], pre[maxn], tree2[4*maxn][2];

int left (int x) { return (x << 1); }
int right(int x) { return (x << 1) + 1; }

node merge (node l, node r) {
    node ret;
    ret.sum = l.sum + r.sum;
    ret.centre = max(l.right + r.left, max(l.centre, r.centre));
    ret.left = max(l.left, l.sum + r.left);
    ret.right = max(r.right, r.sum + l.right);
    ret.centre = max(ret.centre, max(ret.left, ret.right));
    return ret;
}

void build(int i, int L, int R) {
    if (L == R) {
        tree[i].sum = tree[i].centre = tree[i].left = tree[i].right = A[L];
    }
    else {
        int mid = (L+R)/2;
        build(left(i), L, mid);
        build(right(i), mid+1, R);
        tree[i] = merge(tree[left(i)], tree[right(i)]);
    }
}

void build2(int i, int L, int R) {
    if (L == R) {
        tree2[i][0] = tree2[i][1] = pre[L];
    }
    else {
        int mid = (L+R)/2;
        build2(left(i), L, mid);
        build2(right(i), mid+1, R);
        tree2[i][0] = max(tree2[left(i)][0], tree2[right(i)][0]);
        tree2[i][1] = min(tree2[left(i)][1], tree2[right(i)][1]);
    }
}

ll query2(int i, int L, int R, int li, int ri, int t) {
    if (ri < L || li > R) {
        if (!t) return -INF64;
        else return INF64;
    }
    if (li <= L && ri >= R) {
        return tree2[i][t];
    }
    int mid = (L+R)/2;
    if (!t) return max(query2(left(i), L, mid, li, ri, t), query2(right(i), mid+1, R, li, ri, t));
    else return min(query2(left(i), L, mid, li, ri, t), query2(right(i), mid+1, R, li, ri, t));
}


node query(int i, int L, int R, int li, int ri) {
    if (ri < L || li > R)
        return node (-INF, -INF, -INF, -INF);
    if (li <= L && ri >= R)
        return tree[i];
    int mid = (L+R)/2;
    return merge(query(left(i), L, mid, li, ri), query(right(i), mid+1, R, li, ri));
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int N;
        scanf("%d", &N);
        for (int i = 1; i <= N; i++) {
            scanf("%lld", &A[i]);
            pre[i+1] = pre[i] + A[i];
        }
        //for (int i = 1; i <= N+1; i++) cout << pre[i] << " "; cout << endl;
        build(1, 1, N);
        build2(1, 1, N+1);
        int Q;
        scanf("%d", &Q);
        while (Q--) {
            int x1, y1, x2, y2;
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            ll ans = -INF64;
            if (y1 >= x2) {
                //overlap
                ans = max(query2(1, 1, N+1, y1+1, y2+1, 0) - query2(1, 1, N+1, x1, y1, 1),
                          query2(1, 1, N+1, x2+1, y2+1, 0) - query2(1, 1, N+1, x1, x2, 1));
                ans = max(ans, query(1, 1, N, x2, y1).centre);
            }
            else {
                //dont overlap
                ans = query2(1, 1, N+1, x2+1, y2+1, 0) - query2(1, 1, N+1, x1, y1, 1);
            }
            printf("%lld\n", ans);
        }
    }
}