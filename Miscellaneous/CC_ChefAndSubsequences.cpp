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
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip> 
using namespace std;
 
 
#define debug(x) cout << x << endl;
#define debugV(v) for (auto x : v) cout << x << " "; cout << endl;
#define debug2(x,y) cout << x << " " << y << endl;
#define mp make_pair
#define pb push_back
 
typedef long long int ll;
typedef long double ld;
typedef std::pair <int, int> ii;
typedef std::vector <int> vi;
typedef std::vector <ll> vll;
const int INF = int(1e9);
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
using namespace std;

inline bool cmp(long double a, long double b) {
    if (fabs(a-b) < EPS) return true;
    else return a <= b;
}
ll K;
inline bool isOverflow(ll a, ll b) {
    //return !cmp(log10(a) + log10(b), log10(K));
    return b > K/a;
}
int main() {

    int N;
    scanf("%d %lld", &N, &K);
    ll A[N];
    int mid = N/2;
    vector <ll> first_half, second_half;
    for (int i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
    }
    //sort(first_half.begin(), first_half.end());
    //sort(second_half.begin(), second_half.end());
    int ans = 0;

    for (int mask = 1; mask < (1 << mid); mask++) {
        ll prod1 = 1, prod2 = 1;
        for (int i = 0; i < mid; i++) {
            if (mask & (1 << i)) {
                if (!isOverflow(prod1, A[i])) {
                    prod1 *= A[i];
                }
                else {
                    prod1= 0;
                    break;
                }
            }
        }
        if (prod1) {
            first_half.pb(prod1);
            ans++;
        }
    }

    for (int mask = 1; mask < (1 << (mid + ((N%2) == 1 ? 1 : 0))); mask++) {
        ll prod2 = 1;
        for (int i = mid; i < N; i++) {
            if ((mask << mid) & (1 << i)) {
                if (!isOverflow(prod2, A[i])) {
                    prod2 *= A[i];
                }
                else {
                    prod2 = 0;
                    break;
                }
            }
        }
        if (prod2) {
            second_half.pb(prod2);
            ans++;
        }
    }
    sort(first_half.begin(), first_half.end());
    sort(second_half.begin(), second_half.end());
    //debugV(first_half); debugV(second_half);
    //debug(ans);
    for (ll curr : first_half) {
        assert(curr <= K);
        auto it = upper_bound(second_half.begin(), second_half.end(), K/curr);
        if (it != second_half.begin()) {
            it = prev(it);
            ans += distance(second_half.begin(), it) + 1;
            assert(*it * curr <= K);
            //debug(*it);
            //cout << curr << " " << K/curr << " "  << it - second_half.begin() + 1 << endl;

        }
    }
    printf("%d\n", ans);
}