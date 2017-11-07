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




ll A[207];
int F[207], T[207];


int dp[207][6007];


int main() {
	#ifndef ONLINE_JUDGE
		freopen("inp.txt", "r", stdin);
	#endif

	int N, K;
	scanf("%d %d", &N, &K);

	for (int i = 0; i < 207; i++) {
		for (int k = 0; k < 6007; k++) {
			dp[i][k] = -INF;
		}
	}
	memset(F, 0, sizeof(F));
	memset(T, 0, sizeof(T));

	int ff = 0, tt = 0;
	for (int i = 0; i < N; i++) {
		scanf("%lld", &A[i]);
		ll n = A[i];
		while (n % 2 == 0) {
			n /= 2;
			T[i]++;
		}
		while (n % 3 == 0) {
			n /= 3;
		}
		while (n % 5 == 0) {
			n /= 5;
			F[i]++;
		}
		ff += F[i];
		tt += T[i];
		//cout << A[i] << " " << F[i] << " " << T[i] << endl;
	}
	int ans = 0;

	assert(ff <= 6000);

	dp[0][0] = 0;
	dp[1][F[0]] = T[0];

	if (K == 1) ans = min(F[0], T[0]);
	for (int i = 1; i < N; i++) {
		for (int k = K; k >= 1; k--) {
			for (int f = ff; f >= 0; f--) {
				if (f-F[i] >= 0) {
					dp[k][f] = max(dp[k][f], dp[k-1][f-F[i]] + T[i]);
				}
				if (k == K) ans = max(ans, min(dp[k][f], f));
			}
		}
	}

	printf("%d\n", ans);
}