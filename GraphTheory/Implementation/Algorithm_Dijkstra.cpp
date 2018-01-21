//Tutorial Link: https://www.hackerearth.com/practice/algorithms/graphs/shortest-path-algorithms/tutorial/
//Problem type: Graph Theory

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
    
    int n, m, a, b, c, start = 1;
    vector <vector <ii>> graph (10007);
    vector <int> dist (10007, INF);
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        graph[a].push_back(mp(b,c));
        graph[b].push_back(mp(a,c)); //bi-directional graph
    }
    
    priority_queue <ii, vector <ii>, greater<ii>> pq;
    pq.push(mp(0, start));
    dist[start] = 0;
    while (!pq.empty()) {
        ii front = pq.top();
        pq.pop();
        int d = front.first, u = front.second;
        if (dist[u] < d) continue;
        for (auto it = graph[u].begin(); it != graph[u].end(); ++it) {
            int v = (*it).first, weight = (*it).second;
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push(mp(dist[v], v));
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        printf("%d ", dist[i]);
    }
    printf("\n");
}