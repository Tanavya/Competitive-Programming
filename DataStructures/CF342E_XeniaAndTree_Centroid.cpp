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

const int maxn = 100007;
int N, S, ans[maxn], depth[maxn], size[maxn], parent[maxn], dist[20][maxn], P[maxn][20], color[maxn];
set <int> tree[maxn];

void dfs0(int node, int par) {
    depth[node] = depth[par] + 1;
    P[node][0] = par;
    for (int adj : tree[node]) {
        if (adj != par) {
            dfs0(adj, node);
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
    assert(P[u][0] == P[v][0]);
    return P[u][0];
}

void preprocess() {
    dfs0(1, 0);
    for (int i = 1; i < 20; i++) {
        for (int u = 1; u <= N; u++) {
            P[u][i] = P[P[u][i-1]][i-1];
        }
    }
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
void decompose(int node, int par) {
    S = 0;
    dfs1(node, 0);
    S = size[node];
    int centroid = dfs2(node, 0);
    parent[centroid] = par;
    for (int adj : tree[centroid]) {
        tree[adj].erase(centroid);
        decompose(adj, centroid);
    }
    tree[centroid].clear();
}
int distance(int u, int v) {
    return depth[u] + depth[v] - 2 * depth[lca(u, v)];
}
void precompute_dist(int start) {
    int d = 0, u = start;
    while (u) {
        dist[d++][start] = distance(u, start);
        u = parent[u];
    }
}

void update(int start) {
    int d = 0, u = start;
    while (u) {
        ans[u] = min(ans[u], dist[d++][start]);
        u = parent[u];
    }
}

int query(int start) {
    int d = 0, u = start, ret = INF;
    while (u) {
        ret = min(ret, ans[u] + dist[d++][start]);
        u = parent[u];
    }
    return ret;
}

int main() {
    int M;
    scanf("%d %d", &N, &M);
    for (int i = 1; i < N; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        tree[u].insert(v);
        tree[v].insert(u);
    }
    preprocess();
    decompose(1, 0);
    for (int i = 1; i <= N; i++) {
        ans[i] = INF;
        precompute_dist(i);
        //printf("parent[%d] = %d\n", i, parent[i]);
        //for (int j = 0; j <= 2; j++) printf("dist[%d][%d] = %d\n", j, i, dist[j][i]);
    }
    update(1);
    while (M--) {
        int type, u;
        scanf("%d %d", &type, &u);
        if (type == 1) {
            update(u);
        }
        else {
            printf("%d\n", query(u));
        }
    }
}