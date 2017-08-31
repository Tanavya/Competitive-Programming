//Problem Link: http://codeforces.com/contest/762/problem/D
//Problem type: Dynamic Programming
//Learning Exp: 

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
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip> //cout << setprecision(node) << fixed << num

#define mp make_pair
#define ii pair<int, int>
#define pb push_back
#define x first
#define y second
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << "\n";
typedef long long int ll;
typedef long double ld;
const int INF = int(1e9);
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

using namespace std;


ll grid[3][100007], dp[3][100007];
int N;
int main() {
    scanf("%d", &N);
    for (int i = 0; i < 3; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%lld", &grid[i][j]);
        }
    }
    for (int i = 1; i <= N; i++) {
        if (i == 1) {
            dp[0][i] = grid[0][i];
            dp[1][i] = dp[0][i] + grid[1][i];
            dp[2][i] = dp[1][i] + grid[2][i]; 
        }
        else {
            dp[0][i] = max(max(dp[0][i-1], dp[1][i-1] + grid[1][i]), dp[2][i-1] + grid[2][i] + grid[1][i]) + grid[0][i];
            dp[1][i] = max(max(dp[0][i-1] + grid[0][i], dp[1][i-1]), dp[2][i-1] + grid[2][i]) + grid[1][i];
            dp[2][i] = max(max(dp[0][i-1] + grid[0][i] + grid[1][i], dp[1][i-1] + grid[1][i]), dp[2][i-1]) + grid[2][i];
            dp[0][i] = max(dp[0][i], dp[2][i-2] + grid[2][i-1] + grid[2][i] + grid[1][i] + grid[1][i-1] + grid[0][i-1] + grid[0][i]);
            dp[2][i] = max(dp[2][i], dp[0][i-2] + grid[0][i-1] + grid[0][i] + grid[1][i] + grid[1][i-1] + grid[2][i-1] + grid[2][i]);
        }
    }
    cout << dp[2][N] << endl;
}