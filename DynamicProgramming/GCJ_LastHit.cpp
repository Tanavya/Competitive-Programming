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

const int maxn = 107;
/*
int P, Q, N, H[maxn], G[maxn], memo[maxn][207][1007];
int rec(int i, int rem_hp, int extra_shots) {
    if (rem_hp <= 0 && i + 1 == N) return 0;
    if (rem_hp <= 0) return rec(i + 1, H[i + 1], extra_shots);
    if (memo[i][rem_hp][extra_shots] != -1)
        return memo[i][rem_hp][extra_shots];
    int &ret = memo[i][rem_hp][extra_shots];
    ret = rec(i, rem_hp - Q, extra_shots + 1);
    if (extra_shots > 0) {
        int gold = (rem_hp <= P) ? G[i] : 0;
        ret = max(ret, gold + rec(i, rem_hp - P, extra_shots - 1));
    }
    return ret;
}
int main() {
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);


    int T, t = 1;
    scanf("%d", &T);

    while (T--) {
        scanf("%d %d %d", &P, &Q, &N);
        for (int i = 0; i < N; i++) {
            scanf("%d %d", &H[i], &G[i]);
        }

        memset(memo, -1, sizeof(memo));
        printf("Case #%d: %d\n", t, rec(0, H[0], 1));
        t++;
    }
}
*/

int P, Q, N, H[maxn], G[maxn], dp[maxn][maxn*maxn];

void calc (int idx, bool kill, int &d, int &m) {
    if (kill) {
        if (H[idx] % Q == 0) m = H[idx]/Q-1;
        else m = H[idx]/Q;
        d = (int)ceil((H[idx]-Q*m)/float(P));
    }
    else {
        d = 0;
        m = (int)ceil(H[idx]/float(Q));
    }
    //cout << d << " " << m << endl;
}

int rec(int idx, int moves) {
    if (moves < 0) return -INF;
    if (idx == N) return 0;
    if (dp[idx][moves] != -1)
        return dp[idx][moves];
    int &ret = dp[idx][moves];
    //kill
    int d, m;
    calc(idx, true, d, m);
    ret = max(ret, rec(idx + 1, m-d+moves) + G[idx]);
    //ignore
    calc(idx, false, d, m);
    ret = max(ret, rec(idx + 1, m-d+moves));
    return ret;
}

int main() {

    freopen("inp2.txt", "r", stdin);
    freopen("out2.txt", "w", stdout);


    int T, t = 1;
    scanf("%d", &T);

    while (T--) {
        scanf("%d %d %d", &P, &Q, &N);
        for (int i = 0; i < N; i++) {
            scanf("%d %d", &H[i], &G[i]);
        }

        memset(dp, -1, sizeof(dp));
        printf("Case #%d: %d\n", t, rec(0, 1)); //Important observation (why I was getting WA earlier) : you start with 1 extra move!!!!
        t++;
    }
}