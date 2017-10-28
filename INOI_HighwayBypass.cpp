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
 
int grid[307][307];
ll dp[307][307][307];
ll down[307][307][307], ri[307][307][307];
//li down[307][307], rite[307][307];
const int mod = 20011;
int main() {
	#ifndef ONLINE_JUDGE
		freopen("inp.txt", "r", stdin);
	#endif 
	int R, C, d;
	scanf("%d %d %d", &R, &C, &d);
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			scanf("%d", &grid[i][j]);
		}
	}
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (grid[i][j]) {
				if (i == 1 && j == 1) {
					ri[i][j][0] = down[i][j][0] = 1;
				}
				else {
					for (int k = 1; k <= d; k++) {
						ri[i][j][k] = ri[i][j-1][k-1];
						down[i][j][k] = down[i-1][j][k-1];
					}
					for (int k = 1; k <= d; k++) {
						ri[i][j][0] += down[i][j][k];
						down[i][j][0] += ri[i][j][k]; 

						ri[i][j][0] %= mod;
						down[i][j][0] %= mod;
					}
				}
			}
		}
	}
	if (R == 1 && C == 1) cout << 1 << endl;
	else cout << (ri[R][C][0] + down[R][C][0]) % mod << endl;
} 