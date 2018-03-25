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


ld check(ld x, int r, int c, ld cap) {

	vector <ld> glass(r*r+7, 0);
	int n = 1;
	glass[n] = x;
	for (int i = 1; i < r ; i++) {
		for (int j = 1; j <= i; j++) {
			x = glass[n];
			
			if (abs(x-cap) < EPS) {
				glass[n] = cap;
				x = 0;
			}
			else if (x >= cap) {
				glass[n] = cap;
				x -= cap;

			}
			else {
				glass[n] = x;
				x = 0;
			}

			//glass[n] = (x >= cap) ? cap : x;
			//x = (x >= cap) ? (x - cap) : 0;

			glass[n + i] += x/2;
			glass[n + i + 1] += x/2;

			n++;
		}
	}
	return glass[r*(r-1)/2 + c];
}


int main() {
	#ifndef ONLINE_JUDGE 
		freopen("inp.txt", "r", stdin);
	#endif
	int T;
	cin >> T;
	while (T--) {
		int r, c;
		ld cap;
		cin >> r >> c >> cap;
		

		ld mid, ret;
		ll lo = 0, hi = INF64;
		
		if (check(hi, r, c, cap) < cap) {
		    cout << -1 << endl;
		    continue;
		}
		
		ld ans = -1;
		while (hi - lo > 1) {

			mid = (lo + hi) / 2;
			ret = check(mid, r, c, cap);
            
		    if (ret >= cap) {
			    ans = mid;
				hi = mid;
			}
			else {
				lo = mid;
			}

		}
		ans = ceil(ans);
		if (ans == -1) {
		    cout << "impossible" << endl;
		}
		else {
		    assert(check(ans-1, r, c, cap) < cap);
		    printf("%lld\n", (ll)ans);
		}
	}
}