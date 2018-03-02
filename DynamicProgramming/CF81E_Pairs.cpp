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
#include <iomanip>
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

const int maxn = (int) 1e5+7;
vi tree[maxn], graph[maxn], comp;
vector <ii> pairs;
int gender[maxn], bff[maxn], dp[maxn][2], dp2[maxn][2], parent[maxn], N;
bool visited[maxn];
ii nxt[maxn][2];

void dfs(int node, int par) {
    dp[node][0] = dp[node][1] = dp2[node][0] = dp2[node][1] = 0;
    nxt[node][1] = mp(0, 0);
    for (int adj : tree[node]) {
        if (adj != par) {
            dfs(adj, node);
            dp[node][1] += dp[adj][0];
            dp2[node][1] += dp2[adj][0];
        }
    }
    for (int adj : tree[node]) {
        if (adj != par) {
            int tmp = dp[adj][1] + 1 + dp[node][1] - dp[adj][0];
            if (dp[node][0] < tmp) {
                dp[node][0] = tmp;
                dp2[node][0] = dp2[adj][1] + (gender[node] != gender[adj]) + dp2[node][1] - dp2[adj][0];
                nxt[node][0] = mp(adj, 1);
            }
            else if (dp[node][0] == tmp) {
                tmp = dp2[adj][1] + (gender[node] != gender[adj]) + dp2[node][1] - dp2[adj][0];
                if (tmp > dp2[node][0]) {
                    dp2[node][0] = tmp;
                    nxt[node][0] = mp(adj, 1);
                }
            }
        }
    }
    if (dp[node][1] > dp[node][0]) {
        dp[node][0] = dp[node][1];
        dp2[node][0] = dp2[node][1];
        nxt[node][0] = {0, 1};
    }
    else if (dp[node][1] == dp[node][0]) {
        if (dp2[node][1] > dp2[node][0]) {
            dp2[node][0] = dp2[node][1];
            nxt[node][0] = {0, 1};
        }
    }
}
vector <ii> pairings, final_pairings;

void dfs2(int node, int par, int type) {
    ii nxt_pair = nxt[node][type];
    if (type == 1 && par != 0) {
        pairings.pb(mp(node, par));
    }
    for (int adj : tree[node]) {
        if (adj != par) {
            if (adj == nxt_pair.fi) {
                dfs2(adj, node, 1);
            }
            else {
                dfs2(adj, node, 0);
            }
        }
    }
}

void dfsFindComponents(int node) {
    visited[node] = true;
    comp.pb(node);
    for (int adj : graph[node]) {
        if (!visited[adj]) {
            dfsFindComponents(adj);
        }
    }
}

int root(int x) {
    while (parent[x] != x) {
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
    return x;
}

inline void Union(int a, int b) {
    a = root(a), b = root(b);
    parent[a] = b;
}

inline bool Find(int a, int b) {
    return root(a) == root(b);
}

ii solve(vi &component) {

    int start = 0;
    ii problem_edge = mp(-1, -1);
    set <ii> edges;
    for (int n : component) {
        if (Find(n, bff[n])) {
            assert(problem_edge == mp(-1, -1));
            problem_edge = mp(n, bff[n]);
        }
        else {
            Union(n, bff[n]);
            int u = n, v = bff[n];
            if (u > v) swap(u, v);
            edges.insert(mp(u, v));
            if (!start) start = u;
            tree[u].pb(v);
            tree[v].pb(u);
        }
    }
    pairings.clear();
    dfs(start, 0);
    int t = dp[start][0], e = dp2[start][0];
    dfs2(start, 0, 0);

    //create second graph
    start = 0;
    int u = problem_edge.se, v = bff[problem_edge.se];
    if (u > v) swap(u, v);
    edges.erase(mp(u, v));
    edges.insert(problem_edge);
    for (int n : component) {
        tree[n].clear();
        tree[bff[n]].clear();
    }
    for (ii edge : edges) {
        if (!start) start = edge.fi;
        tree[edge.fi].pb(edge.se);
        tree[edge.se].pb(edge.fi);
    }
    //second graph made

    dfs(start, 0);
    if (dp[start][0] > t) {
        t = dp[start][0];
        e = dp2[start][0];
        pairings.clear();
        dfs2(start, 0, 0);
    }
    else if (dp[start][0] == t && dp2[start][0] > e) {
        e = dp2[start][0];
        pairings.clear();
        dfs2(start, 0, 0);
    }

    for (ii p : pairings) {
        final_pairings.pb(p);
    }
    return mp(t, e);
}

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        int v;
        scanf("%d %d", &v, &gender[i]);
        pairs.pb(mp(i, v));
        graph[i].pb(v);
        graph[v].pb(i);
        bff[i] = v;
        parent[i] = i;
    }
    vector <vi> components;
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            comp.clear();
            dfsFindComponents(i);
            components.pb(comp);
        }
    }
    memset(visited, false, sizeof(visited));
    int t = 0, e = 0;
    for (int i = 0; i < components.size(); i++) {
        ii ret = solve(components[i]);
        t += ret.fi, e += ret.se;
    }
    printf("%d %d\n", t, e);
    for (ii p : final_pairings) {
        printf("%d %d\n", p.fi, p.se);
    }
}