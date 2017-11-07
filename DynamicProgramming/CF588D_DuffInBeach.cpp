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
const int mod = 1e9+7;
int main() {
	#ifndef ONLINE_JUDGE
		freopen("inp.txt", "r", stdin);
	#endif
	int n, k;
	ll l;
	scanf("%d %lld %d", &n, &l, &k);
	vi A(n);
	//map <ll, int> M;
	vector <pair <ll, int>> P;
	for (int i = 0; i < n; i++) {
		scanf("%d", &A[i]);
		//M[A[i]] = max(M[A[i]], i);
		P.pb({A[i], i});
	}
	//vi P = A;
	sort(P.begin(), P.end());
	if (l <= n) {
		cout << l << endl;
	}
	else {
		ll dp[k+7][n+7];
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < n; i++) {
			dp[0][i] = 1;
		}

		for (int i = 1; i < k; i++) {
			int ptr = 0;
			ll sum = 0;
			
			while (ptr < n) {
				
				sum += dp[i-1][P[ptr].y];
				sum %= mod;
				int ptr2 = ptr+1;
				while (ptr2 < n && P[ptr2].x == P[ptr2-1].x) {
					sum += dp[i-1][P[ptr2].y];
					sum %= mod;
					ptr2++;
				}
				dp[i][P[ptr].y] = sum;
				ptr++;
				while (ptr < n && P[ptr].x == P[ptr-1].x) {
					dp[i][P[ptr].y] = sum;
					ptr++;
				}
				/*
				sum += dp[i-1][P[ptr].y];
				sum %= mod;
				dp[i][P[ptr].y] = sum;
				ptr++;*/
			}
		}
		ll ans = 0;
		ll c = l/n;
		int rem = l % n;
		for (int i = 0; i < k; i++) {
			for (int j = 0; j < n; j++) {
				
				ll cnt = c-i;
				if (j < rem) 
					cnt++;
				if (cnt >= 0)
					ans += ((dp[i][j] * (cnt % mod))) % mod;
				ans %= mod;
		
			}
		}
		cout << ans << endl;
	}
}