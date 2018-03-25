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

int N, M;
vector <vi> tree(maxn);
vector <vector <ii>> tickets(maxn);
vll dp(maxn, INF64);
//vll path;

int len = 1;
ll path[maxn];
int A[maxn];
ll stree[maxn*4];

inline int left(int x) { return (x << 1); }
inline int right(int x) { return (x << 1) + 1; }


void update(int p, int L, int R, int idx, ll val) {
	if (L == R) {
		path[idx] = val;
		stree[p] = val;
	}
	else  {
		int mid = (L+R)/2;
		if (mid >= idx)
			update(left(p), L, mid, idx, val);
		else
			update(right(p), mid+1, R, idx, val);
		stree[p] = min(stree[left(p)], stree[right(p)]);
	}
}

ll query(int p, int L, int R, int li, int ri) {
	if (ri < L || li > R) {
		return INF64;
	}
	else if (li <= L && ri >= R) {
		return stree[p];
	}
	else {
		int mid = (L+R)/2;
		return min(query(left(p), L, mid, li, ri), query(right(p), mid+1, R, li, ri));
	}
}

ll find_min(int k) {
	/*
	//replace with rmq
	int n = len;
	ll best = INF64;
	for (int i = n-1; i >= n-k && i >= 0; i--) {
		best = min(best, path[i]);
	}
	return best;*/
	return query(1, 1, N, max(len-k, 0), len-1);
}


void dfs(int node, int par) {

	for (ii ticket : tickets[node]) {
		dp[node] = min(dp[node], find_min(ticket.x) + ticket.y);
	}
	update(1, 1, N, len, dp[node]);
	//path[len] = dp[node];
	len++;
	for (int adj : tree[node]) {
		if (adj != par) { 
			dfs(adj, node);
		}
	}
	len--;
	//path[len] = INF64;
	update(1, 1, N, len, INF64);
	
}

int main() {

	#ifndef ONLINE_JUDGE
		freopen("inp.txt", "r", stdin);
	#endif
	path[0] = INF64;
	int u, v, k, w;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N-1; i++) {
		scanf("%d %d", &u, &v);
		tree[u].pb(v);
		tree[v].pb(u);
	}
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &v, &k, &w);
		tickets[v].pb({k,w});
	}
	int Q, n;
	scanf("%d", &Q);
	dp[1] = 0;
	dfs(1, 0);
	while (Q--) {
		scanf("%d", &n);
		printf("%lld\n", dp[n]);
	}
}