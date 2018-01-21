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


const int maxn = (int)1e5+10;
vector <vector <ii>> graph(maxn);
int N, M, K, cnt[maxn];
ll dist[maxn];

int main() {


    scanf("%d %d %d", &N, &M, &K);

    for (int i = 0; i < M; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u].pb(mp(v, w));
        graph[v].pb(mp(u, w));
    }

    vector <ii> trains;

    for (int i = 0; i < K; i++) {
        int v, w;
        scanf("%d %d", &v, &w);
        graph[1].pb(mp(v, w));
        graph[v].pb(mp(1, w));
        trains.pb(mp(v, w));
    }

    for (int i = 2; i <= N; i++) {
        dist[i] = INF64;
    }

    priority_queue <ii, vector<ii>, greater <ii>> pq;

    pq.push(mp(0, 1));

    while (!pq.empty()) {
        ii top = pq.top();
        pq.pop();


        int d = top.fi;
        int curr = top.se;

        if (dist[curr] < d) continue;

        for (ii edge : graph[curr]) {
            int adj = edge.fi, weight = edge.se;

            if (dist[curr] + weight < dist[adj]) {
                dist[adj] = dist[curr] + weight;
                cnt[adj] = 1;
                pq.push(mp(dist[adj], adj));
            }

            else if (dist[curr] + weight == dist[adj]) {
                cnt[adj]++;
            }
        }
    }

    int ans = 0;

    for (int i = 0; i < K; i++) {
        int v, w;
        v = trains[i].fi, w = trains[i].se;
        if (w < dist[v]) assert(false);
        if (w == dist[v]) {
            if (cnt[v] > 1) {
                ans++;
                cnt[v]--;
            }
        }
        else {
            ans++;
        }
    }

    printf("%d\n", ans);

}