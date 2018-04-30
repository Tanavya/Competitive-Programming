#include <vector>
#include <algorithm>
#include <stdio.h>

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
typedef std::pair <int, int> ii;
typedef std::vector <int> vi;
typedef std::vector <ii> vii;

using namespace std;

int N;

int main() {
    int K;
    scanf("%d", &K);
    vi A(K), B(K), d(K);
    for (int k = 0; k < K; k++)
        scanf("%d", &A[k]);
    for (int k = 0; k < K; k++)
        scanf("%d", &B[k]);
    for (int k = 0; k < K; k++)
        scanf("%d", &d[k]);
    bool ok = true;
    vii odd, even;
    for (int k = 0; k < K; k++) {
        int diff = abs(A[k] - B[k]);
        if (d[k] == 0) {
            if (diff) {
                ok = false;
                break;
            }
        }
        else if (diff % d[k] != 0) {
            ok = false;
            break;
        }
        else {
            int len = diff / d[k];
            if (len % 2 == 0) even.pb(mp(len, k));
            else odd.pb(mp(len, k));
        }
    }
    if (!even.empty() && !odd.empty()) ok = false;
    printf("%d\n", ok);
    if (!ok) return 0;
    sort(all(even));
    sort(all(odd));
    ll min_len = 0, dist = 0;
    if (!even.empty())
        min_len = even.back().fi;
    else if (!odd.empty())
        min_len = odd.back().fi;
    printf("%lld\n", min_len);
    for (int k = 0; k < K; k++) {
        if (B[k] >= A[k]) swap(A[k], B[k]);
        ll len = 0;
        if (d[k]) len = abs(A[k] - B[k]) / d[k];
        ll n = min_len - len;
        dist += (ll(A[k] + B[k]) * ll(len+1))/2;
        dist += (ll(n) * ll(4 * A[k] + n * d[k]))/4;
    }
    printf("%lld\n", dist);
}
/*
3
0 0 0
-2 0 2
1 1 1
 */