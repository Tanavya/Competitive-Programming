//same as ChefAndQueries but on tree ugh...

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

const int maxn = (int) 2e5+10;
int color[maxn], ST[maxn], EN[maxn], ans[maxn], cnt[maxn], above[maxn], p = 0, block_size;
vi euler, tree[maxn];

struct query {
    int L, R, i, k;
    query(int L, int R, int i, int k): L(L), R(R), i(i), k(k) {}
    query() {}
};

bool cmp (query a, query b) {
    if (a.L/block_size != b.L/block_size)
        return a.L/block_size < b.L/block_size;
    return a.R < b.R;
}

void add(int i) {
    cnt[euler[i]]++;
    if (cnt[euler[i]])
        above[cnt[euler[i]]]++;
}

void rem(int i) {
    if (cnt[euler[i]])
        above[cnt[euler[i]]]--;
    cnt[euler[i]]--;
}

void dfs(int node, int par) {
    euler.pb(color[node]);
    ST[node] = p++;
    for (int adj : tree[node]) {
        if (adj != par) {
            dfs(adj, node);
        }
    }
    euler.pb(color[node]);
    EN[node] = p++;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &color[i]);
    }
    block_size = (int)sqrt(N);
    for (int i = 0; i < N-1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        tree[u].pb(v);
        tree[v].pb(u);
    }
    dfs(1, 0);
    vector <query> queries(M);
    for (int i = 0; i < M; i++) {
        int v, k;
        scanf("%d %d", &v, &k);
        queries[i] = query(ST[v], EN[v], i, k);
    }
    sort(all(queries), cmp);
    int L = 0, R = -1;
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
        ans[q.i] = above[q.k*2];
    }
    for (int i = 0; i < M; i++) {
        printf("%d\n", ans[i]);
    }
}