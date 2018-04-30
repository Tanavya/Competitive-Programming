#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <assert.h>
#include <map>
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

const int maxn = 507;
vector <ii> graph[maxn];
int dist1[maxn][maxn], dist2[maxn][maxn], can_reach[maxn][maxn];
vi S[maxn];

int main() {
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);
    for (int i = 0; i < M; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u].pb(mp(v, w));
        graph[v].pb(mp(u, w));
    }
    for (int i = 1; i <= N; i++) {
        int sz;
        scanf("%d", &sz);
        for (int j = 0; j < sz; j++) {
            int x;
            scanf("%d", &x);
            can_reach[i][x] = true;
            S[i].pb(x);
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            dist1[i][j] = dist2[i][j] = INF;
        }
    }

    for (int start = 1; start <= N; start++) {
        priority_queue <ii, vector <ii>, greater <ii>> pq;
        dist1[start][start] = 0;
        pq.push(mp(0, start));
        while (!pq.empty()) {
            int d = pq.top().fi, node = pq.top().se;
            pq.pop();
            if (d > dist1[start][node]) continue;
            for (ii edge : graph[node]) {
                int adj = edge.fi, w = edge.se;
                if (can_reach[start][adj]) {
                    if (d + w < dist1[start][adj]) {
                        dist1[start][adj] = d+w;
                        pq.push(mp(d+w, adj));
                    }
                }
            }
        }
    }
    int src = 1, dest = N, ans = INF;
    priority_queue <pair <int, ii>, vector <pair <int, ii>>, greater <pair <int, ii>>> pq;
    pq.push(mp(0, mp(src, 0)));
    dist2[src][0] = 0;
    while (!pq.empty()) {
        pair <int, ii> top = pq.top();
        int d = top.fi, node = top.se.fi, k = top.se.se;
        pq.pop();
        if (d > dist2[node][k]) continue;
        if (node == dest) {
            ans = min(ans, d);
            continue;
        }
        if (k < K) {
            for (int adj : S[node]) {
                int w = dist1[node][adj];
                if (d + w < dist2[adj][k+1]) {
                    dist2[adj][k+1] = d+w;
                    pq.push(mp(d+w, mp(adj, k+1)));
                }
            }
        }
    }
    if (ans == INF) printf("%d\n", -1);
    else printf("%d\n", ans);
}
/*
4 5 2
1 2 1
1 3 1
1 4 10
2 4 5
3 4 1
3 1 2 4
4 1 2 3 4
2 1 3
1 4
 */