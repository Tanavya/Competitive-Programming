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

const int maxn = 1e6+7;


int main() {
	#ifndef ONLINE_JUDGE 
		freopen("inp.txt", "r", stdin);
	#endif
	int T;
	scanf("%d", &T);
	while (T--) {
		int N, M;
		scanf("%d", &N);
		vector <vll> dishes(N);
		vector <vll> left(N), right(N);
		vector <vll> A(N);
		vector <int> sizes;
		for (int i = 0; i < N; i++) {
			scanf("%d", &M);
			dishes[i].resize(M);
			sizes.pb(M);
			for (int j = 0; j < M; j++) {
				scanf("%lld", &dishes[i][j]);
			}
			if (M == 1) {
				sizes[i]++;
				M++;
				dishes[i].pb(dishes[i][0]);
			}
			for (int j = 0; j < M; j++) {
				left[i].pb(dishes[i][j] * i);
				right[i].pb(dishes[i][(j-1+M)%M] * (i+1));
			}
			if (i == 0) {
				ll best1 = LLONG_MIN, best2 = LLONG_MIN;
				for (int j = 0; j < M; j++) {
					best1 = max(best1, right[i][j]);
					best2 = max(best2, -right[i][j]);
				}
				A[i] = {best1, best2};
			} 
			else if (i == N-1) {

				ll best1 = LLONG_MIN, best2 = LLONG_MIN;
				for (int j = 0; j < M; j++) {
					best1 = max(best1, left[i][j]);
					best2 = max(best2, -left[i][j]);
				}
				A[i] = {best1, best2};
			}
			else {
				
				ll best1 = LLONG_MIN, best2 = LLONG_MIN, best3 = LLONG_MIN, best4 = LLONG_MIN;
				for (int j = 0; j < M; j++) {
					best1 = max(best1, +left[i][j] + right[i][j]);
					best2 = max(best2, +left[i][j] - right[i][j]);
					best3 = max(best3, -left[i][j] + right[i][j]);
					best4 = max(best4, -left[i][j] - right[i][j]);
				}
				A[i] = {best1, best2, best3, best4};
			}
		}
		if (N == 1) {
			cout << 0 << endl;
		}
		else {
			ll dp[N][4];
			memset(dp, -INF, sizeof(dp));
			for (int i = 0; i < N; i++) {
				if (!i) {
					dp[i][0] = A[i][0];
					dp[i][1] = A[i][1];
					dp[i][2] = dp[i][0];
					dp[i][3] = dp[i][1];
				}
				else if (i == N-1) {
					dp[i][0] = max(dp[i-1][1], dp[i-1][3]) + A[i][0];
					dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + A[i][1];
				}
				else {
					dp[i][0] = max(dp[i-1][1], dp[i-1][3]) + A[i][0];
					dp[i][1] = max(dp[i-1][1], dp[i-1][3]) + A[i][1];
					dp[i][2] = max(dp[i-1][0], dp[i-1][2]) + A[i][2];
					dp[i][3] = max(dp[i-1][0], dp[i-1][2]) + A[i][3];
				}
			}
			cout << max(dp[N-1][0], dp[N-1][1]) << endl;
		}
	}
}