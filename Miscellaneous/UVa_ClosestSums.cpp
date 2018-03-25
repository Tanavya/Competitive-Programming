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
#include <map>
#include <unordered_map>
#define MAXN 1007
#define mp make_pair
#define ii pair<int, int>
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << "\n";
typedef long long int ll;
using namespace std;

int main() {
	int n = -1, m, q, a, b, t = 0;
	while (n) {
		scanf("%d", &n);
		if (!n) break;
		t++;
		vector <int> A(n);
		set <long> pairs;
		for (int i = 0; i < n; i++) {
			scanf("%d", &A[i]);
		}
		for (int i = 0; i < n; i++) {
			for (int j = i+1; j < n; j++) {
				pairs.insert(A[i]+A[j]);
			}
		}
		printf("Case %d:\n", t);
		scanf("%d", &m);
		for (int i = 0; i < m; i++) {
			scanf("%d", &q);
			auto it = pairs.lower_bound(q);
			if (it == pairs.begin()) printf("Closest sum to %d is %ld.\n", q, *it);
			else {
				long a = *it, b = *prev(it);
				if (abs(a-q) < abs(b-q)) printf("Closest sum to %d is %ld.\n", q, a);
				else printf("Closest sum to %d is %ld.\n", q, b);
			}
		}
	}
}