//WA
//annoying case handling ;/

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
vi tree[maxn];
int P[maxn][25], lvl[maxn];

void dfs(int node, int par) {
    P[node][0] = par;
    lvl[node] = lvl[par] + 1;
    for (int adj : tree[node]) {
        if (adj != par) {
            dfs(adj, node);
        }
    }
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
    if (u == v) return u;
    for (int i = k; i >= 0; i--) {
        if (P[u][i] != P[v][i] && P[u][i] != -1) {
            u = P[u][i];
            v = P[v][i];
        }
    }
    assert(P[u][0] == P[v][0]);
    return P[u][0];
}

bool in_subtree(int a, int b) {
    //returns if a is in subtree of b
    cout << a << " " << b << endl;
    if (a == b) return true;
    return lca(a, b) != a;
}

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N-1; i++) {
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
    lvl[0] = -1;
    dfs(1, 0);
    for (int i = 1; i < 25; i++) {
        for (int u = 1; u <= N; u++) {
            if (P[u][i-1] != -1) {
                P[u][i] = P[P[u][i-1]][i-1];
            }
        }
    }
    int Q;
    scanf("%d", &Q);
    cout << in_subtree(1, 1) << endl;
    while (Q--) {
        int root, u, v;
        scanf("%d %d %d", &root, &u, &v);
        if (lvl[u] < lvl[v]) swap(u, v);
        int w = lca(u, v);
        if (in_subtree(root, w) && (in_subtree(u, root) || in_subtree(v, root))) {
            printf("%d\n", root);
        }
        else if (in_subtree(w, root)) {
            printf("%d\n", w);
        }
        else if (in_subtree(root, u)) {
            printf("%d\n", u);
        }
        else if (in_subtree(root, v)) {
            printf("%d\n", v);
        }
        else {
            assert(false);
        }
    }
}