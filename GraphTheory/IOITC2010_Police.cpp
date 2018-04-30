#include <vector>
#include <stdio.h>
#include <queue>
#include <iostream>
#include <map>
#include <assert.h>
#include <set>
#include <bitset>
#include <algorithm>
#include <cstring>

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << endl;
#define debug(x) cout << x << endl;
#define debug2(x,y) cout << x << " " << y << endl;
#define debug3(x,y,z) cout << x << " " << y << " " << z << endl;
#define debug4(a,b,c,d) cout << a << " " << b << " " << c << " " << d << endl;
#define debug5(a,b,c,d,e) cout << a << " " << b << " " << c << " " << d << " " << e << endl;
#define trace(x) cout << #x << ": " << x << endl;

typedef long long int ll;
typedef long double ld;
typedef unsigned long long int ull;
typedef std::pair <int, int> ii;
typedef std::vector <int> vi;
typedef std::vector <ll> vll;
typedef std::vector <ld> vld;

const int INF = 2147483647;
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
using namespace std;

const int maxn = (int) 2e5+10;
int N, id[maxn], dfs_num[maxn], dfs_low[maxn], depth[maxn], P[maxn][25];
bool AP[maxn], visited[maxn];
map <int, bool> bridge[maxn];
vi graph[maxn], tree[maxn];
vector <vi> components;

int t = 1;
vi stk;

void dfs0(int node, int par) {
    dfs_num[node] = dfs_low[node] = t++;
    int children = 0;
    stk.pb(node);
    for (int adj : graph[node]) {
        if (dfs_num[adj] == 0) {
            dfs0(adj, node);
            children++;
            if (dfs_num[node] <= dfs_low[adj]) {
                AP[node] = true;
                vi comp = {node};
                while (comp.back() != adj) {
                    comp.pb(stk.back());
                    stk.pop_back();
                }
                components.pb(comp);
            }
            if (dfs_num[node] < dfs_low[adj]) {
                bridge[node][adj] = bridge[adj][node] = true;
            }
            dfs_low[node] = min(dfs_low[node], dfs_low[adj]);
        }
        else if (adj != par) {
            dfs_low[node] = min(dfs_low[node], dfs_num[adj]);
        }
    }
}

void dfs1(int node, int par) {
    depth[node] = depth[par] + 1;
    P[node][0] = par;
    for (int adj : tree[node]) {
        if (adj != par) {
            dfs1(adj, node);
        }
    }
}

void build_tree() {
    //builds the block cut tree
    int n = 0;
    for (int i = 1; i <= N; i++) {
        if (AP[i]) {
            id[i] = ++n;
        }
    }
    for (vi comp : components) {
        n++;
        for (int u : comp) {
            if (AP[u]) {
                tree[n].pb(id[u]);
                tree[id[u]].pb(n);
            }
            else id[u] = n;
        }
    }
    dfs1(1, 0);
    for (int i = 1; i < 21; i++) {
        for (int u = 1; u <= n; u++) {
            P[u][i] = P[P[u][i-1]][i-1];
        }
    }
}


int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    int d = depth[u] - depth[v];
    for (int i = 20; i >= 0; i--) {
        if ((1 << i) & d) {
            u = P[u][i];
        }
    }
    if (u == v) return u;
    for (int i = 20; i >= 0; i--) {
        if (P[u][i] != P[v][i]) {
            u = P[u][i];
            v = P[v][i];
        }
    }
    return P[u][0];
}
inline bool isAncestorOf(int a, int b) {
    return lca(a, b) == a;
}

bool bothAbove(int A, int B, int C) {
    return (!isAncestorOf(C, A) && !isAncestorOf(C, B));
}

bool remainsConnected(int A, int B, int C) {
    if (bothAbove(A, B, C)) return true;
    return !isAncestorOf(lca(A, B), C);
}

int main() {
    int M;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u].pb(v);
        graph[v].pb(u);
    }
    dfs0(1, 0);
    build_tree();
    int Q;
    scanf("%d", &Q);
    while (Q--) {
        int type;
        scanf("%d", &type);
        bool disconnected = true;
        if (type == 1) {
            int A, B, u, v;
            scanf("%d %d %d %d", &A, &B, &u, &v);
            if (id[A] == id[B]) {
                disconnected = false;
            }
            else if (!bridge[u][v]) {
                disconnected = false;
            }
            else {
                if (AP[u] && AP[v]) {
                    A = id[A]; B = id[B]; u = id[u]; v = id[v];
                    if (depth[u] > depth[v]) swap(u, v);
                    if (remainsConnected(A, B, P[v][0])) disconnected = false;
                }
                else {
                    if (AP[u]) swap(u, v);
                    assert(!AP[u]);
                    if (A != u && B != u) disconnected = false;
                }
            }
        }
        else {
            int A, B, C;
            scanf("%d %d %d", &A, &B, &C);
            A = id[A]; B = id[B];
            if (A == B) disconnected = false;
            else if (!AP[C]) disconnected = false;
            else {
                C = id[C];
                if (remainsConnected(A, B, C)) disconnected = false;
            }
        }
        if (disconnected) printf("no\n");
        else printf("yes\n");
    }
}