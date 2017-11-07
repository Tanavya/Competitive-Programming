//requires KMP wtf ???
//WA after 3 hours :((((

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

int dp[101][101][101];
int pre[101][101][101][3];
bool use[101][101][101];
string s1, s2, virus;

void setdp (int &val, int cmp, int i, int j, int c, int prei, int prej, int prec, bool u) {
	if (val < cmp) {
		val = cmp;
		pre[i][j][c][0] = prei;
		pre[i][j][c][1] = prej;
		pre[i][j][c][2] = prec;
		use[i][j][c] = u;
	}
}
string reconstruct (int i, int j, int c) {
	string ret = "";
	if (i || j || c) {
		if (use[i][j][c]) {
			ret += s1[i-1];
		}
		int i2 = pre[i][j][c][0];
		int j2 = pre[i][j][c][1];
		int c2 = pre[i][j][c][2];
		ret = reconstruct(i2, j2, c2) + ret;
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
					int &val = dp[i][j][c];
					if (c) setdp(val, dp[i][j][c-1], i, j, c, i, j, c-1, 0);
					if (s1[i-1] == s2[j-1]) {
						if (virus[k-1] != s1[i-1]) {
							setdp(val, dp[i-1][j-1][c] + 1, i, j, c, i-1, j-1, c, 1);
						}
						else {
							setdp(val, dp[i-1][j-1][c-1], i, j, c, i-1, j-1, c-1, 1);
						}
					}
					else {
						if (dp[i-1][j][c] > dp[i][j-1][c]) {
							setdp(val, dp[i-1][j][c], i, j, c, i-1, j, c, 0);
						}
						else {
							setdp(val, dp[i][j-1][c], i, j, c, i, j-1, c, 0);
						}
					}
				}
			}
		}
	}
	int ans = dp[N][M][V-1];
	//cout << ans << endl;
	if (!ans) {
		cout << ans << endl;
	}
	else {
		string strAns = reconstruct(N, M, V-1);
		assert(strAns.size() == ans);
		cout << strAns << endl;
	}
}
/*
30
BBITUNCLTADXYLFTNQERYVXBBGXZWS
*/