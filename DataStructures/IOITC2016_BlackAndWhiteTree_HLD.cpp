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

const int maxn = (int) 2e5+10;
int N, t = 0, ST[4*maxn], nxt[maxn], euler[maxn], in[maxn], size[maxn], depth[maxn], P[maxn][20], col[maxn];
vi tree[maxn];

inline int left(int x) { return (x << 1); }
inline int right(int x) { return (x << 1) + 1; }

void build(int i, int L, int R) {
    if (L == R) {
        ST[i] = col[euler[L]];
    }
    else {
        int mid = (L+R)/2;
        build(left(i), L, mid);
        build(right(i), mid+1, R);
        ST[i] = ST[left(i)] + ST[right(i)];
    }
}

int get(int i, int L, int R, int li, int ri) {
    if (ri < L || li > R)
        return 0;
    if (li <= L && ri >= R)
        return ST[i];
    int mid = (L+R)/2;
    return get(left(i), L, mid, li, ri) + get(right(i), mid+1, R, li, ri);
}

int query(int i, int L, int R, int k) {
    if (L == R) {
        return L;
    }
    else {
        int mid = (L+R)/2;
        if (k <= ST[left(i)])
            return query(left(i), L, mid, k);
        else
            return query(right(i), mid+1, R, k - ST[left(i)]);
    }
}

void update(int i, int L, int R, int idx) {
    if (L == R) {
        assert(idx == L);
        ST[i] ^= 1;
        col[euler[L]] ^= 1;
    }
    else {
        int mid = (L+R)/2;
        if (idx <= mid)
            update(left(i), L, mid, idx);
        else
            update(right(i), mid+1, R, idx);
        ST[i] = ST[left(i)] + ST[right(i)];
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v])
        swap(u, v);
    int d = depth[u] - depth[v];
    for (int i = 0; i < 20; i++) {
        if (d & (1 << i)) {
            u = P[u][i];
        }
    }
    if (u == v) return u;
    for (int i = 19; i >= 0; i--) {
        if (P[u][i] != P[v][i]) {
            u = P[u][i];
            v = P[v][i];
        }
    }
    assert(P[u][0] == P[v][0]);
    return P[u][0];
}

int count(int u, int v) {
    int cnt = 0;
    while (nxt[u] != nxt[v]) {
        if (depth[nxt[u]] < depth[nxt[v]]) swap(u, v);
        cnt += get(1, 1, N, in[nxt[u]], in[u]);
        u = P[nxt[u]][0];
    }
    if (depth[u] > depth[v]) swap(u, v);
    cnt += get(1, 1, N, in[u] + 1, in[v]);
    return cnt;
}



int query(int u, int v, int k) {
    int LCA = lca(u, v);
    int c1 = count(u, LCA);
    int c2 = count(v, LCA) + col[LCA];
    if (c1 + c2 < k) return -1;
    else if (k > c1) {
        k = c2 - (k - c1) + 1;
        swap(u, v);
    }
    while (nxt[u] != nxt[LCA]) {
        int val = get(1, 1, N, in[nxt[u]], in[u]);
        if (val < k)
            k -= val;
        else {
            int tmp = 1 + (val - k) + get(1, 1, N, 1, in[nxt[u]]-1);
            int kth = query(1, 1, N, tmp);
            return euler[kth];
        }
        u = P[nxt[u]][0];
    }
    int val = get(1, 1, N, in[LCA], in[u]);
    int tmp = 1 + (val - k) + get(1, 1, N, 1, in[LCA]-1);
    int kth = query(1, 1, N, tmp);
    return euler[kth];
}

void dfs0(int node) {
    depth[node] = depth[P[node][0]] + 1;
    size[node] = 1;
    for (int &adj : tree[node]) {
        dfs0(adj);
        size[node] += size[adj];
        if (size[adj] > size[tree[node][0]])
            swap(adj, tree[node][0]);
    }
}

void dfs_hld(int node) {
    in[node] = ++t;
    euler[in[node]] = node;
    for (int adj : tree[node]) {
        if (adj == tree[node][0]) nxt[adj] = nxt[node];
        else nxt[adj] = adj;
        dfs_hld(adj);
    }
}

void preprocess() {
    dfs0(1);
    for (int i = 1; i < 20; i++) {
        for (int u = 1; u <= N; u++) {
            P[u][i] = P[P[u][i-1]][i-1];
        }
    }
    dfs_hld(1);
    build(1, 1, N);
}

int main() {
    int Q;
    scanf("%d %d", &N, &Q);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &col[i]);
    }
    for (int i = 2; i <= N; i++) {
        scanf("%d", &P[i][0]);
        tree[P[i][0]].pb(i);
    }
    preprocess();
    while (Q--) {
        char type;
        scanf("%s ", &type);
        if (type == 'T') {
            int u;
            scanf("%d", &u);
            update(1, 1, N, in[u]);
        }
        else if (type == 'C') assert(false);
        else {
            int u, v, k;
            scanf("%d %d %d", &u, &v, &k);
            printf("%d\n", query(u, v, k));
        }
    }
}
/*
7 7
1 1 1 1 1 1 1
1 1 1 2 2 4
Q 5 3 2
T 1
Q 7 2 3
C 7 3
T 2
Q 6 7 3
Q 4 1 2

 */