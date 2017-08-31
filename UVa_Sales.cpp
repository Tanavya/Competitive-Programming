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

	int t, n, a;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		int A[n];
		long ans = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &A[i]);
			if (i > 0) {
				int cunt = 0;
				for (int j = 0; j < i; j++) {
					if (A[j] <= A[i]) cunt++;
				}
				ans += cunt;
			}
		}
		printf("%ld\n", ans);
	}
}