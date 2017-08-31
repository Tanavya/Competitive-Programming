//Problem Link: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=654&page=show_problem&problem=1437
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

int T, x, y, N, dp[20][5000];
ii beepers[11], start;

inline int dist(ii a, ii b) {
    return (abs(a.first - b.first) + abs(a.second - b.second));
}
int rec(int n, int msk) {
    if (dp[n][msk] != -1) {
        return dp[n][msk];
    }
    int ret = 1000000000;
    if (msk == (1 << N) - 1) {
        ret = dist(beepers[n], start);
    }
    else {
        for (int next = 0; next < N; next++) {
            if (!((1 << next) & msk)) {
                ret = min(ret, dist(beepers[n], beepers[next]) + rec(next, msk | (1 << next)));
            }
        }
    }
    dp[n][msk] = ret;
    return ret;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &x, &y);
        scanf("%d %d", &start.first, &start.second);
        scanf("%d", &N);
        beepers[0] = start;
        for (int i = 1; i <= N; i++) {
            scanf("%d %d", &beepers[i].first, &beepers[i].second);
        }
        N++;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j <= (1 << N) + 10; j++) {
                dp[i][j] = -1;
            }
        }
        printf("The shortest path has length %d\n", rec(0, 1));
    }
}