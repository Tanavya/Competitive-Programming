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
using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

int main() {
	vector <int> vals;
	int n, tmp, m = -1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		m = max(m, tmp);
		vals.push_back(tmp);
	}
	long ans = 0;
	for (int i = 0; i < n; i++) {
		ans += m-vals[i];
	}
	printf("%ld\n", ans);

}