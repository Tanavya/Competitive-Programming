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

ll dp[1007][1007];
int optk[1007][1007];

int main() {
    int N, M;
    while (scanf("%d %d", &N, &M) != EOF) {
        vector<ll> breaks(M);
        for (int i = 0; i < M; i++) {
            scanf("%lld", &breaks[i]);
        }
        breaks.pb(0);
        breaks.pb((ll)N);
        sort(all(breaks));
        M = (int) breaks.size();
        //print(breaks);
        for (int d = 0; d < M; d++) {
            for (int i = 0; i+d < M; i++) {
                if (d == 0 || d == 1) {
                    optk[i][i+d] = i;
                    dp[i][i+d] = 0;
                }
                else {
                    int j = i + d;
                    dp[i][j] = INF64;
                    for (int k = optk[i][j-1]; k <= optk[i+1][j]; k++) {
                        ll val = dp[i][k] + dp[k][j] + breaks[j] - breaks[i];
                        if (dp[i][j] > val) {
                            dp[i][j] = val;
                            optk[i][j] = k;
                        }
                    }
                    //printf("dp[%d][%d] = %lld\n", i, j, dp[i][j]);
                }
            }
        }
        printf("%lld\n", dp[0][M-1]);
    }
}