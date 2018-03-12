//Problem: SPOJ Acquire
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
#include <iomanip> //cout << setprecision(node) << fixed << num
#include <stack>
#include <sstream>

#define all(x) x.begin(), x.end()
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

const int maxn = 50007, maxw = 1000007;

inline int left(int x) { return (x << 1); }
inline int right(int x) { return (x << 1) + 1; }

struct line {
    ll m, b;
    line(ll __m = INF, ll __b = INF){ m = __m, b = __b; }
    ll get(ll x) { return m * x + b; }
} tree[maxw * 4];
bool vis[maxw * 4];

void update(int i, int L, int R, line v) {
    if (!vis[i]) {
        vis[i] = true;
        tree[i] = v;
        return;
    }
    if (tree[i].get(L) < v.get(L) && tree[i].get(R) < v.get(R))
        return;
    if (tree[i].get(L) > v.get(L) && tree[i].get(R) > v.get(R)) {
        tree[i] = v;
        return;
    }
    int mid = (L+R)/2;
    if (tree[i].get(L) > v.get(L))
        swap(tree[i], v); //make v worse than tree[i] for x = L
    //compare with mid
    if (tree[i].get(mid) < v.get(mid))
        update(right(i), mid + 1, R, v); //v is worse for x = mid
    else {
        swap(tree[i], v);
        update(left(i), L, mid, v);
    }
}

ll query(int i, int L, int R, int idx) {
    if (L == R)
        return tree[i].get(L);
    int mid = (L+R)/2;
    ll ans = tree[i].get(idx);
    if (idx <= mid)
        ans = min(ans, query(left(i), L, mid, idx));
    else
        ans = min(ans, query(right(i), mid+1, R, idx));
    return ans;
}
int main() {
    int N;
    scanf("%d", &N);
    vector <ii> A(N), rect;
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &A[i].fi, &A[i].se);
    }
    sort(all(A));
    for (int i = 0; i < N; i++) {
        while (!rect.empty() && A[i].se >= rect.back().se) {
            rect.pop_back();
        }
        rect.pb(A[i]);
    }
    N = (int)rect.size();
    ll cost;
    update(1, 1, maxw, line(rect[0].se, 0));
    for (int i = 0; i < N; i++) {
        cost = query(1, 1, maxw, rect[i].fi);
        if (i < N-1)
            update(1, 1, maxw, line(rect[i+1].se, cost));
    }
    printf("%lld\n", cost);
}