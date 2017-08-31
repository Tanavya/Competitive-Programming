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
#include <iomanip> //cout << setprecision(node) << fixed << scc
 
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << endl;
#define debug(x) cout << x << endl;
#define debug2(x,y) cout << x << " " << y << endl;
typedef long long int ll;
typedef long double ld;
typedef std::pair <int, int> ii;
typedef std::vector <int> vi;
typedef std::vector <ll> vll;
const int INF = int(1e9);
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
using namespace std;
const int nmax = 5e5 + 7;
vector <vi> graph(nmax), rgraph(nmax), ngraph(nmax);
vi value(nmax), topo, scc(nmax), component_sum(nmax, 0), dp(nmax, -1);
bitset <nmax> pubs, pubs2, visited;
int N, M, x = 1;

void dfs1(int node) {
    visited[node] = true;
    for (int adj : graph[node]) {
        if (!visited[adj]) {
            dfs1(adj);
        }
    }
    topo.pb(node);
}
void dfs2(int node) {
    visited[node] = true;
    for (int adj : rgraph[node]) {
        if (!visited[adj])
            dfs2(adj);
    }
    if (pubs[node]) pubs2[x] = true;
    component_sum[x] += value[node];
    scc[node] = x;
}
int dfs3(int node) {
    int &val = dp[node];
    if (val != -1)
        return val;
    if (pubs2[node]) val = component_sum[node];
    else val = -INF;
    for (int adj : ngraph[node]) {
        int tmp = dfs3(adj);
        if (tmp != -INF) val = max(val, component_sum[node] + tmp);
    }
    return val;
}
int main() {
    int u, v, S, P;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &u, &v);
        graph[u].pb(v);
        rgraph[v].pb(u);
    }
    for (int i = 1; i <= N; i++) {
        scanf("%d", &value[i]);
    }
    visited.reset();
    scanf("%d %d", &S, &P);
    for (int i = 0; i < P; i++) {
        scanf("%d", &u);
        pubs[u] = true;
    }
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) dfs1(i);
    }    
    visited.reset();
    for (int i = topo.size()-1; i >= 0; i--) {
        int n = topo[i];
        if (!visited[n]) {
            dfs2(n);
            x++;
        }
    }
    set <ii> edges;
    for (int i = 1; i <= N; i++) {
        for (int j : graph[i]) {
            u = scc[i], v = scc[j];
            if (u != v && edges.find({u,v}) == edges.end()) {
                edges.insert({u,v});
                ngraph[u].pb(v);
            } 
        }
    }
    
    cout << dfs3(scc[S]) << endl;
}
/*
6 7 
1 2 
2 3 
3 5 
2 4 
4 1 
2 6 
6 5 
10 
12 
8 
16 
1
5
1 4 
4 3 5 6
*/