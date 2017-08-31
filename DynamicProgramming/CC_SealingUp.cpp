//Problem Link: https://www.codechef.com/LTIME44/problems/SEALUP
//Problem type: Dynamic Programming
//learning experience: freaking make sure to keep INF as 1000000000000000000LL, LONG_MAX is too less lmao ugh
//also, try not to keep 2D DP arrays and see if it can be reduced to 1D, otherwise TLE chances increase.
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <stdio.h>
#include <queue>
#include <set>
#include <cmath>
#include <assert.h>
#include <bitset>
#include <map>
#include <unordered_map>
#include <iomanip> //cout << setprecision(n) << fixed << num
 
#define MAXN 1007
#define mp make_pair
#define ii pair<int, int>
#define PI 3.14159265
#define INF 1000000000000000000LL
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << "\n";
typedef long long int ll;
using namespace std;
 
inline int calc(pair<ll,ll> a, pair<ll,ll> b) {
    return (int) ceil(sqrt( (ll)pow(a.first-b.first,2) + (ll)pow(a.second-b.second,2)));
}
int main() {
    int t, n, m;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        vector <pair<ll,ll>> points(n);
        for (int i = 0; i < n; i++) {
            scanf("%lld %lld", &points[i].first, &points[i].second);
        }
        vector <int> sides;
        for (int i = 0; i < n-1; i++) {
            sides.push_back(calc(points[i], points[i+1]));
        }
        sides.push_back(calc(points[n-1], points[0]));
        scanf("%d", &m);
        int length[m];
        ll cost[m];
        for (int i = 0; i < m; i++) {
            scanf("%d %lld", &length[i], &cost[i]);
        }
        ll MAX = 2.5e6+10;
        vector <ll> dp(MAX, INF); 
        dp[0] = 0;
        for (int i = 0; i < m; i++) {
            for (int d = length[i]; d < MAX; d++) {
                dp[d] = min(dp[d], dp[d - length[i]] + cost[i]);
            }
        }
        for (int i = MAX-2; i >= 0; i--) {
            dp[i] = min(dp[i], dp[i+1]);
        }
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ans += dp[sides[i]];
        }
        cout << ans << endl;
        
    }
} 