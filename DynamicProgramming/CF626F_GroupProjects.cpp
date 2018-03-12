//Open Close Interval Trick
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

const int mod = (int) 1e9+7;
ll dp[207][207][1007];

#define add(a, b) a = (a + (b % mod)) % mod

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    vi A(N+1,0);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &A[i]);
    }
    sort(all(A));
    dp[0][0][0] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            for (int k = 0; k <= K; k++) {
                ll cnt = dp[i-1][j][k];
                int val = k + j * (A[i] - A[i-1]);
                if (val > K) continue;
                add(dp[i][j][val], cnt * (j+1));
                if (j) add(dp[i][j-1][val], j * cnt);
                add(dp[i][j+1][val], cnt);
            }
        }
    }
    ll ans = 0;
    for (int k = 0; k <= K; k++) {
        add(ans, dp[N][0][k]);
    }
    cout << ans << endl;
}
