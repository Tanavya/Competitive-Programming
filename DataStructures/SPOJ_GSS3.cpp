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

#define int ll

struct node {
    int centre;
    int left;
    int right;
    int sum;
    node (int a = 0, int b = 0, int c = 0, int d = 0) {
        centre = a;
        left = b;
        right = c;
        sum = d;
    }
};

const int maxn = (int)5e4;
node tree[4*maxn];
int A[maxn];

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

node query(int i, int L, int R, int li, int ri) {
    if (ri < L || li > R)
        return node (-INF, -INF, -INF, -INF);
    if (li <= L && ri >= R)
        return tree[i];
    int mid = (L+R)/2;
    return merge(query(left(i), L, mid, li, ri), query(right(i), mid+1, R, li, ri));
}
void update (int i, int L, int R, int idx, int val) {
    if (L == R) {
        assert(idx == L);
        A[idx] = val;
        tree[i].sum = tree[i].centre = tree[i].left = tree[i].right = A[idx];
    }
    else {
        int mid = (L+R)/2;
        if (idx <= mid)
            update(left(i), L, mid, idx, val);
        else
            update(right(i), mid+1, R, idx, val);
        tree[i] = merge(tree[left(i)], tree[right(i)]);
    }
}
signed main() {
    int N, M;
    scanf("%lld", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%lld", &A[i]);
    }
    build(1, 1, N);
    scanf("%lld", &M);
    int x, y, type;
    while (M--) {
        cin >> type;
        if (type == 0) {
            int idx, val;
            scanf("%lld %lld", &idx, &val);
            update(1, 1, N, idx, val);
        }
        else {
            scanf("%lld %lld", &x, &y);
            printf("%lld\n", query(1, 1, N, x, y).centre);
        }
    }
}