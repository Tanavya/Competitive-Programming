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

const int maxn = 1007;
int N, M, scc[maxn], dp[maxn][maxn], num[maxn];
bitset <maxn> visited;
bool mat[maxn][maxn];
ll A[maxn];
vi graph[maxn], rgraph[maxn], ngraph[maxn], components[maxn], euler;

bool cmp(int a, int b) {
    return A[a] < A[b];
}
void dfs1(int node) {
    visited[node] = true;
    for (int adj : graph[node]) {
        if (!visited[adj]) {
            dfs1(adj);
        }
    }
    euler.pb(node);
}

void dfs2(int node, int c) {
    visited[node] = true;
    scc[node] = c;
    components[c].pb(node);
    for (int adj : rgraph[node]) {
        if (!visited[adj]) {
            dfs2(adj, c);
        }
    }
}

int dfs3(int node, int prev) {
    int &val = dp[node][prev];
    if (val != -1)
        return val;
    val = A[node] > A[prev];
    assert(components[scc[node]][num[node]] == node);
    if (components[scc[node]].back() == node) {
        assert(num[node]+1 == components[scc[node]].size());
        for (int adj : ngraph[scc[node]]) {
            val = max(val, dfs3(components[adj].front(), prev));
            if (A[node] > A[prev])
                val = max(val, dfs3(components[adj].front(), node) + 1);
        }
    }
    else {
        val = max(val, dfs3(components[scc[node]][num[node] + 1], prev));
        if (A[node] > A[prev])
            val = max(val, dfs3(components[scc[node]][num[node] + 1], node) + 1);
    }
    return val;
}

int main() {
    memset(dp, -1, sizeof(dp));
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++) {
        scanf("%lld", &A[i]);
    }
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
    reverse(all(euler));
    visited.reset();
    int c = 0;
    for (int i : euler) {
        if (!visited[i]) {
            dfs2(i, ++c);
        }
    }
    for (int i = 1; i <= c; i++) {
        sort(all(components[i]), cmp);
    }
    for (int i = 1; i <= N; i++) {
        for (int j : graph[i]) {
            int u = scc[i], v = scc[j];
            if (u != v && !mat[u][v]) {
                ngraph[u].pb(v);
                mat[u][v] = true;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= c; i++) {
        for (int j = 0; j < components[i].size(); j++) {
            num[components[i][j]] = j;
        }
    }
    for (int i = 1; i <= c; i++) {
        for (int j : components[i]) {
            ans = max(ans, dfs3(j, 0));
        }
    }
    printf("%d\n", ans);
}