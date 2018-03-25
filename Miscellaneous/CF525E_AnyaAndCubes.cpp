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



int main() {
    /*
    int mask = 0;
    mask |= (1 << 3);
    mask |= (1 << 2);
    mask |= (1 << 5);
    for (int submask = mask; submask >= 0; submask = ( mask & (submask-1) )) {
        print_mask(submask);
        if (!submask) break;
    }*/
    /*
    while (mask) {
        int pos = (mask & (-mask));
        cout << pos << endl;
        mask &= ~pos;
    }*/

    //return 0;

    //max A[i] for factorial -> 18
    ll factorial[19];
    factorial[1] = 1;
    for (int i = 2; i <= 18; i++) {
        factorial[i] = factorial[i-1] * i;
    }
    int N, K;
    ll S;
    scanf("%d %d %lld", &N, &K, &S);
    vector <int> A(N);

    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);
    sort(A.begin(), A.end());
    //meet in the middle
    int mid = N/2;
    map <ll, int> count[K+1];
    vector <ll> second_half[K+1];

    for (int msk = 0; msk < (1 << mid); msk++) {
        for (int sub_msk = msk; sub_msk >= 0; sub_msk = (msk & (sub_msk - 1))) {
            int mask = msk;
            bool ok = true;
            int k = 0;
            ll s = 0;
            while (mask) {
                int pos = (mask & (-mask));
                int i = (int)log2(pos);
                if (pos & sub_msk) {
                    if (A[i] > 18) {
                        ok = false;
                        break;
                    }
                    else if (s + factorial[A[i]] > S) {
                        ok = false;
                        break;
                    }
                    else s+= factorial[A[i]];
                    k++;
                }
                else {
                    if (s + A[i] > S) ok = false;
                    else s += A[i];
                }
                mask &= ~pos;
            }
            if (ok && k <= K) {
                for (int x = k; x <= K; x++) {
                    count[x][s]++;
                }
            }
            if (!sub_msk) break;
        }
    }
    int sz = N-mid;
    for (int msk = 0; msk < (1 << sz); msk++) {
        for (int sub_msk = msk; sub_msk >= 0; sub_msk = (msk & (sub_msk - 1))) {
            int mask = msk;
            bool ok = true;
            int k = 0;
            ll s = 0;
            while (mask) {
                int pos = (mask & (-mask));
                int i = mid+(int)log2(pos);
                if (pos & sub_msk) {
                    if (A[i] > 18) {
                        ok = false;
                        break;
                    }
                    else if (s + factorial[A[i]] > S) {
                        ok = false;
                        break;
                    }
                    else s+= factorial[A[i]];
                    k++;
                }
                else {
                    if (s + A[i] > S) ok = false;
                    else s += A[i];
                }
                mask &= ~pos;
            }
            if (ok && k <= K) {
                second_half[k].pb(s);
            }
            if (!sub_msk) break;
        }
    }
    ll ans = 0;

    for (int k = K; k >= 0; k--) {
        for (ll s : second_half[k]) {
            ans += count[K-k][S-s];
        }
    }
    cout << ans << endl;
}