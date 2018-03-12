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
#include <unordered_map>
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
#define show(a) cout << #a << " " << a << endl;
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

const int maxn = 200007;
int N, K, S, P[maxn][20], depth[maxn], A[maxn], size[maxn], parent[maxn], best[1000007];
ll dist[maxn];
vi children[maxn];
vector <ii> edges[maxn], paths[maxn];
set <int> tree[maxn];

void dfs0(int node, int par) {
    P[node][0] = par;
    depth[node] = depth[par] + 1;
    dist[node] = dist[par] + A[node];
    for (ii edge : edges[node]) {
        int adj = edge.fi, w = edge.se;
        if (adj != par) {
            A[adj] = w;
            dfs0(adj, node);
        }
    }
}

void preprocess() {
    dfs0(1, 0);
    for (int i = 1; i < 20; i++) {
        for (int u = 1; u <= N; u++) {
            P[u][i] = P[P[u][i-1]][i-1];
        }
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
    if (u == v)
        return u;
    for (int i = 19; i >= 0; i--) {
        if (P[u][i] != P[v][i]) {
            u = P[u][i];
            v = P[v][i];
        }
    }
    return P[u][0];
}

void dfs1(int node, int par) {
    size[node] = 1;
    for (int adj : tree[node]) {
        if (adj != par) {
            dfs1(adj, node);
            size[node] += size[adj];
        }
    }
}

int dfs2(int node, int par) {
    for (int adj : tree[node]) {
        if (adj != par && size[adj] > S/2) {
            return dfs2(adj, node);
        }
    }
    return node;
}
void update(int start) {
    int u = start;
    while (u) {
        int LCA = lca(start, parent[u]);
        ll d = dist[start] + dist[parent[u]] - 2 * dist[LCA];
        int l = depth[start] + depth[parent[u]] - 2 * depth[LCA];
        if (d <= K)
            paths[u].pb(mp(d, l));
        u = parent[u];
    }
}

void decompose(int node, int par) {
    dfs1(node, 0);
    S = size[node];
    int centroid = dfs2(node, 0);
    parent[centroid] = par;
    children[par].pb(centroid);
    update(centroid);
    for (int adj : tree[centroid]) {
        tree[adj].erase(centroid);
        decompose(adj, centroid);
    }
    tree[node].clear();
}

int main() {
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N-1; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        u++; v++;
        tree[u].insert(v);
        tree[v].insert(u);
        edges[u].pb(mp(v, w));
        edges[v].pb(mp(u, w));
    }
    preprocess();
    decompose(1, 0);
    int ret = INF;
    for (int u = 1; u <= N; u++) {
        vi modifs;
        for (int v : children[u]) {
            for (ii p : paths[v]) {
                int d = p.fi, l = p.se;
                if (d == K)
                    ret = min(ret, l);
                else
                    ret = min(ret, (best[K-d] ? best[K-d] : INF) + l);
            }
            for (ii p : paths[v]) {
                int d = p.fi, l = p.se;
                if (d <= K) {
                    best[d] = (best[d] ? min(best[d], l) : l);
                    modifs.pb(d);
                }
            }
        }
        for (int d : modifs) {
            best[d] = 0;
        }
    }
    printf("%d\n", ret == INF ? -1 : ret);
}