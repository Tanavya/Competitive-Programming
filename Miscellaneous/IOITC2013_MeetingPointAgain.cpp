#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <assert.h>

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

const int INF = int(1e9)+10;
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
using namespace std;

const int mod = (int)1e9+7;
int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    vll X[3];
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < K; k++) {
            ll x;
            scanf("%lld", &x);
            X[k].pb(x);
        }
    }
    sort(all(X[0]));
    sort(all(X[1]));
    sort(all(X[2]));
    ll ans = 1;
    if (N % 2 == 0) {
        int mid = (N-1)/2;
        for (int k = 0; k < K; k++) {
            ll tmp = (((X[k][mid+1] % mod) - (X[k][mid] % mod) + 1) % mod);
            while (tmp < 0) tmp += mod;
            tmp %= mod;
            ans *= tmp;
            ans %= mod;
        }
    }
    printf("%lld\n", ans);
}
/*
4 2
0 0
3 3
2 1
1 2
 */