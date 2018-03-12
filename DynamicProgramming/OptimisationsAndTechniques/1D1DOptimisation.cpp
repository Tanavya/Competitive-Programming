//IOI 2002 Batch Scheduling
//https://sites.google.com/site/ubcprogrammingteam/news/1d1ddynamicprogrammingoptimization-parti
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

const int maxn = 10007;
int N, optk[maxn];
ll S, F[maxn], T[maxn], Tsum[maxn], Fsum[maxn], dp[maxn];

//must satisfy QI
inline ll w(int i, int j) {
    //i is excluded, so basically i+1 to j
    return S * (Fsum[N] - Fsum[i]) + Tsum[j] * (Fsum[j] - Fsum[i]);
}
ll get(int i, int x) {
    return dp[i] + w(i, x);
}
bool better(int opt1, int opt2, int x) {
    return get(opt1, x) <= get(opt2, x);
}

int main() {
    scanf("%d", &N);
    scanf("%lld", &S);
    for (int i = 1; i <= N; i++) {
        scanf("%lld %lld", &T[i], &F[i]);
        Tsum[i] = Tsum[i-1] + T[i];
        Fsum[i] = Fsum[i-1] + F[i];
    }
    vector <ii> segments = {mp(0, 0)}; //start pos, i
    for (int x = 1; x <= N; x++) {
        int k = (--upper_bound(all(segments), make_pair(x, INF)))->second;
        dp[x] = get(k, x);
        int newi = x;
        while (!segments.empty()) {
            int y = segments.back().fi, oldi = segments.back().se;
            if (y <= x) break;
            //checking if optimum value of i for y can be newi
            if (better(newi, oldi, y)) segments.pop_back();
            else break;
        }
        if (!segments.empty()) {
            //binary search to find where to insert newi
            //newi inserted in first position where newi is better than oldi
            //might be possible there is no place for newi
            int oldi = segments.back().se;
            int L = segments.back().fi, R = N+1; //important: R = N+1 not N
            assert(!better(newi, oldi, L) || L <= x);
            L++;
            while (L != R) {
                int mid = (L+R)/2;
                if (better(newi, oldi, mid)) {
                    R = mid;
                }
                else {
                    L = mid+1;
                }
            }
            assert(L == R);
            if (L != N+1)
                segments.pb(mp(L, newi));
        }
    }
    //for (int i = 1; i <= N; i++) cout << dp[i] << " ";cout << endl;
    printf("%lld\n", dp[N]);
}