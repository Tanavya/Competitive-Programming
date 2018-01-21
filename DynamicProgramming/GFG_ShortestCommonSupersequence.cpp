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

const int maxn = 1007;
int dp[maxn][maxn], N, M;
string A, B;

int rec(int i, int j) {

    if (i == N && j == M)
        return 0;

    if (i == N || j == M)
        return max(N - i, M - j);

    if (dp[i][j] != -1)
        return dp[i][j];

    int ret = INF;

    if (A[i] == B[j]) {
        ret = 1 + rec(i+1, j+1);
    }
    else {
        ret = min(ret, 1 + min(rec(i+1, j), rec(i, j+1)));
    }
    return dp[i][j] = ret;
}

int main () {
    int T;
    scanf("%d", &T);
    while (T--) {
        memset(dp, -1, sizeof(dp));
        cin >> A >> B;
        N = (int) A.size();
        M = (int) B.size();
        printf("%d\n", rec(0, 0));
    }
}