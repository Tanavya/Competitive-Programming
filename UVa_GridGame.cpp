//Problem Link: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=644&page=show_problem&problem=2548
//Problem type: Complete Search

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
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << "\n";
typedef long long int ll;
using namespace std;

int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        int grid[n][n];
        vector <int> perm;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &grid[i][j]);
            }
            perm.push_back(i);
        }
        int ans = INT_MAX;
        do {
            int total = 0;
            for (int i = 0; i < n; i++) {
                total += grid[i][perm[i]];
            }
            ans = min(ans, total);
        } while (next_permutation(perm.begin(), perm.end()));
        printf("%d\n", ans);
    }
}