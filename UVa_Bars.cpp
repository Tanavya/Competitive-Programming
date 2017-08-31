//Problem Link: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=644&page=show_problem&problem=3886
//Problem type: Complete Search / DP
//Learning: It's a subSET, i.e no repetitions allowed to find the sum!

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
 
#define MAXN 1007
#define mp make_pair
#define ii pair<int, int>
#define PI 3.14159265
#define INF 1000000000000000000LL
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << "\n";
typedef long long int ll;
using namespace std;

void solveDP(int n, int p) {
    int DP[n+1][p+1], bars[p];
    for (int i = 0; i < p; i++) {
        scanf("%d", &bars[i]);
        DP[0][i] = true;
    }
    DP[0][p] = true;
    for (int i = 1; i <= n; i++) {
        DP[i][0] = false;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= p; j++) {
            DP[i][j] = DP[i][j-1];
            if (i >= bars[j-1] && DP[i-bars[j-1]][j-1]) {
                DP[i][j] = 1;
            }
        }
    }
    if (DP[n][p]) printf("YES\n");
    else printf("NO\n");
}

void solveBrute(int n, int p) {
    int bars[p];
    for (int i = 0; i < p; i++) {
        scanf("%d", &bars[i]);
    }
    for (int mask = 0; mask < (1 << p); mask++) {
        int sum = 0;
        for (int i = 0; i < p; i++) {
            if (mask & (1 << i)) sum += bars[i];
        }
        if (sum == n) {
            printf("YES\n");
            return;
        }
    }
    printf("NO\n");
}
int main() {
    int tc, n, p;
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d", &n);
        scanf("%d", &p);
        solveBrute(n,p);
    }
}