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

const int maxn = (int)1e5+10;
const int mod = (int)1e9+7;
string S, T;
int N, M;
int A[maxn], B[maxn];

ll dp[maxn], ans[maxn], pref[maxn];
void KMP() {
    //Find occurrences of T in S
    int i = 0, j = -1;
    B[0] = -1;
    while (i < M) {
        while (j >= 0 && T[i] != T[j]) j = B[j];
        i++; j++;
        B[i] = j;
    }
    i = 0, j = 0;
    while (i < N) {
        while (j >= 0 && S[i] != T[j])  j = B[j];
        i++; j++;
        if (j == M) {
            A[i-1] = true;
            j = B[j];
        }
    }
}

int main() {
    cin >> S >> T;
    N = S.size();
    M = T.size();
    KMP();
    for (int i = 1; i <= N; i++) {
        if (A[i-1]) {
            //cout << i << endl;
            dp[i] = (i-M+1 + pref[i-M]) % mod;
        }
        else {
            dp[i] = dp[i-1];
        }
        ans[i] = (ans[i-1] + dp[i]) % mod;
        pref[i] = (pref[i-1] + ans[i]) % mod;
    }
    cout << ans[N] << endl;
}