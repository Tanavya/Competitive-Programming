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

const int maxn = 400007;
int P[maxn][25];
ll dp[maxn][25], W[maxn];

int main() {
    int N = 1, last = 0, Q;
    W[0] = INF64;
    for (int i = 0; i < 25; i++)
        for (int u = 1; u < maxn; u++)
            dp[u][i] = INF64;

    scanf("%d", &Q);
    while (Q--) {
        int type;
        ll p, q;
        scanf("%d %lld %lld", &type, &p, &q);
        p ^= last;
        q ^= last;
        if (type == 1) {
            int R = (int) p;
            W[++N] = q;
            if (W[R] >= W[N]) {
                P[N][0] = R;
            }
            else {
                //let NXT[u] = v be the immediate next node such that W[v] >= W[u].
                //P[u][i] gives the result of NXT[NXT[NXT...NXT[u]..]] 2^i times
                int nxt = R;
                for (int i = 24; i >= 0; i--) {
                    if (W[P[nxt][i]] < W[N]) {
                        nxt = P[nxt][i];
                    }
                }
                P[N][0] = P[nxt][0];
            }
            dp[N][0] = P[N][0] == 0 ? INF64: W[P[N][0]];
            for (int i = 1; i < 25; i++) {
                P[N][i] = P[P[N][i-1]][i-1];
                dp[N][i] = P[N][i] == 0 ? INF64 : dp[N][i-1] + dp[P[N][i-1]][i-1];
            }
        }
        else {
            int R = (int) p;
            ll X = q;
            if (W[R] > X){
                printf("%d\n", 0);
                last = 0;
            }
            else {
                X -= W[R];
                int ans = 1;
                for (int i = 24; i >= 0; i--) {
                    if (dp[R][i] <= X) {
                        ans += (1 << i);
                        X -= dp[R][i];
                        R = P[R][i];
                    }
                }
                printf("%d\n", ans);
                last = ans;
            }
        }
    }
}