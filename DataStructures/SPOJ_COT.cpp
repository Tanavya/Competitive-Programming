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

struct node {
    int val;
    node *left, *right;
    node() : val(0), left(NULL), right(NULL) {}
    node(int val, node *left, node *right): val(val), left(left), right(right) {}
};
#define null new node(0, NULL, NULL)

node *root[maxn];
vi tree[maxn];
int P[maxn][25], lvl[maxn];
ll A[maxn], limL = INF64, limR = -INF64;

void update(node *prev, node *curr, ll L, ll R, ll idx, int val) {
    if (L == R) {
        assert(L == idx);
        curr->val = prev->val + val;
    }
    else {
        ll mid = (L+R)/2;
        if (idx <= mid) {
            curr->right = prev->right;
            curr->left = null;
            update(prev->left, curr->left, L, mid, idx, val);
        }
        else {
            curr->left = prev->left;
            curr->right = null;
            update(prev->right, curr->right, mid+1, R, idx, val);
        }
        curr->val = curr->left->val + curr->right->val;
    }
}

void dfs(int n, int par) {
    P[n][0] = par;
    lvl[n] = lvl[par] + 1;
    for (int i = 0; i < tree[n].size(); i++) {
        int adj = tree[n][i];
        if (adj != par) {
            root[adj] = null;
            update(root[n], root[adj], limL, limR, A[adj], 1);
            dfs(adj, n);
        }
    }
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

ll query(node *a, node *b, node *c, node *d, ll L, ll R, int k) {
    if (L == R)
        return L;
    int val = a->left->val + b->left->val - c->left->val - d->left->val;
    ll mid = (L+R)/2;
    if (k <= val)
        return query(a->left, b->left, c->left, d->left, L, mid, k);
    else
        return query(a->right, b->right, c->right, d->right, mid+1, R, k-val);
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++) {
        scanf("%lld", &A[i]);
        limL = min(limL, A[i]);
        limR = max(limR, A[i]);
    }
    for (int i = 1; i < N; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        tree[u].pb(v);
        tree[v].pb(u);
    }
    root[0] = null;
    root[0]->left = root[0];
    root[0]->right = root[0];
    root[1] = null;
    update(root[0], root[1], limL, limR, A[1], 1);
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
    while (M--) {
        int u, v, k;
        scanf("%d %d %d", &u, &v, &k);
        int LCA = lca(u, v);
        //cout << LCA << endl;;;
        ll ans = query(root[u], root[v], root[LCA], root[P[LCA][0]], limL, limR, k);
        printf("%lld\n", ans);
    }
}
