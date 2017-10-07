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
	string S, T;
	cin >> T;
	int N = T.size();
	for (int i = 0; i < N; i++) {
		S += "#" + string{T[i]};
	}
	S += "#";
	cout << S << endl;
	vi P(2*N+1);
	int C = 0, R = -1, rad; 
	for (int i = 0; i < S.size(); ++i) {
	    if (i <= R) {
	        rad = min(P[2*C-i], R-i) + 1; 
	    } else {
	        rad = 0; 
	    }
	    // Try to extend
	    while (i+rad < S.size() && i-rad >= 0 && S[i-rad] == S[i+rad]) {
	        rad++; 
	    }
	    P[i] = rad;
	    if (i + rad - 1 > R) {
	        C = i; 
	        R = i + rad - 1; 
	    }
	}
	for (int i = 0; i < P.size(); i++) {
		P[i]--;
		cout << P[i] << " ";
	}
	cout << endl;
}