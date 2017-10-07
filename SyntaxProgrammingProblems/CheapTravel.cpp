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

void solve() {
	int T;
	scanf("%d", &T);
		while (T--) {
		int n, m, a, b;
		scanf("%d %d %d %d", &n, &m, &a, &b);

		ll opt1 = (n/m) * b + (n%m) * a;
		ll opt2 = n * a;
		ll opt3 = (n/m) * b;
		if (n%m) opt3 += b;
		cout << min(min(opt1,opt2), opt3) << endl;
	}
}
void gen_tc() {
	int T = 1000;
	cout << T << endl;
	while (T--) {
		int n = (rand() % 1000) + 1;
		int m = (rand() % 1000) + 1;
		int a = (rand() % 1000) + 1;
		int b = (rand() % 1000) + 1;
		printf("%d %d %d %d\n", n, m, a, b);
	}
}
int main() {
	#ifndef ONLINE_JUDGE
		freopen("inp.txt", "r", stdin);
	#endif
    srand(time(NULL));

    for (int i = 0; i <= 2; i++) {
    	string loc = "CheapTravel/input/input" + to_string(i) + ".txt";
        freopen(loc.c_str(), "w", stdout);
    	if (!i) {
    		cout << 2 << endl;
    		cout << "6 2 1 2\n5 2 2 3\n";
    	}
        else {
        	gen_tc();
        }
	}
	for (int i = 0; i <= 2; i++) {
		string loc = "CheapTravel/input/input" + to_string(i) + ".txt";
		freopen(loc.c_str(), "r", stdin);
		loc = "CheapTravel/output/output" + to_string(i) + ".txt";
		freopen(loc.c_str(), "w", stdout);
		solve();
	}
}