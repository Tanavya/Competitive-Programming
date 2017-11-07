//Memory limit exceeded

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

short int dp[101][101][101][101]; //dp[i][j][k][c] -> max length subseq such that s1[i]==s1[j]!=virus[k] and at most c elements are common till now
short int pre[101][101][101][101][4];
bool use[101][101][101][101];
string s1, s2, virus;

void setdp(short int &val, int cmp, int i, int j, int k, int c, int prei, int prej, int prek, int prec, bool u) {
	if (val < cmp) {
		val = cmp;
		pre[i][j][k][c][0] = prei;
		pre[i][j][k][c][1] = prej;
		pre[i][j][k][c][2] = prek;
		pre[i][j][k][c][3] = prec;
		use[i][j][k][c] = u;
	}
}

string reconstruct (int i, int j, int k, int c) {
	string ret = "";
	if (i || j || k || c) {
		if (use[i][j][k][c]) {
			ret += s1[i-1];
		}
		int i2 = pre[i][j][k][c][0];
		int j2 = pre[i][j][k][c][1];
		int k2 = pre[i][j][k][c][2];
		int c2 = pre[i][j][k][c][3];
		//assert(use == pre[i][j][k][c][4]);
		ret = reconstruct(i2, j2, k2, c2) + ret;
	}
	return ret;
}


int main() {

	#ifndef ONLINE_JUDGE
		freopen("inp.txt", "r", stdin);
	#endif
	
	cin >> s1 >> s2 >> virus;
	int N = s1.size(), M = s2.size(), V = virus.size();

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			for (int k = 1; k <= V; k++) {
				for (int c = 0; c <= V-1; c++) {
					short int &val = dp[i][j][k][c];
					//if (c) val = dp[i][j][k][c-1];
					if (c) setdp(val, dp[i][j][k][c-1], i, j, k, c, i, j, k, c-1, 0);
					if (s1[i-1] == s2[j-1]) {
						if (virus[k-1] != s1[i-1]) {
							setdp(val, dp[i-1][j-1][k-1][c] + 1, i, j, k, c, i-1, j-1, k-1, c, 1);
							//val = max(val, dp[i-1][j-1][V][c] + 1);
							//val = max(val, dp[i-1][j-1][max(1, k-1)][c] + 1);
						}
						else {
							//if (c) val = max(val, dp[i-1][j-1][k-1][c-1] + 1);
							//if (c) val = max(val, dp[i-1][j-1][V][c-1] + 1);
							//else val = max(val, max(dp[i-1][j][k][c], dp[i][j-1][k][c]));
							if (c && k == V) setdp(val, dp[i-1][j-1][k-1][c-1] + 1, i, j, k, c, i-1, j-1, k-1, c-1, 1);
						}
					}
					else {
						//val = max(val, max(dp[i-1][j][k][c], dp[i][j-1][k][c]));
						//val = max(val, max(dp[i-1][j][V][c], dp[i][j-1][V][c]));
						if (k == V && dp[i-1][j][k-1][c] > dp[i][j-1][k-1][c])
							setdp(val, dp[i-1][j][k-1][c], i, j, k, c, i-1, j, k-1, c, 0);
						else
							setdp(val, dp[i][j-1][k-1][c], i, j, k, c, i, j-1, k-1, c, 0);
					}
				}
			}
		}
	}
	int ans = dp[N][M][V][V-1];
	if (ans) {
		cout << ans << endl;
		string strAns = reconstruct(N, M, V, V-1);
		assert(strAns.size() == ans);
		cout << reconstruct(N, M, V, V-1) << endl;
	}
	else {
		cout << ans << endl;
	}
}