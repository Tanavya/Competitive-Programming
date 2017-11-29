//Smart DP trick involving switching of parameters.
//dp[i][p][q] -> 1/0 can be reformed as
//dp[i][p] -> q, where q is minimised

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

vi sections;
int N, P, Q, dp[2007][2007], w, pre[2007][2];

int cmp(int i, int x) {
    auto it = lower_bound(sections.begin(), sections.end(), sections[i] - x + 1);
    if (it == sections.begin()) return 0;
    else return (int)distance(sections.begin(), prev(it)) + 1;
}

int rec(int i, int p) {
    if (dp[i][p] != -1)
        return dp[i][p];
    int &ret = dp[i][p];
    ret = INF;
    if (i == 0) {
        return ret = 0;
    }
    if (p) ret = min(ret, rec(pre[i-1][0], p-1));
    int q = rec(pre[i-1][1], p);
    if (q + 1 <= Q) ret = min(ret, q+1);
    return ret;
}

int main() {

    scanf("%d %d %d", &N, &P, &Q);
    set <int> s;
    int x;
    for (int i = 0; i < N; i++) {
        scanf("%d", &x);
        if (s.find(x) == s.end()) {
            s.insert(x);
            sections.pb(x);
        }
    }
    if (P + Q >= N) {
        cout << 1 << endl;
        return 0;
    }
    N = (int)sections.size();
    sort(sections.begin(), sections.end());
    //print(sections);
    int L = 1, R = int(1e9) + 7, ans = -1;
    while (R - L > 0) {
        //debug2(L, R);
        w = (R+L)/2;
        memset(dp, -1, sizeof(dp));
        memset(pre, -1, sizeof(pre));
        for (int i = 0; i < N; i++) {
            pre[i][0] = cmp(i, w);
            pre[i][1] = cmp(i, w*2);
        }
        if (rec(N, P) <= Q) {
            R = w;
            ans = w;
        }
        else
            L = w+1;
    }
    cout << ans << endl;
}
