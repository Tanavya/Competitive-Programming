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


ll dp[107][107][107];
const int mod = 1e9+7;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}
vector <vi> coprime(107);

int main() {
	#ifndef ONLINE_JUDGE
		freopen("inp.txt", "r", stdin);
	#endif
	int N, K, X;
	scanf("%d %d %d", &N, &X, &K);

	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			if (gcd(i, j) == 1) {
				coprime[i].pb(j);
			}
		}
	}
	ll ans = 0;
	for (int n = 0; n < N; n++) {
		for (int k = 0; k <= K; k++) {
			for (int i = 1; i <= 100; i++) {
				if (n == 0) {
					if (!k && i != X) dp[n][k][i] = 1;
					else if (k == 1 && i == X) dp[n][k][i] = 1;
				}
				else {
					for (int j : coprime[i]) {
						if (i == X) {
							if (k) {
								dp[n][k][i] += dp[n-1][k-1][j];
								dp[n][k][i] %= mod;
							}
						}
						else {
							dp[n][k][i] += dp[n-1][k][j];
							dp[n][k][i] %= mod;
						}
					}
				}
				if (n == N-1 && k == K) {

					ans += dp[n][k][i];
					ans %= mod;
				}
			}
		}
	}
	printf("%lld\n", ans);
}