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

const int maxm = (int) 5e5+10, mod = (int) 1e8+7;
ll dp[maxm], pre[20][maxm];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int N, M;
        scanf("%d %d", &N, &M);
        memset(dp, 0, sizeof(dp));
        memset(pre, 0, sizeof(pre));
        for (int l = 1; l < 20; l++) {
            for (int i = N; i >= 1; i--) {
                pre[l][i] = pre[l][i+1];
                if (2*i > N) {
                    if (l == 1) pre[l][i] += 1;
                }
                else {
                    pre[l][i] += pre[l-1][2*i];
                }
                pre[l][i] %= mod;
            }
        }
        dp[0] = 1;
        for (int i = 1; i <= M; i++) {
            for (int l = 1; l < 20 && i-l >= 0; l++) {
                dp[i] += (dp[i-l] * pre[l][1]);
                dp[i] %= mod;
            }
        }
        printf("%lld\n", dp[M]);
    }
}