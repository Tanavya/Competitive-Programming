//Problem Link: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=44
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
    int n;
    scanf("%d", &n);
    int A[n+1][n+1];
    for (int i = 0; i <= n; i++) {
        A[0][i] = A[i][0] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &A[i][j]);
            if (i > 1) A[i][j] += A[i-1][j];
            if (j > 1) A[i][j] += A[i][j-1];
            if (i > 1 && j > 1) A[i][j] -= A[i-1][j-1];
        }
    }
    /*
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    */
    int ans = -1000000000;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = i; k <= n; k++) {
                for (int l = j; l <= n; l++) {
                    ans = max(ans, A[k][l] - A[k][j-1] - A[i-1][l] + A[i-1][j-1]);
                }
            }
        }
    }
    printf("%d\n", ans);
}