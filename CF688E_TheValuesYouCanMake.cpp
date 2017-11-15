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

const int maxn = 507;
int dp[maxn][maxn];
int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    vector <int> A(N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    sort(A.begin(), A.end());

    //for (int i = 0; i < N; i++) dp[i][0][0] = dp[i][A[i]][0] = dp[i][0][A[i]] = 1;

    set <int> ans;

    for (int i = 0; i < N; i++) {
        if (!i) dp[0][0] = dp[A[i]][0] = dp[0][A[i]] = 1;
        for (int j = K; j >= 0; j--) {
            for (int k = K; k >= 0; k--) {
                if (i && j+k <= K) {
                    if (j >= A[i]) dp[j][k] = max(dp[j][k], dp[j-A[i]][k]);
                    if (k >= A[i]) dp[j][k] = max(dp[j][k], dp[j][k-A[i]]);
                }
                if (j+k == K && dp[j][k]) {
                    ans.insert(j);
                    ans.insert(k);
                }
            }
        }
    }

    cout << ans.size() << endl;
    while (!ans.empty()) {
        cout << *ans.begin() << " ";
        ans.erase(ans.begin());
    }
}