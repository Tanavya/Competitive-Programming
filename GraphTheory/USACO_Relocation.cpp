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

const int maxn = (int) 1e4 + 7;
vector <vector <ii>> graph(maxn);
int dist[5][maxn];
bool ismarket[maxn];
int main() {

    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);

    vi markets(K);
    for (int i = 0; i < K; i++) {
        scanf("%d", &markets[i]);
        ismarket[markets[i]] = true;
    }
    for (int i = 0; i < M; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u].pb(mp(v, w));
        graph[v].pb(mp(u, w));
    }

    sort(all(markets));

    for (int j = 0; j < K; j++) {
        int market = markets[j];
        for (int i = 1; i <= N; i++) {
            dist[j][i] = INF;
        }
        dist[j][market] = 0;
        priority_queue <ii, vector <ii>, greater <ii>> pq;
        pq.push(mp(0, market));
        while (!pq.empty()) {
            int d = pq.top().fi;
            int curr = pq.top().se;
            pq.pop();
            if (d > dist[j][curr])
                continue;
            assert(d == dist[j][curr]);
            for (ii edge : graph[curr]) {
                int adj = edge.fi;
                int w = edge.se;
                if (dist[j][curr] + w < dist[j][adj]) {
                    dist[j][adj] = dist[j][curr] + w;
                    pq.push(mp(dist[j][adj], adj));
                }
            }
        }
    }
    vi order;
    for (int i = 0; i < K; i++)
        order.pb(i);
    ll best = INF64;
    do {
        for (int i = 1; i <= N; i++) {
            if (ismarket[i]) continue;
            ll curr = dist[order[0]][i];
            for (int j = 1; j < K; j++) {
                curr += dist[order[j]][markets[order[j-1]]];
            }
            curr += dist[order[K-1]][i];
            best = min(best, curr);
        }

    } while (next_permutation(all(order)));
    printf("%lld\n", best);
}