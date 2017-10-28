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
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip> //cout << setprecision(node) << fixed << num

#define mp make_pair
#define pb push_back
#define x first
#define y second
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << "\n";

typedef long long int ll;
typedef long double ld;
typedef std::pair <int, int> ii;
typedef std::vector <int> vi;
typedef std::vector <ll> vll;
const int INF = int(1e9);
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

using namespace std;

const int MOD = 1e9 + 7;
int N, K, A[50007];
ll ans;
vector <vi> tree;
vector <vll> dp;

inline ll add(ll a, ll b) {
    return ((a % MOD) + (b % MOD)) % MOD;
}
inline ll mult(ll a, ll b) {
    return ((a % MOD) * (b % MOD)) % MOD;
}
void dfs(int node, int parent) {
    if (A[node]) 
        dp[node][1] = 1;
    else
        dp[node][0] = 1;
    
    for (int adj : tree[node]) {
        if (adj != parent) {
            dfs(adj, node);
            vll temp (107, 0);
            for (int i = 0; i <= K; i++) {
                temp[i] = (dp[node][i] * dp[adj][0]) % MOD;
            }
            for (int i = K; i >= 0; i--) {
                for (int j = 1; i+j <= K; j++) {
                    //dp[node][i+j] = add(dp[node][i+j], mult(dp[node][i], dp[adj][j]));
                    dp[node][i+j] += dp[node][i] * dp[adj][j];
                    dp[node][i+j] %= MOD;
                    //printf("dp[%d][%d] = %lld\n", node, i+j, dp[node][i+j]);

                }
            }
            for (int i = 0; i <= K; i++) {
                dp[node][i] += temp[i];
                dp[node][i] %= MOD;
            }
        }
    }
    ans += dp[node][K];
    ans %= MOD;
}
void reset() {
    tree.assign(N+7, {});
    dp.assign(N+7, vll(K+7, 0));
    ans = 0;
}
int main() {
    int T, a, b;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &N, &K);
        reset();
        for (int i = 1; i <= N; i++)
            scanf("%d", &A[i]);
        for (int i = 0; i < N-1; i++) {
            scanf("%d %d", &a, &b);
            tree[a].pb(b);
            tree[b].pb(a);
        }
        dfs(1, 0);
        //cout << dp[2][0] << endl;
        printf("%d\n", ans);
    }
    
}
/*
1
7 4
1 0 1 1 0 1 1
1 2
1 3
2 4
2 5
3 6
3 7
*/