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
#include <unordered_map>
#include <unordered_set>
#include <iomanip> //cout << setprecision(node) << fixed << num
#include <stack>
#include <sstream>


#define MAX(a,b) ((a)>(b)?(a):(b))
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

const int maxn = 100010;
vector <vi> graph(maxn);

bitset <maxn> visited;
bool cycle = false;
void dfs(int node, int prev) {
    visited[node] = true;
    for (int adj : graph[node]) {
        if (adj != prev) {
            if (visited[adj]) {
                cycle = true;
            }
            else {
                dfs(adj, node);
            }
        }
    }
}
int main() {
    int N, M, u, v;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &u, &v);
        graph[u].pb(v);
        graph[v].pb(u);
    }
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            cycle = false;
            dfs(i, 0);
            if (!cycle)
                ans += 1;
        }
    }
    printf("%d\n", ans);
}