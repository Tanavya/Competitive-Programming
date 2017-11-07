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

bool cmp(ii a, ii b) {
	return a.second < b.second;
}

const int mod = 1e8;
int main() {
  	
	map <int, int> lol;
	/*
	lol[3] = 100;
	lol[5] = 102;

	auto it = lol.lower_bound(4);
	cout << it->first << " " << it->second << endl;

  	return 0;
  	*/
  	#ifndef ONLINE_JUDGE
	  freopen("inp.txt", "r", stdin);
	#endif

	int N;
	while (true) {
		scanf("%d", &N);
		if (N < 0) break;
		vector <ii> activites(N);
		map <int, int> M;
		for (int i = 0; i < N; i++) {
			scanf("%d %d", &activites[i].x, &activites[i].y);			
		}

		sort(activites.begin(), activites.end(), cmp);

		for (int i = 0; i < N; i++) {
			//if (!M[activites[i].y]) 
			M[activites[i].y] = i+1;
		}

		//for (ii act : activites) debug2(act.x, act.y);debug("");
		//for (auto it : M)debug2(it.first, it.second);debug("");

		vll dp(N, 1), pref(N, 1);
		for (int i = 1; i < N; i++) {
			int e = activites[i].x;
			auto it = M.upper_bound(e);

			if (it == M.begin()) {
				dp[i] = 1; 
				pref[i] = (pref[i-1] + dp[i]) % mod;
			}
			else {
				it = prev(it);
				int last = it->second - 1;
				assert(last >= 0);
				dp[i] = 1 + pref[last];	
				pref[i] = (pref[i-1] + dp[i]) % mod;
			}
		}
		//for (int i = 0; i < N; i++) printf("%lld ", dp[i]); printf("\n");
		//for (int i = 0; i < N; i++) printf("%lld ", pref[i]); printf("\n");
		cout << setfill('0') << setw(8) << pref[N-1] << endl;
	}
}