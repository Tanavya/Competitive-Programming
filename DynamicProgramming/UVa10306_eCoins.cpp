//Problem Link: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3836
//Problem type: Dynamic Programming
//Learning Exp: 

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <stdio.h>
#include <queue>
#include <set>
#include <cmath>
#include <assert.h>
#include <bitset>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip> //cout << setprecision(n) << fixed << num

#define mp make_pair
#define ii pair<int, int>
#define PI 3.14159265
#define INF 1000000000000000000LL
#define EPS 1e-6
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << "\n";
typedef long long int ll;\
using namespace std;  

int traditional_values[41], it_values[41], dp[1000][1000];
int T, N, S;
int rec(int x, int y) {
	if (dp[x][y] != -1) return dp[x][y];
	int ret = 100000000;
	float s = sqrt(x * x + y * y);
	if (abs(s-S) <= EPS) ret = 0;
	else if (s +EPS > S) return 100000000;
	else {
		for (int n = 0; n < N; n++) {
			ret = min(ret, 1 + rec(x + traditional_values[n], y + it_values[n]));
		}
	}
	dp[x][y] = ret;
	return ret;
}
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &N, &S);
		for (int i = 0; i < N; i++) {
			scanf("%d %d", &traditional_values[i], &it_values[i]);
		}
		/*
		for (int j = 0; j < 1000; j++) {
			for (int k = 0; k < 1000; k++) {
				dp[j][k] = -1;
			}
		}

		int ans = rec(0,0);
		if (ans == 100000000) printf("not possible\n");
		else printf("%d\n", ans);
		*/
		
		for (int i = 0; i <= S; i++) {
			for (int j = 0; j <= S; j++) {
				dp[i][j] = 100000000;
			}
		}
		dp[0][0] = 0;
		for (int i = 0; i < N; i++) {
			for (int x = 0; x <= S; x++) {
				for (int y = 0; y <= S; y++) {
					if (x >= traditional_values[i] && y >= it_values[i]) 
						dp[x][y] = min( dp[x][y], 1 + dp[x - traditional_values[i]][y - it_values[i]] );
					//printf("dp[%d][%d] = %d\n", x, y, dp[x][y]);
				}
			}
		}
		int ans = 100000000;
		for (int x = 0; x <= S; x++) {
			for (int y = 0; y <= S; y++) {
				if ( S*S == y*y + x*x ) ans = min(ans, dp[x][y]); 
			}
		}
		if (ans == 100000000) printf("not possible\n");
		else printf("%d\n", ans);
	}
}/*
1
3 20
2 0
0 2
2 1
*/