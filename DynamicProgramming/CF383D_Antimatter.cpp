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
#include <stack>
#include <sstream>


#define MAX(a,b) ((a)>(b)?(a):(b))
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

const int mod = (int)1e9+7;
ll dp[1001][20001];
int A[1001];
int main() {
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d", &A[i]);
    dp[0][10000] = 1;
    for (int i = 0; i <= N; i++)
        dp[i][10000] = 1;
    ll ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= 20001; j++) {
            if (j >= A[i])
                dp[i][j] += dp[i-1][j-A[i]];
            if (j+A[i] <= 20000)
                dp[i][j] += dp[i-1][j+A[i]];
            dp[i][j] %= mod;
            if (j == 10000) {
                ans += dp[i][j] - 1;
                ans %= mod;
            }
        }
    }
    cout << (ans+mod)%mod << endl;
}