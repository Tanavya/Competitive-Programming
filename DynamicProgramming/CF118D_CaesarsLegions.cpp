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

const int mod = (int) 1e8;
ll dp[107][107][10][2];
int N1, N2, K1, K2;

ll rec(int i, int j, int k, int t) {


    if (i > N1 || j > N2)
        return 0;
    if (t == 0 && k > K1)
        return 0;
    if (t == 1 && k > K2)
        return 0;

    if (i == N1 && j == N2)
        return 1;

    if (dp[i][j][k][t] != -1)
        return dp[i][j][k][t];

    ll ret = 0;
    if (t == 0) ret = rec(i+1, j, k+1, 0) + rec(i, j+1, 1, 1);
    else ret = rec(i+1, j, 1, 0) + rec(i, j+1, k+1, 1);
    ret %= mod;
    return dp[i][j][k][t] = ret;

}

int main() {
    cin >> N1 >> N2 >> K1 >> K2;
    memset(dp, -1, sizeof(dp));
    cout << rec(0, 0, 0, 0) << endl;
}