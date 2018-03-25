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

const int mod = (int) 1e9 + 7;

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll power(ll x, ll y) {
    if (y == 0)
        return 1;
    ll p = power(x, y/2) % mod;
    p = (p * p) % mod;
    return (y%2 == 0) ? p : (x * p) % mod;
}

ll modInverse(ll a) {
    return power(a, mod-2);
}
struct fraction {
    //fraction of the form p*sqrt(irr)/q
    ll p, q, irr;
    fraction() {}
    fraction(ll P, ll Q, ll IRR): p(P), q(Q), irr(IRR) {
        p = (p + mod) % mod;
        q = (q + mod) % mod;
    }
};
fraction COS[61], SIN[61], dpCOS[61], dpSIN[61];

inline fraction mult (fraction a, fraction b) {
    if (a.irr == b.irr)
        return fraction{((a.p * b.p) % mod) * a.irr, a.q * b.q, 1};
    else
        return fraction{a.p * b.p, a.q * b.q, a.irr * b.irr};

}
inline fraction add (fraction a, fraction b) {
    return fraction{((a.p * b.q) % mod) + ((a.q * b.p) % mod), a.q * b.q, a.irr};
}
inline fraction sub (fraction a, fraction b) {
    return fraction{((a.p * b.q) % mod) - ((a.q * b.p) % mod), a.q * b.q, a.irr};
}

int main() {
    int TC;
    scanf("%d", &TC);
    while (TC--) {
        ll l, d, t;
        scanf("%lld %lld %lld", &l, &d, &t);

        COS[0] = fraction(d, l, 1);
        for (int i = 1; i < 61; i++) {
            ll p = COS[i-1].p, q = COS[i-1].q;
            COS[i] = fraction(2*p*p - q*q, q*q, 1);
        }
        SIN[0] = fraction(1,l,(l*l-d*d) % mod);
        for (int i = 1; i < 61; i++) {
            SIN[i] = fraction(2*SIN[i-1].p*COS[i-1].p, SIN[i-1].q*COS[i-1].q, SIN[i-1].irr);
        }
        vll positions;
        for (ll i = 0; i < 61; i++) {
            if ((1LL << i) & t)
                positions.pb(i);
        }
        dpCOS[0] = COS[positions[0]];
        dpSIN[0] = SIN[positions[0]];
        for (int i = 1; i < positions.size(); i++) {
            dpCOS[i] = sub(mult(COS[positions[i]], dpCOS[i-1]), mult(SIN[positions[i]], dpSIN[i-1]));
            dpSIN[i] = add(mult(SIN[positions[i]], dpCOS[i-1]), mult(COS[positions[i]], dpSIN[i-1]));
        }
        fraction D = mult(fraction(l, 1, 1), dpCOS[positions.size()-1]);
        ll p = D.p % mod, q = D.q;
        ll r = modInverse(q);
        ll ans = (p * r) % mod;
        while (ans < 0) ans += mod;
        printf("%lld\n", ans);
    }
}