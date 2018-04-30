#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <assert.h>
#include <set>
#include <random>
#include <iomanip>
#include <map>
#include <bitset>
#include <queue>

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

const int INF = 2147483647;
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
using namespace std;

const int maxn = 2507, mod = 10243;
int N, K;
ll dp[maxn][100], ans = 0;
vi tree[maxn];

void dfs(int node, int par) {
    dp[node][1] = 1;
    for (int adj : tree[node]) {
        if (adj != par) {
            dfs(adj, node);
            for (int k = K; k >= 1; k--) {
                for (int i = 1; i <= k; i++) {
                    int j = k-i;
                    dp[node][k] += (dp[node][i] * dp[adj][j]) % mod;
                    dp[node][k] %= mod;
                }
            }
        }
    }
    ans += dp[node][K];
    ans %= mod;
}

int main() {
    scanf("%d %d", &N, &K);
    for (int i = 1; i < N; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        tree[u].pb(v);
        tree[v].pb(u);
    }
    dfs(1, 0);
    printf("%lld\n", ans);
}
/*
6 3
1 2
2 5
3 2
4 5
6 5

 */