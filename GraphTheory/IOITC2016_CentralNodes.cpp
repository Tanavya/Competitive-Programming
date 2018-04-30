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


const int maxn = 507;
vii graph[maxn];
vi prv[maxn];
int N, M;
ll dist[maxn][maxn];
bitset <maxn> visited, central;


void dijkstra(int src) {
    //trace(src);
    for (int i = 1; i <= N; i++) {
        dist[src][i] = INF;
        prv[i].clear();
    }
    visited.reset();
    dist[src][src] = 0;
    priority_queue <pair <ll, int>, vector <pair<ll, int>>, greater <pair<ll, int>>> pq;
    pq.push(mp(0, src));
    while (!pq.empty()) {
        pair <ll, int> top = pq.top();
        pq.pop();
        ll d = top.fi;
        int curr = top.se;
        if (d > dist[src][curr]) continue;
        if (prv[curr].size() == 1 && prv[curr][0] != src)
            central[prv[curr][0]] = true;
        for (ii edge : graph[curr]) {
            int adj = edge.fi; ll w = edge.se;
            if (d + w < dist[src][adj]) {
                prv[adj] = {curr};
                dist[src][adj] = d+w;
                pq.push(mp(d+w, adj));
            }
            else if (d + w == dist[src][adj]) {
                prv[adj].pb(curr);
            }
        }
    }
}
int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u].pb(mp(v, w));
        graph[v].pb(mp(u, w));
    }
    for (int n = 1; n <= N; n++) {
        dijkstra(n);
    }
    vi ans;
    for (int n = 1; n <= N; n++) {
        if (central[n]) ans.pb(n);
    }
    printf("%d\n", (int) ans.size());
    print(ans);
}
/*
4 4
4 3 4
1 2 2
2 3 3
4 1 5

 */