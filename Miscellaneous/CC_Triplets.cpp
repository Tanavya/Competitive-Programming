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

#define MOD 1000000007

inline ll mult(ll a, ll b) {
    return ((a % MOD) * (b % MOD)) % MOD;
}

int main() {
    int T, p, q, r;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &p, &q, &r);
        vll A(p), B(q), C(r), preA(p, 0), preC(r, 0);
        for (int i = 0; i < p; i++) {
            scanf("%lld", &A[i]);
        }
        for (int i = 0; i < q; i++) {
            scanf("%lld", &B[i]);
        }
        for (int i = 0; i < r; i++) {
            scanf("%lld", &C[i]);
        }
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        sort(C.begin(), C.end());
        for (int i = 0; i < p; i++) {
            if (i) preA[i] = (A[i] + preA[i-1]) % MOD;
            else preA[i] = A[i];
        }
        for (int i = 0; i < r; i++) {
            if (i) preC[i] = (C[i] + preC[i-1]) % MOD;
            else preC[i] = C[i];
        }
        //X <= Y >= Z
        //(X+Y)(Y+Z) = XY + XZ + YZ + Y^2
        vi AB(q, -1), CB(q, -1);
        for (int i = 0, j = 0; i < q && j < p; i++) {
            while (A[j] <= B[i]) {
                AB[i] = j;
                j++;
                if (j == p) break;
            }
            if (j) j--; 
        }
        for (int i = 0, j = 0; i < q && j < r; i++) {
            while (C[j] <= B[i]) {
                CB[i] = j;
                j++;
                if (j == r) break;
            }
            if (j) j--;
        }
        //print(AB);
        //print(CB);
        ll ans = 0;
        for (int i = 0; i < q; i++) {
            int ix = AB[i], iz = CB[i];
            if (ix != -1 && iz != -1) {
                ans = (ans + mult(mult(preA[ix], B[i]), iz+1)) % MOD;
                //debug((preA[ix] * B[i] * (iz+1)));
                ans = (ans + mult(mult(preC[iz], B[i]), ix+1)) % MOD;
                //debug((preC[iz] * B[i] * (ix+1)));
                ans = (ans + mult(preA[ix], preC[iz])) % MOD;
                //debug((preA[ix] * preC[iz]));
                ans = (ans + mult(mult(mult(B[i], B[i]), (iz+1)), (ix+1))) % MOD;
                //debug((B[i] * B[i] * (iz+1) * (ix+1)));
            }
        }
        printf("%lld\n", ans % MOD);

    }
}