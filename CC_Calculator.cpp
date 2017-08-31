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
 
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << endl;
#define debug(x) cout << x << endl;
#define debug2(x,y) cout << x << " " << y << endl;
typedef long long int ll;
typedef long double ld;
typedef std::pair <int, int> ii;
typedef std::vector <int> vi;
typedef std::vector <ll> vll;
const int INF = int(1e9);
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
using namespace std;
 
ll N, B;
ll f(ll x) {
    ll y = N - B * x;
    ll ret = x*y;
    if (ret < 0) return -INF64;
    else return ret;
}

int main() {
    
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%lld %lld", &N, &B);
        //y + Bx <= N
        if (N < B) {
            cout << 0 << endl; 
            continue;
        }
        ll low = 0, hi = (N/B) + 1, mid, ans;
        for (int i = 0; i <= 100; i++) {
            mid = (low + hi)/2;
            ll p = f(mid-1);
            ll q = f(mid);
            ll r = f(mid+1);
            if (p > q && q > r) hi = mid;
            else if (p < q && q < r) low = mid;
            else break;
        }
        cout << f(mid) << endl;
    }

}