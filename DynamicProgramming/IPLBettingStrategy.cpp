#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <assert.h>
#include <set>
#include <random>
#include <iomanip>

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << endl;
#define debug(x) cout << x << endl;
#define debug2(x,y) cout << x << " " << y << endl;
#define debug3(x,y,z) cout << x << " " << y << " " << z << endl;

typedef long long int ll;
typedef long double ld;
typedef unsigned long long int ull;
typedef std::pair <int, int> ii;
typedef std::vector <int> vi;
typedef std::vector <ll> vll;
typedef std::vector <ld> vld;

const int INF = 2147483647;
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
using namespace std;

double dp[100][100][100];

int main() {
    int N = 50;
    double p = 0.55;
    //dp[n][k] -> after n games you have won k-1 times in a row if k > 0
    //else you have lost >= 2 games in a row and your points are in -ve
    dp[1][1][0] = 1;
    double final_prob = 0;
    for (int i = 1; i <= N; i++) {
        for (int k = 0; k <= N; k++) {
            for (int t = 0; t <= N; t++) {
                assert(dp[i][k][t] <= 1);
                if (k == 4)
                    dp[i+1][k+1][t+1] += dp[i][k][t] * p;
                else
                    dp[i+1][k+1][t] += dp[i][k][t] * p;
                dp[i+1][0][t] += dp[i][k][t] * (1 - p);
                if (i == N && t >= 1) final_prob += dp[i][k][t];
            }
        }
    }
    cout << setprecision(10) << final_prob << endl;
}