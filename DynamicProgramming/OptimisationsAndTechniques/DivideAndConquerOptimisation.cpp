//https://www.hackerrank.com/contests/ioi-2014-practice-contest-2/challenges/guardians-lunatics-ioi14/problem
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

const int maxn = 8007, maxg = 807;

int optk[maxg][maxn], N, G;
ll dp[maxg][maxn], R[maxn];

inline ll w(int i, int j) {
    return (R[j] - R[i]) * ll(j-i);
}

void calc(int i, int l, int r) {
    if (l > r) return;
    if (l == 1) optk[i][0] = 0;
    if (r == N) optk[i][N+1] = N;
    int m = (l+r)/2;
    dp[i][m] = INF64;
    for (int k = optk[i][l-1]; k <= optk[i][r+1] && k < m; k++) {
        ll tmp = dp[i-1][k] + w(k, m);
        if (tmp < dp[i][m]) {
            dp[i][m] = tmp;
            optk[i][m] = k;
        }
    }
    if (l != r) {
        calc(i, l, m - 1);
        calc(i, m + 1, r);
    }
}

int main() {
    scanf("%d %d", &N, &G);
    for (int i = 1; i <= N; i++) {
        scanf("%lld", &R[i]);
        R[i] += R[i-1];
    }
    dp[0][0] = 0;
    for (int i = 1; i <= N; i++) dp[0][i] = INF64;
    for (int i = 1; i <= G; i++) {
        calc(i, 1, N);
    }
    printf("%lld\n", dp[G][N]);
}