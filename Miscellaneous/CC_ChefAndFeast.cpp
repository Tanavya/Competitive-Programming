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

int main() {

    int T, N;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        vll A(N);
        for (int i = 0; i < N; i++) {
            scanf("%lld", &A[i]);
        }
        sort(A.rbegin(), A.rend());
        ll total = 0, r_sum = 0, pos = 0;
        for (int i = 0; i < N; i++) {
            if ((r_sum + A[i]) * (i-pos+1) >= r_sum * (i-pos) + A[i]) {
                //extending the running sum is better
                r_sum += A[i];
            }
            else {
                total += (r_sum * (i-pos)); 
                r_sum = A[i];
                pos = i;
            }
        }
        total += (r_sum * (N-pos));
        cout << total << endl;
    }
}
