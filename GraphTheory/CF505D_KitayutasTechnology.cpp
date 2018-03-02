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
vi graph[maxn], r_graph[maxn], n_graph[maxn];
bitset <maxn> visited;
int color[maxn];

#define WHITE 0
#define GRAY 1
#define BLACK 2

bool has_cycle(int node) {
    color[node] = GRAY; //vertex being processed by DFS, but traversal hasn't been complete
    for (int adj : graph[node]) {
        if (color[adj] != BLACK) {
            if (color[adj] == GRAY)
                return true; //this is a back edge, and causes a cycle
            if (has_cycle(adj))
                return true;
        }
    }
    color[node] = BLACK; //vertex completely processed
    return false;
}
bool cycle = false;
void dfs(int node) {
    //visits all nodes in the weakly connected component
    //and checks if there is a (directed) cycle
    visited[node] = true;
    if (color[node] == WHITE && has_cycle(node)) {
        cycle = true;
    }
    for (int adj : graph[node]) {
        if (!visited[adj]) {
            dfs(adj);
        }
    }
    for (int adj : r_graph[node]) {
        if (!visited[adj]) {
            dfs(adj);
        }
    }
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u].pb(v);
        r_graph[v].pb(u);
    }
    int ans = N;
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            cycle = false;
            dfs(i);
            if (!cycle) ans--;
        }
    }
    printf("%d\n", ans);
}