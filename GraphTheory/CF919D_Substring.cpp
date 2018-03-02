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

const int maxn = 300007;
int N, M, root, ans = 0;
vi graph[maxn];
bool visited[maxn];
string A;
vi topo;
int MAP[maxn], dp[maxn][30];

void dfs(int node) {
    visited[node] = true;
    for (int adj : graph[node]) {
        if (!visited[adj])
            dfs(adj);
    }
    topo.pb(node);
}


int main() {
    scanf("%d %d", &N, &M);
    cin >> A;
    for (int i = 0; i < M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u].pb(v);
    }
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            root = i;
            dfs(root);
        }
    }
    reverse(all(topo));
    //print(topo);
    for (int i = topo.size() - 1; i >= 0; i--) {
        int u = topo[i];
        MAP[u] = i;
        for (int v : graph[u]) {
            for (int j = 0; j <= 26; j++) {
                dp[u][j] = max(dp[v][j], dp[u][j]);
            }
        }
        dp[u][A[u-1]-97]++;
    }
    for (int i = topo.size() - 1; i >= 0; i--) {
        int u = topo[i];
        for (int v : graph[u]) {
            if (MAP[v] <= i) {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= 26; j++)
            ans = max(ans, dp[i][j]);
    }
    cout << ans << endl;

}