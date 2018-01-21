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

const int maxn = 1e4+10, mod = 1e9+7;

vector <vi> graph(maxn);
bitset <maxn> visited;
vi topo;
ll dp[maxn];
bool mat[maxn][maxn], ans_big[maxn];
int MAP[maxn];

void dfs(int node) {
    visited[node] = true;
    for (int adj : graph[node]) {
        if (!visited[adj])
            dfs(adj);
    }
    topo.pb(node);
}

int main() {

    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u].pb(v);
        mat[u][v] = true;
    }
    dfs(1);
    reverse(all(topo));
    dp[2] = 1;

    for (int i = topo.size() - 1; i >= 0; i--) {
        int u = topo[i];
        MAP[u] = i;
        for (int v : graph[u]) {
            dp[u] += dp[v];
            if (dp[u] > mod || ans_big[v])
                ans_big[u] = true;
            dp[u] %= mod;
        }
    }
    for (int i = topo.size() - 1; i >= 0; i--) {
        int u = topo[i];
        for (int v : graph[u]) {
            if (MAP[v] < i) {
                if (dp[v] || (!dp[v] && ans_big[v])) {
                    printf("inf\n");
                    return 0;
                }
            }
        }
    }
    /*
    if (ans_big[1]) {
        cout << setw(9) << setfill('0') << dp[1] << endl;
    }
    else {
        cout << dp[1] << endl;
    }*/
    cout << dp[1] << endl;
}