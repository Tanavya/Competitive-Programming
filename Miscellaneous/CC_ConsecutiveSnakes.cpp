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
#include <iomanip> //cout << setprecision(node) << fixed << num

#define mp make_pair
#define pb push_back
#define x first
#define y second
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << endl;

typedef long long int ll;
typedef long double ld;
typedef std::pair <int, int> ii;
typedef std::vector <int> vi;
typedef std::vector <ll> vll;
const int INF = int(1e9);
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
using namespace std;

int N, L, A, B;
vector <int> start_pts;
ll f(double x) {
    // need to find minima of f(x)
    int currPtr = (int)x;
    ll ret = 0;
    for (int i = 0; i < N; i++) {
        ret += (ll)abs(currPtr - start_pts[i]);
        currPtr += L;
    }
    return ret;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        
        scanf("%d %d %d %d", &N, &L, &A, &B);
        start_pts.assign(N,0);
        for (int i = 0; i < N; i++) {
            scanf("%d", &start_pts[i]);
        }
        sort(start_pts.begin(), start_pts.end());
        ll ans = INF64;
        
        double left = A, right = B-L*N, leftThird, rightThird;

        while (right - left > 10) {
            leftThird = (left * 2 + right) / 3;
            rightThird = (right * 2 + left) / 3;
            //leftThird = left + (right - left) / 3;
            //rightThird = right - (right - left) / 3;
            ll f1 = f(leftThird), f2 = f(rightThird);
            if (f1 < f2) {
                right = rightThird;
                ans = min(ans, f1);
            }
            else {
                left = leftThird;
                ans = min(ans, f2);
            }
        }
        for (int i = left; i <= right; i++) {
            ans = min(ans, f(i));
        }
        cout << ans << endl;
    }
}