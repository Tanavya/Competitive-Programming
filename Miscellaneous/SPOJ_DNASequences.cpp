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

string A, B;
int K;

const int maxn = 1e3+7;
int dp[maxn][maxn][107]; int dp0[maxn][maxn][107];
int solve_mine() {

	int N, M;
	N = A.size();
	M = B.size();

	//vector <vector <vi> > dp, dp0;
	//dp.assign(N, vector <vi> (M, vi (K+7, 0)));
	//dp0.assign(N, vector <vi> (M, vi (K+7, 0)));
	//memset(dp,0,sizeof(dp));
	//dp[i][j][k] -> LCS ending at A[i] and B[j] and having last segment size >= k, and previous segments >= K
	//dp0[i][j][k] -> LCSegment ending at A[i] and B[j] and having last segment size >= k, and no previous segments
	
	int ans = 0;
	/*
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				for (int k = 0; k < K; k++) {
					ans++;
				}
			}
		}
		return ans;
	*/


	//int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			
			dp[i][j][0] = 0;
			if (j) 
				dp[i][j][0] = dp[i][j-1][0];
			if (i)
				dp[i][j][0] = MAX(dp[i][j][0], dp[i-1][j][0]);
			
			for (int k = K; k >= 1; k--) {

				dp[i][j][k] = dp0[i][j][k] = 0;

				if (A[i] == B[j]) {

					dp[i][j][k] = dp0[i][j][k] = 1;

					if (i && j) {

						dp0[i][j][k] = MAX(dp0[i][j][k], dp0[i-1][j-1][k-1] + 1); 
						dp[i][j][k] = MAX(dp[i][j][k], dp[i-1][j-1][k-1] + 1);

						if (k == K) {

							dp0[i][j][k] = MAX(dp0[i][j][k], dp0[i-1][j-1][K] + 1); 
							dp[i][j][k] = MAX(MAX(dp[i][j][k], dp[i-1][j-1][K] + 1), dp0[i-1][j-1][K-1] + 1);
						
						}
					}
				}
				if (dp[i][j][k] < K) dp[i][j][k] = 0;
				//printf("dp[%d][%d][%d] = %d\n", i, j, k, dp[i][j][k]);
			}
			ans = MAX(ans, dp[i][j][K]);
			dp[i][j][0] = max(dp[i][j][0], dp[i][j][K]);
		}
	}
	return ans;
	//O(N^2 K) gives TLE for some rlly fucking absurd reason, but O(N^3) doesnt!!! 
}

int AC() {

	int k = K, dp[1005][1005], i, j, xlen, ylen, c;
	string x = A, y = B;

	xlen = x.size();
	ylen = y.size();

	for(i=0; i<=xlen; i++){
		for(j=0; j<=ylen; j++){
			dp[i][j] = 0;
			if(i==0 || j==0)
				continue;

			c = 1;
			while(i-c>=0 && j-c>=0 && x[i-c]==y[j-c]){
				if(c>=k)
					dp[i][j] = MAX(dp[i][j], c+dp[i-c][j-c]);
				c++;
			}
			dp[i][j] = MAX(dp[i][j], dp[i-1][j]);
			dp[i][j] = MAX(dp[i][j], dp[i][j-1]);
		}
	}
	return dp[xlen][ylen];
}


void gen_tcs() {
	srand(time(NULL));
	for (int t = 0; t < 1; t++) {
		//int K = (rand() % 100) + 1;
		int K = (rand() % 4) + 1;
		cout << K << endl;
		int N = (rand() % 950) + 50, M = (rand() % 950) + 50;
		//int N = 10, M = 10;
		string A = "";
		for (int i = 0; i < N; i++) {
			char ch = char((rand() % 10) + 97);
			assert(ch != '\n');
			A += ch;
		}
		cout << A << endl;
		string B = "";
		for (int i = 0; i < M; i++) {
			char ch = char((rand() % 10) + 97);
			assert(ch != '\n');
			B += ch;
		}
		cout << B << endl;
	}
	cout << 0 << endl;
}

int main() {
	#ifndef ONLINE_JUDGE 
		freopen("inp.txt", "r", stdin); 
		//freopen("inp.txt", "w", stdout); gen_tcs(); return 0;
	#endif
	
	while (scanf("%d", &K) != EOF) {
		if (!K) break;
		cin >> A >> B;

		//cout << K << endl << A << endl << B << endl;
		/*
		int x = solve_mine(), y = AC();
		cout << x << " " << y << endl;

		assert(x==y);
		*/
		/*
		int ans = 0;
		for (int i = 0; i < A.size(); i++) {
			for (int j = 0; j < B.size(); j++) {
				for (int k = 0; k < K; k++) {
					ans++;
				}
			}
		}
		cout << ans << endl;
		*/
		cout << solve_mine() << endl;
	}
}