//OOPS not possible using HLD, i'm so stupid :P
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

const int maxn = 100007;
int in[maxn], euler[maxn], size[maxn], A[maxn], nxt[maxn], tree[maxn*4], parent[maxn], depth[maxn], N;
vector <ii> g[maxn];

struct node {
    int val;
    node *left, *right;
    node() {}
    node(int val, node *left, node *right): val(val), left(left), right(right) {}
};

#define null new node(0, NULL, NULL)

void update(node *curr, int L, int R, int idx) {
    if (L == R) {
        assert(L == idx);
        curr->val = 1;
    }
    else {
        if (!curr->left) curr->left = null;
        if (!curr->right) curr->right = null;
        int mid = (L+R)/2;
        if (idx <= mid)
            update(curr->left, L, mid, idx);
        else
            update(curr->right, mid+1, R, idx);
        curr->val = curr->left->val + curr->right->val;
    }
}

int query(node *curr, int L, int R, int li, int ri) {
    if (ri < L || li > R)
        return 0;
    if (li <= L && ri >= R)
        return curr->val;
    int mid = (L+R)/2;
    return query(curr->left, L, mid, li, ri) + query(curr->right, mid+1, R, li, ri);
}

void dfs_sz(int node, int par) {
    size[node] = 1;
    parent[node] = par;
    depth[node] = depth[par] + 1;
    for (ii &edge : g[node]) {
        int adj = edge.fi, w = edge.se;
        if (adj != par) {
            dfs_sz(adj, node);
            size[node] += size[adj];
            A[adj] = w;
            if (size[adj] > size[g[node][0].fi])
                swap(edge, g[node][0]);
        }
    }
}
int t = 0;
void dfs_hld(int node, int par) {
    in[node] = ++t;
    euler[in[node]] = node;
    for (ii edge : g[node]) {
        int adj = edge.fi;
        if (adj != par) {
            nxt[adj] = (adj == g[node][0].fi ? nxt[node]: adj);
            dfs_hld(node, par);
        }
    }
}

int query(int u, int v) {
    return 0;
}

void update(int u, int v, int w) {
    if (parent[v] == u) swap(u, v);
    assert(parent[u] == v);
}

int main() {
    int M;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N-1; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        g[u].pb(mp(v, w));
        g[v].pb(mp(u, w));
    }
    dfs_sz(1, 0);
    dfs_hld(1, 0);
}