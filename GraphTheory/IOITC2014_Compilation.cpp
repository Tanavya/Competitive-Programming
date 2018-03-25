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

const int maxn = (int) 1e5+10;
vi graph[maxn], rgraph[maxn];
ll dp2[maxn], dp1[maxn], A[maxn], ans = 0;
bitset <maxn> visited;

void dfs1(int node) {
    visited[node] = true;
    for (int adj : graph[node]) {
        if (!visited[adj]) {
            dfs1(adj);
        }
    }
    dp1[node] = A[node];
    for (int adj : graph[node]) {
        dp1[node] = max(dp1[node], dp1[adj] + A[node]);
    }
    ans = max(ans, dp1[node]);
}

void dfs2(int node) {
    visited[node] = true;
    for (int adj : rgraph[node]) {
        if (!visited[adj]) {
            dfs2(adj);
        }
    }
    dp2[node] = A[node];
    for (int adj : rgraph[node]) {
        dp2[node] = max(dp2[node], dp2[adj] + A[node]);
    }
}

int main() {
    int N, M;
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
    for (int n = 1; n <= N; n++) {
        if (!visited[n]) dfs1(n);
    }
    visited.reset();
    for (int n = 1; n <= N; n++) {
        if (!visited[n]) dfs2(n);
    }
    printf("%lld\n", ans);
    int Q;
    scanf("%d", &Q);
    while (Q--) {
        int n; ll d;
        scanf("%d %lld", &n, &d);
        printf("%lld\n", max(ans, dp1[n] + dp2[n] + d - A[n]));
    }
    return 0;
}
/*5 4
2 9 3 5 12
2 1
3 5
3 2
4 5*/