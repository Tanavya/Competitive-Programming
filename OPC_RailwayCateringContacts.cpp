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

int main() {

	long long n, k;
	scanf("%lld %lld", &n, &k);
	vector <long long int > dp(n+1);
	vector <long long int > vals(n+1);
	long long int best = LONG_MIN;
	long long int sum = 0;
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		scanf("%lld", &vals[i]);
		sum += vals[i];
		dp[i+1] = min(dp[i], sum);
		if (i >= k) best = max(best, sum - dp[i-k+1]);
	}
	assert (best != LONG_MIN);
	printf("%lld\n", best);

}
/*8 5
-20
90
-30
-20
80
-70
-60
125*/