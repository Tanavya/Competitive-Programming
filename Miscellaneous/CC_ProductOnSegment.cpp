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


#define MAX(a,b) ((a)>(b)?(a):(b))
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << endl;
#define debug(x) cout << x << endl;
#define debug2(x,y) cout << x << " " << y << endl;
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

const int maxn = (int)1e6+10;
ll A[maxn], prefix[maxn], x;
int b, T, N, P, Q, L, R;
int B[maxn];

ll inverse[maxn];


ll power(ll x, int y, int m) {
    if (y == 0)
        return 1;
    ll p = power(x, y/2, m) % m;
    p = (p * p) % m;
    return (y%2 == 0)? p : (x * p) % m;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        x = L = R = 0;
        scanf("%d %d %d", &N, &P, &Q);
        for (int i = 0; i < N; i++) {
            scanf("%lld", &A[i]);
            if (i) prefix[i] = (prefix[i-1] * A[i]) % P;
            else prefix[i] = A[i];
            inverse[i] = power(prefix[i], P-2, P);
        }
        for (int i = 0; i < Q/64+2; i++) {
            scanf("%d", &B[i]);
        }
        for (int i = 0; i < Q; i++) {
            if (i % 64 == 0) {
                L = (B[i/64] + x) % N;
                R = (B[i/64+1] + x) % N;
            }
            else {
                L = (L+x)%N;
                R = (R+x)%N;
            }
            if (L > R) swap(L, R);
            if (L) x = prefix[R] * inverse[L-1];
            else x = prefix[R];
            x = (x+1)%P;
        }
        printf("%lld\n", x);
    }
}