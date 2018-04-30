#include <vector>
#include <algorithm>
#include <stdio.h>
#include <assert.h>
//#include <iostream>

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
typedef std::vector <ii> vii;
typedef std::vector <ll> vll;
typedef std::vector <ld> vld;

const int INF = int(1e9)+10;
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
using namespace std;

struct PT {
    double x, y;
    PT() {}
    PT(double x, double y) : x(x), y(y) {}
    PT(const PT &p) : x(p.x), y(p.y) {}
    PT operator + (const PT &p) const { return PT(x+p.x, y+p.y); }
    PT operator - (const PT &p) const { return PT(x-p.x, y-p.y); }
    PT operator * (double c) const { return PT(x*c, y*c ); }
    PT operator / (double c) const { return PT(x/c, y/c); }
};

int main() {
    PT src;
    pair <double, double> mirror;
    scanf("%lf %lf", &src.x, &src.y);
    scanf("%lf %lf", &mirror.fi, &mirror.se);
    int S, C;
    vector <pair <PT, PT>> screens;
    scanf("%d %d", &S, &C);
    for (int i = 0; i < S; i++) {
        PT a, b;
        scanf("%lf %lf %lf", &a.x, &a.y, &b.y);
        b.x = a.x;
        screens.pb(mp(a, b));
    }
    vector <PT> crystals(C);
    vi lit;
    for (int i = 0; i < C; i++) {
        scanf("%lf %lf", &crystals[i].x, &crystals[i].y);
        double m = (crystals[i].x * src.y + src.x * crystals[i].y) / (src.y + crystals[i].y);
        if (m >= mirror.fi && m <= mirror.se)
            lit.pb(i+1);
    }
    printf("%d\n", (int)lit.size());
    for (int c : lit) printf("%d\n", c);
}
/*
-70 70
-35 35
3 4
-28 0 10
56 63 84
42 7 21
38 70
70 70
70 63
49 14
 */