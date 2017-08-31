//Problem Link: http://codeforces.com/problemset/problem/414/B
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

ll dp[2007][2007];
int main() {

    int N, K;
    scanf("%d %d", &N, &K);
    dp[1][1] = 1;
    for (int len = 1; len <= K; len++) {
        for (int i = 1; i <= N; i++) {
            if (len == 1) dp[len][i] = 1;
            else {
                for (int j = i; j <= N; j += i) {
                    dp[len][j] = ((dp[len][j] % MOD) + (dp[len-1][i] % MOD)) % MOD;
                } 
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i <= N; i++) {
        ans = ((ans % MOD) + (dp[K][i] % MOD)) % MOD;
    }
    printf("%lld\n", ans);
}