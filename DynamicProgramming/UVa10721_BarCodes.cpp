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

ll dp[60][60][60] = {0};
int main() {
    dp[1][1][1] = 2;
    for (int n = 1; n <= 50; n++) {
        for (int k = 1; k <= n; k++) {
            for (int m = 1; m <= 50; m++) {
                if (n <= m && k == 1) dp[n][k][m] = 1;
                else {
                    for (int i = 1; i <= m && n >= i; i++) {
                        dp[n][k][m] += dp[n-i][k-1][m];
                    }
                }
            }
        }
    }
    int n, k, m;
    while (scanf("%d %d %d", &n, &k, &m) != EOF) {
        printf("%lld\n", dp[n][k][m]);
    }
}