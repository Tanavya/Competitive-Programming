//Wrong Answer :(
//-------------------
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <assert.h>
#include <bitset>
#include <set>

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
typedef std::vector <ll> vll;
typedef std::vector <ld> vld;

const int INF = int(1e9);
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
using namespace std;

const int maxn = (int) 1e6+10;
int N, M, depth[maxn], parent[maxn], dp[maxn];
vi graph[maxn], tree[maxn], layer_bfs[maxn], layer_dfs[maxn];
vi n_graph[maxn];
bitset <maxn> visited, stack;
bool ok, cycle;

void reset() {
    for (int i = 0; i <= N; i++) {
        graph[i].clear();
        tree[i].clear();
        n_graph[i].clear();
        layer_bfs[i].clear();
        layer_dfs[i].clear();
        depth[i] = parent[i] = 0;
    }
    ok = true;
    visited.reset();
    stack.reset();
}

void dfs0(int node, int d = 0) {
    layer_dfs[d].pb(node);
    depth[node] = d;
    for (int child : tree[node]) {
        dfs0(child, d+1);
    }
}

void dfs1(int node) {
    for (int adj : graph[node]) {
        if (parent[adj] == node) continue;
        if (depth[adj] > depth[node]) {
            int u = node, v = parent[adj];
            assert(depth[u] == depth[v]);
            n_graph[u].pb(v);
        }
    }
    for (int child : tree[node])
        dfs1(child);
}

void dfs2(int node) {
    //debug(node);
    if (stack[node])
        cycle = true;
    if (visited[node]) return;
    stack[node] = visited[node] = true;
    if (!visited[parent[node]]) {
        dfs2(parent[node]);
    }
    for (int adj : n_graph[node]) {
        dfs2(adj);
    }
    stack[node] = false;
}

void solve() {
    dfs0(1);
    visited.reset();
    queue <int> Q;
    Q.push(1);
    vi dist(N+1, 0);
    visited[1] = true;
    int d = 0;
    while (!Q.empty()) {
        int curr = Q.front();
        layer_bfs[dist[curr]].pb(curr);
        d = max(d, dist[curr]);
        Q.pop();
        for (int adj : graph[curr]) {
            if (!visited[adj]) {
                visited[adj] = true;
                dist[adj] = dist[curr] + 1;
                Q.push(adj);
            }
        }
    }
    for (int i = 0; i <= d; i++) {
        sort(all(layer_bfs[i]));
        sort(all(layer_dfs[i]));
        if (layer_bfs[i] != layer_dfs[i]) ok = false;
    }
    for (int i = 1; i <= N; i++) {
        if (dist[i] != depth[i])
            ok = false;
    }
    if (!ok) {
        printf("NO\n");
        return;
    }
    visited.reset();
    dfs1(1);
    visited.reset();
    stack.reset();
    /*
    for (int i = 1; i <= N; i++) {
        cout << i << ": "; print(tree[i]);
    }
    debug("");
    for (int i = 1; i <= N; i++) {
        cout << i << ": "; print(graph[i]);
    }
    debug("");
    for (int i = 1; i <= N; i++) {
        cout << i << ": "; print(n_graph[i]);
    }*/

    bitset <maxn> VIZ;
    VIZ[1] = true;
    vi layer = {1};
    while (!layer.empty()) {
        vi nxt_layer;
        for (int curr : layer) {
            for (int adj : tree[curr]) {
                if (!VIZ[adj]) {
                    VIZ[adj] = true;
                    visited.reset();
                    for (int n : layer) visited[n] = true;
                    cycle = false;
                    dfs2(adj);
                    if (cycle) {
                        printf("NO\n");
                        return;
                    }
                    nxt_layer.pb(adj);
                }
            }
        }
        layer = nxt_layer;
    }
//    for (int i = 1; i <= N; i++) assert(visited[i]);
    if (cycle) {
        printf("NO\n");
    }
    else {
        printf("YES\n");
    }
}

int main() {
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--) {
        reset();
        scanf("%d %d", &N, &M);
        for (int i = 0; i < M; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            graph[u].pb(v);
            graph[v].pb(u);
        }
        for (int i = 2; i <= N; i++) {
            scanf("%d", &parent[i]);
            tree[parent[i]].pb(i);
        }
        solve();
    }
}
/*

1
5 6
1 4
3 5
3 2
4 5
3 1
2 4
4 1 1 4

1
5 6
1 4
3 5
3 2
4 5
3 1
2 4
4 1 1 3

1
15 21
1 2
1 6
1 9
2 3
2 12
3 4
3 11
5 6
5 9
5 14
6 8
6 10
7 12
7 15
8 13
9 10
9 15
10 14
11 15
12 13
12 14
1 2 3 6 1 15 6 1 6 15 2 8 5 9



 */