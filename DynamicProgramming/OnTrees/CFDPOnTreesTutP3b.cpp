//Problem Link: http://codeforces.com/blog/entry/20935?locale=en
//Problem type: Dynamic Programming On Trees
/*
We are given a tree with N nodes and a weight assigned to each node, along with a number K. The aim is to delete enough nodes from 
the tree so that the tree is left with precisely K leaves. The cost of such a deletion is the sum of the weights of the nodes deleted. 
What is the minimum cost to reduce to tree to a tree with K leaves?
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

int N, K, ans = 0;
vector <vi> dp(50007, vi (507, 0)); //dp[v][k] Max total weight of sub tree rooted at v with k nodes
vector <vi> tree(50007);
vi weights(50007);

/*
void rec(int curr_node, int parent) {

    vi dp_prev(507, 0);
    dp_prev[0] = 0;
    for (auto it = tree[curr_node].begin(); it != tree[curr_node].end(); ++it) {
        if (*it != parent) {
            vi dp_this (507, 0);
            rec(*it, curr_node);
            for (int i = 0; i <= K; i++) {
                for (int j = 0; j+i <= K; j++) {
                    dp_this[i+j] = max(dp_this[i+j], dp_prev[i] + dp[*it][j]);
                }
            }
            dp_prev = dp_this;
        }
    }
    for (int i = 0; i <= K; i++) {
        dp[curr_node][i+1] = dp_prev[i] + weights[curr_node];
    }
    ans = max(ans, dp[curr_node][K]);
}
*/
void dfs(int node, int parent) {
    dp[node][1] = weights[node];
    for (int adj : tree[node]) {
        if (adj != parent) {
            dfs(adj, node);
            for (int i = K; i >= 1; i--) {
                for (int j = 0; j+i <= K; j++) {
                    dp[node][i+j] = max(dp[node][i+j], dp[node][i] + dp[adj][j]);
                }
            }
        }
    }
    ans = max(ans, dp[node][K]);
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
    printf("%d\n", ans);
    
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

8 4
1 2
1 5
2 3
2 4
5 6
5 8
5 7
1 1 1 1 4 5 6 3
*/