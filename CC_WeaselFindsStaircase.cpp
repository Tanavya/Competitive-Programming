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
const int INF = int(1e9);
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
using namespace std;
 
const int nmax = 1e5+7, aimax = 1e5+7;
int N, K;
ll hist[nmax];
ll dp[nmax][57];
int main() {

	#ifndef ONLINE_JUDGE
	freopen("inp.txt", "r", stdin);
	#endif
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &N, &K);
		memset(hist, 0, sizeof(hist));
		for (int i = 1; i <= N; i++) {
			scanf("%lld", &hist[i]);
		}		 
		stack <int> s;
		vi right(N+7), left(N+7);

		for (int i = 1; i <= N; i++) {
			while (!s.empty() && hist[i] <= hist[s.top()]) {
			  s.pop();
			}
			if (s.empty()) {
			  left[i] = 0;
			}
			else {
			  left[i] = s.top();
			}
			s.push(i);
		}
		while (!s.empty()) {
			s.pop();
		}
		for (int i = N; i >= 1; i--) {
			while (!s.empty() && hist[s.top()] >= hist[i]) {
			  s.pop();
			}
			if (s.empty()) {
			  right[i] = N+1;
			}
			else {
			  right[i] = s.top();
			}
			s.push(i);
	  	}
	  	
		memset(dp, 0, sizeof(dp));
		ll ans = 0;
		for (int i = 1; i <= N; i++) {
			dp[i][0] = hist[i] * (i - left[i]);
			ans = max(ans, 1LL * hist[i] * (right[i] - left[i] - 1));
			//printf("dp[%d][%d] = %lld, %lld, %lld\n", i, 0, dp[i][0], dp[i][0] + (right[i]-i-1) * hist[i], 1LL * hist[i] * (right[i] - left[i] - 1));
		}
		for (int i = 2; i <= N; i++) {
			for (int j = 1; j < i; j++) {
				for (int k = 0; k <= K; k++) {
					
					int u = i;
					int v = j;
					int w = max(v,left[i]);
					if (right[v] >= i) {
						//cout << dp[v][k-1] << " " << hist[v] << " " << (w-v) << " " << hist[u] << " " << (u-w) << endl;
						if (k) dp[u][k] = max(dp[u][k], dp[v][k-1] + 1LL * hist[v] * (w-v) + 1LL * hist[u] * (u-w));
						//printf("dp[%d][%d] = %lld, %lld\n", i, k, dp[i][k], dp[i][k] + (right[i]-i-1) * hist[i]);
						ans = max(ans, dp[i][k] + (right[i]-i-1) * hist[i]);
					}
				}
			}
		}
		cout << ans << endl;
	}
} 