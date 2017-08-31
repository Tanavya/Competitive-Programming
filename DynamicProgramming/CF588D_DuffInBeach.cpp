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

const int mod = 1e9 + 7;
const int maxn = 1e6+7;

int main() {
    ll N, K, L;
    scanf("%lld %lld %lld", &N, &L, &K);  
    vi A(N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    if (L >= N) K = min(K, (L%N == 0) ? L/N : (L/N + 1));
    else K = 1;
    //sort(A.begin(), A.end());
    vector <vll> dp1(K+7, vll(N+7, 0)), dp2(K+7, vll(N+7, 0));
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < N; j++) {
            if (i) dp1[i][j] = (1 + dp1[i-1][j] + dp2[i-1][j]) % mod;
            else dp1[i][j] = 1;
            if (j) dp2[i][j] = (dp2[i][j-1] + dp1[i][j]) % mod;
            else dp2[i][j] = dp1[i][j];
        }
    }
    if (L % N != 0) {
        int x = L - (N * (L/N));
        //cout << x << endl;
        vi A_last;
        for (int i = 0; i < x; i++) {
            A_last.pb(A[i]);
        }
        sort(A.begin(), A.end());
        sort(A_last.begin(), A_last.end());
        int p = 0;
        ll val = 0, sum = 0;
        bool fi = true;
        int add = 0;
        for (int i = 0; i < x; i++) {
            while (A[p] <= A_last[i] && p < N) {
                p++;
            }
            if (fi) {
                if (p-2 >= 0) add = dp2[K-2][p-2];
                fi = false;
            }
            val = (1 + dp1[K-2][p-1] + dp2[K-2][p-1]) % mod;
            sum += val;
            sum %= mod;
            //cout << val << endl;
            p--;
        }
        sum += add;
        cout << L/N-K+1 <<endl;
        cout << dp2[K-2][N-1] << endl;

        if (K == 1) cout << sum << endl;
        else if (L/N-K+1 == 1) cout << sum << endl;
        //else cout << (((L/N-K+1) * dp2[K-2][N-1]) % mod + ((L/N-K) * sum) % mod) % mod << endl;
        else cout << (((((L/N-K) % mod) * dp2[K-2][N-1]) % mod) + ((((L/N-K-1) % mod) * sum) % mod)) % mod  << endl;
     }
     else {
         //cout << dp2[K-1][N-1] << endl;
         //cout << dp2[K-1][N-1] << endl;
         cout << (((L/N-K+1) % mod) * dp2[K-1][N-1]) % mod << endl;
     }
    //cout << dp2[0][0] << " " << dp1[2][1] << " " << dp1[2][2] << endl;
}