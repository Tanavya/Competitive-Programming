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

const int maxn = 200007;
int N, M, block_size, size[maxn], parent[maxn], res[maxn], components_count = 0;
bool mark[maxn], visited[maxn];
vi small_graph[maxn];


struct query {
    int i, L, R;
    query(int i, int L, int R): i(i), L(L), R(R) {}
};

bool cmp(query a, query b) {
    return a.R < b.R;
}

int root(int x) {
    while (x != parent[x]) {
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
    return x;
}
inline void Union(int a, int b) {
    a = root(a), b = root(b);
    if (a == b) return;
    components_count--;
    if (size[a] < size[b]) swap(a, b);
    size[a] += size[b];
    parent[b] = a;
}

inline void init_dsu() {
    components_count = N;
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
        size[i] = 1;
    }
}

int DFS(int node) {
    visited[node] = true;
    int ret = 1;
    for (int adj : small_graph[node]) {
        if (!visited[adj]) {
            ret += DFS(adj);
        }
    }
    return ret;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {

        int Q;

        scanf("%d %d %d", &N, &M, &Q);

        vector <ii> edges;
        block_size = (int)sqrt(M);
        vector <query> blocks[block_size+10];

        for (int i = 0; i < M; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            edges.pb(mp(u, v));
        }

        for (int i = 0; i < Q; i++) {
            int L, R;
            scanf("%d %d", &L, &R);
            L--;
            R--;
            if (R - L <= block_size+7) {
                vi nodes;
                for (int __j = L; __j <= R; __j++) {
                    int u = edges[__j].fi, v = edges[__j].se;
                    if (u == v) continue;
                    small_graph[u].pb(v);
                    small_graph[v].pb(u);
                    nodes.pb(v);
                    nodes.pb(u);
                }
                int small_components = N;
                for (int node : nodes) {
                    if (!visited[node]) {
                        small_components++;
                        small_components -= DFS(node);
                    }
                }
                for (int node : nodes) {
                    small_graph[node].clear();
                    visited[node] = false;
                }
                res[i] = small_components;
            }
            else {
                blocks[L/block_size + 1].pb(query(i, L, R));
            }
        }

        for (int i = 0; i < M; i += block_size) {
            int b = i/block_size+1;
            if (!blocks[b].empty()) {
                sort(all(blocks[b]), cmp);
                init_dsu();
                int R = b * block_size;
                for (query q : blocks[b]) {
                    //assert(q.R >= R);
                    for (; R <= q.R; R++) {
                        Union(edges[R].fi, edges[R].se);
                    }
                    R--;
                    vi nodes;
                    int cnt = 0;
                    for (int L = (b * block_size) - 1; L >= q.L; L--) {
                        int u = root(edges[L].fi), v = root(edges[L].se);
                        if (u == v) continue;
                        if (!mark[u]) {
                            mark[u] = true;
                            cnt++;
                        }
                        if (!mark[v]) {
                            mark[v] = true;
                            cnt++;
                        }
                        small_graph[u].pb(v);
                        small_graph[v].pb(u);
                        nodes.pb(v);
                        nodes.pb(u);
                    }

                    int ans = components_count - cnt;

                    for (int node : nodes) {
                        if (!visited[node]) {
                            ans++;
                            DFS(node);
                        }
                    }
                    for (int node : nodes) {
                        mark[root(node)] = visited[node] = false;
                        small_graph[node].clear();
                    }
                    res[q.i] = ans;
                }
            }
        }
        for (int i = 0; i < Q; i++) printf("%d\n", res[i]);
    }
}