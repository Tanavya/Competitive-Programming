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
typedef unsigned long long int ull;
typedef std::pair <int, int> ii;
typedef std::vector <int> vi;
typedef std::vector <ll> vll;
const int INF = int(1e9);
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
using namespace std;

int N, M, dp[3007][107][107];
vi A, B;

int rec(int i, int j, int k) {
    /*
    if (i < 0 || j < 0 || k < 0) assert(false);
    int &ret = dp[i][j][k];
    if (ret != -1) return ret;
    ret = max(A[i], B[k]);
    if (i && j) ret = max(ret, rec(i-1, j-1, k) + A[i]);
    if (i-1 > 0) ret = max(ret, rec(i-2, j, k) + A[i]);
    if (j && k) ret = max(ret, rec(i, j-1, k-1) + B[k]);
    if (i && k) ret = max(ret, rec(i-1, j, k-1) + B[k]);
    printf("dp[%d][%d][%d] = %d\n", i, j, k, dp[i][j][k]);
    return ret;
    */
    int &ret = dp[i][j][k];
    if (ret != -1) return ret;
    ret = 0;
    if (i < N) ret = A[i];
    if (i+1 <= N && j+k+1 <= M) ret = max(rec(i+1, j, k+1) + B[k], rec(i+1, j+1, k) + A[i]);
    if (i+2 <= N && j+k <= M) ret = max(ret, rec(i+2, j, k) + A[i]);
    if (i+1 <= N && j+k <= M) ret = max(ret, rec(i+1, j, k));
    if (j+k+2 <= M) ret = max(ret, rec(i, j+1, k+1) + B[k]);
    return ret;
}

int main() {

    scanf("%d", &N);
    A.resize(N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    scanf("%d", &M);
    B.resize(M);
    for (int i = 0; i < M; i++) {
        scanf("%d", &B[i]);
    }
    //sort(B.begin(), B.end());
    sort(B.rbegin(), B.rend());
    memset(dp, -1, sizeof(dp));
    //cout << rec(N-1, M-1, M-1) << endl;
    cout << rec(0, 0, 0) << endl;
}

/*
5
10
12
6
14
7
3
1
8
2

5
10
2
10
2
10
0
*/