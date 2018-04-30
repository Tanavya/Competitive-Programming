#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <assert.h>
#include <map>
#include <queue>

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << endl;
#define debug(x) cout << x << endl;
#define debug2(x,y) cout << x << " " << y << endl;
#define debug3(x,y,z) cout << x << " " << y << " " << z << endl;
#define debug4(a,b,c,d) cout << a << " " << b << " " << c << " " << d << endl;
#define debug5(a,b,c,d,e) cout << a << " " << b << " " << c << " " << d << " " << e << endl;
#define trace(x) cout << #x << ": " << x << endl;

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

const int maxn = 107, maxm = 1007;
ll dp[maxn][maxn][maxm];
int main() {
    int N, M, H;
    scanf("%d %d %d", &N, &M, &H);
    vector <pair <ll, pair <ll, ll>>> rides(N);
    for (int i = 0; i < N; i++) {
        scanf("%lld %lld %lld", &rides[i].fi, &rides[i].se.fi, &rides[i].se.se);
    }
    sort(all(rides));
    int ans = 0;
    for (int n = 0; n < N; n++) {
        for (int k = 0; k < N; k++) {
            for (int m = 0; m <= M; m++) {
                dp[n][k][m] = -INF;
            }
        }
    }
    dp[0][0][0] = H;
    for (int n = 0; n < N; n++) {
        for (int k = 0; k < N; k++) {
            for (int m = 0; m <= M; m++) {
                ll h = dp[n][k][m];
                ll cost = rides[n].se.fi, inc = rides[n].se.se;
                if (h >= rides[n].fi) {
                    if (m+cost <= M) {
                        dp[n+1][k+1][m+cost] = max(dp[n+1][k+1][m+cost], h+inc);
                        ans = max(ans, k+1);
                    }
                    ans = max(ans, k);
                    dp[n+1][k][m] = max(dp[n+1][k][m], h);
                }
            }
        }
    }
    printf("%d\n", ans);
}