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

const int maxn = (int) 10007;
int sz[maxn], in[maxn], euler[maxn], out[maxn], nxt[maxn], stree[4*maxn], weight[maxn][maxn], A[maxn], depth[maxn], parent[maxn], N;
vi tree[maxn];

inline int left(int x) { return (x << 1); }
inline int right(int x) { return (x << 1) + 1; }

void build(int i, int L, int R) {
    if (L == R) {
        stree[i] = A[euler[L]];
    }
    else {
        int mid = (L+R)/2;
        build(left(i), L, mid);
        build(right(i), mid+1, R);
        stree[i] = max(stree[left(i)], stree[right(i)]);
    }
}

int query(int i, int L, int R, int li, int ri) {
    if (ri < L || li > R)
        return -INF;
    if (li <= L && ri >= R)
        return stree[i];
    int mid = (L+R)/2;
    return max(query(left(i), L, mid, li, ri), query(right(i), mid+1, R, li, ri));
}

void update(int i, int L, int R, int idx, int val) {
    if (L == R) {
        assert(L == idx);
        stree[i] = A[euler[L]] = val;
    }
    else {
        int mid = (L+R)/2;
        if (idx <= mid)
            update(left(i), L, mid, idx, val);
        else
            update(right(i), mid+1, R, idx, val);
        stree[i] = max(stree[left(i)], stree[right(i)]);
    }
}
void dfs_sz(int node, int par) {
    sz[node] = 1;
    A[node] = weight[node][par];
    depth[node] = depth[par] + 1;
    parent[node] = par;
    for (int i = 0; i < tree[node].size(); i++) {
        int &adj = tree[node][i];
        if (adj != par) {
            dfs_sz(adj, node);
            sz[node] += sz[adj];
            if (sz[adj] > sz[tree[node][0]])
                swap(adj, tree[node][0]);
        }
    }
}
int t = 1;
void dfs_hld(int node, int par) {
    in[node] = t++;
    euler[in[node]] = node;
    for (int i = 0; i < tree[node].size(); i++) {
        int adj = tree[node][i];
        if (adj != par) {
            nxt[adj] = (adj == tree[node][0] ? nxt[node] : adj);
            dfs_hld(adj, node);
        }
    }
    out[node] = t; //not needed for path queries
}

int query(int u, int v) {
    int res = -INF;
    while (nxt[u] != nxt[v]) {
        if (depth[nxt[u]] < depth[nxt[v]]) swap(u, v);
        res = max(res, query(1, 1, N, in[nxt[u]], in[u]));
        u = parent[nxt[u]];
    }
    if (depth[u] > depth[v]) swap(u, v);
    //u is the lca, found implicitly
    //want to exclude lca, hence in[u]+1
    res = max(res, query(1, 1, N, in[u]+1, in[v]));
    return res;
}

void update(int u, int v, int w) {
    if (parent[v] == u) swap(u, v);
    assert(parent[u] == v);
    update(1, 1, N, in[u], w);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        t = 1;
        for (int i = 1; i <= N; i++) {
            tree[i].clear();
        }
        scanf("%d", &N);
        vector <ii> edges;
        for (int i = 0; i < N - 1; i++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            tree[u].pb(v);
            tree[v].pb(u);
            weight[u][v] = weight[v][u] = w;
            edges.pb(mp(u, v));
        }
        nxt[1] = 1;
        dfs_sz(1, 0);
        dfs_hld(1, 0);
        build(1, 1, N);
        while (true) {
            char s[10];
            scanf("%s", s);
            if (s[0] == 'C') {
                int i, w;
                scanf("%d %d", &i, &w);
                i--;
                update(edges[i].fi, edges[i].se, w);
            }
            else if (s[0] == 'Q') {
                int u, v;
                scanf("%d %d", &u, &v);
                assert(u != v);
                printf("%d\n", query(u, v));
            }
            else break;
        }
    }
}