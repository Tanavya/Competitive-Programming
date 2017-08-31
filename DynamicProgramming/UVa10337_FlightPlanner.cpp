//Problem Link: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=655&page=show_problem&problem=1278
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
#define MAX 1e9
#define EPS 1e-5
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << "\n";
typedef long long int ll;
using namespace std;

int N, wind[1007][10], dp[1007][10];
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        N /= 100;
        for (int i = 9; i >= 0; i--) {
            for (int j = 0; j < N; j++) {
                scanf("%d", &wind[j][i]);
                dp[j][i] = MAX;
            }
        }
        dp[0][0] = 0;
        for (int pos = 1; pos <= N; pos++) {
            for (int alt = 0; alt < 10; alt++) {
                dp[pos][alt] = dp[pos-1][alt] + 30 - wind[pos-1][alt]; //stay steady
                if (alt) dp[pos][alt] = min(dp[pos][alt], dp[pos-1][alt-1] + 60 - wind[pos-1][alt-1]); //climb 1 mile
                if (alt < 9) dp[pos][alt] = min(dp[pos][alt], dp[pos-1][alt+1] + 20 - wind[pos-1][alt+1]); //sink 1 mile
            }
        }
        printf("%d\n\n", dp[N][0]);
    }
}