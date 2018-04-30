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

const int INF = int(1e9);
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
using namespace std;

const int maxn = (int)2e6+10;
int N, H, V[1<<22], C[1<<22], b, dp[maxn][22];
inline int left(int x) { return (x << 1); }
inline int right(int x) { return (x << 1) + 1; }


int main() {
    scanf("%d", &H);
    int N = (1<<H)-1;
    for (int i = 1; i <= N; i++)
        scanf("%d", &V[i]);
    V[0] = INF;
    for (int i = 1; i <= N; i++)
        scanf("%d", &C[i]);
    scanf("%d", &b);
    for (int n = N; n >= 1; n--) {
        int anc = n;
        for (int k = 0; k <= H; k++, anc /= 2) {
            int val = V[anc];
            if (n * 2 <= N) {
                int l = dp[n * 2][k + 1], r = dp[n * 2 + 1][k + 1];
                if (V[n * 2] <= val)
                    l = min(l, dp[n * 2][0]);
                if (V[n * 2 + 1] <= val)
                    r = min(r, dp[n * 2 + 1][0]);
                dp[n][k] += l + r;
            }
            if (val != V[n]) dp[n][k] += C[n];
            if (!anc) break;
        }
    }
    printf("%d\n", min(dp[1][0], dp[1][1]));
}
/*
2
2 3 3
3 1 1
0
 */