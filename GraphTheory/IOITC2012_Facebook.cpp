#include <vector>
#include <stdio.h>
#include <queue>
#include <set>
#include <bitset>
#include <algorithm>
#include <cstring>

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

const int maxn = 7007;
vector <ii> graph[maxn], edges;
int par[maxn], N;
ll dist[maxn][2], query[maxn][maxn];

bitset <maxn> visited;

void dijkstra(int src, int t) {
    priority_queue <pair <ll, int>, vector <pair <ll, int>>, greater <pair <ll, int>>> pq;
    for (int i = 0; i < N; i++) {
        dist[i][t] = INF64;
    }
    dist[src][t] = 0;
    pq.push(mp(0, src));
    while (!pq.empty()) {
        ll d = pq.top().fi;
        int curr = pq.top().se;
        pq.pop();
        if (d > dist[curr][t]) continue;
        for (ii edge : graph[curr]) {
            ll w = edge.se;
            int adj = edge.fi;
            if (d + w < dist[adj][t]) {
                dist[adj][t] = d + w;
                par[adj] = curr;
                pq.push(mp(dist[adj][t], adj));
            }
        }
    }
}

set <pair <ll, int>> join;

void dfs(int node) {
    if (visited[node]) return;
    visited[node] = true;
    for (ii edge : graph[node]) {
        int adj = edge.fi; ll w = edge.se;
        if (adj != par[node]) {
            ll tmp = dist[node][1] + w + dist[adj][0];
            join.insert(mp(tmp, adj));
        }
        if (par[adj] == node) dfs(adj);
    }
    for (ii edge : graph[node]) {
        int adj = edge.fi;
        if (par[adj] == node) dfs(adj);
    }
}

int main() {
    int M, Q;
    scanf("%d %d %d", &N, &M, &Q);
    for (int i = 0; i < M; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        edges.pb(mp(u, v));
        graph[u].pb(mp(v, w));
        graph[v].pb(mp(u, w));
    }
    int s = 0, t = N-1;
    dijkstra(t, 1);
    memset(par, 0, sizeof(par));
    dijkstra(s, 0);
    int curr = t;
    visited[curr] = true;
    vi path = {curr};
    while (curr != par[curr]) {
        curr = par[curr];
        visited[curr] = true;
        path.pb(curr);
    }
    reverse(all(path));
    visited.reset();
    //print(path);
    for (int i = (int)path.size()-1; i >= 1; i--) {
        curr = path[i];
        dfs(curr); //dfs visits all nodes who has a BEST path through curr
        //hence if visited[u] is true, u contains erroneous distance
        int u = join.begin()->second;
        while (visited[u] && !join.empty()) {
            join.erase(join.begin());
            u = join.begin()->second;
            //find unvisited node with smallest dist
        }
        ll mindist = join.empty() ? -1 : join.begin()->first;
        query[curr][path[i-1]] = mindist;
        query[path[i-1]][curr] = mindist;
    }
    for (int i = 0; i < Q; i++) {
        int e;
        scanf("%d", &e);
        int u = edges[e].fi, v = edges[e].se;
        printf("%lld\n", query[u][v] ? query[u][v] : dist[N-1][0]);
    }
}
/*
4 4 2
0 1 2
1 2 2
0 2 3
2 3 4
2
3
 */