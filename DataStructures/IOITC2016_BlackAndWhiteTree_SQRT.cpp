//incomplete
//too lazy
//:P
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
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip> //cout << setprecision(node) << fixed << num

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
typedef std::vector <ii> vii;
typedef std::vector <ll> vll;
typedef std::vector <ld> vld;

const int INF = int(1e9);
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
using namespace std;

const int maxn = (int) 2e5+10;
int N, ans[maxn], size[maxn], depth[maxn], P[maxn], col[maxn], head[maxn], block_size;
set <int> tree[maxn];
bitset <maxn> visited;

int lca(int a,int b){
    if (depth[a] > depth[b])
        swap(a,b);
    while (depth[b] > depth[a]) b = P[b];
    while (a != b) {
        a = P[a];
        b = P[b];
    }
    return a;
}

void dfs0(int node) {
    depth[node] = depth[P[node]] + 1;
    size[node] = 1;
    for (int adj : tree[node]) {
        dfs0(adj);
        size[node] += size[adj];
    }
}

void dfs1(int node, int &cnt) {
    visited[node] = true;
    for (int adj : tree[node]) {
        if (cnt+1 <= block_size) {
            ans[adj] = ans[node] + col[adj];
            head[adj] = head[node];
            dfs1(adj, ++cnt);
        }
        else
            return;
    }
}

void update(int u) {
    ans[u] -= col[u];
    col[u] ^= 1;
    int cnt = 1;
    dfs1(u, cnt);
}

int query(int u, int v, int k) {
    int a = u, b = v;
    int su = 0, sv = 0;
    while (head[u] != head[v]) {
        if (depth[head[u]] < depth[head[v]]){
            sv += ans[v];
            v = P[head[v]];
        }
        else {
            if (su + ans[u] >= k) {
                k -= su;
                while (k) {
                    if (col[u]) k--;
                    if (k) u = P[u];
                }
                return u;
            }
            su += ans[u];
            u = P[head[u]];
        }
    }
    int LCA = lca(u, v);
    su += ans[u] - ans[LCA];
    sv += ans[v] - ans[LCA] + col[LCA];
    u = a, v = b;
    if (su + sv < k) return -1;
    else if (k > su) {
        k = sv - (k - su) + 1;
        swap(u, v);
    }
//    debug2(u, k);
    while (head[u] != head[LCA]) {
        int val = ans[u];
        if (val < k)
            k -= val;
        else {
            while (k) {
                if (col[u]) k--;
                if (k) u = P[u];
            }
            return u;
        }
        u = P[head[u]];
    }
    while (k) {
        if (col[u]) k--;
        if (k) u = P[u];
    }
    return u;
}

void preprocess() {
    dfs0(1);
    for (int u = 1; u <= N; u++) {
        if (!visited[u]) {
            int cnt = 1;
            ans[u] = col[u];
            head[u] = u;
            dfs1(u, cnt);
        }
    }
//    for (int i = 1; i <= N; i++) printf("head[%d] = %d\n", i, head[i]);
}

int main() {
    int Q;
    scanf("%d %d", &N, &Q);
    block_size = 500;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &col[i]);
    }
    for (int i = 2; i <= N; i++) {
        scanf("%d", &P[i]);
        tree[P[i]].insert(i);
    }
    preprocess();
    while (Q--) {
        char type;
        scanf("%s ", &type);
        if (type == 'T') {
            int u;
            scanf("%d", &u);
            update(u);
        }
        else if (type == 'C') assert(false);
        else {
            int u, v, k;
            scanf("%d %d %d", &u, &v, &k);
            printf("%d\n", query(u, v, k));
        }
    }
}
/*
7 7
1 1 1 1 1 1 1
1 1 1 2 2 4
Q 5 3 2
T 1
Q 7 2 3
C 7 3
T 2
Q 6 7 3
Q 4 1 2

 */