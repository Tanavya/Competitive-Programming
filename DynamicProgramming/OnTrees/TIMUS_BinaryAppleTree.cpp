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
vector <vi> dp(107, vi (107, 0)); //dp[v][k] Max total weight of sub tree rooted at v with k edges
vector <vector <ii>> tree(50007);

void dfs(int node, int parent) {

    for (ii edge : tree[node]) {
        int adj = edge.x, weight = edge.y;
        if (adj != parent) {
            dfs(adj, node);
            for (int i = K; i >= 0; i--) {
                for (int j = 0; i+j+1 <= K; j++) {
                    dp[node][i+j+1] = max(dp[node][i+j+1], dp[node][i] + weight + dp[adj][j]);
                    //printf("dp[%d][%d] = %d\n", node, i+j+1, dp[node][i+j+1]);
                }
            }
        }
    }
}
int main() {

    scanf("%d %d", &N, &K);
    int a, b, c;
    for (int i = 0; i < N-1; i++) {
        scanf("%d %d %d", &a, &b, &c);
        tree[a].pb(mp(b, c));
        tree[b].pb(mp(a, c));
    }
    dfs(1, 0);
    printf("%d\n", dp[1][K]);
    
}