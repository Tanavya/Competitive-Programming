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

const int maxn = 200007, maxai = (int) 1e9+10;
int N = 0, Q = 0, res[maxn], A[maxn], block_size, cnt[maxn], above[maxn];

struct query {
    int L, R, i, k;
};
bool cmp(query a, query b) {
    if (a.L/block_size != b.L/block_size)
        return a.L/block_size < b.L/block_size;
    return a.R < b.R;
}

void add(int i) {
    if (cnt[A[i]] >= 0)
        above[cnt[A[i]]]++;
    cnt[A[i]]++;

}

void rem(int i) {
    cnt[A[i]]--;
    if (cnt[A[i]] >= 0)
        above[cnt[A[i]]]--;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        for (int i = 0; i <= N; i++) {
            A[i] = cnt[i] = above[i] = 0;
        }
        for (int i = 0; i <= Q; i++) {
            res[i] = 0;
        }
        scanf("%d %d", &N, &Q);
        block_size = (int)sqrt(N);
        int t = 0;
        map <int, int> MAP;
        for (int i = 1; i <= N; i++) {
            scanf("%d", &A[i]);
            if (!MAP[A[i]])
                MAP[A[i]] = ++t;
            A[i] = MAP[A[i]];
        }
        vector <query> queries(Q);
        for (int i = 0; i < Q; i++) {
            scanf("%d %d %d", &queries[i].L, &queries[i].R, &queries[i].k);
            queries[i].i = i;
        }
        sort(all(queries), cmp);
        int L = 1, R = 0;
        for (query q : queries) {
            while (L < q.L) {
                rem(L++);
            }
            while (L > q.L) {
                add(--L);
            }
            while (R < q.R) {
                add(++R);
            }
            while (R > q.R) {
                rem(R--);
            }
            res[q.i] = above[0] - above[q.k];
            //debug3(q.L, q.R, q.k);
            //debug3(above[0], above[q.k], res[q.i]);
        }
        for (int i = 0; i < Q; i++)
            printf("%d\n", res[i]);
    }
}