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
	freopen("FancyFence/input/1.txt", "w", stdout);
	cout << 179 << endl;
	for (int i = 1; i < 180; i++) {
		cout << i << endl;
	}
	freopen("FancyFence/input/1.txt", "r", stdin);
	freopen("FancyFence/output/1.txt", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		int a;
		cin >> a;
		double n = 360.0/(180.0-a);
		if (int(n) < n) {
			cout << "NO" << endl;
		} 
		else {
			cout << "YES" << endl;
		}
	}
}