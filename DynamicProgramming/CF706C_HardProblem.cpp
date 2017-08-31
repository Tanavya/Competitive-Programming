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
typedef std::pair <int, int> ii;
typedef std::vector <int> vi;
typedef std::vector <ll> vll;
const int INF = int(1e9);
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
using namespace std;

int main() {

    int N;
    scanf("%d", &N);
    vector <string> A(N);
    vi E(N);
    vector <vll> dp(N, vll(2, INF64));
    for (int i = 0; i < N; i++) {
        scanf("%d", &E[i]);
    }
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < N; i++) {
        if (i == 0) {
            dp[i][0] = 0;
            dp[i][1] = E[i];
        }
        else {
            string prev = A[i-1], prevR = A[i-1], curr = A[i], currR = A[i];
            reverse(prevR.begin(), prevR.end());
            reverse(currR.begin(), currR.end());
            if (prev <= curr) dp[i][0] = min(dp[i][0], dp[i-1][0]);
            if (prevR <= curr) dp[i][0] = min(dp[i][0], dp[i-1][1]);
            if (prev <= currR) dp[i][1] = min(dp[i][1], dp[i-1][0] + E[i]);
            if (prevR <= currR) dp[i][1] = min(dp[i][1], dp[i-1][1] + E[i]);
        }
    }
    ll ans = min(dp[N-1][0], dp[N-1][1]);
    printf("%lld\n", ans == INF64 ? -1 : ans);
}