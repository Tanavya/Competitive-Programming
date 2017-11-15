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
#define x first
#define y second
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << endl;
#define debug(x) cout << x << endl;
#define debug2(x,y) cout << x << " " << y << endl;
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


const int maxn = (int)1e5;
vector <vector <int>> graph(maxn);
bool visited[maxn];
int component_size = 0, dist[maxn];

void dfs(int node) {
    component_size++;
    for (int adj : graph[node]) {
        if (!visited[adj]) {
            visited[adj] = true;
            dfs(adj);
        }
    }
}

int main() {

    int N, M;
    //N nodes
    //M edges

    scanf("%d %d", &N, &M);
    int u, v;
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    //Finding size of each connected component
    for (int node = 1; node <= N; node++) {
        if (!visited[node]) {
            visited[node] = true;
            component_size = 0;
            dfs(node);
            printf("Size of connected component of %d: %d\n", node, component_size);
        }
    }
    queue <pair <int, int>> Q; //(node, prev)

    int start = 1;
    Q.push({start, 0});
    vector <int> prev (maxn, 0);

    for (int i = 1; i <= N; i++)
        visited[i] = false;

    visited[start] = true;

    int target = 5, path_length = -1;
    while (!Q.empty()) {
        pair <int, int> curr = Q.front();
        Q.pop();
        int node = curr.first;
        int pre = curr.second;
        prev[node] = pre;
        dist[node] = dist[pre] + 1;
        if (node == target) {
            path_length = dist[node];
            break;
        }
        for (int adj : graph[node]) {
            if (!visited[adj]) {
                visited[adj] = true;
                Q.push({adj, node});
            }
        }
    }
    if (path_length != -1) {
        printf ("Path length: %d\n", path_length);

        int curr = target;
        vector <int> path = {curr};
        while (prev[curr] != 0) {
            curr = prev[curr];
            path.push_back(curr);
        }
        //vector <int> can basically act like a stack lol
        printf("Path: ");
        while (!path.empty()) {
            printf("%d ", path.back());
            path.pop_back();
        }
        printf("\n");
    }
    else {
        printf("No path from %d to %d\n", start, target);
    }
}