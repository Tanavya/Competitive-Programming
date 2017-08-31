//Problem Link: http://codeforces.com/problemset/problem/385/C
//Problem type: Dynamic Programming
//Learning Exp: Always mod final answer, and ALL intermediate steps

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
#include <iomanip> //cout << setprecision(node) << fixed << num

#define mp make_pair
#define ii pair<int, int>
#define PI 3.14159265
#define INF 1000000000000000000LL
#define MAX 1e9
#define MAXN 10000010
#define EPS 1e-5
#define MOD 1000000007
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << "\node";
typedef long long int ll;
using namespace std;

//int dp[507][507][507];
int dp[507][507];
int main() {
    int N, M, B, mod;
    scanf("%d %d %d %d", &N, &M, &B, &mod);
    int bugs[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &bugs[i]);
    }
    for (int n = 0; n < N; n++) {
        for (int m = 0; m <= M; m++) {
            for (int b = 0; b <= B; b++) {
                if (n == 0) {
                    if (m * bugs[n] <= b) {
                        dp[m][b] = 1;
                    }
                }
                else {
                    if (m == 0 && b == 0) dp[m][b] = 1;
                    else {
                        if (m && b-bugs[n] >= 0) dp[m][b] = (dp[m][b] + (dp[m-1][b-bugs[n]] % mod)) % mod; //write 1 line of code
                    }
                }
                //printf("dp[%d][%d][%d] = %d\n", n, m, b, dp[m][b]);
            }
        }
    }
    printf("%d\n", dp[M][B] % mod);
}