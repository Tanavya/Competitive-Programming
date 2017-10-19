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

vector <vi> tree(2507);
int dp[2507][100];
int N, K;
const int mod = 10243;
void dfs(int node, int par) {
	dp[node][0] = 1; //?
	dp[node][1] = 1;
	for (int adj : tree[node]) {
		if (adj != par) {
			dfs(adj, node);
			for (int i = K; i >= 1; i--) {
				for (int j = 1; j < i; j++) {
					dp[node][i] = ((dp[node][i] % mod) + ((dp[node][i-j] * dp[adj][j]) % mod)) % mod;
				}
			}
		}
	}
}
// K = 3
//        1
//       /
//      2
//     / \
//    5   3
//   / \
//  4   6
int main() {

	#ifndef ONLINE_JUDGE
		freopen("inp.txt", "r", stdin);
	#endif

	scanf("%d %d", &N, &K);
	int u, v;
	for (int i = 0; i < N-1; i++) {
		scanf("%d %d", &u, &v);
		tree[u].pb(v);
		tree[v].pb(u);
	}
	dfs(1, 0);
	int ans = 0;
	for (int n = 1; n <= N; n++) {
		ans = (ans + dp[n][K]) % mod;
	}
	cout << ans << endl;
}