//Problem Link: http://codeforces.com/blog/entry/20935?locale=en
//Problem type: Dynamic Programming On Trees
/*
Given a tree T, where each node i has cost Ci. Steve starts at root node, and navigates to one node that he hasn't visited yet at random. 
Steve will stop once there are no unvisited nodes. Such a path takes total time equal to sum of costs of all nodes visited. What node should 
be assigned as root such that expected total time is minimised?
*/

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

int N, K, ans_node;
float ans = INF;
vector <vi> tree(50007);
vi weights(50007);
vector <float> f(50007, 0), g(50007, 0), sums(50007, 0);

void dfs(int node, int parent) {
    int n = 0;
    for (auto it = tree[node].begin(); it != tree[node].end(); ++it) {
        if (*it != parent) {
            n++;
            dfs(*it, node);
            sums[node] += f[*it];
        }
    }

    if (n) f[node] = sums[node]/float(n) + weights[node];
    else f[node] = weights[node];

}
void dfs2(int node, int parent) {
    int n = (int)tree[node].size() - (parent == 0 ? 0 : 1);
    for (auto it = tree[node].begin(); it != tree[node].end(); ++it) {
        if (*it != parent) {
            if (parent == 0) g[*it] = (sums[node] - f[*it] + g[node])/float(n-1 == 0 ? 1: n-1) + weights[node];
            else g[*it] = (sums[node] - f[*it] + g[node])/float(n) + weights[node];
            //printf("g[%d] = %f\n", *it, g[*it]);
            dfs2(*it, node);
        }
    }
    if (parent == 0) {
        ans = min(ans, f[node]);
    }
    else {
        float tmp = weights[node] + (g[node] + sums[node])/float(n+1);
        if (ans > tmp) {
            ans = tmp;
            ans_node = node;
        }
    }
}

int main() {
    scanf("%d %d", &N, &K);
    int a, b;
    for (int i = 0; i < N-1; i++) {
        scanf("%d %d", &a, &b);
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    for (int i = 1; i <= N; i++) {
        scanf("%d", &weights[i]);
    }
    dfs(1, 0);
    dfs2(1, 0);
    cout << "Ans: " << ans << " at node " << ans_node << endl; 
    
}
/*
9 2
1 2
1 3
1 4
2 5
2 6
4 8
8 9
3 7
1 2 3 4 5 6 7 8 9
*/