#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <assert.h>

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

const int maxn = 1007, maxc = 30007;
int N, D, C[maxn], S[maxn], P[maxn];
ll dp[maxn][maxc], dp2[maxn][600];
vector <ii> tree[maxn];

void dfs0(int node, int par) {
    P[node] = par;
    S[node] = C[node];
    for (ii &edge : tree[node]) {
        int adj = edge.fi;
        if (adj != par) {
            dfs0(adj, node);
            if (S[adj] > S[tree[node][0].fi] || tree[node][0].fi == par) swap(edge, tree[node][0]);
            S[node] += S[adj];
        }
    }
}


void dfs(int node, int par) {
    S[node] = C[node];
    for (int i = 0; i < maxc; i++)
        dp[node][i] = INF64;
    dp[node][C[node]] = 0;
    for (ii edge : tree[node]) {
        int adj = edge.fi;
        ll w = 2*edge.se;
        if (adj != par) {
            dfs(adj, node);
            for (int i = S[node]; i >= C[node]; i--) {
                for (int j = C[adj]; j <= S[adj] && i+j <= S[node]+S[adj]; j++) {
                    dp[node][i+j] = min(dp[node][i+j], w + dp[node][i] + dp[adj][j]);
                }
            }
            S[node] += S[adj];
        }
    }
}

void dfs_st1(int node, int par) {
    dp2[node][0] = C[node];
    for (ii edge : tree[node]) {
        int adj = edge.fi;
        ll w = 2*edge.se;
        if (adj != par) {
            dfs_st1(adj, node);
            for (int i = D; i >= 0; i--) {
                for (int j = 0; i+j+w <= D; j++) {
                    dp2[node][i+j+w] = max(dp2[node][i] + dp2[adj][j], dp2[node][i+j+w]);
                }
            }
        }
    }
}

int main() {
    scanf("%d %d", &N, &D);
    for (int i = 1; i <= N; i++)
        scanf("%d", &C[i]);
    for (int i = 1; i < N; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        tree[u].pb(mp(v, w));
        tree[v].pb(mp(u, w));
    }
    /*
    if (D <= 100) {
        dfs_st1(1, 0);
        ll ans = 0;
        for (int d = 0; d <= D; d++) {
            ans = max(dp2[1][d], ans);
        }
        printf("%lld\n", ans);
        return 0;
    }*/
    dfs(1, 0);
    /*
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= 30; j++) {
            printf("dp[%d][%d] = %lld\n", i, j, dp[i][j]);
        }
    }*/
    int ans = 0;
    for (int i = 0; i < maxc; i++) {
        if (dp[1][i] <= D) ans = i;
    }
    printf("%d\n", ans);
}
/*
6 8
0 10 5 3 2 8
1 3 1
3 2 5
3 4 1
4 6 2
1 5 1
 */
