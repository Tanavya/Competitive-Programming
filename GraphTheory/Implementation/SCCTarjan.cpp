//Tutorial Link : http://www.geeksforgeeks.org/tarjan-algorithm-find-strongly-connected-components/
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

vi low, disc, S;
vector <vi> graph;
bitset <20> visited, recursiveStack;
int t = 0, cnt = 0;

void tarzan(int node) {
    low[node] = disc[node] = t++;
    recursiveStack[node] = visited[node] = 1;
    S.pb(node);
    for (int adj : graph[node]) {
        if (!visited[adj])
            tarzan(adj);
        if (recursiveStack[adj]) //part of current SCC
            low[node] = min(low[node], low[adj]);
    }
    if (low[node] == disc[node]) {
        printf("SCC: %d\n", ++cnt);
        while (true) {
            int v = S.back(); S.pop_back(); 
            recursiveStack[v] = 0;
            printf("%d ", v);
            if (v == node) break;
        }
        printf("\n");
    }
}

int main() {
    int N, M, a, b;
    scanf("%d %d", &N, &M);
    low = disc = vi (N+1, 0);
    graph.resize(N+1);
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &a, &b);
        graph[a].pb(b);
    }
    for (int i = 1; i <= N; i++)
        if (!visited[i])
            tarzan(i);
}
/*
7 9
0 1
1 3
3 2
2 1
3 4
4 5
5 7
7 6
6 4
*/