//Trivial lmao

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

int dp[107][107][2], A[107], N;

int rec(int i, int j, int b) {
    if (dp[i][j][b] != -1)
        return dp[i][j][b];
    int &ret = dp[i][j][b];
    if (i + j == N) return ret = 0;
    if (b == 0) ret = max(rec(i+1, j, 1) + A[i], rec(i, j+1, 1) + A[N-j-1]);
    else ret = min(rec(i+1, j, 0), rec(i, j+1, 0));
    return ret;
}

int main() {
    scanf("%d", &N);
    int S = 0;
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
        S += A[i];
    }
    memset(dp, -1, sizeof(dp));
    int A = rec(0, 0, 0);
    cout << A << " " << S-A << endl;
}