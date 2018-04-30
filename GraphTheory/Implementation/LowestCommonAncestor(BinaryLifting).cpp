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
int N, depth[maxn], P[maxn][21];
vector <vi> tree(maxn);

void dfs0(int node, int par) {
	depth[node] = depth[par] + 1;
	P[node][0] = par;
	for (int adj : tree[node]) {
		if (adj != par) {
			dfs0(adj, node);
		}
	}
}

int lca(int u, int v) {
	if (depth[u] < depth[v])
		swap(u, v);
	int d = depth[u] - depth[v];
	for (int i = 0; i < 20; i++) {
		if (d & (1 << i)) {
			u = P[u][i];
		}
	}
	if (u == v)
		return u;
	for (int i = 19; i >= 0; i--) {
		if (P[u][i] != P[v][i]) {
			u = P[u][i];
			v = P[v][i];
		}
	}
	assert(P[u][0] == P[v][0]);
	return P[u][0];
}

void preprocess() {
	dfs0(1, 0);
	for (int i = 1; i < 20; i++) {
		for (int u = 1; u <= N; u++) {
			P[u][i] = P[P[u][i-1]][i-1];
		}
	}
}

int getAncestor(int u, int dist) {
	int k = 20;
	int s = 0;
	for (int i = k; i >= 0; i--) {
		if (P[u][i] != -1 && s + (1 << i) <= dist) {
			s += (1 << i);
			u = P[u][i];
		}
	}
	return u;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("inp.txt", "r", stdin);
	#endif

	scanf("%d", &N);
	int u, v;
	for (int i = 0; i < N-1; i++) {
		scanf("%d %d", &u, &v);
		tree[u].pb(v);
		tree[v].pb(u);
	}

	for (int i = 0; i < 21; i++) {
		for (int j = 1; j <= N; j++) {
			P[i][j] = -1;
		}
	}

	preprocess();
	int Q;
	scanf("%d", &Q);
	int dist;
	while (Q--) {
		/*
		scanf("%d %d", &u, &v);
		printf("%d\n", lca(u, v));
		*/
		scanf("%d %d", &u, &dist);
		printf("%d\n", getAncestor(u, dist));
	}
}