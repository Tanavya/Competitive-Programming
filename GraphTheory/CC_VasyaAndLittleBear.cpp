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

const int maxn = (int)1e5+10;

int ST[maxn], EN[maxn], H[maxn], C[maxn], P[maxn][25], lvl[maxn], cnt[maxn], pre[maxn], block_size;
vi tree[maxn], euler = {0};
map <ll, int> MAP;
ll ans[15], res[maxn];
deque <int> connect[15];

struct query {
    int L, R, i, lca;
};

bool cmp(query a, query b) {
    if (a.L/block_size != b.L/block_size)
        return a.L/block_size < b.L/block_size;
    return a.R < b.R;
}
/*
void add(int i) {
    cout << "adding... " << i << endl;
    int n = euler[i], col = C[euler[i]];
    cnt[n]++;
    debug2(n, col);
    cout << "connect: "; print(connect[col]);
    if (cnt[n] == 1) {
        if (!connect[col].empty())
            ans[col] += pow(H[n] - H[connect[col].back()], 2);
        connect[col].pb(n);
    }
    else if (cnt[n] == 2) {
        assert(connect[col].back() == n);
        connect[col].pop_back();
        if (!connect[col].empty())
            ans[col] -= pow(H[connect[col].back()] - H[n], 2);
    }
}

void rem(int i) {
    cout << "removing... " << i << endl;
    int n = euler[i], col = C[euler[i]];
    cnt[n]--;
    debug2(n, col);
    cout << "connect: "; print(connect[col]);
    if (cnt[n] == 1) {
        if (!connect[col].empty())
            ans[col] += pow(H[n] - H[connect[col].back()], 2);
        connect[col].pb(n);
    }
    else if (cnt[n] == 0) {
        assert(connect[col].back() == n);
        connect[col].pop_back();
        if (!connect[col].empty())
            ans[col] -= pow(H[connect[col].back()] - H[n], 2);
    }
}*/

void dfs(int node, int par) {
    euler.pb(node);
    P[node][0] = par;
    lvl[node] = lvl[par] + 1;
    ST[node] = (int)euler.size()-1;
    for (int adj : tree[node]) {
        if (adj != par) {
            dfs(adj, node);
        }
    }
    euler.pb(node);
    EN[node] = (int)euler.size()-1;
}

int lca(int u, int v) {
    if (lvl[u] < lvl[v]) swap(u, v);
    int k;
    for (k = 0; (1 << k) <= lvl[u]; k++);
    k--;
    for (int i = k; i >= 0; i--) {
        if (P[u][i] != -1 && lvl[u] - (1 << i) >= lvl[v]) {
            u = P[u][i];
        }
    }
    if (u == v)
        return u;
    for (int i = k; i >= 0; i--) {
        if (P[u][i] != -1 && P[v][i] != -1 && P[u][i] != P[v][i]) {
            u = P[u][i];
            v = P[v][i];
        }
    }
    assert(P[u][0] == P[v][0]);
    return P[u][0];
}

int main() {
    int N, M, t = 0;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        ll x;
        scanf("%lld", &x);
        if (!MAP[x])
            MAP[x] = ++t;
        C[i] = MAP[x];
    }
    for (int i = 1; i <= N; i++) {
        scanf("%d", &H[i]);
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
    //print(euler);
    for (int i = 1; i < 25; i++) {
        for (int u = 1; u <= N; u++) {
            if (P[u][i-1] != -1)
                P[u][i] = P[P[u][i-1]][i-1];
        }
    }
    scanf("%d", &M);
    block_size = (int)sqrt(N);
    vector <query> queries(M);
    for (int i = 0; i < M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        if (ST[u] > ST[v]) swap(u, v);
        int LCA = lca(u, v);
        //debug3(u, v, LCA);
        queries[i].i = i;
        if (LCA == u) {
            queries[i].L = ST[u];
            queries[i].R = ST[v];
        }
        else {
            queries[i].L = EN[u];
            queries[i].R = ST[v];
        }
        queries[i].lca = LCA;
    }
    sort(all(queries), cmp);
    int L = 1, R = 0;
    for (query q : queries) {
        //debug2(q.L, q.R);
        while (L > q.L) {
            //add(--L);
            L--;
            int i = L;
            int n = euler[i], col = C[euler[i]];
            cnt[n]++;
            //debug2(n, col);
            //cout << "connect: "; print(connect[col]);
            if (cnt[n] == 1) {
                if (!connect[col].empty())
                    ans[col] += pow(H[n] - H[connect[col].front()], 2);
                connect[col].push_front(n);
            }
            else if (cnt[n] == 2) {
                assert(connect[col].front() == n);
                connect[col].pop_front();
                if (!connect[col].empty())
                    ans[col] -= pow(H[connect[col].front()] - H[n], 2);
            }
        }
        while (L < q.L) {
            //rem(L++);
            int i = L;
            int n = euler[i], col = C[euler[i]];
            cnt[n]--;
            //debug2(n, col);
            //cout << "connect: "; print(connect[col]);
            if (cnt[n] == 1) {
                if (!connect[col].empty())
                    ans[col] += pow(H[n] - H[connect[col].front()], 2);
                connect[col].push_front(n);
            }
            else if (cnt[n] == 0) {
                assert(connect[col].front() == n);
                connect[col].pop_front();
                if (!connect[col].empty())
                    ans[col] -= pow(H[connect[col].front()] - H[n], 2);
            }
            L++;
        }
        while (R > q.R) {
            //rem(R--);
            int i = R;
            int n = euler[i], col = C[euler[i]];
            cnt[n]--;
            //debug2(n, col);
            //cout << "connect: "; print(connect[col]);
            if (cnt[n] == 1) {
                if (!connect[col].empty())
                    ans[col] += pow(H[n] - H[connect[col].back()], 2);
                connect[col].pb(n);
            }
            else if (cnt[n] == 0) {
                assert(connect[col].back() == n);
                connect[col].pop_back();
                if (!connect[col].empty())
                    ans[col] -= pow(H[connect[col].back()] - H[n], 2);
            }
            R--;
        }
        while (R < q.R) {
            //add(++R);
            R++;
            int i = R;
            int n = euler[i], col = C[euler[i]];
            cnt[n]++;
            //debug2(n, col);
            //cout << "connect: "; print(connect[col]);
            if (cnt[n] == 1) {
                if (!connect[col].empty())
                    ans[col] += pow(H[n] - H[connect[col].back()], 2);
                connect[col].pb(n);
            }
            else if (cnt[n] == 2) {
                assert(connect[col].back() == n);
                connect[col].pop_back();
                if (!connect[col].empty())
                    ans[col] -= pow(H[connect[col].back()] - H[n], 2);
            }
        }
        for (int i = 1; i <= t; i++) {
            if (i != C[q.lca])
                res[q.i] += ans[i];
        }
    }
    for (int i = 0; i < M; i++)
        printf("%lld\n", res[i]);
}