//Problem Link: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=652&page=show_problem&problem=1760
//Problem type: Dynamic Programming
//Learning Exp: 

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <stdio.h>
#include <string.h>
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
int values[107], costs[107], dp[107][10207];
int M, N, p, f;
int rec(int n, int w) {
    /*
    if (dp[n][w] != -1) return dp[n][w];
    int ret = 0;
    if (n == 0 || w == 0) ret = 0;
    else if (costs[n] > w) ret = rec(n-1, w);
    else ret = max(rec(n-1, w), rec(n-1, w - costs[n]));
    */
    if (dp[n][w] != -1) return dp[n][w];
    int ret = 0;
    //if (n == N || w == M || (w > 2000 && w <= M+200)) ret = 0;
    if (n == N) {
        if (w <= M) ret = 0;
        else if (w > 2000 && w <= M+200) ret = 0;
        else ret = -1;
    }
    else if (costs[n]+w > M+200) ret = rec(n+1, w);
    else {
        int x = rec(n+1, w+costs[n]);
        if (x == -1) ret = rec(n+1, w);
        else ret = max(rec(n+1, w), values[n] + x); 
        //ret = max(rec(n+1, w), values[n] + rec(n+1, w+costs[n]));
    }
    dp[n][w] = ret;
    return ret;
}

int main() {
    while (scanf("%d %d", &M, &N) != EOF) {
        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= M+200; j++) {
                dp[i][j] = -1;
            }
        }
        for (int i = 0; i < N; i++) {
            scanf("%d %d", &costs[i], &values[i]);
        }
        int ans = rec(0, 0);
        printf("%d\n", ans);

    }

}