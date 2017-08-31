//Problem Link : https://www.codechef.com/problems/KINGCON
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

vi low, disc;
vector <vi> graph;
bitset <3001> visited, AP;
int t, rootChildren;

inline void reset(int N) {
    visited.reset(); AP.reset();
    graph.clear(); graph.resize(N);
    low = disc = vi (N, 0);
    t = rootChildren = 0;
}

void dfs(int node, int parent) {
    low[node] = disc[node] = t++;
    visited[node] = 1;
    for (int adj : graph[node]) {
        if (!visited[adj]) {
            if (node == 0) rootChildren++;
            dfs(adj, node);
            if (low[adj] >= disc[node]) AP[node] = 1;
            low[node] = min(low[node], low[adj]);
        }
        else if (adj != parent) {
            low[node] = min(low[node], disc[adj]);
        }
    }
}

int main() {
    int T, N, M, K, a, b;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &N, &M, &K);
        reset(N+1);
        for (int i = 0; i < M; i++) {
            scanf("%d %d", &a, &b);
            graph[a].pb(b);
            graph[b].pb(a);
        }
        dfs(0, -1);
        AP[0] = (rootChildren > 1);
        int cunt = 0;
        for (int i = 0; i <= N; i++) if (AP[i]) cunt++;
        printf("%d\n", cunt * K);
    }
}