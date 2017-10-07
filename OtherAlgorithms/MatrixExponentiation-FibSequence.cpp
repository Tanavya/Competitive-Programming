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
const int INF = int(1e9);
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
using namespace std;

const int mod = 1e9+7;
int N = 2;
void print_mat(vector <vll> mat) {
	for (int i = 0; i < N; i++) {
		printf("| ");
		for (int j = 0; j < N; j++) {
			printf("%lld ", mat[i][j]);
		}
		printf("|\n");
	}
	printf("\n");
}
void mat_mult(vector <vll> &A, vector <vll> &B, vector <vll> &mult) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			mult[i][j] = 0;
			for (int k = 0; k < N; k++) {
				mult[i][j] += (A[i][k] * B[k][j]);
				//mult[i][j] %= mod;
			}
		}
	}
}
vector <vll> mat_pow(vector <vll> base, ll power) {
	vector <vll> ret (N, vll (N, 0));
	vector <vll> temp (N, vll (N, 0));
	for (int i = 0; i < N; i++) 
		ret[i][i] = 1;
	while (power > 0) {
		if (power % 2 == 1) {
			mat_mult(ret, base, temp);
			ret = temp;
		}
		mat_mult(base, base, temp);
		base = temp;
		power /= 2;
	}
	return ret;
}

int main() {
	#ifndef ONLINE_JUDGE 
		//freopen("inp.txt", "r", stdin); 
	#endif 
	ll fib;
	int T;
	scanf("%d", &T);
	while (T--) {
	scanf("%lld", &fib);
		//for (fib = 0; fib < 100; fib++) {
			vector <vll> Z = {{1,1},{1,0}};
			ll res;
			if (fib == 0) res = 0;
			else if (fib == 1 || fib == 2) res = 1;
			else {
				Z = mat_pow(Z, fib-1);
				res = Z[0][0];
			}
			printf("Fib(%lld) = %lld\n", fib, res);
		//}
	}
}