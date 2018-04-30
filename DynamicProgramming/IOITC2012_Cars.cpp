#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <assert.h>
#include <set>
#include <random>
#include <iomanip>
#include <map>

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

const int maxn = 5007;
int N, A[maxn], dp[maxn][maxn], DP[207][207][207],RMQ[maxn];


int brute() {
    int ans = 0;
    for (int i = 1; i <= N+1; i++) {
        for (int a = 0; a <= N+1; a++) {
            for (int b = 0; b <= N+1; b++) {
                DP[i][a][b] = -INF;
            }
        }
    }
    DP[1][N+1][N+1] = 0;
    for (int i = 1; i <= N; i++) {
        for (int a = 0; a <= N+1; a++) {
            for (int b = 0; b <= N+1; b++) {
                int val = DP[i][a][b];
                if (val < 0) continue;
                if (A[i] < a)
                    DP[i+1][A[i]][b] = max(DP[i+1][A[i]][b], val + 1);
                else
                    DP[i+1][a][b] = max(DP[i+1][a][b], val);
                if (A[i] < b)
                    DP[i+1][a][A[i]] = max(DP[i+1][a][A[i]], val + 1);
                else
                    DP[i+1][a][b] = max(DP[i+1][a][b], val);
                //printf("dp[%d][%d][%d] = %d\n", i, a, b, DP[i][a][b]);
            }
        }
    }
    for (int a = 0; a <= N+1; a++)
        for (int b = 0; b <= N+1; b++)
            ans = max(ans, DP[N+1][a][b]);
    return ans;
}

int main() {
    //freopen("inp.txt", "r", stdin);
    map <int, int> HASH;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &A[i]);
        HASH[A[i]] = 0;
    }
    int t = 0;
    for (auto it : HASH) {
        HASH[it.first] = ++t;
    }
    for (int i = 1; i <= N; i++) A[i] = HASH[A[i]];
    RMQ[0] = N+2;
    for (int i = 1; i <= N; i++) {
        RMQ[i] = min(RMQ[i-1], A[i]);
    }
    for (int i = 1; i <= N+1; i++) {
        for (int a = 0; a <= N+1; a++) {
            dp[i][a] = -INF;
        }
    }
    dp[2][N+1] = 1;
    int ans = 0;
    for (int i = 2; i <= N; i++) {
        for (int a = 0; a <= N+1; a++) {
            int val = dp[i][a];
            if (val < 0) continue;
            if (a > RMQ[i-1]) {
                int b = RMQ[i-1];
                if (A[i] == RMQ[i]) {
                    dp[i+1][a] = max(dp[i+1][a], val+1);
                    dp[i+1][b] = max(dp[i+1][b], val+1);
                }
                else if (A[i] < a) {
                    dp[i+1][A[i]] = max(dp[i+1][A[i]], val+1);
                    assert(A[i] > b);
                }
                dp[i+1][a] = max(dp[i+1][a], val);
                //printf("dp[%d][%d] = %d\n", i, a, dp[i][a]);
            }
            else {
                assert(false);
            }
        }
    }
    for (int a = 0; a <= N+1; a++)
        ans = max(ans, dp[N+1][a]);
    printf("%d\n", ans);
}