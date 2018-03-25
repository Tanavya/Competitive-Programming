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
#define ii pair<int, int>
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << "\n";
typedef long long int ll;
using namespace std;

int main() {
	int k;
	while (scanf("%d", &k) != EOF) {
		int cnt = 0;
		for (int i = k+1; i <= k*2; i++) {
			if ((i*k) % (i-k) == 0) {
				cnt++;
			}
		}
		printf("%d\n", cnt);
		for (int i = k+1; i <= k*2; i++) {
			if ((i*k) % (i-k) == 0) {
				printf("1/%d = 1/%d + 1/%d\n", k, (i*k) / (i-k), i);
			}
		}
	}
}