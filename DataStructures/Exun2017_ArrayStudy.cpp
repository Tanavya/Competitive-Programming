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
#include <random>
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

int block_size;
const int maxn = (int) 2e5+7, offset = (int)1e5;
int earliest[maxn], latest[maxn], A[maxn], occ[maxn];

void add(int x, int i) {
    x += offset;
    if (i < earliest[x])
        earliest[x] = i;
    if (i > latest[x])
        latest[x] = i;
}
void init(int N) {
    for (int i = 0; i <= N; i++) {
        earliest[offset+i] = earliest[offset-i] = INF;
        latest[offset+i] = latest[offset-i] = -INF;
    }
}
inline int get_earliest(int x) {
    return earliest[x+offset];
}
inline int get_latest(int x) {
    return latest[x+offset];
}

int brute(int L, int R) {
    int sum = offset, res = 0;
    occ[sum] = L-1;
    for (int i = L; i <= R; i++) {
        sum += A[i];
        occ[sum] = min(occ[sum], i);
        res = max(res, i - occ[sum]);
    }
    sum = offset;
    occ[sum] = INF;
    for (int i = L ; i <= R; i++) {
        sum += A[i];
        occ[sum] = INF;
    }
    return res;
}

struct query {
    int L, R, i;
    query() {}
    query(int L, int R, int i): L(L), R(R), i(i) {}
};

bool cmp (query a, query b) {
    if (a.L/block_size != b.L/block_size) assert(false);
    return a.R < b.R;
}

int main() {
    for (int i = 0; i < maxn; i++) occ[i] = INF;
    int T;
    scanf("%d", &T);
    while (T--) {
        int N;
        scanf("%d", &N);
        init(N+1);
        for (int i = 1; i <= N; i++) {
            scanf("%d", &A[i]);
        }
        block_size = (int) sqrt(N);
        int Q;
        scanf("%d", &Q);
        vector <query> blocks[block_size+7];
        ll ans = 0;
        for (int i = 0; i < Q; i++) {
            int L, R;
            scanf("%d %d", &L, &R);
            if (R-L <= block_size+7) {
                //light queries
                ans += brute(L, R);
            }
            else {
                blocks[L/block_size].pb(query(L, R, i));
            }
        }
        for (int b = 0; b <= block_size+1; b++) {
            if (blocks[b].empty()) continue;
            sort(all(blocks[b]), cmp);
            init(N+1);
            int R = (b+1) * block_size;
            int pref = 0, res = 0;
            add(0, R-1);
            for (query q : blocks[b]) {
                for (; R <= q.R; R++) {
                    pref += A[R];
                    add(pref, R);
                    res = max(res, R - get_earliest(pref));
                }
                int tmp = res;
                assert(q.R >= (b+1) * block_size - 1);
                tmp = max(tmp, brute(q.L, (b+1) * block_size - 1));
                int suff = 0;
                for (int L = (b+1) * block_size - 1; L >= q.L; L--) {
                    suff += A[L];
                    tmp = max(tmp, get_latest(-suff) - L + 1);
                }
                ans += tmp;
            }
        }
        printf("%lld\n", ans);
    }
}