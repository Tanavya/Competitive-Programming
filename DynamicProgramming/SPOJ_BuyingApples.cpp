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

int dp[107][107]; //dp[n][k] -> minimum sum buying n packets of k kilograms
int main() {

	#ifndef ONLINE_JUDGE
		freopen("inp.txt", "r", stdin);
	#endif

	int T, N, K;
	scanf("%d", &T);

	while (T--) {
		
		scanf("%d %d", &N, &K);
		vi cost(K+7);
		for (int i = 1; i <= K; i++) {
			scanf("%d", &cost[i]);
		}
		int ans = INF;

		for (int i = 0; i <= N; i++) {
			for (int j = 0; j <= K; j++) {
				dp[i][j] = INF;
			}
		}
		dp[0][0] = 0;

		for (int n = 1; n <= N; n++) {
			for (int k = 1; k <= K; k++) {
				dp[n][k] = INF;
				for (int w = 1; w <= K; w++) {
					if (cost[w] != -1 && k >= w) {
						dp[n][k] = min(dp[n][k], dp[n-1][k-w] + cost[w]);
					}
				}
				if (k == K) {
					ans = min(ans, dp[n][k]);
				}
			}
		}
		if (ans == INF) printf("%d\n", -1);
		else printf("%d\n", ans);
	}
}