#include <iostream>
#include <vector>

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


int main() {
	#ifndef ONLINE_JUDGE 
		freopen("inp.txt", "r", stdin);
	#endif
	int K;
	while (true) {
		scanf("%d", &K);
		if (!K) break;
		int N, M;
		string A, B;
		cin >> A >> B;
		N = A.size();
		M = B.size();

		vector <vector <vi> > dp, dp0;
		dp.assign(N, vector <vi> (M, vi (K+7, 0)));
		dp0.assign(N, vector <vi> (M, vi (K+7, 0)));
		//dp[i][j][k] -> LCS ending at A[i] and B[j] and having last segment size >= k, and previous segments >= K
		//dp0[i][j][k] -> LCSegment ending at A[i] and B[j] and having last segment size >= k, and no previous segments

		int ans = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {

				if (A[i] == B[j] && i && j && dp0[i-1][j-1][K-1]) {
					dp[i][j][K] = dp0[i-1][j-1][K-1] + 1;
					dp[i][j][0] = dp0[i-1][j-1][K-1] + 1;
				}
				if (j) 
					dp[i][j][0] = max(dp[i][j][0], dp[i][j-1][0]);
				if (i)
					dp[i][j][0] = max(dp[i][j][0], dp[i-1][j][0]);

				for (int k = K; k >= 0; k--) {

					dp0[i][j][k] = dp0[i][j][k+1];
					if (A[i] == B[j]) {
						if (i && j && k) {
							if (k < K) 
								dp0[i][j][k] = max(dp0[i][j][k], dp0[i-1][j-1][k-1] + 1); 
							else 
								dp0[i][j][k] = max(dp0[i][j][k], dp0[i-1][j-1][K] + 1); 
						}
						else if (k == 1)
							dp0[i][j][k] = 1;
					}

					dp[i][j][k] = max(dp[i][j][k], dp[i][j][k+1]);
					if (A[i] == B[j]) {
						if (i && j && k) {
							if (k < K)
								dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-1][k-1] + 1);
							else
								dp[i][j][k] = max(max(dp[i][j][k], dp[i-1][j-1][K] + 1), dp[i-1][j-1][0] + 1);
						}
						else if (!k && i && j && dp[i-1][j][k]) {
							dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-1][0] + 1);
						}
					}
					if (dp[i][j][k] < K) dp[i][j][k] = 0;
					ans = max(ans, dp[i][j][k]);

				}

			}
		}
		//cout << ans << endl;
		/*
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (A[i] == B[j] && i && j && dp0[i-1][j-1][K-1]) {
					dp[i][j][K] = dp0[i-1][j-1][K-1] + 1;
					dp[i][j][0] = dp0[i-1][j-1][K-1] + 1;
				}
				if (j) 
					dp[i][j][0] = max(dp[i][j][0], dp[i][j-1][0]);
				if (i)
					dp[i][j][0] = max(dp[i][j][0], dp[i-1][j][0]);
				//if (i == 4 && j == 1)
				for (int k = K; k >= 0; k--) {
					dp[i][j][k] = max(dp[i][j][k], dp[i][j][k+1]);
					if (A[i] == B[j]) {
						if (i && j && k) {
							if (k < K)
								dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-1][k-1] + 1);
							else
								dp[i][j][k] = max(max(dp[i][j][k], dp[i-1][j-1][K] + 1), dp[i-1][j-1][0] + 1);
						}
						else if (!k && i && j && dp[i-1][j][k]) {
							dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-1][0] + 1);
						}
					}
					if (dp[i][j][k] < K) dp[i][j][k] = 0;
					ans = max(ans, dp[i][j][k]);
					//printf("dp[%d][%d][%d] = %d\n", i, j, k, dp[i][j][k]);
				}
			}
		}
		*/
		//cout << dp[8][2][1] << endl;
		//cout << dp0[4][1][1] << endl;
		printf("%d\n", ans);
	}
}