//Easy LCA logic with binary lifting. Just a lot of special case handling.
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


#define MAX(a,b) ((a)>(b)?(a):(b))
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

const int maxn = 1e5+10;
vector <vi> tree(maxn);
int P[maxn][25], lvl[maxn], size[maxn];

void dfs(int node, int par) {
    //debug2(node, par);
    P[node][0] = par;
    lvl[node] = lvl[par] + 1;
    size[node] = 1;
    for (int adj : tree[node]) {
        if (adj != par) {
            dfs(adj, node);
            size[node] += size[adj];
        }
    }
}
int lca(int u, int v) {
    if (lvl[u] < lvl[v])
        swap(u, v);
    int k = ceil(log2(lvl[u]));
    //debug2(lvl[u], lvl[v]);
    for (int i = k; i >= 0; i--) {
        //cout << u << " " << lvl[u] << " " << i << " " << lvl[v] << endl;
        if (P[u][i] != -1 && (lvl[u] - (1 << i) >= lvl[v])) {
            u = P[u][i];
        }
    }
    if (u == v)
        return u;
    //debug2(u, v);
    assert(lvl[u] == lvl[v]);
    for (int i = k; i >= 0; i--) {
        if (P[u][i] != -1 && P[u][i] != P[v][i]) {
            u = P[u][i];
            v = P[v][i];
        }
    }
    assert(P[u][0] == P[v][0]);
    return P[u][0];
}
int kth_ancestor(int u, int k) {
    int s = 0;
    for (int i = 24; i >= 0; i--) {
        if (P[u][i] != -1 && s + (1 << i) <= k) {
            s += (1 << i);
            u = P[u][i];
        }
    }
    return u;
}
int main() {
    int N, u, v;
    scanf("%d", &N);
    for (int i = 0; i < N-1; i++) {
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
    int Q, a, b;
    scanf("%d", &Q);
    while (Q--) {
        scanf("%d %d", &a, &b);
        if (lvl[a] > lvl[b])
            swap(a, b);
        int LCA = lca(a, b);
        int dist = lvl[a] + lvl[b] - 2 * lvl[LCA];
        int ans = 0;
        if (a == b)
            ans = N;
        else if (lvl[a] == lvl[b]) {
            ans = size[1] - (size[kth_ancestor(b, dist/2 - 1)] + size[kth_ancestor(a, dist/2 - 1)]);
        }
        else {
            if (dist % 2 == 0) {
                ans = size[kth_ancestor(b, dist/2)] - size[kth_ancestor(b, dist/2 - 1)];
            }
        }
        printf("%d\n", ans);
    }
}