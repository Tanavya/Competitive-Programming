//Problem Link: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=649&page=show_problem&problem=728
//Problem type: Dynamic Programming
//Learning Exp: Requires BigInteger :/

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
    int tmp;
    while (scanf("%d", &tmp) != EOF) {
        vector <int> A;
        while (tmp != -999999) {
            A.push_back(tmp);
            scanf("%d", &tmp);
        }
        //print(A);
        int n = A.size();
        ll ans = 0;
        ll DP[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (j == i) DP[i][j] = A[j];
                else DP[i][j] = DP[i][j-1] * A[j]; 
                if (i == 0 && j == 0) ans = DP[i][j];
                else ans = max(DP[i][j], ans);
            }
        }
        printf("%lld\n", ans);
    }

}