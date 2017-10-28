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


const int maxn = 1e6+7;
int A[maxn], dp1[maxn], dp2[maxn];
int main() {
	#ifndef ONLINE_JUDGE
		freopen("inp.txt", "r", stdin);
	#endif
	int N, k;
	scanf("%d %d", &N, &k);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}

	memset(dp1, -INF, sizeof(dp1));
	memset(dp2, -INF, sizeof(dp2));

	dp1[k-1] = 0;
	for (int i = k; i < N; i++) {
		dp1[i] = dp1[i-1] + A[i];
		if (i-2 >= k-1) dp1[i] = max(dp1[i], dp1[i-2] + A[i]);
	}
	dp2[0] = A[0];
	for (int i = 1; i < N; i++) {
		dp2[i] = dp2[i-1] + A[i];
		if (i-2 >= 0) dp2[i] = max(dp2[i], dp2[i-2] + A[i]);
	}
	int ans = -INF;
	for (int i = k-1; i < N; i++) {
		int curr = dp1[i] + dp2[i];
		curr -= A[i];
		ans = max(ans, curr);
	}
	printf("%d\n", ans);
}