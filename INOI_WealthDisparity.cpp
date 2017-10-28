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
 
const int maxn = 1e5+7;
vector <vi> tree(maxn);
int N, A[maxn];

vi dp(maxn, -INF);

void dfs(int node, int par) {
	dp[node] = A[node];
	for (int adj : tree[node]) {
		if (adj != par) {
			dfs(adj, node);
			dp[node] = min(dp[node], dp[adj]);
		}
	}
}


int main() {
	#ifndef ONLINE_JUDGE
		freopen("inp.txt", "r", stdin);
	#endif 

	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
	}
	int j;
	int start = 0;
	for (int i = 1; i <= N; i++) {
		scanf("%d", &j);
		if (j == -1) {
			start = i;
		}
		else {
			tree[i].pb(j);
			tree[j].pb(i);
		}
	}
	dfs(start, 0);
	int ans = -INF;
	for (int i = 1; i <= N; i++) {
		ans = max(ans, A[i] - dp[i]);
	}
	printf("%d\n", ans);
}