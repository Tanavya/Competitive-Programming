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
typedef long long int ll;
using namespace std;

int C, i, d, k;
vector <int> A;
ll f(int n) {
	ll ret = 0;
	for (int i = 0; i < A.size(); i++) {
		ret += (A[i] * pow(n, i));
	}
	return ret;
}
int main() {
	scanf("%d", &C);
	while (C--) {
		scanf("%d", &i);
		A.clear();
		A.resize(i+1);
		for (int j = 0; j <= i; j++) {
			scanf("%d", &A[j]);
		}
		scanf("%d", &d);
		scanf("%d", &k);
		int a = 0;
		for (int x = 0; x < k; x += a*d) {
			a++;
		//printf("%d\n", a);
		printf("%lld\n", f(a));
		//if (C) printf("\n");
	}	
}