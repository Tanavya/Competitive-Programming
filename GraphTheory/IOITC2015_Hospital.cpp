#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <assert.h>
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
vector <lli> graph[maxn];
ll dist[maxn];
bool ishospital[maxn], visited[maxn];

int main() {
    //freopen("inp.txt", "r", stdin);
    int N, M, P;
    scanf("%d %d %d", &N, &M, &P);
    vi hospitals(P);
    priority_queue <lli, vector <lli>, greater<lli>> pq;
    for (int i = 1; i <= N; i++) dist[i] = INF64;

    for (int i = 0; i < P; i++) {
        scanf("%d", &hospitals[i]);
        pq.push(mp(0, hospitals[i]));
        dist[hospitals[i]] = 0;
        ishospital[hospitals[i]] = true;
    }
    for (int i = 0; i < M; i++) {
        int u, v, d;
        scanf("%d %d %d", &u, &v, &d);
        graph[u].pb(mp(d, v));
        graph[v].pb(mp(d, u));
    }
    while (!pq.empty()) {
        lli top = pq.top();
        pq.pop();
        ll d = top.fi;
        int curr = top.se;
        if (dist[curr] < d) continue;
        if (visited[curr]) continue;
        visited[curr] = true;
        for (lli edge : graph[curr]) {
            ll w = edge.fi;
            int adj = edge.se;
            if (dist[adj] > d+w) {
                dist[adj] = d+w;
                pq.push(mp(dist[adj], adj));
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        if (!ishospital[i])
            printf("%d %lld\n", i, dist[i] == INF64 ? -1 : dist[i]);
    }
}
/*
5 7 2
1 3
1 2 10
1 4 20
1 5 30
2 3 11
2 4 5
3 5 18
4 5 2
 */