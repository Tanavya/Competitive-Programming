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

#define mp make_pair
#define pb push_back
#define x first
#define y second
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << endl;
#define debug(x) cout << x << endl;
#define debug2(x,y) cout << x << " " << y << endl;
typedef long long int ll;
typedef long double ld;
typedef std::pair <int, int> ii;
typedef std::vector <int> vi;
typedef std::vector <ll> vll;
const int INF = int(1e9);
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
using namespace std;

int N, K;
ll M;
ll dp[1007][107][2], exp_memo[1007][107][2]; //i, j ; i <= N, j <= K
ll ans = 0;

ll expow(int n, int p, int modulus) {
    ll &res = exp_memo[n][p][modulus == K];
    if (res != -1) return res;
    res = 1;
    n = (n % modulus);
    while (p > 0) {
        if (p & 1) res = (1LL * res * n) % modulus;
        p = p >> 1;
        n = (1LL * n * n) % modulus;
    }
    return res;
}
ll count(int i, int j, bool last_zero) {
    ll &val = dp[i][j][last_zero];
    if (val != -1) return val;
    val = 0;
    if (j == 0 && !last_zero) {
        if (i == N) val = 1;
        else val = (9 * expow(10, N-i-1, M)) % M;
    }
    else if (i != N) {
        for (int d = 0; d <= 9; d++) {
            val += count(i + 1, (j + (d * expow(10, i, K))) % K, d == 0);
            val %= M;
        }
    }
    return val;
}

int main() {
    memset(dp, -1, sizeof(dp));
    memset(exp_memo, -1, sizeof(exp_memo));
    scanf("%d %d %lld", &N, &K, &M);
    cout << count(0, 0, 1) << endl;
}