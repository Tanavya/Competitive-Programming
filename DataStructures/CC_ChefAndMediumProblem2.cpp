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

const int maxn = (int) 1e5 + 10;
int tree[3][maxn*4], lazy[3][maxn*4], A[3][maxn], V[maxn], N;

inline int left (int x) { return (x << 1); }
inline int right (int x) { return (x << 1) + 1; }

vi simplify (int &x) {
    vi ret;
    for (int i : {2, 3, 5}) {
        int cnt = 0;
        while (x % i == 0) {
            x /= i;
            cnt++;
        }
        ret.pb(cnt);
    }
    return ret;
}
void propagate (int i, int L, int R, int val, int t) {
    tree[t][i] += (R-L+1) * val;
    if (L != R) {
        lazy[t][left(i)] += val;
        lazy[t][right(i)] += val;
    }
}
void build (int i, int L, int R, int t) {
    if (L == R) {
        tree[t][i] = A[t][L];
    }
    else {
        int mid = (L+R)/2;
        build(left(i), L, mid, t);
        build(right(i), mid+1, R, t);
        tree[t][i] = tree[t][left(i)] + tree[t][right(i)];
    }
}
void updateRange (int i, int L, int R, int li, int ri, int val, int t) {
    if (lazy[t][i]) {
        propagate(i, L, R, lazy[t][i], t);
        lazy[t][i] = 0;
    }
    if (ri < L || li > R)
        return;
    if (li <= L && ri >= R) {
        propagate(i, L, R, val, t);
        return;
    }
    int mid = (L+R)/2;
    updateRange(left(i), L, mid, li, ri, val, t);
    updateRange(right(i), mid+1, R, li, ri, val, t);
    tree[t][i] = tree[t][left(i)] + tree[t][right(i)];
}
int queryRange (int i, int L, int R, int li, int ri, int t) {
    if (lazy[t][i]) {
        propagate(i, L, R, lazy[t][i], t);
        lazy[t][i] = 0;
    }
    if (ri < L || li > R)
        return 0;
    if (li <= L && ri >= R)
        return tree[t][i];
    int mid = (L+R)/2;
    return queryRange(left(i), L, mid, li, ri, t) + queryRange(right(i), mid+1, R, li, ri, t);
}

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &V[i]);
        vi simple = simplify(V[i]);
        A[0][i] = simple[0];
        A[1][i] = simple[1];
        A[2][i] = simple[2];
        //debug3(A[0][i], A[1][i], A[2][i]);
    }
    build(1, 1, N, 0);
    build(1, 1, N, 1);
    build(1, 1, N, 2);
    int M, type, l, r, p, t, i, d;
    scanf("%d", &M);
    while (M--) {
        scanf("%d", &type);
        if (type == 1) {
            scanf("%d %d %d", &l, &r, &p);
            if (p == 2) t = 0;
            else if (p == 3) t = 1;
            else t = 2;
            updateRange(1, 1, N, l, r, -1, t);
        }
        else if (type == 2) {
            scanf("%d", &i);
            scanf("%d", &V[i]);
            vi simple = simplify(V[i]);
            A[0][i] = simple[0];
            A[1][i] = simple[1];
            A[2][i] = simple[2];
            vi old(3);
            for (t = 0; t < 3; t++) {
                old[t] = queryRange(1, 1, N, i, i, t);
                updateRange(1, 1, N, i, i, A[t][i]-old[t], t);
            }
        }
    }
    for (i = 1; i <= N; i++) {
        vi old(3), opt = {2, 3, 5};
        int final = 1;
        for (t = 0; t < 3; t++) {
            old[t] = queryRange(1, 1, N, i, i, t);
            if (old[t] > 0)
                final *= pow(opt[t], old[t]);
        }
        final *= V[i];
        printf("%d ", final);
    }
    printf("\n");
}