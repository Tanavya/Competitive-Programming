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


int main() {
	#ifndef ONLINE_JUDGE 
		freopen("inp.txt", "r", stdin);
	#endif
	int T;
	scanf("%d", &T);
	while (T--) {
		int N, Q;
		scanf("%d %d", &N, &Q);
		vector <int> A(N);
		for (int i = 0; i < N; i++) {
			scanf("%d", &A[i]);
		}
		char type;
		int i, X, L, R;
		while (Q--) {
			cin >> type;
			if (type == '+') {
				scanf("%d %d", &i, &X);
			}
			else {
				scanf("%d %d %d", &i, &L, &R); 
				i--;

				int l = i;
				int r = N;

				while (r-l >= 1) {
					int mid = (r+l)/2;
					if (A[mid] >= R) {
						r = mid;
					}
					else {
						l = mid;
					}
				}

				int n = R-L+1;
				int h = 0;
				int cnt = 0;
				for (int j = i; j < N; j++) {
					if (A[j] > h) {
						if (A[j] > L - 0.5) {
							if (L + n - 1.5 > h) {
								cnt++;
								h = A[j];
							}
						}
					}
				}
				cout << cnt << endl;
			}
		}
	}
}