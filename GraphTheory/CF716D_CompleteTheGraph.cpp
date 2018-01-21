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

#define lli pair <ll, int>

const int maxn = 1007;
bool erased[maxn][maxn];
vector <vector <lli>> graph(maxn);
ll dist[maxn][2], mat[maxn][maxn];
ii pre[maxn][2];

set <ii> path;

ll dijkstra(int n, int a, int b, vector <vi> &graph) {
    path.clear();
    ll DIST[maxn];
    int pre[maxn];
    for (int i = 0; i < n; i++) {
        DIST[i] = INF64;
        pre[i] = -1;
    }
    DIST[a] = 0;
    priority_queue <lli, vector <lli>, greater <lli>> pq;
    pq.push(mp(0, a));
    while (!pq.empty()) {
        lli top = pq.top();
        pq.pop();
        ll d = top.fi;
        int curr = top.se;
        if (DIST[curr] > d) continue;
        for (int adj : graph[curr]) {
            ll w = mat[curr][adj];
            if (d + w < DIST[adj]) {
                DIST[adj] = d+w;
                pq.push(mp(DIST[adj], adj));
                pre[adj] = curr;
            }
        }
    }

    int curr = b;
    while (curr != -1) {
        if (pre[curr] != -1) {
            path.insert(mp(min(curr, pre[curr]), max(curr, pre[curr])));
        }
        curr = pre[curr];
    }
    return DIST[b];
}


int main() {
    vector <ii> all_edges;
    int n, m, L, s, t;
    scanf("%d %d %d %d %d", &n, &m, &L, &s, &t);
    for (int i = 0; i < m; i++) {
        int u, v;
        ll w;
        scanf("%d %d %lld", &u, &v, &w);
        if (w == 0) {
            erased[u][v] = erased[v][u] = true;
            w = INF64;
        }
        mat[u][v] = mat[v][u] = w;
        all_edges.pb(mp(u, v));
    }
    vector <vi> graph(maxn);
    for (ii edge : all_edges) {
        int u = edge.fi, v = edge.se;
        if (!erased[u][v]) {
            graph[u].pb(v);
            graph[v].pb(u);
        }
    }
    ll d = dijkstra(n, s, t, graph);
    if (d < L) {
        printf("NO\n");
        return 0;
    }
    for (ii edge : all_edges) {
        int u = edge.fi, v = edge.se;
        if (erased[u][v]) {
            mat[u][v] = mat[v][u] = 1;
            graph[u].pb(v);
            graph[v].pb(u);
        }
    }
    d = dijkstra(n, s, t, graph);
    if (d > L) {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    while (d < L) {
        for (ii edge : path) {
            if (erased[edge.fi][edge.se]) {
                mat[edge.fi][edge.se] += L - d;
                mat[edge.se][edge.fi] += L - d;
                break;
            }
        }
        d = dijkstra(n, s, t, graph);
    }
    for (ii edge : all_edges) {
        int u = edge.fi, v = edge.se;
        ll w = mat[u][v];
        printf("%d %d %lld\n", u, v, w);
    }
}