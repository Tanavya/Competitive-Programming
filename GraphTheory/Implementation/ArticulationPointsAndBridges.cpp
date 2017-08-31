//Tutorial Link : https://www.hackerearth.com/practice/algorithms/graphs/articulation-points-and-bridges/tutorial/

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

vector <vector <int>> graph(100);
int disc[100], low[100], t = 0, rootChildren = 0;
bitset <100> visited;
set <ii> bridges;
set <int> AP;

void dfs(int node, int parent) {
    disc[node] = low[node] = t++;
    visited[node] = true;
    for (int adj : graph[node]) {
        if (visited[adj] == false) {
            if (node == 0) rootChildren++;
            dfs(adj, node);
            if (low[adj] >= disc[node]) AP.insert(node); //adj and its subtree doesn't have a back-edge
            if (low[adj] > disc[node]) bridges.insert(mp(min(adj,node), max(adj,node)));
            //^ because every back edge can end at at current node in an AP, but not in a bridge.
            low[node] = min(low[node], low[adj]);
        }
        else if (adj != parent) {
            low[node] = min(low[node], disc[adj]);
        }
    }
}

int main() {
    int N, M, a, b;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &a, &b);
        graph[a].pb(b);
        graph[b].pb(a);
    }
    dfs(0, -1);
    AP.erase(0);
    if (rootChildren > 1) AP.insert(0);
    printf("%d\n", (int) AP.size()); for (int ap: AP) printf("%d ", ap); printf("\n");
    printf("%d\n", (int) bridges.size()); for (ii bridge: bridges) printf("%d %d\n", bridge.x, bridge.y);
}