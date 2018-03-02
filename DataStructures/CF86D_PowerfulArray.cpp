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

const int maxn = 200007, maxai = (int) 1e6+7;
int N, block_size;
ll A[maxn], cnt[maxai], res[maxn], ans = 0;

struct query {
    int i, L, R;
};

bool cmp (query a, query b) {
    if (a.L/block_size != b.L/block_size)
        return a.L/block_size < b.L/block_size;
    return a.R < b.R;
}

int main() {
    int Q;
    scanf("%d %d", &N, &Q);
    block_size = (int)sqrt(N);
    for (int i = 1; i <= N; i++) {
        scanf("%lld", &A[i]);
    }
    vector <query> queries(Q);
    for (int i = 0; i < Q; i++) {
        scanf("%d %d", &queries[i].L, &queries[i].R);
        queries[i].i = i;
    }
    sort(all(queries), cmp);
    int L = 1, R = 0;
    for (query q : queries) {
        while (L < q.L) {
            ll x = A[L++];
            ans -= (cnt[x] * cnt[x] * x);
            cnt[x]--;
            ans += (cnt[x] * cnt[x] * x);
        }
        while (L > q.L) {
            ll x = A[--L];
            ans -= (cnt[x] * cnt[x] * x);
            cnt[x]++;
            ans += (cnt[x] * cnt[x] * x);
        }

        while (R < q.R) {
            ll x = A[++R];
            ans -= (cnt[x] * cnt[x] * x);
            cnt[x]++;
            ans += (cnt[x] * cnt[x] * x);
        }
        while (R > q.R) {
            ll x = A[R--];
            ans -= (cnt[x] * cnt[x] * x);
            cnt[x]--;
            ans += (cnt[x] * cnt[x] * x);
        }
        res[q.i] = ans;
    }
    for (int i = 0; i < Q; i++) printf("%lld\n", res[i]);
}