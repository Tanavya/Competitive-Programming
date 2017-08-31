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

int N;
float dp[10][2000];
int next_point[10][2000];
ii points[10];

inline float dist(ii a, ii b) {
    int x = a.first - b.first, y = a.second - b.second;
    return sqrt(x*x + y*y);
}
float rec(int n, int msk) {
    if (dp[n][msk] != -1) {
        return dp[n][msk];
    }
    float ret = 1000000000;
    if (msk == (1 << N) - 1) {
        ret = 0;
    }
    else {
        for (int next = 0; next < N; next++) {
            if (!((1 << next) & msk)) {
                float x = 16 + dist(points[n], points[next]) + rec(next, msk | (1 << next));
                if (x < ret) {
                    ret = x;
                    next_point[n][msk] = next;
                }
            }
        }
    }
    dp[n][msk] = ret;
    return ret;
}
void reset() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < (1 << N) + 7; j++) {
            dp[i][j] = -1;
            next_point[i][j] = -1;
        }
    }
}
int main() {
    int t = 0;
    while (true) {
        scanf("%d", &N);
        if (!N) break;
        for (int n = 0; n < N; n++) {
            scanf("%d %d", &points[n].first, &points[n].second);
        }
        
        float ans = 1000000000;
        int next = -1, prev = -1;
        reset();
        for (int i = 0; i < N; i++) {
            float x = rec(i, (1 << i));
            if (x < ans) {
                ans = x;
                prev = i;
            }
        }

        printf("**********************************************************\nNetwork #%d\n", ++t);
        int msk = 0;
        while (true) {
            msk |= (1 << prev);
            next = next_point[prev][msk];
            if (next == -1) break;
            printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2f feet.\n", 
            points[prev].first, points[prev].second, points[next].first, points[next].second, 16 + dist(points[prev], points[next]));
            prev = next;
        }
        printf("Number of feet of cable required is %.2f.\n", ans);
    }

}