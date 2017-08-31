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

#define mp make_pair
#define pb push_back
#define x first
#define y second
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << endl;
#define debug(x) cout << x << endl;
#define debug2(x,y) cout << x << " " << y << endl;
typedef long long int ll;
typedef long double ld;
typedef std::pair <int, int> ii;
typedef std::vector <int> vi;
typedef std::vector <ll> vll;
const int INF = int(1e9);
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
using namespace std;

int main() {


    int T, N, M, K, u, v;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &N, &M, &K);
        vector <vector <int>> graph(N + 7);
        for (int i = 0; i < M; i++) {
            scanf("%d %d", &u, &v);
            graph[u].pb(v);
        }
        queue <ii> Q;
        Q.push({1, 0});
        bitset <107> viz;
        int ans = 0, cnt = 0;
        while (!Q.empty()) {
            int u = Q.front().x, d = Q.front().y; 
            Q.pop();
            if (u == N) {
                cnt++;
                ans = max(ans, d);
                if (cnt == K) break;
            }
            //if (viz[u]) continue;
            //viz[u] = true;
            for (int v : graph[u]) {
                Q.push({v, d+1});                
            }
        }
        cout << ans << endl;
    }


}