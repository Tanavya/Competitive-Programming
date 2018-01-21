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

const int maxn = 1e5+10;
int tree[4*maxn], lazy[4*maxn], A[maxn];

inline int left (int x) { return (x << 1); }
inline int right (int x) { return (x << 1) + 1; }

void propagate (int i, int L, int R, int val) {
    tree[i] += (R-L+1) * val;
    if (L != R) {
        lazy[left(i)] += val;
        lazy[right(i)] += val;
    }
}

void build (int i, int L, int R) {
    if (L == R) {
        tree[i] = A[L];
    }
    else {
        int mid = (L+R)/2;
        build(left(i), L, mid);
        build(right(i), mid+1, R);
        tree[i] = tree[left(i)] + tree[right(i)];
    }
}

void updateRange(int i, int L, int R, int li, int ri, int val) {
    if (lazy[i]) {
        propagate(i, L, R, lazy[i]);
        lazy[i] = 0;
    }
    if (ri < L || li > R)
        return;
    if (li <= L && ri >= R) {
        propagate(i, L, R, val);
        return;
    }
    int mid = (L+R)/2;
    updateRange(left(i), L, mid, li, ri, val);
    updateRange(right(i), mid+1, R, li, ri, val);
    tree[i] = tree[left(i)] + tree[right(i)];
}

int queryRange(int i, int L, int R, int li, int ri) {
    if (lazy[i]) {
        propagate(i, L, R, lazy[i]);
        lazy[i] = 0;
    }
    if (ri < L || li > R)
        return 0;
    if (li <= L && ri >= R)
        return tree[i];
    int mid = (L+R)/2;
    return queryRange(left(i), L, mid, li, ri) + queryRange(right(i), mid+1, R, li, ri);
}

int main() {
    int N, Q, l, r, x;
    scanf("%d %d", &N, &Q);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &A[i]);
    }
    build(1, 1, N);
    int type;
    while (Q--) {
        scanf("%d", &type);
        if (type == 1) {
            //update
            scanf("%d %d %d", &l, &r, &x);
            updateRange(1, 1, N, l, r, x);
        }
        else {
            //query
            scanf("%d %d", &l, &r);
            printf("%d\n", queryRange(1, 1, N, l, r));
        }
        //for (int i = 1; i <= N; i++) cout << queryRange(1, 1, N, i, i) << " "; cout << endl;
    }
}