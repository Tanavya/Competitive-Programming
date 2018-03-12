//dynamic CHT in Data Structures folder
//Problem: SPOJ ACQUIRE
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

const int maxn = 50007;

ll dp[maxn];
vector <ii> rect;

inline ll w(int i, int j) {
    return rect[i].se * rect[j-1].fi;
}

inline ll get(int i, int x) {
    return dp[i] + w(i, x);
}

bool better(int opt1, int opt2, int x) {
    return get(opt1, x) <= get(opt2, x);
}

int main() {
    int N;
    scanf("%d", &N);
    vector <ii> A(N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &A[i].fi, &A[i].se);
    }
    sort(all(A));
    for (int i = 0; i < N; i++) {
        while (!rect.empty() && A[i].se >= rect.back().se) {
            rect.pop_back();
        }
        rect.pb(A[i]);
    }
    //height is monotonicly increasing
    //width is monotonicly decreasing
    N = (int)rect.size();
    vector <ii> segments = {mp(0, 0)}; //first pos, i
    for (int x = 1; x <= N; x++) {
        int k = (--upper_bound(all(segments), mp(x, INF)))->second;
        dp[x] = get(k, x);
        //debug3(k,x,dp[x]);
        int newi = x;
        while (!segments.empty()) {
            int y = segments.back().fi, oldi = segments.back().se;
            if (y <= x) break;
            if (better(newi, oldi, y)) segments.pop_back();
            else break;
        }
        if (!segments.empty()) {
            int L = segments.back().fi, oldi = segments.back().se;
            assert(L <= x || !better(newi, oldi, L));
            int R = N+1;
            while (L != R) {
                int mid = (L+R)/2;
                if (better(newi, oldi, mid))
                    R = mid;
                else
                    L = mid+1;
            }
            assert(L == R);
            if (L != N+1) segments.pb(mp(L, newi));
        }
        if (segments.empty()) segments.pb(mp(0, 0));
    }
    printf("%lld\n", dp[N]);
}