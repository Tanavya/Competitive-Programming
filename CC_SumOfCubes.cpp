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
const int INF = int(1e9);
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
using namespace std;
int N, K;
unordered_map <int, unordered_map<int,int >> graph;
vector <vi> graph2;
const int mod = 1e9+7;
vi sub;
ll rec(int i) {
	ll ret = 0;
	if (i > N) return 0;
	if (i == N) {
		for (int k = 0; k < sub.size(); k++) {
			for (int j = k+1; j < sub.size(); j++) {
				ret += graph[sub[k]][sub[j]];
			}
		}
		return pow(ret, K);
	}
	else {
		sub.pb(i+1);
		ret += rec(i+1);
		ret %= mod;
		sub.pop_back();
		ret += rec(i+1);
		ret %= mod;
		return ret;
	}
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("inp.txt", "r", stdin);
	#endif
	int T, M;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d %d", &N, &M, &K);
		graph.clear();
		graph2.assign(N+7, {});
		int u, v;
		for (int i = 0; i < M; i++) {
			scanf("%d %d", &u, &v);
			graph[u][v] = 1;
			graph[v][u] = 1;
			graph2[u].pb(v);
			graph2[v].pb(u);
		}
		if (K == 1) {
			ll ans = 1;
			for (int i = 1; i <= N-2; i++) {
				ans *= 2;
				ans %= mod;
			}
			ans *= M;
			ans %= mod;
			cout << ans << endl;
		}
		else {
			cout << rec(0) << endl;
		}
	}
}