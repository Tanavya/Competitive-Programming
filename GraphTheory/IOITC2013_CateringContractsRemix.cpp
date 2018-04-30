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

const int INF = int(1e9)+10;
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
using namespace std;

const int maxn = 100007;
vector <ii> tree[maxn];
int color[maxn], dp[maxn][107], values[maxn][2];

void dfs(int node, int par) {
    for (ii edge : tree[node]) {
        int adj = edge.fi;
        if (adj != par) {
            dfs(adj, node);
        }
    }
    values[node][0] = values[node][1] = INF;
    for (int col = 0; col <= 100; col++) {
        if (color[node] == -1 || color[node] == col) {
            dp[node][col] = 0;
            for (ii edge : tree[node]) {
                int adj = edge.fi, w = edge.se;
                if (adj != par) {
                    int tmp = dp[adj][col]; //take both same color
                    if (dp[adj][col] == values[adj][0])
                        tmp = min(tmp, w + values[adj][1]);
                    else
                        tmp = min(tmp, w + values[adj][0]);
                    dp[node][col] += tmp;
                }
            }
            if (dp[node][col] < values[node][0])
                values[node][0] = dp[node][col];
            else if (dp[node][col] < values[node][1])
                values[node][1] = dp[node][col];
        }
        else {
            dp[node][col] = INF;
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 1; i < N; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        tree[u].pb(mp(v, w));
        tree[v].pb(mp(u, w));
    }
    for (int i = 1; i <= N; i++) {
        scanf("%d", &color[i]);
    }
    dfs(1, 0);
    int ans = INF;
    for (int i = 0; i <= 100; i++) {
        ans = min(ans, dp[1][i]);
    }
    printf("%d\n", ans);
}