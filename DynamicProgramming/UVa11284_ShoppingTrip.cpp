//Problem Link: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=654&page=show_problem&problem=2259
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
#define EPS 1e-5
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << "\n";
typedef long long int ll;
using namespace std;

int dp[15][20000], shops[15], MAX = 1e9;
float dist[51][51], savings[15];
int N, M, P;

inline float float_min(float a, float b) {
    if (a - b < numeric_limits<float>::epsilon() && fabs(a-b) > numeric_limits<float>::epsilon()) 
        return a;
    else 
        return b;
}
inline float float_max(float a, float b) {
    if (a - b > numeric_limits<float>::epsilon() && fabs(a-b) > numeric_limits<float>::epsilon()) 
        return a;
    else 
        return b;
}
float rec(int n, int msk) {
    if (abs(dp[n][msk] + MAX) > numeric_limits<float>::epsilon()) {
        return dp[n][msk];
    }
    float ret = -dist[shops[n]][0];

    for (int i = 0; i < P; i++) {
        if (!((1 << i) & msk)) {
            ret = float_max(ret, savings[i] - dist[shops[n]][shops[i]] + rec(i, msk | (1 << i)));
        }
    }
    dp[n][msk] = ret;
    return ret;
}


int main() {
    int T, a, b;
    float c;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &N, &M);
        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= N; j++) {
                dist[i][j] = MAX;
            }
        }
        int dollars, cents;
        char junk;
        for (int i = 0; i < M; i++) {
            cin >> a >> b >> c;
            dist[a][b] = min(dist[a][b], c);
            dist[b][a] = min(dist[b][a], c);
            //dist[a][b] = min(dist[a][])
        }
        for (int k = 0; k <= N; k++) {
            for (int i = 0; i <= N; i++) {
                for (int j = 0; j <= N; j++) {
                    dist[i][j] = float_min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        dist[0][0] = 0;

        scanf("%d", &P);
        shops[0] = 0; savings[0] = 0;
        P++;
        for (int i = 1; i < P; i++) {
            cin >> a >> c;
            shops[i] = a;
            savings[i] = c;
        }

        for (int i = 0; i < P; i++) {
            for (int j = 0; j < (1 << (P+1)) + 7; j++) {
                dp[i][j] = -MAX;
            }
        }
        float ans = rec(0, 0);
        if (ans > 0) printf("Daniel can save $%.2f\n", float(ans));
        else printf("Don't leave the house\n");
    }
}
/*
2
4 5
0 1 1.00
1 2 3.00
1 3 2.00
2 4 4.00
3 4 3.25
3
2 1.50
3 7.00
4 9.00

*/