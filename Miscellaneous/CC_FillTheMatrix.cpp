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
 
#define pb push_back
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
const int INF = int(1e9);
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
using namespace std;

const int maxn = (1e5)+7;
bitset <maxn> viz;
vector <vi> graph;
vi col;
unordered_map<int,unordered_map<int,int>> assigned;
unordered_map<int,unordered_map<int,int>> mat;

bool solve() {
	int N, Q, a, b, val;
	bool impossible = false;
	assigned.clear();
	mat.clear();
	scanf("%d %d", &N, &Q);
	graph.assign(N+1, {});
	for (int i = 0; i < Q; i++) {
		scanf("%d %d %d", &a, &b, &val);
		
		if (a == b && val) 
			impossible = true;
		
		int x = min(a,b);
		int y = max(a,b);
		
		if (assigned[x][y] == true) { 
			if (mat[x][y] != val) impossible = true;
		}
		else {
			graph[x].pb(y);
			graph[y].pb(x);
		}
		assigned[x][y] = true;
		mat[x][y] = val;
	}
	if (impossible) return false; 
	viz.reset();
	col.assign(N+1, -1);
	for (int i = 1; i <= N; i++) {
		if (!viz[i]) {
			viz[i] = true;
			col[i] = 0;
			queue <int> Q;
			Q.push(i);
			while (!Q.empty()) {
				int curr = Q.front();
				Q.pop();
				assert(col[curr] >= 0);
				for (int adj : graph[curr]) {
					int x = min(adj, curr);
					int y = max(adj, curr);
					if (!viz[adj]) {
						viz[adj] = true;
						if (mat[x][y] == 1) 
							col[adj] = !col[curr];
						else
							col[adj] = col[curr];
						Q.push(adj);
					}
					else {
						if (mat[x][y] == 1 && col[adj] == col[curr]) return false;
						if (mat[x][y] == 0 && col[adj] != col[curr]) return false;
					}
				}
			}
		}
	}
	return true;
}


int main() {
	#ifndef ONLINE_JUDGE
		freopen("inp.txt", "r", stdin);
	#endif
	int T;
	scanf("%d", &T);
	while (T--) {
		if (solve()) printf("yes\n");
		else printf("no\n");
	}
}