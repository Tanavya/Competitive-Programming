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

const int maxn = 301;
int freq[maxn], S[maxn], dp[maxn][maxn], opt[maxn][maxn], N;

inline int w(int i, int j) {
    return S[j] - S[i-1];
}

bool satisfies_QI() {
    for (int i = 1; i < N; i++) {
        for (int j = 1; j < N; j++) {
            if (dp[i][j] + dp[i+1][j+1] > dp[i][j+1] + dp[i+1][j])
                return false;
        }
    }
    return true;
}

bool is_monotone() {
    for (int i = 1; i < N; i++) {
        for (int j = 1; j < N; j++) {
            int a = dp[i][j], b = dp[i][j+1], c = dp[i+1][j], d = dp[i+1][j+1];
            if (b < a && d >= c) return false;
            if (b == a && d > c) return false;
        }
    }
    return true;
}

void solve_optimal() {
    //O(N^2) Knuth Yao Optimisation
    for (int d = 1; d <= N; d++) {
        for (int i = 1; i+d-1 <= N; i++) {
            if (d == 1) {
                dp[i][i] = freq[i];
                opt[i][i] = i;
            }
            else {
                int j = i + d - 1;
                dp[i][j] = INF;
                for (int k = opt[i][j - 1]; k <= opt[i + 1][j]; k++) {
                    int c = dp[i][k - 1] + dp[k + 1][j] + w(i, j);
                    if (c < dp[i][j]) {
                        dp[i][j] = c;
                        opt[i][j] = k;
                    }
                }
            }
        }
    }
    int ans = dp[1][N] - w(1, N);
    printf("%d\n", ans);
}

void solve_naive() {
    //O(N^3)
    for (int d = 1; d <= N; d++) {
        for (int i = 1; i+d-1 <= N; i++) {
            int j = i+d-1;
            dp[i][j] = INF;
            for (int k = i; k <= j; k++) {
                int c = dp[i][k-1] + dp[k+1][j] + w(i, j);
                dp[i][j] = min(dp[i][j], c);
            }
        }
    }
    int ans = dp[1][N] - w(1, N);
    printf("%d\n", ans);
}

int main() {
    while (scanf("%d", &N) != EOF) {
        for (int i = 1; i <= N; i++) {
            scanf("%d", &freq[i]);
            S[i] = S[i-1] + freq[i];
        }
        for (int i = 0; i <= N; i++)
            for (int j = 0; j <= N; j++)
                dp[i][j] = opt[i][j] = 0;
        solve_optimal();
    }
}