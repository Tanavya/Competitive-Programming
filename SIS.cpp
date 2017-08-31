#include <algorithm>
#include <iostream>
#include <vector>
#include <bitset>
#include <set>
#include <climits>
#include <stdio.h>
#include <assert.h>
#include <map>

#define mod 1000000007
using namespace std;
int DP[8001][8001] = {0};
int A[8001] = {0};
int main() {

    int N,M;
    cin >> N >> M;
    for (int j = 0; j <= N; j++) {
    	if (j < N) A[j] = j+1;
    	DP[1][j] = j+1;
    }
    for (int i = 2; i <= M; i++) {
    	for (int j = 0; j < N; j++) {
    		if (j < i-1) DP[i][j] = 0;
    		else DP[i][j] = (DP[i-1][j-1] % mod + DP[i][j-1] % mod) % mod;
    	}
    }
    cout << DP[M][N-1] << endl;


}