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

int N, P, A[307], dp[307][307][37], dp2[307][37], pre[307][37];

int main() {
    scanf("%d %d", &N, &P);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &A[i]);
    }
    //for (int i = 0; i < 307; i++) for (int j = 0; j < 307; j++) for (int k = 0; k < 37; k++) dp[i][j][k] = INF;
    //for (int i = 0; i < 307; i++) for (int p = 0; p < 37; p++) dp2[i][p] = INF;
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= i; j++) {
            for (int p = 0; p <= P; p++) {
                if (!i) {
                    dp[i][j][p] = 0;
                    dp2[i][p] = 0;
                }
                else if (!j) {
                    dp[i][j][p] = dp2[i][p] = INF;
                }
                else if (!p) {
                    dp[i][j][p] = INF;
                    dp2[i][p] = INF;
                }
                else {
                    int x = 0;
                    for (int k = j; k <= i; k++) {
                        if (p > 1) x += min(A[k] - A[j], A[i] - A[k]);
                        else x += A[i] - A[k];
                    }
                    if (p == 1) dp[i][j][p] = dp2[j-1][p-1] + x;
                    else dp[i][j][p] = dp2[j][p-1] + x;
                    if (dp[i][j][p] < dp2[i][p]) {
                        dp2[i][p] = dp[i][j][p];
                        pre[i][p] = j;
                    }
                }
                //printf("dp[%d][%d][%d] = %d\n", i, j, p, dp[i][j][p]);
            }
        }
    }

    int ans = INF, start = -1;
    for (int i = 1; i <= N; i++) {
        int curr = dp2[i][P];
        for (int j = i+1; j <= N; j++) {
            curr += A[j] - A[i];
        }
        if (curr < ans) {
            ans = curr;
            start = i;
        }
    }
    cout << ans << endl;

    int x = start;
    vi soln;
    int p = P;
    while (pre[x][p] != 0) {
        soln.pb(x);
        x = pre[x][p];
        p--;
    }
    while (!soln.empty()) {
        cout << A[soln.back()] << " ";
        soln.pop_back();
    }
    cout << endl;

}