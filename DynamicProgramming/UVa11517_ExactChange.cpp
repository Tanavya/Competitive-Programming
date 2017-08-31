//Problem Link: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3836
//Problem type: Dynamic Programming
//Learning Exp: 

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
#include <unordered_set>
#include <iomanip> //cout << setprecision(n) << fixed << num

#define mp make_pair
#define ii pair<int, int>
#define PI 3.14159265
#define INF 1000000000000000000LL
#define EPS 1e-9
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << "\n";
typedef long long int ll;
using namespace std;

int T, C, N, coins[101], dp[30007][102];
int main() {

    scanf("%d", &T);
    while (T--) {
        int MAX = 100000000;
        scanf("%d", &C);
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            scanf("%d", &coins[i]);
        }
        for (int i = 0; i <= 20007; i++) {
            for (int j = 0; j <= N; j++) {
                dp[i][j] = MAX;
            }
        }

        dp[0][0] = 0;
        for (int i = 0; i <= 20007; i++) {
            for (int j = 1; j <= N; j++) {
                if (i == 0) dp[i][j] = 0; 
                else if (i < coins[j-1]) dp[i][j] = dp[i][j-1];
                else dp[i][j] = min(dp[i][j-1], dp[i-coins[j-1]][j-1] + 1);
            }
        }
        for (int i = C; i <= 20007; i++) {
            if (dp[i][N] != MAX) {
                printf("%d %d\n", i, dp[i][N]);
                break;
            }
        }
    }
}