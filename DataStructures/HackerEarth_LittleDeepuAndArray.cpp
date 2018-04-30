#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <assert.h>
#include <set>
#include <bitset>
#include <queue>

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

const int INF = 2147483647;
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
using namespace std;

const int maxn = (int) 100007;
int N, A[maxn], MAP[maxn], ans[maxn], tree[4*maxn];

inline int left(int x) { return (x << 1); }
inline int right(int x) { return (x << 1) + 1; }

void build(int i, int L, int R) {
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

void update(int i, int L, int R, int idx, int val) {
    if (L == R) {
        assert(idx == L);
        tree[i] += val;
    }
    else {
        int mid = (L+R)/2;
        if (idx <= mid)
            update(left(i), L, mid, idx, val);
        else
            update(right(i), mid+1, R, idx, val);
        tree[i] = tree[left(i)] + tree[right(i)];
    }
}

int get(int i, int L, int R, int li, int ri) {
    if (ri < L || li > R)
        return 0;
    if (li <= L && ri >= R)
        return tree[i];
    int mid = (L+R)/2;
    return get(left(i), L, mid, li, ri) + get(right(i), mid+1, R, li, ri);
}

int query(int i, int L, int R, int k) {
    if (L == R) {
        if (k > tree[i]) return -1;
        return L;
    }
    else {
        int mid = (L+R)/2;
        if (tree[left(i)] >= k)
            return query(left(i), L, mid, k);
        else
            return query(right(i), mid+1, R, k-tree[left(i)]);
    }
}
int main() {
    int Q;
    scanf("%d", &N);
    vector <ii> V;
    for (int i = 1; i <= N; i++) {
        int x;
        scanf("%d", &x);
        V.pb(mp(x, i));
    }
    sort(all(V));
    A[1] = V[0].fi;
    MAP[1] = V[0].se;
    for (int i = 2; i <= N; i++) {
        A[i] = V[i-1].fi - V[i-2].fi;
        MAP[i] = V[i-1].se;
    }
    build(1, 1, N);
    //for (int i = 1; i <= N; i++) cout << get(1, 1, N, 1, i) << " "; cout << endl;
    //for (int i = 1; i <= N; i++) cout << get(1, 1, N, i, i) << " "; cout << endl;
    scanf("%d", &Q);
    while (Q--) {
        int x;
        scanf("%d", &x);
        int pos = query(1, 1, N, x+1);
        if (pos != -1)
            update(1, 1, N, pos, -1);
        //for (int j = 1; j <= N; j++) cout << get(1, 1, N, 1, j) << " "; cout << endl;
    }
    for (int i = 1; i <= N; i++) {
        ans[MAP[i]] = get(1, 1, N, 1, i);
    }
    for (int i = 1; i <= N; i++) printf("%d ", ans[i]); printf("\n");
}