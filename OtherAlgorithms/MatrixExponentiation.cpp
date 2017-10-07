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
ll power(ll base, ll pow) {
	ll ret = 1;
	while (pow > 0) {
		if (pow % 2 == 1) {
			ret = (ret * base) % mod;
		}
		base = (base * base) % mod;
		pow /= 2;
	}
	return ret;
}
void print_mat(vector <vll> mat, int p = 0) {
	for (int i = 0; i < N; i++) {
		printf("| ");
		for (int j = 0; j < N; j++) { 
			printf("%lld ", mat[i][j]);
			if (!i && j == N-1 && p) printf("| ^ %d", p);
		}
		if (!p || i) printf("|");
		printf("\n");
	}
	printf("\n");
}
void mat_mult(vector <vll> &A, vector <vll> &B, vector <vll> &mult) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			mult[i][j] = 0;
			for (int k = 0; k < N; k++) {
				mult[i][j] += (A[i][k] * B[k][j]);
				mult[i][j] %= mod;
			}
		}
	}
}
vector <vll> mat_pow(vector <vll> base, ll pow) {
	vector <vll> temp(N, vll (N, 0));
	vector <vll> ret(N, vll (N, 0));
	for (int i = 0; i < N; i++)
		ret[i][i] = 1;
	while (pow > 0) {
		if (pow % 2 == 1) {
			mat_mult(ret, base, temp);
			ret = temp;
		}
		mat_mult(base, base, temp);
		base = temp;
		pow /= 2;
	}
	return ret;
}

int main() {

	
	#ifndef ONLINE_JUDGE 
		freopen("inp.txt", "r", stdin); 
	#endif 
	vector <vll> A = {{5,7}, {6,8}};
	print_mat(A, 3);
	N = 2;
	vector <vll> res = mat_pow(A, 3);
	print_mat(res);

}