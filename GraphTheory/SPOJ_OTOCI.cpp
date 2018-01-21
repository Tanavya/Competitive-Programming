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

const int maxn = (int) 3e4+10;
int A[maxn], parent[maxn], size[maxn], ST[maxn], ET[maxn], stree[8*maxn], deg[maxn], lvl[maxn], P[maxn][21];
vector <vi> tree(maxn);
vi euler;

inline int left(int x) { return (x << 1); }
inline int right(int x) { return (x << 1) + 1; }

int root(int x) {
    while (parent[x] != x) {
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
    return x;
}

bool Find(int a, int b) {
    return root(a) == root(b);
}

void Union(int a, int b) {
    a = root(a);
    b = root(b);
    if (size[a] < size[b]) swap(a, b);
    size[a] += size[b];
    parent[b] = a;
}

void dfs(int node, int par) {
    lvl[node] = lvl[par] + 1;
    P[node][0] = par;
    euler.pb(node);
    ST[node] = (int)euler.size();
    for (int adj : tree[node]) {
        if (adj != par) {
            dfs(adj, node);
        }
    }
    euler.pb(node);
    ET[node] = (int)euler.size();
}

void build (int i, int L, int R) {
    if (L == R) {
        int node = euler[L-1];
        if (ST[node] == L)
            stree[i] = A[node];
        else
            stree[i] = -A[node];
    }
    else {
        int mid = (L+R)/2;
        build(left(i), L, mid);
        build(right(i), mid+1, R);
        stree[i] = stree[left(i)] + stree[right(i)];
    }
}

void update(int i, int L, int R, int idx, int val) {
    if (L == R) {
        assert(L == idx);
        stree[i] = val;
    }
    else {
        int mid = (L+R)/2;
        if (idx <= mid)
            update(left(i), L, mid, idx, val);
        else
            update(right(i), mid+1, R, idx, val);
        stree[i] = stree[left(i)] + stree[right(i)];
    }
}
int Query (int i, int L, int R, int li, int ri) {
    if (ri < L || li > R)
        return 0;
    if (li <= L && ri >= R)
        return stree[i];
    int mid = (L+R)/2;
    return Query(left(i), L, mid, li, ri) + Query(right(i), mid+1, R, li, ri);
}

int lca(int u, int v) {
    if (lvl[u] < lvl[v]) swap(u, v);

    int k;
    for(k = 0; (1<<k) <= lvl[u]; k++);
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
struct query {
    int type, A, B, ans;
};
int main() {

    int N;
    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        scanf("%d", &A[i]);
        parent[i] = i;
        size[i] = 1;
    }

    int Q, a, b;
    scanf("%d", &Q);
    vector <query> queries(Q);
    string type;
    for (int i = 0; i < Q; i++) {
        cin >> type;
        scanf("%d %d", &a, &b);
        if (type == "bridge") {
            queries[i].type = 0;
            if (!Find(a, b)) {
                Union(a, b);
                tree[a].pb(b);
                tree[b].pb(a);
                deg[a]++;
                deg[b]++;
                queries[i].ans = 1;
            }
            else {
                queries[i].ans = 0;
            }
        }
        else if (type == "penguins")
            queries[i].type = 1;
        else {
            queries[i].type = 2;
            if (!Find(a, b))
                queries[i].ans = -1;
            else queries[i].ans = 0;
        }
        queries[i].A = a;
        queries[i].B = b;
    }
    for (int i = 1; i <= N; i++) {
        if (!Find(0, i)) {
            Union(0, i);
            tree[0].pb(i);
            tree[i].pb(0);
        }
    }


    for (int i = 0; i < 21; i++) {
        for (int j = 0; j <= N; j++) {
            P[i][j] = -1;
        }
    }

    lvl[0] = -1;
    dfs(0, 0);

    for (int i = 1; i < 21; i++) {
        for (int u = 0; u <= N; u++) {
            if (P[u][i-1] != -1) {
                P[u][i] = P[P[u][i-1]][i-1];
            }
        }
    }
    N = euler.size();
    build(1, 1, N);

    for (query q : queries) {
        if (q.type == 0) {
            if (q.ans) printf("yes\n");
            else printf("no\n");
        }
        else if (q.type == 1) {
            update(1, 1, N, ST[q.A], q.B);
            update(1, 1, N, ET[q.A], -q.B);
            A[q.A] = q.B;
        }
        else {
            if (q.ans == -1)
                printf("impossible\n");
            else {
                int d1 = Query(1, 1, N, 1, ST[q.A]);
                int d2 = Query(1, 1, N, 1, ST[q.B]);
                int d3 = Query(1, 1, N, 1, ST[lca(q.A, q.B)]);
                printf("%d\n", d1+d2-2*d3+A[lca(q.A, q.B)]);
            }
        }
    }
}