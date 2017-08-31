//Problem Link: http://codeforces.com/contest/580/problem/D
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
#define PI 3.14159265
#define INF 1000000000000000000LL
#define MAX 1e9
#define MAXN 10000010
#define EPS 1e-5
#define MOD 1000000007
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << "\n";
typedef long long int ll;
using namespace std;

int N, M, K;
ll satisfaction[20], rules[20][20], dp[20][1 << 20];

ll rec(int n, int mask, int m) {
    ll ret = 0;
    if (dp[n][mask] != -1) {
        return dp[n][mask];
    }
    else {
        if (m == M) {
            ret = 0;
        }
        else {
            for (int i = 1; i <= N; i++) {
                if (!(mask & (1 << i))) {
                    ret = max(ret, satisfaction[i] + rules[n][i] + rec(i, mask | (1 << i), m+1));
                }
            }
        }
    }
    dp[n][mask] = ret;
    return ret;
}
int main() {

    scanf("%d %d %d", &N, &M, &K);
    for (int i = 1; i <= N; i++) {
        scanf("%lld", &satisfaction[i]);
    }
    int a, b;
    for (int i = 0; i < K; i++) {
        scanf("%d %d", &a, &b);
        scanf("%lld", &rules[a][b]);
    }
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j < (1 << (N+1)); j++) {
            dp[i][j] = -1;
        }
    }

    cout << rec(0, 0, 0) << endl;
}
