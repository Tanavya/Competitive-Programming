#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <assert.h>
#include <queue>
#include <bitset>
#include <map>
#include <iostream>

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << endl;
#define debug(x) cout << x << endl;
#define debug2(x,y) cout << x << " " << y << endl;
#define debug3(x,y,z) cout << x << " " << y << " " << z << endl;
#define debug4(a,b,c,d) cout << a << " " << b << " " << c << " " << d << endl;
#define debug5(a,b,c,d,e) cout << a << " " << b << " " << c << " " << d << " " << e << endl;
#define trace(x) cout << #x << ": " << x << endl;

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

const int maxn = 31, mod = (int) 1e9+7;
ll dp1[16][2][2], dp2[16][2][2];
ll dp[1<<22][22];
int gap_count[1<<22][22], N, K;

int count(int msk, int n) {
    int cnt = 0;
    for (int i = 0; i < n-1; i++) {
        if (!i && msk & (1 << i)) cnt++;
        else if (!(msk & (1 << i)) && (msk & (1 << (i+1)))) cnt++;
    }
    return cnt;
}

void print_msk(int msk, int n) {
    for (int i = 0; i < n; i++) {
        if (msk & (1 << i)) printf("1");
        else printf("0");
    }
}

int brute() {
    for (int msk = 0; msk < (1 << N); msk++) {
        gap_count[msk][N] = count(msk, N);
        if ((msk & (1 << 0)) && (msk & (1 << (N-1)))) gap_count[msk][N]--;
    }
    dp[0][0] = 1;
    ll ans = 0;
    for (int msk = 0; msk < (1 << N); msk++) {
        for (int k = 0; k <= K; k++) {
            if (!dp[msk][k]) continue;
            //printf("count["); print_msk(msk, N); printf("] = %d\n", gap_count[msk]);
            //printf("dp["); print_msk(msk, N); printf("][%d] = %lld\n", k, dp[msk][k]);
            assert(k >= gap_count[msk][N]);
            if (msk == (1 << N) - 1) {
                ans += dp[msk][k];
                ans %= mod;
            }
            else {
                for (int i = 0; i < N; i++) {
                    if (!(msk & (1 << i))) {
                        int nxt_msk = msk | (1 << i);
                        int nxt_k = max(k, gap_count[nxt_msk][N]);
                        if (nxt_k <= K) {
                            dp[nxt_msk][nxt_k] += dp[msk][k];
                            dp[nxt_msk][nxt_k] %= mod;
                        }
                    }
                }
            }
        }
    }
    return (int)ans;
}

inline bool check(int msk, int i) {
    return (msk & (1 << i)) > 0;
}

int main() {
    scanf("%d %d", &N, &K);
    //handle small N separately?
    //printf("%d\n", brute());

    int mid = N/2;
    int s1 = mid;
    int s2 = N-mid;
    for (int msk = 0; msk < (1 << s1); msk++) {
        gap_count[msk][s1] = count(msk, s1);
        printf("count["); print_msk(msk, s1); printf("] = %d\n", gap_count[msk][s1]);
    }
    for (int msk = 0; msk < (1 << s2); msk++) {
        gap_count[msk][s2] = count(msk, s2);
    }

    dp[0][0] = 1;
    for (int msk = 0; msk < (1 << s1); msk++) {
        for (int k = 0; k <= K; k++) {
            if (!dp[msk][k]) continue;

            int cnt = gap_count[msk][s1];
            assert(cnt <= k);
            dp1[cnt][check(msk, 0)][check(msk, s1-1)] += dp[msk][k];
            for (int i = 0; i < s1; i++) {
                if (!(msk & (1 << i))) {
                    int nxt_msk = msk | (1 << i);
                    int nxt_k = max(k, gap_count[nxt_msk][s1]);
                    if (nxt_k <= K) {
                        dp[nxt_msk][nxt_k] += dp[msk][k];
                        dp[nxt_msk][nxt_k] %= mod;
                    }
                }
            }
        }
    }

    for (int i = 0; i <= N; i++) {
        for (int a = 0; a < 2; a++) {
            for (int b = 0; b < 2; b++) {
                printf("dp[%d][%d][%d] = %lld\n", i, a, b, dp1[i][a][b]);
            }
        }
    }

    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;

    for (int msk = 0; msk < (1 << s2); msk++) {
        for (int k = 0; k <= K; k++) {
            if (!dp[msk][k]) continue;
            int cnt = gap_count[msk][s2];
            assert(cnt <= k);
            dp2[cnt][check(msk, 0)][check(msk, s2-1)] += dp[msk][k];
            for (int i = 0; i < s2; i++) {
                if (!(msk & (1 << i))) {
                    int nxt_msk = msk | (1 << i);
                    int nxt_k = max(k, gap_count[nxt_msk][s2]);
                    if (nxt_k <= K) {
                        dp[nxt_msk][nxt_k] += dp[msk][k];
                        dp[nxt_msk][nxt_k] %= mod;
                    }
                }
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i <= K; i++) {
        for (int j = 0; j <= K; j++) {
            for (int a1 = 0; a1 < 2; a1++) {
                for (int b1 = 0; b1 < 2; b1++) {
                    for (int a2 = 0; a2 < 2; a2++) {
                        for (int b2 = 0; b2 < 2; b2++) {
                            int cnt = i+j;
                            if (b1 && a2) cnt--;
                            if (a1 && b2) cnt--;
                            if (cnt >= 0 && cnt <= K) {
                                ans += dp1[i][a1][b1] * dp2[j][a2][b2];
                                ans %= mod;
                            }
                        }
                    }
                }
            }
        }
    }
    printf("%lld\n", ans);
}