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

const int maxn = 100007;
int N;
vi tree[maxn];
vector <ll> child_values[maxn];
ll ans = 0, dp1[maxn], dp2[maxn], dp3[maxn], dp4[maxn];

void dfs(int node, int par) {
    for (int adj : tree[node]) {
        if (adj != par) {
            dfs(adj, node);
            child_values[node].pb(dp1[adj]);
            dp1[node] = max(dp1[node], 1 + dp1[adj]);
            dp2[node] = max(dp2[node], dp2[adj]);
        }
    }
    sort(child_values[node].rbegin(), child_values[node].rend());
    dp2[node] = max(dp2[node], dp1[node]);
    if (child_values[node].size() >= 2)
        dp2[node] = max(dp2[node], child_values[node][0] + child_values[node][1] + 2);
}

void dfs2(int node, int par) {
    if (node != 1) {
        dp3[node] = dp3[par] + 1;
        if (child_values[par].size() >= 2) {
            if (dp1[node] == child_values[par][0]) {
                dp3[node] = max(dp3[node], child_values[par][1] + 2);
            }
            else {
                dp3[node] = max(dp3[node], child_values[par][0] + 2);
            }
        }
    }
    ans = max(ans, dp2[node] * dp4[node]);
    for (int adj : tree[node]) {
        if (adj != par) {
            dp4[adj] = dp3[node];
            if (child_values[node].size() >= 2) {
                if (dp1[adj] == child_values[node][0]) {
                    dp4[adj] = max(dp4[adj], dp3[node] + child_values[node][1] + 1);
                }
                else {
                    dp4[adj] = max(dp4[adj], dp3[node] + child_values[node][0] + 1);
                }
            }
            if (child_values[node].size() >= 3) {
                if (dp1[adj] == child_values[node][0]) {
                    dp4[adj] = max(dp4[adj], child_values[node][1] + child_values[node][2] + 2);
                }
                else if (dp1[adj] == child_values[node][1]) {
                    dp4[adj] = max(dp4[adj], child_values[node][0] + child_values[node][2] + 2);
                }
                else {
                    dp4[adj] = max(dp4[adj], child_values[node][0] + child_values[node][1] + 2);
                }
            }
            dfs2(adj, node);
        }
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N-1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        tree[u].pb(v);
        tree[v].pb(u);
    }
    dfs(1, 0);
    dfs2(1, 0);
    //for (int i = 1; i <= N; i++) cout << dp1[i] << " " << dp2[i] << " " << dp3[i] << " " << dp4[i] << endl;
    printf("%lld\n", ans);
}