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

const int max_val = 100000;
unordered_map <int, int> cnt;
int main() {
	#ifndef ONLINE_JUDGE
		freopen("inp.txt", "r", stdin);
	#endif
	int N;
	scanf("%d", &N);


	vi A(N), B(N);
	set <int> S;
	int best = 0, idx = 0;

	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
		B[i] = A[i] + i + 1;
		if (B[i] > best) {
			best = B[i];
		}
		S.insert(B[i]);
		cnt[B[i]]++;
	}
	vi ans = {best};

	for (int i = 2; i <= N; i++) {
		int dec = N-i+1;
		cnt[B[dec]]--;
		if (!cnt[B[dec]]) 
			S.erase(B[dec]);
		B[dec] -= N;
		S.insert(B[dec]);
		cnt[B[dec]]++;
		ans.pb((*prev(S.end())) + i - 1);
		
	}
	print(ans);
}