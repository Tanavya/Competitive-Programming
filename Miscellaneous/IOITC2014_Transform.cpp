#include <vector>
#include <algorithm>
#include <stdio.h>
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
typedef std::vector <ii> vii;
typedef std::vector <ll> vll;
typedef std::vector <ld> vld;

const int INF = int(1e9)+10;
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
using namespace std;

const int maxn = 507;
int N, A[maxn];

vector <vi> ops;
void update(int i, int x, int b, int j) {
    for (int k = 0; k < 30; k++) {
        if (x & (1 << k)) {
            ops.pb({i, j, k});
        }
    }
    A[i] += b*x;
}

int main() {
    scanf("%d", &N);
    int neg = 0, pos = 0;
    ii low_neg = mp(INF, INF), low_pos = mp(INF, INF);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &A[i]);
        if (A[i] > 0) {
            low_pos = min(low_pos, mp(A[i], i));
            pos++;
        }
        else if (A[i] < 0) {
            low_neg = min(low_neg, mp(-A[i], i));
            neg++;
        }
    }
    if (pos && neg) printf("1\n");
    else if (pos == 1 || neg == 1) printf("1\n");
    else {
        printf("0\n");
        return 0;
    }
    while (true) {
        pos = neg = 0;
        low_neg = mp(INF, INF);
        low_pos = mp(INF, INF);
        for (int i = 1; i <= N; i++) {
            if (A[i] > 0) {
                low_pos = min(low_pos, mp(A[i], i));
                pos++;
            }
            else if (A[i] < 0) {
                low_neg = min(low_neg, mp(-A[i], i));
                neg++;
            }
        }
        if (pos == 1 && !neg) break;
        if (neg == 1 && !pos) break;
        if (pos == 1 && neg == 1) {
            if (low_pos.fi == low_neg.fi) {
                update(low_pos.se, 1, -low_neg.fi, low_neg.se);
                break;
            }
        }
        if (!pos && !neg) assert(false);
        for (int i = 1; i <= N; i++) {
            if (A[i] > 0) {
                int j = low_neg.se;
                if (i == low_pos.se && A[i] % (-A[j]) == 0)
                    update(i, -(A[i]/A[j])-1, A[j], j);
                else
                    update(i, -(A[i]/A[j]), A[j], j);
            }
            else if (A[i] < 0) {
                int j = low_pos.se;
                if (i == low_neg.se && (-A[i]) % A[j] == 0)
                    update(i, -A[i]/A[j]-1, A[j], j);
                else
                    update(i, -A[i]/A[j], A[j], j);
            }
        }
    }
    printf("%d\n", (int)ops.size());
    for (vi op : ops) {
        printf("%d %d %d\n", op[0], op[1], op[2]);
    }
}