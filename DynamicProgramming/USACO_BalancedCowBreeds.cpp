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

const int maxn = (int) 1e3+10, mod = 2012;
int A[maxn], O[maxn], dp[maxn][maxn];
int main() {
    string inp;
    cin >> inp;
    int N = (int)inp.size();
    for (int i = 0; i < N; i++) {
        if (inp[i] == '(') A[i] = 1;
        else A[i] = -1;
        if (i) O[i] = O[i-1];
        O[i] += A[i];
    }

    for (int i = 0; i < N; i++) {
        for (int a = 0; a < maxn; a++) {
            int b = O[i] - a;
            if (b < 0) continue;
            if (!i) {
                dp[i][a] = 1;
                continue;
            }
            if (A[i] == 1) {
                if (a > 0) dp[i][a] += dp[i-1][a-1];
                if (b > 0) dp[i][a] += dp[i-1][a];
            }
            else {
                dp[i][a] = dp[i-1][a+1] + dp[i-1][a];
            }
            dp[i][a] %= mod;
        }
    }
    cout << dp[N-1][0] << endl;
}