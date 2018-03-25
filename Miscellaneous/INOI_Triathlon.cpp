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


int A[200007][3];
int main() {
	#ifndef ONLINE_JUDGE
		freopen("inp.txt", "r", stdin);
	#endif 
	int N;
	scanf("%d", &N);
	vector <pair<ll,ll>> B;
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &A[i][0], &A[i][1], &A[i][2]);
		B.pb({A[i][1] + A[i][2], A[i][0]});
	}
	sort(B.rbegin(), B.rend());
	ll ans = 0;
	ll s = 0;
	for (int i = 0; i < N; i++) {
		s += B[i].y;
		ans = max(ans, s + B[i].x);
	}
	printf("%lld\n", ans);
}