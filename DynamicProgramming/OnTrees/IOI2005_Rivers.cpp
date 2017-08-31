//Used Malvika's github repository : https://github.com/keshav57/ioi-training/blob/master/IOI/2005/rivers.cpp
//Important observation : Each node's cost is always being controlled by the nearest mill above it.
//Hence, at each node you can either place a mill at it, allowing only k-1 mills in subtree below it, resetting distance
//from nearest mill to 0, and changing the controlling node to the current node..
//Or, you can ignore current node, and recurse to its first child, keeping all other parameters the same.
//In each case, you're moving to one level below, and here, you have to find most efficient way to partition the allowed k mills.

//Malvika's trick which helped her easily do this was to precompute all siblings at a certain level. So, sib[node] points to the left
//sibling of the current node. first_child[node] points to the first child, or the right most child of the current node.
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <stdio.h>
#include <queue>
#include <set>
#include <list>
#include <cstring>
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

int f(int, int, int, int);
int g(int, int, int, int);

int N, K;
const int nmax = 107, kmax = 57;
vector <vector <ii>> tree (nmax);
int T[nmax], first_child[nmax], par_dist[nmax], sib[nmax];
int dp1[nmax][kmax][nmax];
int dp2[nmax][kmax][nmax]; 

int g(int node, int k, int dist, int controller) {
    if (k < 0) return INF;
    if (node < 0) return 0;
    int &val = dp2[node][k][controller];
    if (val != -1)
        return val;
    if (sib[node] == -1) {
        val = f(node, k, dist, controller);
        return val;
    }
    val = INF;
    for (int i = 0; i <= k; i++) {
        val = min(val, g(sib[node], k-i, dist, controller) + f(node, i, dist, controller));
    }
    // ^ checks for best way to paritition remaining mills amongst all siblings at same level.
    return val;
}

int f(int node, int k, int dist, int controller) { // controller is node with the nearest mill.
    int &val = dp1[node][k][controller];
    if (val != -1)
        return val;
    dist += par_dist[node];
    if (k) val = min( g(first_child[node], k, dist, controller) + T[node] * dist, g(first_child[node], k-1, 0, node));
    else val = g(first_child[node], k, dist, controller) + T[node] * dist;
    return val;
} 


void dfs(int node) {
    int p = -1, adj;
    for (ii edge : tree[node]) {
        adj = edge.x;
        sib[adj] = p;
        p = adj;
        dfs(adj);
    }
    first_child[node] = p;
}

int main() {

    memset(dp1,-1,sizeof(dp1));
	memset(dp2,-1,sizeof(dp2));

    int node, weight;
    scanf("%d %d", &N, &K);
    for (int i = 1; i <= N; i++) {
        scanf("%d %d %d", &T[i], &node, &weight);
        tree[node].pb({i, weight});
        par_dist[i] = weight;
    }
    dfs(0);
    cout << f(0, K, 0, 0) << endl;
}

/*
4 2
1 0 1
1 1 10
10 2 5
1 2 3
*/