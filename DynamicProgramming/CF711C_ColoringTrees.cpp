//Problem Link: http://codeforces.com/problemset/problem/711/C
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
#define MOD 1000000007
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << "\n";
typedef long long int ll;
using namespace std;

int initial[100], N, M, K;
ll amount[107][107], ans = INF, dp[107][107][107];
int main() {
    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 100; j++) {
            for (int k = 0; k <= 100; k++) {
                dp[i][j][k] = INF;
            }
        }
    }
    scanf("%d %d %d", &N, &M, &K);
    for (int i = 0; i < N; i++) {
        scanf("%d", &initial[i]);
    }
    for (int i = 0; i < N; i++) {
        for (int j = 1; j <= M; j++) {
            scanf("%lld", &amount[i][j]);
            if (initial[i] == j) amount[i][j] = 0;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int k = 1; k <= K; k++) {
            for (int last = 1; last <= M; last++) {
                if (initial[i] != 0 && last != initial[i]) continue;
                
                if (i == 0 && k == 1) dp[i][k][last] = amount[i][last];
                else if (i > 0) {
                    dp[i][k][last] = dp[i-1][k][last] + amount[i][last];
                    ll temp = INF;
                    for (int j = 1; j <= M; j++) {
                        if (j != last) temp = min(temp, dp[i-1][k-1][j] + amount[i][last]);
                    }
                    dp[i][k][last] = min(dp[i][k][last], temp);
                }
                if (i == N-1 && k == K) ans = min(ans, dp[i][k][last]);
            }
        }
    }
    if (ans == INF) ans = -1;
    printf("%lld\n", ans);


}