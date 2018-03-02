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

const int maxn = 111111;

vi tree[maxn], euler = {0};
int P[maxn][25], ST[maxn], ET[maxn], lvl[maxn], block_size, ans = 0, A[maxn], cnt[maxn], cnt2[maxn], res[maxn];
map <int, int> HASH;

struct query {
    int L, R, sp, i;
};

void add(int i) {
    int n = euler[i], val = A[euler[i]];
    cnt[n]++;
    if (cnt[n] == 1) {
        cnt2[val]++;
        if (cnt2[val] == 1)
            ans++;
    }
    else if (cnt[n] == 2) {
        cnt2[val]--;
        if (cnt2[val] == 0)
            ans--;
    }
    //assert(cnt[n] >= 1);
}
void rem(int i) {
    int n = euler[i], val = A[euler[i]];
    cnt[n]--;
    if (cnt[n] == 0) {
        cnt2[val]--;
        if (cnt2[val] == 0)
            ans--;
    }
    else if (cnt[n] == 1) {
        cnt2[val]++;
        if (cnt2[val] == 1)
            ans++;
    }
    //assert(cnt[n] >= 0);
}

bool cmp(query a, query b) {
    if (a.L/block_size != b.L/block_size)
        return a.L/block_size < b.L/block_size;
    return a.R < b.R;
}

void dfs(int n, int par) {
    euler.pb(n);
    ST[n] = (int) euler.size()-1;
    P[n][0] = par;
    lvl[n] = lvl[par] + 1;
    for (int i = 0; i < tree[n].size(); i++) {
        int adj = tree[n][i];
        if (adj != par) {
            dfs(adj, n);
        }
    }
    euler.pb(n);
    ET[n] = (int) euler.size()-1;
}

int lca(int u, int v) {
    if (lvl[u] < lvl[v]) swap(u, v);
    int k;
    for(k = 0; (1 << k) <= lvl[u]; k++);
    k--;
    for (int i = k; i >= 0; i--) {
        if (P[u][i] != -1 && lvl[u] - (1 << i) >= lvl[v]) {
            u = P[u][i];
        }
    }
    if (u == v)
        return u;
    for (int i = k; i >= 0; i--) {
        if (P[u][i] != -1 && P[u][i] != P[v][i]) {
            u = P[u][i];
            v = P[v][i];
        }
    }
    assert(P[u][0] == P[v][0]);
    return P[u][0];
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    int t = 0;
    for (int i = 1; i <= N; i++) {
        int x;
        scanf("%d", &x);
        if (!HASH[x])
            HASH[x] = ++t;
        A[i] = HASH[x];
    }
    for (int i = 1; i < N; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        tree[u].pb(v);
        tree[v].pb(u);
    }
    for (int i = 0; i < 25; i++) {
        for (int u = 1; u <= N; u++) {
            P[u][i] = -1;
        }
    }
    dfs(1, 0);
    for (int i = 1; i < 25; i++) {
        for (int u = 1; u <= N; u++) {
            if (P[u][i-1] != -1) {
                P[u][i] = P[P[u][i-1]][i-1];
            }
        }
    }
    vector <query> queries(M);
    block_size = (int)(sqrt(N));
    for (int i = 0; i < M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        int LCA = lca(u, v);
        if (ST[u] > ST[v])
            swap(u, v);
        if (LCA == u) {
            queries[i].L = ST[u];
            queries[i].R = ST[v];
            queries[i].sp = -1;
        }
        else {
            queries[i].L = ET[u];
            queries[i].R = ST[v];
            queries[i].sp = LCA;
        }
        queries[i].i = i;
    }
    sort(all(queries), cmp);
    int L = 1, R = 0;
    for (query q : queries) {
        while(L > q.L) {
            add(--L);
        }
        while(L < q.L) {
            rem(L++);
        }
        while (R > q.R) {
            rem(R--);
        }
        while(R < q.R) {
            add(++R);
        }
        res[q.i] = ans;
        if (q.sp != -1) {
            int val = A[euler[ST[q.sp]]];
            if (cnt2[val] == 0)
                res[q.i]++;
        }
    }
    for (int i = 0; i < M; i++)
        printf("%d\n", res[i]);
}
