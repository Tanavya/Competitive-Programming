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

ll dp[150007];
ull pow2[150007];
int main() {

	#ifndef ONLINE_JUDGE
		freopen("inp.txt", "r", stdin);
	#endif 
	ll N, M;
	scanf("%lld %lld", &N, &M);
	pow2[0] = 1;
	for (int i = 1; i <= 150000; i++) {
		pow2[i] = (pow2[i-1] * 2) % M;
	}
	dp[1] = 2;
	dp[2] = 2;
	for (int i = 3; i <= N; i++) {
		
		int n = i;
		for (int j = 1; j * j <= n; j++) {
			if (n % j == 0) {
				dp[i] = (dp[i] + dp[j]) % M;
				if (n/j != j && j != 1) dp[i] = (dp[i] + dp[n/j]) % M;
			}
		}
		dp[i] = (pow2[i] - dp[i] + M) % M; 		
	}
	cout << dp[N] << endl;
}
