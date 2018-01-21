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

int main() {

    int N, M, tc = 0;
    while (scanf("%d %d", &N, &M) != EOF) {

        vector <vector <ii>> graph(N+7);
        for (int i = 0; i < M; i++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            graph[u].pb(mp(v, w));
            graph[v].pb(mp(u, w));
        }

        int dist[N+7][N+7][2];

        for (int s = 0; s < N; s++) {
            for (int i = 0; i < N; i++) {
                dist[s][i][0] = dist[s][i][1] = INF;
            }
            dist[s][s][0] = 0;
            priority_queue <ii, vector <ii>, greater <ii>> pq;
            pq.push(mp(0, s));

            while (!pq.empty()) {
                ii top = pq.top();
                int d = top.fi;
                int curr = top.se;
                pq.pop();
                if (d > dist[s][curr][0]) continue;

                for (ii edge : graph[curr]) {
                    int adj = edge.fi, w = edge.se;
                    if (d + w < dist[s][adj][0]) {
                        dist[s][adj][0] = d + w;
                        pq.push(mp(dist[s][adj][0], adj));
                    }
                }
            }
        }

        for (int s = 0; s < N; s++) {
            for (int t = 0; t < N; t++) {
                for (int u = 0; u < N; u++) {
                    for (ii edge : graph[u]) {
                        int v = edge.fi, w = edge.se;
                        if (dist[s][u][0] == INF || dist[v][t][0] == INF) continue;
                        int tmp = dist[s][u][0] + w + dist[v][t][0];
                        if (tmp != dist[s][t][0] && tmp < dist[s][t][1]) {
                            dist[s][t][1] = tmp;
                        }
                    }
                }
            }
        }

        printf("Set #%d\n", ++tc);
        int Q;
        scanf("%d", &Q);
        int a, b;
        while (Q--) {
            scanf("%d %d", &a, &b);
            //assert(dist[a][b][1] == INF || (dist[a][b][0] != dist[a][b][1]));
            if (dist[a][b][1] == INF) {
                printf("?\n");
            }
            else {
                printf("%d\n", dist[a][b][1]);
            }
        }
    }

}
/*
4 3
0 1 12
0 2 20
1 2 15
 */