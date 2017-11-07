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

const int maxn = 1e5+7;

int dpDown[maxn], dpUp[maxn];
vector <vi> tree(maxn), distances(maxn);
vector <bool> affected(maxn, 0);
vi closest(maxn, 0), farthest(maxn);

int N, M, D, root = 0;

void dfs(int node, int par) {
	//debug2(node, par);
	if (affected[node]) {
		dpDown[node] = 0;
		farthest[node] = node;
	}
	else {
		dpDown[node] = -INF;
		farthest[node] = 0;
	}
	for (int adj : tree[node]) {
		if (adj != par) {
			dfs(adj, node);
			if (dpDown[adj] + 1 > dpDown[node] && farthest[adj]) {
				dpDown[node] = dpDown[adj] + 1;
				farthest[node] = farthest[adj];
			}
			distances[node].pb(dpDown[adj]);
		}
	}
	sort(distances[node].rbegin(), distances[node].rend());
}
void dfs2(int node, int par) {

	if (node == root) 
		dpUp[node] = 0;
	else 
		dpUp[node] = max(dpUp[node], dpUp[par] + 1);

	for (int adj : tree[node]) {
		if (adj != par) {
			if (distances[node].size() > 1) {
				if (dpDown[adj] == distances[node][0]) {
					dpUp[adj] = max(dpUp[adj], distances[node][1] + 2);
				}
				else {
					dpUp[adj] = max(dpUp[adj], distances[node][0] + 2);
				}
			}
			dfs2(adj, node);
		}
	}
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("inp.txt", "r", stdin);
	#endif
	scanf("%d %d %d", &N, &M, &D);
	int u, v;
	for (int i = 0; i < M; i++) {
		scanf("%d", &u);
		affected[u] = 1;
		if (!root)
			root = u;
	}
	for (int i = 0; i < N-1; i++) {
		scanf("%d %d", &u, &v);
		tree[u].pb(v);
		tree[v].pb(u);
	}

	dfs(root, 0);
	dfs2(root, 0);

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		//cout << i << ": "; debug2(dpDown[i], dpUp[i]);
		if (dpDown[i] <= D && dpUp[i] <= D) ans++;
	}
	cout << ans << endl;

}