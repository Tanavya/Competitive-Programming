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

const int maxn = (int)1e5+10;
int A[maxn], cnt[maxn], res[maxn], RMAP[maxn], ans = 0, block_size = 320;
map <int, int> MAP;

struct query {
    int i, L, R;
};

bool cmp(query a, query b) {
    if (a.L/block_size != b.L/block_size)
        return a.L/block_size < b.L/block_size;
    return a.R < b.R;
}

void add(int i) {
    if (cnt[A[i]] == RMAP[A[i]]) ans--;
    cnt[A[i]]++;
    if (cnt[A[i]] == RMAP[A[i]]) ans++;
}

void rem(int i) {
    if (cnt[A[i]] == RMAP[A[i]]) ans--;
    cnt[A[i]]--;
    if (cnt[A[i]] == RMAP[A[i]]) ans++;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    int t = 0;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &A[i]);
        if (!MAP[A[i]]) {
            MAP[A[i]] = ++t;
            RMAP[t] = A[i];
        }
        A[i] = MAP[A[i]];
    }
    vector <query> queries(M);
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &queries[i].L, &queries[i].R);
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
        res[q.i] = ans;
    }
    for (int i = 0; i < M; i++) printf("%d\n", res[i]);
}