//Tutorial Link: https://www.hackerearth.com/practice/algorithms/graphs/shortest-path-algorithms/tutorial/

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
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << endl;
 
typedef long long int ll;
typedef long double ld;
typedef std::pair <int, int> ii;
typedef std::vector <int> vi;
typedef std::vector <ll> vll;
const int INF = int(1e9);
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
using namespace std;

int main() {
    int N, M, w, a, b;
    scanf("%d %d", &N, &M);
    vector <vector<ii>> graph(N+7);
    vi dist(N+7, INF);
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &a, &b, &w);
        graph[a].pb(mp(w,b));
        //graph[b].pb(mp(w,a));
    }
    dist[1] = 0;
    for (int i = 0; i < N-1; i++) {
        for (int u = 1; u <= N; u++) {
            for (ii edge : graph[u]) {
                int v = edge.y, w = edge.x;
                dist[v] = min(dist[u] + w, dist[v]);
            }
        }
    }
    //Printing distance from 1 to all other nodes
    for (int dest = 2; dest <= N; dest++) printf("%d ", dist[dest]); printf("\n");

    //Checking For Negative Weight Cycles
    for (int u = 1; u <= N; u++) {
        for (ii edge : graph[u]) {
            int w = edge.x, v = edge.y;
            if (dist[u] + w < dist[v]) {
                printf("Graph contains a negative-weight cycle.. !\n");
                return 0;
            }
        }
    }
    printf("Graph doesn't a contain negative-weight cycle.\n");
}
/*
6 6
1 2 -1
2 4 -2
4 3 5
3 1 1
1 5 5
5 6 7
*/