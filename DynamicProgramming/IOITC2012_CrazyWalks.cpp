#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <assert.h>
#include <map>
#include <queue>
#include <set>


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

const int maxn = 10007, maxl = 1007;
ll dp1[maxn*2][maxl], dp2[maxn*2][maxl];
bool mark[maxn];

int main() {
    int N, L, Q;
    scanf("%d %d %d", &N, &L, &Q);
    int M;
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        int x;
        scanf("%d", &x);
        mark[x] = true;
    }
    for (int i = 1; i <= N+L; i++) {
        for (int j = 1; j <= L; j++) {
            dp1[i][j] = dp2[i][j] = INF64;
        }
    }
    ll ans = INF64;
    for (int n = 1; n <= N+L; n++) {
        if (mark[n]) continue;
        vll vals;
        for (int l = 1; l <= L && l <= n; l++) {
            if (n-l == 0) dp1[n][l] = Q;
            else dp1[n][l] = min(dp1[n-l][l] + 1, dp2[n-l][l] + Q);
            vals.pb(dp1[n][l]);
            if (n >= N) ans = min(ans, dp1[n][l]);
        }
        sort(all(vals));
        for (int l = 1; l <= L && l <= n; l++) {
            if (dp1[n][l] == vals[0]) {
                if (vals.size() > 1)
                    dp2[n][l] = vals[1];
            }
            else dp2[n][l] = vals[0];
            //printf("dp[%d][%d] = %lld\n", n, l, dp1[n][l]);
        }
    }
    if (ans == INF64) printf("%d\n", -1);
    else printf("%lld\n", ans);
}
/*
13 3 10
3
1 2 6
 */