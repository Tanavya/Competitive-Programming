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

const int maxn = 1e5+7;
int N;
vector <vector <ii>> tree(maxn);
ll max_dist = -1;
void dfs(int node, int parent, ll dist) {
    //if (tree[node].size() == 1) 
        max_dist = max(max_dist, dist);
    
    for (ii edge : tree[node]) {
        int adj = edge.x, w = edge.y;
        if (adj != parent) 
            dfs(adj, node, w + dist);
    }
}

int main() {
    int u, v, w;
    scanf("%d", &N);
    ll total = 0;
    for (int i = 0; i < N-1; i++) {
        scanf("%d %d %d", &u, &v, &w);
        tree[u].pb({v, w});
        tree[v].pb({u, w});
        total += 2*w;
    }
    dfs(1, 0, 0);
    cout << total - max_dist << endl;
    
}