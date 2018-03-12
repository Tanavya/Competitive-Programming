//Have to hate SPOJ and their super strict time limits ;_;
//Ugh using pointers is twice as slow :(
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

const int maxn = 200007;
int N, S, ans[maxn], A[maxn], P[maxn][20], depth[maxn], size[maxn], parent[maxn], dist[maxn], color[maxn];
set <ii> tree[maxn];
vi children[maxn];


//------------- segment tree used as a set ------------
struct node {
    int val;
    int left, right;
    node() : val(-INF), left(0), right(0) {}
    node(int val) : val(val), left(0), right(0) {}
    node(int val, int l, int r) : val(val), left(l), right(r) {}
};
#define null node(-INF, 0, 0);
node stree[maxn*60];
int SET[maxn];

int nodeCnt = 0;
void update(int &curr, int L, int R, int idx, int val) {
    if (!curr) curr = ++nodeCnt;
    if (L == R) {
        stree[curr].val = val;
    }
    else {
        int mid = (L+R)/2;
        if (idx <= mid)
            update(stree[curr].left, L, mid, idx, val);
        else
            update(stree[curr].right, mid+1, R, idx, val);
        stree[curr].val = max(stree[stree[curr].left].val, stree[stree[curr].right].val);
    }
}
int query(int curr) {
    if (!curr) return -INF;
    return stree[curr].val;
}

/*
struct node {
    int val;
    node *left, *right;
    node() {}
    node(int val, node *left, node *right): val(val), left(left), right(right) {}
};
node *SET[maxn];

#define null new node(-INF, nullptr, nullptr);

void update(node *curr, int L, int R, int idx, int val) {
    if (L == R) {
        assert(L == idx);
        curr->val = val;
    }
    else {
        if (!curr->left) curr->left = null;
        if (!curr->right) curr->right = null;
        int mid = (L+R)/2;
        if (idx <= mid)
            update(curr->left, L, mid, idx, val);
        else
            update(curr->right, mid+1, R, idx, val);
        curr->val = max(curr->left->val, curr->right->val);
    }
}
int query(node *curr) {
    if (!curr) return -INF;
    return curr->val;
}*/
//-------------Preprocessing the input tree-------------

void binarize_tree(int node, int par) {
    vector <ii> edges;
    for (ii edge : tree[node]) {
        int adj = edge.fi;
        if (adj != par)
            edges.pb(edge);
    }
    while (edges.size() > 2) {
        ii nxt[2];
        int aux = ++N;
        for (int i = 0; i < 2; i++) {
            nxt[i] = edges.back();
            edges.pop_back();
            tree[node].erase(nxt[i]);
            tree[nxt[i].fi].erase(mp(node, nxt[i].se));
            tree[nxt[i].fi].insert(mp(aux, nxt[i].se));
            tree[aux].insert(mp(nxt[i].fi, nxt[i].se));
        }
        edges.pb(mp(aux, 0));
        tree[node].insert(mp(aux, 0));
        tree[aux].insert(mp(node, 0));
    }
    for (ii edge : edges) {
        int adj = edge.fi;
        if (adj != par) {
            binarize_tree(adj, node);
        }
    }
}

void dfs0(int node, int par) {
    depth[node] = depth[par] + 1;
    dist[node] = dist[par] + A[node];
    P[node][0] = par;
    for (ii edge : tree[node]) {
        int adj = edge.fi, w = edge.se;
        if (adj != par) {
            A[adj] = w;
            dfs0(adj, node);
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

void preprocess() {
    dfs0(1, 0);
    for (int i = 1; i < 20; i++) {
        for (int u = 1; u <= N; u++) {
            P[u][i] = P[P[u][i-1]][i-1];
        }
    }
}
//------------------ Centroid Decomposition -----------------
void dfs1(int node, int par) {
    size[node] = 1;
    for (ii edge : tree[node]) {
        int adj = edge.fi;
        if (adj != par) {
            dfs1(adj, node);
            size[node] += size[adj];
        }
    }
}
int dfs2(int node, int par) {
    for (ii edge : tree[node]) {
        int adj = edge.fi;
        if (adj != par && size[adj] > S/2) {
            return dfs2(adj, node);
        }
    }
    return node;
}
void decompose(int node, int par) {
    dfs1(node, 0);
    S = size[node];
    int centroid = dfs2(node, 0);
    parent[centroid] = par;
    children[par].pb(centroid);
    for (ii edge : tree[centroid]) {
        int adj = edge.fi, w = edge.se;
        tree[adj].erase(mp(centroid, w));
        decompose(adj, centroid);
    }
    tree[centroid].clear();
}

inline int distance(int u, int v) {
    return dist[u] + dist[v] - 2 * dist[lca(u, v)];
}
//-------------- Updates/Queries on Centroid Tree ------------
void recalc(int u) {
    int max1 = -INF, max2 = -INF;
    ans[u] = -INF;
    for (int adj : children[u]) {
        int d = query(SET[adj]);
        if (d > max1)
            max2 = max(max2, max1), max1 = d;
        else if (d > max2)
            max2 = d;
        ans[u] = max(ans[u], ans[adj]);
    }
    if (color[u]) ans[u] = max(ans[u], max(0, max1));
    ans[u] = max(ans[u], max1 + max2);
}

void update(int u) {
    int x = u, col = color[u];
    color[u] ^= 1;
    while (x) {
        recalc(x);
        if (col)
            update(SET[x], 1, N, u, -INF);
        else
            update(SET[x], 1, N, u, distance(u, parent[x]));
        x = parent[x];
    }
}
//-----------------------------------------------------
int main() {
    scanf("%d", &N);
    int orgN = N;
    for (int i = 0; i < N - 1; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        tree[u].insert(mp(v, w));
        tree[v].insert(mp(u, w));
    }
    binarize_tree(1, 0);
    preprocess();
    decompose(1, 0);
    for (int i = 1; i <= orgN; i++) {
        update(i);
    }
    int M;
    scanf("%d", &M);
    while (M--) {
        char c;
        scanf(" %c", &c);
        if (c == 'A') {
            int x = ans[children[0][0]];
            if (x == -INF) printf("They have disappeared.\n");
            else printf("%d\n", max(0, x));
        }
        else {
            int u;
            scanf("%d", &u);
            update(u);
        }
    }
}