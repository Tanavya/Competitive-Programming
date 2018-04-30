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

const int INF = 2147483647;
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
using namespace std;

const int maxn = (int) 1e5+10;
vi rgraph[maxn], graph[maxn], components[maxn], topo;
bitset <maxn> visited;
int dp[maxn][2], sz[maxn], scc[maxn], nxt[maxn], prv[maxn], last[maxn], first[maxn];

void dfs1(int node) {
    visited[node] = true;
    for (int adj : graph[node]) {
        if (!visited[adj]) {
            dfs1(adj);
        }
    }
    topo.pb(node);
}

void dfs2(int node, int c) {
    visited[node] = true;
    scc[node] = c;
    sz[c]++;
    for (int adj : rgraph[node]) {
        if (!visited[adj]) {
            dfs2(adj, c);
        }
    }
    components[c].pb(node);
}

int dfs3(int node, int dir) {
    int &val = dp[node][dir];
    if (val != -INF)
        return val;
    int c = scc[node];
    if (dir == 0)
        val = 0;
    else
        val = -1;
    if (dir == 0) {
        for (int adj : graph[node]) {
            if (scc[adj] != c) {
                val = max(val, 1 + dfs3(adj, 0));
                val = max(val, 1 + sz[scc[adj]] + dfs3(adj, 1));
            }
        }
        if (node != last[c]) {
            val = max(val, 1 + dfs3(nxt[node], dir));
        }
    }
    else {
        if (node != first[c]) {
            for (int adj : graph[prv[node]]) {
                if (scc[adj] != c) {
                    val = max(val, dfs3(adj, 0));
                    val = max(val, sz[scc[adj]] + dfs3(adj, 1));
                }
            }
            val = max(val, -1 + dfs3(prv[node], dir));
        }
    }
    return val;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u].pb(v);
        rgraph[v].pb(u);
    }
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            dfs1(i);
        }
    }
    visited.reset();
    int c = 0;
    for (int i = N-1; i >= 0; i--) {
        int u = topo[i];
        if (!visited[u]) {
            dfs2(u, ++c);
        }
    }
    for (int i = 1; i <= c; i++) {
        for (int j = 0; j < components[i].size()-1; j++) {
            nxt[components[i][j]] = components[i][j+1];
        }
        last[i] = components[i].back();
        for (int j = 1; j < components[i].size(); j++) {
            prv[components[i][j]] = components[i][j-1];
        }
        first[i] = components[i].front();
    }
    for (int i = 0; i <= N; i++) {
        dp[i][0] = dp[i][1] = -INF;
    }
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        ans = max(ans, dfs3(i, 0));
        ans = max(ans, sz[scc[i]] + dfs3(i, 1));
    }
    printf("%d\n", ans);
}
/*
6 9
1 2
2 3
3 1
4 5
5 4
1 4
3 5
2 5
2 6
 */