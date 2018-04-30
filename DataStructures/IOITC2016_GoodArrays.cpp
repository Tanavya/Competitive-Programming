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
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip> //cout << setprecision(node) << fixed << num

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << endl;
#define debug(x) cout << x << endl;
#define debug2(x,y) cout << x << " " << y << endl;
#define debug3(x,y,z) cout << x << " " << y << " " << z << endl;
#define debug4(a,b,c,d) cout << a << " " << b << " " << c << " " << d << endl;
#define debug5(a,b,c,d,e) cout << a << " " << b << " " << c << " " << d << " " << e << endl;
#define trace(x) cout << #x << ": " << x << endl;


typedef long long int ll;
typedef long double ld;
typedef unsigned long long int ull;
typedef std::pair <int, int> ii;
typedef std::vector <int> vi;
typedef std::vector <ii> vii;
typedef std::vector <ll> vll;
typedef std::vector <ld> vld;

const int INF = int(1e9);
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
using namespace std;

const int maxn = (int) 1e5+10;
ll lazy[2][4*maxn], tree[2][4*maxn];

inline int left(int x) { return (x << 1); }
inline int right(int x) { return (x << 1) + 1; }

void propagate(int t, int i, int L, int R) {
    tree[t][i] += lazy[t][i];
    if (L != R) {
        lazy[t][left(i)] += lazy[t][i];
        lazy[t][right(i)] += lazy[t][i];
    }
    lazy[t][i] = 0;
}

void merge(int t, int i) {
    if (t == 0)
        tree[t][i] = min(tree[t][left(i)], tree[t][right(i)]);
    else
        tree[t][i] = max(tree[t][left(i)], tree[t][right(i)]);
}

void update(int t, int i, int L, int R, int li, int ri, ll val) {
    if (lazy[t][i])
        propagate(t, i, L, R);
    if (ri < L || li > R)
        return;
    if (li <= L && ri >= R) {
        lazy[t][i] = val;
        propagate(t, i, L, R);
        return;
    }
    int mid = (L+R)/2;
    update(t, left(i), L, mid, li, ri, val);
    update(t, right(i), mid+1, R, li, ri, val);
    merge(t, i);
}

ll query(int t, int i, int L, int R, int li, int ri) {
    if (lazy[t][i])
        propagate(t, i, L, R);
    if (ri < L || li > R) {
        if (t == 0) return INF64;
        else return -INF64;
    }
    if (li <= L && ri >= R)
        return tree[t][i];
    int mid = (L+R)/2;
    if (t == 0)
        return min(query(t, left(i), L, mid, li, ri), query(t, right(i), mid+1, R, li, ri));
    else
        return max(query(t, left(i), L, mid, li, ri), query(t, right(i), mid+1, R, li, ri));
}

int main() {
    int N, Q;
    scanf("%d %d", &N, &Q);
    while (Q--) {
        int type;
        scanf("%d", &type);
        if (type == 1) {
            int L, R;
            ll x;
            scanf("%d %d %lld", &L, &R, &x);
            update(0, 1, 1, N, L, R, ll(1e9*x));
            update(1, 1, 1, N, L, R, ll(-1e9*x));
        }
        else if (type == 2) {
            int L, R;
            ll y;
            scanf("%d %d %lld", &L, &R, &y);
            update(0, 1, 1, N, L, R, y);
            update(1, 1, 1, N, L, R, y);
        }
        else {
            int L, R;
            scanf("%d %d", &L, &R);
            bool ok = true;
            ll q = query(0, 1, 1, N, L, R);
            if (q < -1e9) ok = false;
            q = query(1, 1, 1, N, L, R);
            if (q > 1e9) ok = false;
            if (ok) printf("YES\n");
            else printf("NO\n");
        }
    }
}
/*
5 6
1 3 5 4
2 2 4 8
1 4 5 0
3 1 5
2 2 5 -20
3 1 1

 5 6
1 1 5 3000000000
3 1 5
*/