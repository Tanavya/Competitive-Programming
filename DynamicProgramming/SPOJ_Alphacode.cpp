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

signed long long int dp[5007];
int main() {
  
  	#ifndef ONLINE_JUDGE
	  freopen("inp.txt", "r", stdin);
	#endif

	string S;
	while (true) {

		memset(dp, 0, sizeof(dp));
		cin >> S;
		if (S == "0") break;
		int N = S.size();

		if (S[0] != '0') dp[0] = 1;
		else assert(false);

		for (int i = 1; i < N; i++) {
			int a = stoi(string{S[i]});
			int b = stoi(string{S[i-1]}+S[i]);
			if (a >= 1 && a <= 9) {
				dp[i] += dp[i-1];
			}
			if (b >= 10 && b <= 26) {
				if (i > 1) dp[i] += dp[i-2];
				else dp[i] += 1;
			}
		}
		printf("%lld\n", dp[N-1]);
	}
}