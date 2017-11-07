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

ll dp[200007][2]; //0 -> green, 1 -> red
const int mod = 1e9+7;
int main() {
	#ifndef ONLINE_JUDGE
		freopen("inp.txt", "r", stdin);
	#endif
	memset(dp, 0, sizeof(dp));
	int R, G;
	scanf("%d %d", &R, &G);
	int h = 1;
	while (h * (h+1) / 2 <= R+G) {
		h++;
	}
	h--;
	//dp[0][0][0] = dp[0][0][1] = 1;
	ll ans = 0;
	dp[0][0] = dp[1][1] = 1;

	for (int n = 1; n <= h; n++) {
		for (int r = R; r >= 0; r--) {
			int g = n*(n+1)/2 - r;
			if (g < 0) continue;
			//cout << "red used: " << r << ", green used: " << g << endl;
			if (g - n >= 0 && g <= G) {
				dp[r][0] = (dp[r][0] + dp[r][1]) % mod;
			}
			else {
				dp[r][0] = 0;
			} 
			if (r - n >= 0) {
				dp[r][1] = (dp[r-n][0] + dp[r-n][1]) % mod;
			}
			else {
				dp[r][1] = 0;
			}
			//if ((r == R || g == G) && n == h) {
			//	ans += dp[r][0] + dp[r][1];
			//}
			if (n == h) {
				ans += dp[r][0] + dp[r][1];
				ans %= mod;
			}
			//printf("dp[%d][%d][g] = %lld\n", n, r, dp[r][0]);
			//printf("dp[%d][%d][r] = %lld\n", n, r, dp[r][1]);
		}
	}
	cout << ans << endl;
}
