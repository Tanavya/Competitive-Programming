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

const int maxn = 107, maxk = 1007, mod = (int) 1e9 + 7;
int N = 0, K, C[maxn];
ll dp[maxn][2];
set <int> graph[maxn];
bitset <maxn> visited;

int cycle_st, cycle_en;
void dfs(int node, int par) {
    visited[node] = true;
    for (int adj : graph[node]) {
        if (adj != par) {
            if (visited[adj]) {
                if (cycle_st != -1) continue;
                cycle_st = adj;
                cycle_en = node;
            }
            else {
                dfs(adj, node);
            }
        }
    }
}
void rec(int n, int par) {
    dp[n][0] = dp[n][1] = 1;
    for (int adj : graph[n]) {
        if (adj == par) continue;
        if (n == cycle_st && adj == cycle_en) continue;
        if (adj == cycle_st) {
            dp[n][1] *= 0;
        }
        else {
            rec(adj, n);
            dp[n][0] *= (((((dp[adj][0] * (K-2)) % mod) + dp[adj][1])) % mod);
            dp[n][0] %= mod;
            dp[n][1] *= (((dp[adj][0]) * (K-1)) % mod);
            dp[n][1] %= mod;
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        for (int i = 0; i < N; i++) {
            graph[i].clear();
        }
        scanf("%d %d", &N, &K);
        for (int i = 0; i < N; i++) {
            scanf("%d", &C[i]);
            graph[i].insert(C[i]);
            graph[C[i]].insert(i);
        }
        visited.reset();
        ll ans = 1;
        for (int i = 0; i < N; i++) {
            if (!visited[i]) {
                //find all connected components
                cycle_st = cycle_en = -1;
                dfs(i, -1);
                if (cycle_st == -1)
                    cycle_st = i;
                rec(cycle_st, -1);
                ans *= ((dp[cycle_st][1] * K) % mod);
                ans %= mod;
            }
        }
        assert(ans >= 0);
        printf("%lld\n", ans);
    }
}
/*
3
2 3
1 0
->3
4 3
1 2 3 0
->18
6 3
1 2 3 4 5 0
->66
*/