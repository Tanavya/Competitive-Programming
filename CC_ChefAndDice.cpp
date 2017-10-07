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


int adj[10][10];

bool disjoint(ii a, ii b) {
	assert(a.x != a.y && b.x != b.y);
	return (a.x != b.x && a.y != b.x && a.y != b.y);
}

void solve() {
	int N;
	scanf("%d", &N);
	vi A;
	memset(adj, 0, sizeof(adj));
	vector <set<int>> graph(7);
	vector <ii> edges;
	for (int i = 0; i < N; i++) {
		int tmp;
		scanf("%d", &tmp);
		A.pb(tmp);
	}
	if (N == 1) {
		cout << "2 1 4 3 6 5" << endl;
		return;
	}
	for (int i = 0; i < N; i++) {
		if (i < N-1) adj[A[i]][A[i+1]] = 1;
		if (i) adj[A[i]][A[i-1]] = 1;
	}
	for (int i = 1; i <= 6; i++) {
		for (int j = 1; j <= 6; j++) {
			if (i != j && !adj[i][j] && !adj[j][i] && graph[i].find(j) == graph[i].end() && graph[j].find(i) == graph[j].end()) {
				graph[i].insert(j);
				graph[j].insert(i);
				edges.pb(mp(i, j));
				//edges.pb(mp(j, i));
			}
			if (i == j && adj[i][j]) {
				cout << -1 << endl;
				return;
			}
		}
	}
	
	//for (ii e : edges) cout << e.x << " "<< e.y << endl;

	for (int i = 0; i < edges.size(); i++) {
		for (int j = i+1; j < edges.size(); j++) {
			for (int k = j+1; k < edges.size(); k++) {
				ii a = edges[i], b = edges[j], c = edges[k];
				if (disjoint(a, b) && disjoint(a, c) && disjoint(b, c)) {
					vi ans(7);
					ans[a.x] = a.y;
					ans[a.y] = a.x;
					ans[b.x] = b.y;
					ans[b.y] = b.x;
					ans[c.x] = c.y;
					ans[c.y] = c.x;
					for (int i = 1; i <= 6; i++)
						cout << ans[i] << " ";
					cout << endl;
					return;
				}
			}
		}
	}
	cout << -1 << endl;
}
int main() {
	#ifndef ONLINE_JUDGE
		freopen("inp.txt", "r", stdin);
	#endif
	int T;
	scanf("%d", &T);
	while (T--) {
		solve();
		//return 0;
	}

}