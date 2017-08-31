#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <stdio.h>
#include <queue>
#include <set>
#include <cmath>
#include <assert.h>
#include <bitset>
#define MAXN 1007
#define mp make_pair
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << "\n";
typedef long long int ll;
using namespace std;

int main() {
	ll n, k;
	cin >> n >> k;
	set <ll> vals;
	vals.insert(1);
	vals.insert(n);
	for (ll i = 2; i < (int)sqrt(n) + 1; i++) {
		if (n % i == 0) {
			vals.insert(i);
			vals.insert(n/i);
		}
	}
	
	auto it = vals.begin();
	if (k > vals.size()) cout << -1 << endl;
	else {
		advance(it, k-1);
		cout << *it << endl;
	}
	
}