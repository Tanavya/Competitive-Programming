#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <stdio.h>
#include <queue>
#include <set>
#include <cmath>
#include <assert.h>

using namespace std;
typedef long long int ll;
ll strength[5007] = {0};
ll DP[5007][5007] = {0};
ll digit_sum(ll n) {
	ll sum = 0;
	while (n > 0) {
		sum += (n%10);
		n /= 10;
	}
	return sum;
}

int main() {

	int N, e;
	ll s;S
	scanf("%d %lld", &N, &s);
	strength[0] = s;
	for (int i = 1; i <= N; i++) {
		strength[i] = strength[i-1] + pow(digit_sum(strength[i-1]), 3);
	}

	scanf("%d", &e);
	DP[1][0] = s*e;
	DP[1][1] = 0;

	
	for (int i = 2; i <= N; i++) {
		scanf("%d", &e);
		for (int x = 0; x < i; x++) {
			DP[i][x] = max(DP[i][x], DP[i-1][x] + strength[x] * e);
			DP[i][x+1] = max(DP[i][x+1], DP[i-1][x]);
		}
	}
	ll best = 0;
	for (int x = 0; x <= N; x++) {
		best = max(best, DP[N][x]);
	}

	cout << best << endl;
}