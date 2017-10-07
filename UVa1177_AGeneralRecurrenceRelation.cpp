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

int N = 2;
ld power(ld base, ll pow) {
	ld ret = 1;
	while (pow > 0) {
		if (pow % 2 == 1) {
			ret *= base;
		}
		base *= base;
		pow /= 2;
	}
	return ret;
}
void mat_mult(vector <vld> &A, vector <vld> &B, vector <vld> &mult) {
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
vector <vld> mat_pow(vector <vld> base, ll power) {
	vector <vld> ret (N, vld (N, 0));
	vector <vld> temp (N, vld (N, 0));
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
void gen_tc() {
	
	freopen("inp.txt", "w", stdout);
	int T = 1000000;
	int used = 0;
	cout << 1e6 << endl;
	while (used < 1e6) {
		int f0 = (rand() % 1000) + 1;
		int f1 = (rand() % 1000) + 1;
		ld a = (rand() % 1000) + 1;
		ld b = (rand() % 1000) + 1;
		int n = (rand() % 1000) + 1;
		if (a*a + 4*b > 0 && (a - sqrt((ld)(a*a+4*b))) <= 2) {
			/*
			vector <vld> Z{{a,b},{1,0}};
			Z=mat_pow(Z, n-1);
			ld ans1 = Z[0][0] * f1 + Z[0][1] * f0;
			ld e1 = (a + sqrt(a*a+4*b))/2; 
			ld e2 = (a - sqrt(a*a+4*b))/2; 
			ld ans = ((power(e1,n)-power(e2,n)) * f1 + (power(e2,n)*e1-power(e1,n)*e2) * f0)/(e1-e2);
			if (abs(ans1) <= 1e9) {
				used++;
				cout << f0 << " " << f1 << " " << a << " " << b << " " << n << endl;
				assert(round(ans) == round(ans1));
			}
			*/
			ld e1 = (a + sqrt(a*a+4*b))/2; 
			ld e2 = (a - sqrt(a*a+4*b))/2; 
			ld ans = ((power(e1,n)-power(e2,n)) * f1 + (power(e2,n)*e1-power(e1,n)*e2) * f0)/(e1-e2);
			if (abs(ans) <= 1e9) {
				used++;
				cout << f0 << " " << f1 << " " << a << " " << b << " " << n << endl;
			}
		}
	}
}
int main() {
	srand(time(NULL));


	gen_tc();
	return 0;


	#ifndef ONLINE_JUDGE
		freopen("inp.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif
	int T;
	scanf("%d", &T);
	while (T--) {
		ld f0, f1, n;
		ld a, b;
		//scanf("%lf %lf %lf %lf %lf", &f0, &f1, &a, &b, &n);
		cin >> f0 >> f1 >> a >> b >> n;
		if (n == 0) cout << f0 << endl;
		else if (n == 1) cout << f1 << endl;
		else {

			/*
			vector <vld> Z{{a,b},{1,0}};
			Z=mat_pow(Z, n-1);
			ld ans = Z[0][0] * f1 + Z[0][1] * f0;
			*/
			
			assert(a*a+4*b);
			ld e1 = (a + sqrt(a*a+4*b))/2; 
			ld e2 = (a - sqrt(a*a+4*b))/2; 
			ld ans = ((power(e1,n)-power(e2,n)) * f1 + (power(e2,n)*e1-power(e1,n)*e2) * f0)/(e1-e2);
			
			//^ Should have given AC but bad test cases
			cout << setprecision(0) << fixed << ans << endl;
			
		}
	}
}
