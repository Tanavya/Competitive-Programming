//Problem Link: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=649&page=show_problem&problem=1696
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

int main() {
    int T, n, A, B, C;
    scanf("%d", &T);
    for (int t = 0; t < T; t++) {
        scanf("%d %d %d", &A, &B, &C);
        ll cuboid[A+1][B+1][C+1];
        for (int a = 0; a <= A; a++) {
            for (int b = 0; b <= B; b++) {
                for (int c = 0; c <= C; c++) {
                    if (a == 0 || b == 0 || c == 0) cuboid[a][b][c] = 0;
                    else {
                        scanf("%lld", &cuboid[a][b][c]);
                        if (b > 1) cuboid[a][b][c] += cuboid[a][b-1][c];
                        if (c > 1) cuboid[a][b][c] += cuboid[a][b][c-1];
                        if (b > 1 && c > 1) cuboid[a][b][c] -= cuboid[a][b-1][c-1];
                    }
                }
            }
        }
        ll ans = -INF;
        for (int i = 1; i <= B; i++) {
            for (int j = 1; j <= C; j++) {
                for (int k = i; k <= B; k++) {
                    for (int l = j; l <= C; l++) {
                        ll sum = 0;
                        for (int a = 1; a <= A; a++) {
                            sum += (cuboid[a][k][l] - cuboid[a][k][j-1] - cuboid[a][i-1][l] + cuboid[a][i-1][j-1]);
                            ans = max(ans, sum);
                            if (sum < 0) sum = 0;
                        }
                    }
                }
            }

        }
        printf("%lld\n", ans);
        if (t != T-1) printf("\n");
    }

}