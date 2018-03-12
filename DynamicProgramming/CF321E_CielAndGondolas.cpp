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

const int maxn = 4007, maxk = 807;
int N, K, dp[maxk][maxn], opti[maxk][maxn], A[maxn][maxn], S[maxn][maxn];

#define gc getchar
void scanint(int &x) {
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

inline int w(int i, int j) {
    return (S[j][j] + S[i][i] - S[i][j] - S[j][i]) / 2;
}

void calc(int k, int l, int r) {
    if (l > r) return;
    if (l == 1) opti[k][l-1] = 0;
    if (r == N) opti[k][r+1] = N;
    int m = (l+r)/2;
    dp[k][m] = INF;
    for (int i = opti[k][l-1]; i <= opti[k][r+1]; i++) {
        int val = dp[k-1][i] + w(i, m);
        if (val < dp[k][m]) {
            dp[k][m] = val;
            opti[k][m] = i;
        }
    }
    if (l != r) {
        calc(k, m + 1, r);
        calc(k, l, m - 1);
    }
}

int main() {
    scanint(N);
    scanint(K);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanint(A[i][j]);
            A[i][j] += A[i][j-1];
            S[i][j] = A[i][j] + S[i-1][j];
        }
        dp[0][i] = INF;
    }
    dp[0][0] = 0;
    for (int k = 1; k <= K; k++) {
        calc(k, 1, N);
    }
    printf("%d\n", dp[K][N]);
}