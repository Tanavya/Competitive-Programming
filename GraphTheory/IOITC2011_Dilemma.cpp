#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <assert.h>
#include <map>
#include <stack>

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

const int INF = int(1e9);
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
using namespace std;

const int maxn = 1507, maxnn = maxn*maxn;
int N, M, grid[maxn][maxn], dp[maxn*maxn];
bitset <maxnn> vis;
vi graph[maxn*maxn], euler;

void dfs(int node) {
    vis[node] = true;
    for (int adj : graph[node]) {
        if (!vis[adj]) {
            dfs(adj);
        }
    }
    euler.pb(node);
}

int main() {
    //freopen("inp2.txt", "r", stdin);
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        stack <ii> stk_fwd;
        for (int j = 0; j < M; j++) {
            scanf("%d", &grid[i][j]);
            while (!stk_fwd.empty() && stk_fwd.top().fi > grid[i][j])
                stk_fwd.pop();
            if (!stk_fwd.empty())
                graph[i*M+j].pb(i*M+stk_fwd.top().se);
            stk_fwd.push(mp(grid[i][j], j));
        }
        stack <ii> stk_bck;
        for (int j = M-1; j >= 0; j--) {
            while (!stk_bck.empty() && stk_bck.top().fi > grid[i][j])
                stk_bck.pop();
            if (!stk_bck.empty())
                graph[i*M+j].pb(i*M+stk_bck.top().se);
            stk_bck.push(mp(grid[i][j], j));
        }
    }
    for (int j = 0; j < M; j++) {
        stack <ii> stk_fwd;
        for (int i = 0; i < N; i++) {
            while (!stk_fwd.empty() && stk_fwd.top().fi > grid[i][j])
                stk_fwd.pop();
            if (!stk_fwd.empty())
                graph[i*M+j].pb(stk_fwd.top().se*M+j);
            stk_fwd.push(mp(grid[i][j], i));
        }
        stack <ii> stk_bck;
        for (int i = N-1; i >= 0; i--) {
            while (!stk_bck.empty() && stk_bck.top().fi > grid[i][j])
                stk_bck.pop();
            if (!stk_bck.empty())
                graph[i*M+j].pb(stk_bck.top().se*M+j);
            stk_bck.push(mp(grid[i][j], i));
        }
    }
    int ans = 0;
    for (int i = 0; i < N*M; i++) {
        if (!vis[i]) dfs(i);
    }
    for (int i = (int)euler.size()-1; i >= 0; i--) {
        int node = euler[i];
        dp[node] = max(dp[node], 1);
        ans = max(ans, dp[node]);
        for (int adj : graph[node]) {
            dp[adj] = max(dp[adj], 1 + dp[node]);
        }
    }
    printf("%d\n", ans);
}
/*
4 4
1 5 50 2
42 12 60 55
31 22 46 15
8 4 78 43
 */