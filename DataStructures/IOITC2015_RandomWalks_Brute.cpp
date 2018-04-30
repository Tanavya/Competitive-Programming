#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <assert.h>
#include <set>
#include <bitset>
#include <stack>

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << endl;
#define debug(x) cout << x << endl;
#define debug2(x,y) cout << x << " " << y << endl;
#define debug3(x,y,z) cout << x << " " << y << " " << z << endl;
#pragma comment(linker, "/STACK:2000000")

typedef long long int ll;
typedef long double ld;
typedef unsigned long long int ull;
typedef std::pair <int, int> ii;
typedef std::vector <int> vi;
typedef std::vector <ll> vll;
typedef std::vector <ld> vld;

const int INF = (int) 1e9;
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
using namespace std;

const int maxn = (int) 2e5+10, maxai = (int) 1e6+10;
int N, A[maxn], depth[maxn], P[maxn][21];
vi tree[maxn];
bitset <maxn> visited;

struct node {
    int val;
    node *left, *right;
    node(int val = INF, node *left = nullptr, node *right = nullptr) : val(val), left(left), right(right) {}
};
#define null new node()
node * T[4*maxai];

inline int left(int x) { return (x << 1); }
inline int right(int x) { return (x << 1) + 1; }

int query_DST(node *curr, int L, int R, int li, int ri) {
    if (!curr || ri < L || li > R)
        return INF;
    if (li <= L && ri >= R)
        return curr->val;
    int mid = (L+R)/2;
    return min(query_DST(curr->left, L, mid, li, ri), query_DST(curr->right, mid+1, R, li, ri));
}

void update_DST(node *curr, int L, int R, int idx, int val) {
    if (L == R) {
        assert(L == idx);
        curr->val = val;
    }
    else {
        int mid = (L+R)/2;
        if (!curr->left) curr->left = null;
        if (!curr->right) curr->right = null;
        if (idx <= mid)
            update_DST(curr->left, L, mid, idx, val);
        else
            update_DST(curr->right, mid+1, R, idx, val);
        curr->val = min(curr->left->val, curr->right->val);
    }
}

int query(int i, int L, int R, int li, int ri, int lii, int rii) {
    if (ri < L || li > R)
        return INF;
    if (li <= L && ri >= R)
        return query_DST(T[i], 0, maxai, lii, rii);
    int mid = (L+R)/2;
    return min(query(left(i), L, mid, li, ri, lii, rii), query(right(i), mid+1, R, li, ri, lii, rii));
}

void update(int i, int L, int R, int idx, int n, int val) {
    if (!T[i]) T[i] = null;
    update_DST(T[i], 0, maxai, n, val);
    if (L != R) {
        int mid = (L+R)/2;
        if (idx <= mid)
            update(left(i), L, mid, idx, n, val);
        else
            update(right(i), mid+1, R, idx, n, val);
    }
}

/*
void dfs0(int node, int par) {
    if (node != 0) depth[node] = depth[par] + 1;
    P[node][0] = par;
    visited[node] = true;
    for (int adj : tree[node]) {
        if (adj != par) {
            dfs0(adj, node);
        }
    }
}*/

void dfs0(int node, int par) {
    stack <ii> S;
    S.push(mp(node, par));
    while (!S.empty()) {
        node = S.top().fi, par = S.top().se;
        S.pop();
        visited[node] = true;
        if (node) depth[node] = depth[par] + 1;
        P[node][0] = par;
        for (int adj : tree[node]) {
            if (!visited[adj]) {
                S.push(mp(adj, node));
            }
        }
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v])
        swap(u, v);
    int d = depth[u] - depth[v];
    for (int i = 0; i < 20; i++) {
        if (d & (1 << i)) {
            u = P[u][i];
        }
    }
    if (u == v)
        return u;
    for (int i = 19; i >= 0; i--) {
        if (P[u][i] != P[v][i]) {
            u = P[u][i];
            v = P[v][i];
        }
    }
    return P[u][0];
}

int findParent(int u, int v) {
    //find node such that parent[u] = v
    if (depth[u] == depth[v]) {
        assert(u == v);
        return u;
    }
    assert(depth[u] > depth[v]);
    int d = depth[u] - depth[v] - 1;
    for (int i = 0; i < 20; i++) {
        if (d & (1 << i)) {
            u = P[u][i];
        }
    }
    assert(P[u][0] == v);
    return u;
}

void preprocess() {
    visited.reset();
    dfs0(0, 0);
    for (int i = 1; i < 20; i++) {
        for (int u = 1; u <= 2*N; u++) {
            P[u][i] = P[P[u][i-1]][i-1];
        }
    }
}

void build_tree() {
    for (int u = 0; u <= 2*N; u++) {
        tree[u].clear();
        depth[u] = 0;
        for (int i = 0; i < 21; i++) {
            P[u][i] = 0;
        }
    }
    for (int i = 1; i <= N; i++) {
        int f_i = query(1, 1, N, i+1, N, A[i]+1, maxai);
        int g_i = query(1, 1, N, i+1, N, 0, A[i]-1);
        if (f_i != INF) {
            tree[i].pb(f_i + N);
            tree[f_i + N].pb(i);
        }
        else {
            tree[i].pb(0);
            tree[0].pb(i);
        }
        if (g_i != INF) {
            tree[i + N].pb(g_i);
            tree[g_i].pb(i + N);
        }
        else {
            tree[i + N].pb(0);
            tree[0].pb(i + N);
        }
    }
    preprocess();
}
bool cmp(ii a, ii b) {
    return depth[a.fi] > depth[b.fi];
}
inline bool isAncestor(int a, int b) {
    return lca(a, b) == b;
}
int main() {
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int Q;
    scanf("%d %d", &N, &Q);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &A[i]);
        update(1, 1, N, i, A[i], i);
    }
    build_tree();
    while (Q--) {
        int I, J, K;
        scanf("%d %d %d", &I, &J, &K);
        vector <ii> updates, changes;
        for (int i = 0; i < K; i++) {
            int b, c;
            scanf("%d %d", &b, &c);
            updates.pb(mp(b, c));
            changes.pb(mp(b, A[b]));
            update(1, 1, N, b, A[b], INF);
        }
        for (ii upd : updates) {
            update(1, 1, N, upd.fi, upd.se, upd.fi);
            A[upd.fi] = upd.se;
        }
        //for (int i = 1; i <= N; i++) cout << A[i] << " "; cout << endl;
        build_tree();
        int ans = 0;
        if (I > J) swap(I, J);
        if (lca(I, J+N) == J+N) ans++;
        ans += depth[lca(I, J)];
        printf("%d\n", ans);
        for (ii change : changes) {
            update(1, 1, N, change.fi, A[change.fi], INF);
        }
        for (ii change : changes) {
            update(1, 1, N, change.fi, change.se, change.fi);
            A[change.fi] = change.se;
        }
    }
}
/*
10 99
7 1 3 10 4 2 9 5 8 6
3 1 10
1 7
2 3
3 4
4 10
5 6
6 9
7 2
8 5
9 8
10 1
 */