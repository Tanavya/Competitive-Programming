#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <stdio.h>
#include <queue>
#include <set>
#include <list>
#include <cmath>
#include <assert.h>
#include <bitset>
#include <cstring>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip> //cout << setprecision(node) << fixed << num
#include <stack>
#include <sstream>


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

const int INF = int(1e9);
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
using namespace std;

const int mod = (int) 1e9 + 7;
ll dp[57][57][407][2];

int main() {

    int T;
    scanf("%d", &T);
    while (T--) {

        memset(dp, 0, sizeof(dp));

        int p, q, N, B1, B2, S1, S2;
        scanf("%d %d %d", &p, &q, &N);
        scanf("%d %d", &B1, &B2);
        scanf("%d %d", &S1, &S2);

        dp[0][0][0][0] = dp[0][0][0][1] = 1;
        for (int i = 0; i <= p; i++) {
            for (int j = 0; j <= q; j++) {
                for (int b = 1; b <= B1+B2; b++) {
                    for (int t = 1; t >= 0; t--) {
                        if (t == 0) {
                            for (int s = 1; s <= S1 && i - s >= 0; s++) {
                                dp[i][j][b][t] += dp[i - s][j][b - 1][1];
                                dp[i][j][b][t] %= mod;
                            }
                        } else {
                            for (int s = 1; s <= S2 && j - s >= 0; s++) {
                                dp[i][j][b][t] += dp[i][j - s][b - 1][0];
                                dp[i][j][b][t] %= mod;
                            }
                        }
                        //printf("dp[%d][%d][%d][%d] = %d\n", i, j, b, t, dp[i][j][b][t]);
                    }
                }
            }
        }
        ll ans = 0;
        for (int i = 0; i <= p; i++) {
            int j = N - i;
            if (j > q) continue;

            for (int b1 = 0; b1 <= B1; b1++) {
                for (int b2 : {b1 - 1, b1, b1 + 1}) {
                    if (b2 >= 0 && b1 <= B1 && b2 <= B2) {
                        if (b1 == b2) ans += dp[i][j][b1 + b2][0] + dp[i][j][b1 + b2][1];
                        else if (b1 < b2) ans += dp[i][j][b1 + b2][1];
                        else ans += dp[i][j][b1 + b2][0];
                    }
                }
            }
            ans %= mod;
        }
        printf("%lld\n", ans);
    }
}