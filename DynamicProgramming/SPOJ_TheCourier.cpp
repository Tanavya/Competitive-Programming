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

const int maxn = 107;
vector <vector <ii>> graph;
int n, b[5], N, M, B;
ll dp[13][1 << 13], dist[maxn][maxn];

vector <ii> orders;

ll rec(int last, int msk) {
    if (dp[last][msk] != -1)
        return dp[last][msk];
    ll &ret = dp[last][msk];
    ret = INF64;
    if (msk == (1 << n) - 1)
        ret = dist[orders[last-1].se][B];

    else if (!last) {
        for (int i = 0; i < n; i++) {
            int u = orders[i].fi, v = orders[i].se;
            ret = min(ret, dist[B][u] + dist[u][v] + rec(i+1, (1 << i)));
        }
    }
    else {
        for (int i = 0; i < n; i++) {
            if (!((1 << i) & msk)) {
                int u = orders[i].fi, v = orders[i].se;
                ret = min(ret, dist[orders[last-1].se][u] + dist[u][v] + rec(i+1, msk | (1 << i)));
            }
        }
    }
    return ret;
}

int main() {

    int T;
    scanf("%d", &T);
    while (T--) {

        memset(dist, 0, sizeof(dist));
        scanf("%d %d %d", &N, &M, &B);
        for (int i = 0; i < M; i++) {
            int u, v, d;
            scanf("%d %d %d", &u, &v, &d);
            dist[u][v] = dist[v][u] = d;
        }
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (!dist[i][j] && i != j)
                    dist[i][j] = INF;
            }
        }
        for (int k = 1; k <= N; k++) {
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= N; j++) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
        //for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) debug3(i, j, dist[i][j]);


        int z;
        scanf("%d", &z);
        orders.resize(z);
        for (int i = 0; i < z; i++) {
            scanf("%d %d %d", &orders[i].fi, &orders[i].se, &b[i]);
        }
        for (int i = 0; i < z; i++) {
            for (int j = 1; j < b[i]; j++) {
                orders.pb(mp(orders[i].fi, orders[i].se));
            }
        }
        n = (int)orders.size();
        memset(dp, -1, sizeof(dp));
        ll ans = rec(0, 0);
        printf("%lld\n", ans);
    }

}