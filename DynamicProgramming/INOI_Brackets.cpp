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

int B[707], V[707];
int dp[707][707];
int main() {
	
	#ifndef ONLINE_JUDGE
		freopen("inp.txt", "r", stdin);
	#endif

	int N, K;
	scanf("%d %d", &N, &K);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &V[i]);
	}
	for (int i = 1; i <= N; i++) {
		scanf("%d", &B[i]);
	}
	B[0] = -INF;
	int ans = -INF;
	memset(dp, -INF, sizeof(dp));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j < i; j++) {
			for (int k = j; k <= i; k++) {
				if (B[i] == B[k] + K) {
					dp[i][j] = max(dp[i][j], dp[k-1][j] + V[k] + V[i] + dp[i-1][k+1]);
				}
				dp[i][j] = max(dp[i][j], dp[k-1][j]);
			}
			ans = max(ans, dp[i][j]);
			//printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
		}
	}
	printf("%d\n", ans);
}