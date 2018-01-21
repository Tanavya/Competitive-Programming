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

string N;
const int mod = (int) 1e9 + 7;
ll dp2[1007][1007][2], dp[1007][1007];


int count_on(int x) {
    int cnt = 0;
    for (int i = 20; i >= 0 && x; i--) {
        if ((1 << i) & x)
            cnt++;
    }
    return cnt;
}
ll rec(int i, int j, int b) {
    if (j < 0)
        return 0;
    if (dp2[i][j][b] != -1)
        return dp2[i][j][b];
    ll ret = 0;
    if (i == N.size()) {
        if (j == 0) return 1;
        else return 0;
    }
    if (N[i] == '0') {
        ret = rec(i+1, j, b);
        if (b) ret += rec(i+1, j-1, b);
    }
    else {
        ret = rec(i+1, j, 1) + rec(i+1, j-1, b);
    }
    ret %= mod;
    return dp2[i][j][b] = ret;
}

int main() {
    memset(dp2, -1, sizeof(dp2));
    cin >> N;
    int K;
    cin >> K;
    if (K == 0) {
        cout << 1 << endl;
        return 0;
    }
    dp[1][0] = 1;
    ll ans = 0;
    for (int i = 2; i <= 1000; i++) {
        for (int k = 1; k <= K; k++) {
            dp[i][k] = dp[__builtin_popcountll(i)][k-1];
        }
    }
    ans += dp[1][K-1] * (rec(0, 1, 0) - 1);
    for (int i = 2; i <= 1000; i++) {
        ans += (dp[i][K-1] * rec(0, i, 0)) % mod;
        ans %= mod;
    }
    cout << ans << endl;

}