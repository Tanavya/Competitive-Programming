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

const int maxn = (int) 1e5+10;
int B[maxn], optk[maxn][107], dp[maxn][107], N;

void calc(int i, int l, int r) {
    if (l > r) return;
    if (l == 1) optk[i][l-1] = 100;
    if (r == B[i]) optk[i][r+1] = 1;
    int m = (l+r)/2;
    dp[i][m] = -INF;
    for (int k = optk[i][r+1]; k <= optk[i][l-1] && k <= B[i-1]; k++) {
        assert(k >= 1);
        int val = dp[i-1][k] + abs(k - m);
        if (val > dp[i][m]) {
            dp[i][m] = val;
            optk[i][m] = k;
        }
    }
    calc(i, l, m-1);
    calc(i, m+1, r);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        for (int i = 1; i <= N; i++) scanf("%d", &B[i]);
        /*
        scanf("%d", &B[1]);
        for (int i = 2; i <= N; i++) {
            for (int j = 1; j <= 100; j++) {
                dp[i][j] = -INF;
                optk[i][j] = 0;
            }
            scanf("%d", &B[i]);
            calc(i, 1, B[i]);
        }
        int best = 0;
        for (int i = 1; i <= 100; i++) {
            best = max(best, dp[N][i]);
        }
        printf("%d\n", best);*/
        memset(dp, 0, sizeof(dp));
        //0->reduced to 1
        //1->kept same
        for (int i = 2; i <= N; i++) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + abs(1-B[i-1]));
            dp[i][1] = max(dp[i-1][0] + abs(1-B[i]), dp[i-1][1] + abs(B[i]-B[i-1]));
        }
        printf("%d\n", max(dp[N][0], dp[N][1]));
    }
}
/*
1
5
10 1 10 1 10

1
5
1 1 1 1 1
 */