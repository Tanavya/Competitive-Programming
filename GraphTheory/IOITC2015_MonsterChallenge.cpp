#include <iostream>
#include <stdio.h>
#include <assert.h>
#include <vector>
#include <cstring>

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

using namespace std;

const int maxn = 50007, INF = (int) 1e9;
int N, A[maxn], dp[maxn][2][1<<4][1<<4], nxt[maxn];
bool isPrime[10];

inline int f(int p, int q) {
    if (p == 0) return 0;
    if (q % p == 0) return 0;
    return p % (q % p);
}

inline bool adj(int u, int v) {
    if (u > v) swap(u, v);
    if (u == v) return false;
    return v <= nxt[u];
}

inline bool check(int u, int v, int msk) {
    assert(u < v);
    int diff = v-u-1;
    return (msk & (1 << diff)) > 0;
}

int rec(int i, bool taken, int msk_before, int msk_nxt) {
    if (i == N+1) return 0;
    assert(msk_before < (1 << 4));
    assert(msk_nxt < (1 << 4));
    int &ret = dp[i][taken][msk_before][msk_nxt];
    if (ret != -1)
        return ret;
    ret = -INF;
    int cnt = 0;
    for (int j = i+1; j <= i+4 && j <= N; j++) {
        if (adj(i, j) && check(i, j, msk_nxt)) cnt++;
    }
    for (int j = i-1; j >= i-4 && j >= 1; j--) {
        if (adj(i, j) && check(i-5, j, msk_before)) cnt++;
    }
    if (!taken || isPrime[cnt]) {
        //consider taking i+1 because satisfies prime condition for i
        //or you haven't taken i in the first place
        ret = max(ret, taken + rec(i+1, check(i, i+1, msk_nxt), (msk_before >> 1) | (taken << 3), msk_nxt >> 1));
        ret = max(ret, taken + rec(i+1, check(i, i+1, msk_nxt), (msk_before >> 1) | (taken << 3), (msk_nxt >> 1) | (1 << 3)));
    }
    return ret;
}

int main() {
    isPrime[2] = isPrime[3] = isPrime[5] = isPrime[7] = true;
    memset(dp, -1, sizeof(dp));
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &A[i]);
    }
    for (int i = 1; i <= N; i++) {
        int x = A[i];
        nxt[i] = i;
        for (int j = i+1; j <= N && x; j++) {
            x = f(x, A[j]);
            if (x) {
                nxt[i] = j;
            }
        }
        assert(nxt[i] - i <= 4);
    }
    int ans = 0;
    for (int i = 0; i < (1 << 4); i++) {
        ans = max(ans, max(rec(1, false, 0, i), rec(1, true, 0, i)));
    }
    printf("%d\n", ans);
}