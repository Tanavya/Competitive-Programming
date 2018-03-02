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

const int maxn = 100007, mod = 10007;
ll SumSquares[maxn], Sum[maxn];

inline int left(int x) { return (x << 1); }
inline int right(int x) { return (x << 1) + 1; }

struct node {
    ll val, lazyA, lazyB, lazyC;
    node(): val(0), lazyA(0), lazyB(0), lazyC(0) {}
    node(ll val, ll lazyA, ll lazyB, ll lazyC): val(val), lazyA(lazyA), lazyB(lazyB), lazyC(lazyC) {}
};
node tree[4*maxn];

void propagate(int i, int L, int R, ll a, ll b, ll c) {
    if (!L) tree[i].val += ((a*SumSquares[R]) % mod + (b*Sum[R]) % mod + (c*(R+1)) % mod) % mod;
    else tree[i].val += (((a*(SumSquares[R] - SumSquares[L-1])) % mod) + ((b*(Sum[R] - Sum[L-1])) % mod) + ((c*(R-L+1)) % mod)) % mod;
    tree[i].val %= mod;
    while (tree[i].val < 0)
        tree[i].val += mod;
    if (L != R) {
        for (int child = 2*i; child <= 2*i+1; child++) {
            tree[child].lazyA += a;
            tree[child].lazyB += b;
            tree[child].lazyC += c;
            tree[child].lazyA %= mod;
            tree[child].lazyB %= mod;
            tree[child].lazyC %= mod;
        }
    }
}

void update(int i, int L, int R, int li, int ri, int a, int b, int c) {
    if (tree[i].lazyA || tree[i].lazyB || tree[i].lazyC) {
        propagate(i, L, R, tree[i].lazyA, tree[i].lazyB, tree[i].lazyC);
        tree[i].lazyA = tree[i].lazyB = tree[i].lazyC = 0;
    }
    if (ri < L || li > R)
        return;
    if (li <= L && ri >= R) {
        propagate(i, L, R, a, b, c);
        return;
    }
    update(left(i), L, (L+R)/2, li, ri, a, b, c);
    update(right(i), (L+R)/2+1, R, li, ri, a, b, c);
    tree[i].val = (tree[left(i)].val + tree[right(i)].val) % mod;
}

ll query(int i, int L, int R, int li, int ri) {
    if (tree[i].lazyA || tree[i].lazyB || tree[i].lazyC) {
        propagate(i, L, R, tree[i].lazyA, tree[i].lazyB, tree[i].lazyC);
        tree[i].lazyA = tree[i].lazyB = tree[i].lazyC = 0;
    }
    if (ri < L || li > R)
        return 0;
    if (li <= L && ri >= R)
        return tree[i].val;
    return (query(left(i), L, (L+R)/2, li, ri) + query(right(i), (L+R)/2+1, R, li, ri)) % mod;
}


ll A[maxn];

int main() {
    for (ll i = 1; i < maxn; i++) {
        SumSquares[i] = (SumSquares[i-1] + i*i) % mod;
        Sum[i] = (Sum[i-1] + i) % mod;
    }
    int N, M;
    scanf("%d %d", &N, &M);
    while(M--) {
        int type;
        scanf("%d", &type);
        if (type == 0) {
            int li, ri, a, b, c;
            scanf("%d %d %d %d %d", &li, &ri, &a, &b, &c);
            update(1, 0, N-1, li, ri, a, b, c);
        }
        else {
            int li, ri;
            scanf("%d %d", &li, &ri);
            printf("%lld\n", query(1, 0, N-1, li, ri));
        }
    }
}