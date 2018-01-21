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

const int maxn = 1e5+10, mod = 1e9+7;
int A[maxn];
ll dp[maxn], dp2[maxn];

int main() {
    map <int, int> M;
    int N, K;
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    int cnt = 1;
    int left = 0;
    dp[0] = dp2[0] = 1;
    M[A[0]]++;
    for (int i = 1; i < N; i++) {
        if (!M[A[i]])
            cnt++;
        M[A[i]]++;
        dp[i] = 1;
        while (cnt > K) {
            M[A[left]]--;
            if (!M[A[left]])
                cnt--;
            left++;
        }
        if (left - 2 >= 0)
            dp[i] = (dp2[i-1] - dp2[left-2]) % mod;
        else if (left - 1 >= 0)
            dp[i] = dp2[i-1];
        else
            dp[i] = 1 + dp2[i-1];
        dp[i] %= mod;
        if (dp[i] < 0) dp[i] += mod;
        if (i) dp2[i] = dp2[i-1];
        dp2[i] += dp[i];
        dp2[i] %= mod;
        //printf("dp[%d] = %lld\n", i, dp[i]);
    }
    printf("%lld\n", dp[N-1]);
}