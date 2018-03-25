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
 
const int MOD = 1e9 + 7;
ll dp[60][131][131];
int N;
vi A;
ll rec(int i, int a, int b) {
    ll &ret = dp[i][a][b];
    if (ret != -1) return ret;
    ret = 0;
    if (i+1 < N) ret = rec(i+1, b, A[i+1]);
    if (a && b) {
        int m = min(a, b);
        for (int x = 1; x <= m; x++) {
            if (i+1 >= N) ret = (ret + 1 + rec(i+1, b-x, x)) % MOD;
            else ret = (ret + 1 + rec(i+1, b-x, A[i+1]+x)) % MOD;
        }
    }
    return (ret % MOD);
}
 
int main() {
 
    int T;
    scanf("%d", &T);
    while (T--) {
        
        scanf("%d", &N);
        int tmp;
        A.clear();
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < N; i++) {
            scanf("%d", &tmp);
            A.pb(tmp);
        }
        if (N > 1) cout << 1+rec(1,A[0],A[1]) << endl;
        else cout << 1 << endl;
    }
}
