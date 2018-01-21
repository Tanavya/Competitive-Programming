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

const int maxn = (int) 1e5+10;
ll dist[maxn][2], cnt[maxn][2];

void dijkstra(int start, int t, vector <vector <ii>> &graph) {

    priority_queue <lli, vector<lli >, greater<lli>> pq;
    dist[start][t] = 0;
    cnt[start][t] = 1;
    pq.push(mp(0, start));

    while (!pq.empty()) {
        lli top = pq.top();
        pq.pop();
        ll d = top.fi;
        int curr = top.se;

        if (dist[curr][t] < d) continue;

        for (ii edge : graph[curr]) {
            int adj = edge.fi, w = edge.se;
            if (d + w < dist[adj][t]) {
                dist[adj][t] = d + w;
                cnt[adj][t] = 1;
                pq.push(mp(dist[adj][t], adj));
            }
            else if (d + w == dist[adj][t]) {
                cnt[adj][t] += 1;
                pq.push(mp(dist[adj][t], adj));
            }
        }
    }
}
int main() {

    int N, M, s, t;
    scanf("%d %d %d %d", &N, &M, &s, &t);

    vector <vector <ii>> graph(N+7);
    vector <pair<int, ii>> all_edges;
    for (int i = 0; i < M; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u].pb(mp(v, w));
        all_edges.pb(mp(w, mp(u, v)));
    }

    for (int i = 1; i <= N; i++) {
        dist[i][0] = dist[i][1] = INF;
    }
    dijkstra(s, 0, graph);
    graph.assign(N+7, {});

    for (pair<int, ii> edge : all_edges) {
        int w = edge.fi, u = edge.se.fi, v = edge.se.se;
        graph[v].pb(mp(u, w));
    }

    dijkstra(t, 1, graph);

    for (int i = 1; i <= N; i++) {
        cout << i << " " << dist[i][0] << " " << cnt[i][0] << endl;
    }

    for (pair<int, ii> edge : all_edges) {
        int w = edge.fi, u = edge.se.fi, v = edge.se.se;
        if (dist[u][0] + w + dist[v][1] == dist[t][0]) {
            if (cnt[v][0] == 1) {
                printf("YES\n");
            }
            else {
                printf("CAN 1\n");
            }
        }
        else {
            ll ans = dist[u][0] + w + dist[v][1] - dist[t][0] + 1;
            printf("CAN %lld\n", ans);
        }
    }

}