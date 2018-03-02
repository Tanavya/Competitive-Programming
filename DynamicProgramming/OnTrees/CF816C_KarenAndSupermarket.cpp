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
#include <random>
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

const int maxn = 5007;
int N, B, C[maxn], D[maxn], size[maxn];
ll dp1[maxn][maxn], dp2[maxn][maxn];
vi tree[maxn];

void dfs(int node) {
    size[node] = 1;
    dp1[node][0] = dp2[node][0] = 0;
    dp1[node][1] = D[node] - C[node];
    dp2[node][1] = D[node];
    for (int child : tree[node]) {
        dfs(child);
        for (int i = size[node]; i >= 1; i--) {
            for (int j = 0; i+j <= size[node]+size[child] && j <= size[child]; j++) {
                dp1[node][i+j] = min(dp1[node][i+j], dp1[node][i] + min(dp1[child][j], dp2[child][j]));
            }
        }
        for (int i = size[node]; i >= 0; i--) {
            for (int j = 0; i+j <= size[node]+size[child] && j <= size[child]; j++) {
                dp2[node][i+j] = min(dp2[node][i+j], dp2[node][i] + dp2[child][j]);
            }
        }
        size[node] += size[child];
    }
}

int main() {
    for (int i = 0; i < maxn; i++)
        for (int j = 0; j < maxn; j++)
            dp1[i][j] = dp2[i][j] = INF64;

    scanf("%d %d", &N, &B);
    for (int i = 1; i <= N; i++) {
        scanf("%d %d", &D[i], &C[i]);
        if (i >= 2) {
            int par;
            scanf("%d", &par);
            tree[par].pb(i);
        }
    }
    dfs(1);
    int ans = 0;
    for (int i = 1; i <= N && ((dp1[1][i] <= B) || (dp2[1][i] <= B)); i++)
        ans = max(ans, i);
    for (int i = 2; i <= N; i++) {
        for (int j = 1; j <= N && dp2[i][j] <= B; j++) {
            ans = max(ans, j);
        }
    }
    printf("%d\n", ans);
}