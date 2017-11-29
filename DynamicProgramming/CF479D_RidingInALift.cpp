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

const int mod = (int) 1e9 + 7;
const int maxn = 5005;
int dp1[maxn][maxn], dp2[maxn][maxn];

int main() {

    int N, A, B, K;
    scanf("%d %d %d %d", &N, &A, &B, &K);
    if (A < B) {
        N = B+A-1;
        swap(A, B);
    }
    for (int k = 0; k <= K; k++) {
        for (int j = B+1; j <= N; j++) {
            int i = j-B-1;
            if (k)
                dp1[i][k] = (dp2[min(N-B-1, i*2)][k-1] - dp1[i][k-1] + mod) % mod;
            else
                dp1[i][k] = 1;
            if (i)
                dp2[i][k] = (dp2[i-1][k] + dp1[i][k]) % mod;
            else
                dp2[i][k] = dp1[i][k];
        }
    }
    cout << dp1[A-B-1][K] << endl;
}