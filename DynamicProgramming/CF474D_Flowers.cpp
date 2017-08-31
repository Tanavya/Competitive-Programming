//Problem Link: http://codeforces.com/problemset/problem/161/D
//Problem type: Dynamic Programming

//TODO 765E

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
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip> //cout << setprecision(node) << fixed << num

#define mp make_pair
#define pb push_back
#define x first
#define y second
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " ";

typedef long long int ll;
typedef long double ld;
typedef std::pair <int, int> ii;
typedef std::vector <int> vi;
typedef std::vector <ll> vll;
const int INF = int(1e9);
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
using namespace std;

const int MOD = 1000000007;
ll dp[500007], pre[500007];

int main() {
    int T, K, a, b;
    scanf("%d %d", &T, &K);
    for (int i = 0; i < K; i++) {
        dp[i] = 1;
        pre[i] = i+1;
    }
    for (int i = K; i <= 500000; i++) {
        dp[i] = ((dp[i-1] % MOD) + (dp[i-K] % MOD)) % MOD;
        pre[i] = ((pre[i-1] % MOD) + (dp[i] % MOD)) % MOD;
    }
    for (int t = 0; t < T; t++) {
        scanf("%d %d", &a, &b);
        ll ans = ((pre[b] % MOD) - (pre[a-1] % MOD)) % MOD;
        ans += (ans < 0 ? MOD : 0);
        printf("%lld\n", ans);
    }
}
