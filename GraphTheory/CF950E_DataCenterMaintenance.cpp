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
int N, M, H, C[maxn], scc[maxn], deg[maxn];
vi graph[maxn], rgraph[maxn], euler, components[maxn];
bitset <maxn> visited;

void dfs1(int node) {
    visited[node] = true;
    for (int adj : graph[node]) {
        if (!visited[adj]) {
            dfs1(adj);
        }
    }
    euler.pb(node);
}

void dfs2(int node, int c) {
    visited[node] = true;
    components[c].pb(node);
    scc[node] = c;
    for (int adj : rgraph[node]) {
        if (!visited[adj]) {
            dfs2(adj, c);
        }
    }
}

int main() {
    scanf("%d %d %d", &N, &M, &H);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &C[i]);
    }
    for (int i = 1; i <= M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        if ((C[u] + 1) % H == C[v]) {
            graph[u].pb(v);
            rgraph[v].pb(u);
        }
        if ((C[v] + 1) % H == C[u]) {
            graph[v].pb(u);
            rgraph[u].pb(v);
        }
    }
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            dfs1(i);
        }
    }
    reverse(all(euler));
    visited.reset();
    int c = 0;
    for (int n : euler) {
        if (!visited[n]) {
            dfs2(n, ++c);
        }
    }
    for (int n = 1; n <= c; n++) {
        for (int u : components[n]) {
            for (int v : graph[u]) {
                if (scc[u] != scc[v]) {
                    deg[scc[u]]++;
                }
            }
        }
    }
    int ans = INF, best = 0;
    for (int n = 1; n <= c; n++) {
        if (!deg[n]) {
            if (components[n].size() < ans) {
                ans = (int)components[n].size();
                best = n;
            }
        }
    }
    assert(ans != INF);
    printf("%d\n", ans);
    print(components[best]);
}