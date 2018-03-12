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
vi tree[maxn];
int N, block_size, ans, A[maxn], cnt[maxn], head[maxn], parent[maxn], res[maxn], depth[maxn];
bool mark[maxn];
map <int, int> HASH;

struct query {
    int u, v, i;
    query() {}
    query(int u, int v, int i): u(u), v(v), i(i) {}
};

vector <query> queries[maxn];
vector <query> right_bounds[maxn];

//divide tree into O(sqrt N) subtrees of depth O(sqrt N)
void dfs1(int node, int par, int d, int nearest) {
    parent[node] = par;
    depth[node] = 1 + depth[par];
    if (par == 0 || d >= block_size) {
        mark[node] = true;
        d = 0;
        nearest = node;
    }
    head[node] = nearest;
    for (int adj : tree[node]) {
        if (adj != par) {
            dfs1(adj, node, d+1, nearest);
        }
    }
}

void dfs2(int node, int par) {
    cnt[A[node]]++;
    if (cnt[A[node]] == 1)
        ans++;
    for (query q : right_bounds[node]) {
        int u = q.u;
        res[q.i] = ans;
        vi changed;
        while (true) {
            cnt[A[u]]++;
            if (cnt[A[u]] == 1)
                res[q.i]++;
            changed.pb(A[u]);
            if (u == head[u])
                break;
            u = parent[u];
        }
        for (int x : changed) {
            cnt[x]--;
        }
    }
    for (int adj : tree[node]) {
        if (adj != par) {
            dfs2(adj, node);
        }
    }
    cnt[A[node]]--;
    if (cnt[A[node]] == 0)
        ans--;
}

int main() {
    int M;
    scanf("%d %d", &N, &M);
    int t = 0;
    for (int i = 1; i <= N; i++) {
        int x;
        scanf("%d", &x);
        if (!HASH[x])
            HASH[x] = ++t;
        A[i] = HASH[x];
    }
    block_size = (int) sqrt(N);
    for (int i = 1; i < N; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        tree[u].pb(v);
        tree[v].pb(u);
    }
    dfs1(1, 0, 0, 0);
    set <int> S;
    for (int i = 0; i < M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        if (depth[u] < depth[v])
            swap(u, v);
        if (u == v) {
            res[i] = 1;
        }
        else if (head[u] == head[v]) {
            //brute
            //similar to binary lifting
            //ugh wasted so much time on this fml, isse acha toh LCA hi kar leta
            ans = 0;
            vi changed;
            while (depth[u] > depth[v]) {
                cnt[A[u]]++;
                if (cnt[A[u]] == 1)
                    ans++;
                changed.pb(A[u]);
                u = parent[u];
            }
            while (true) {
                for (int x : {A[u], A[v]}) {
                    cnt[x]++;
                    if (cnt[x] == 1)
                        ans++;
                    changed.pb(x);
                }
                if (u == v) break;
                u = parent[u];
                v = parent[v];
            }
            res[i] = ans;
            for (int x : changed) {
                cnt[x]--;
            }
        }
        else {
            int z = head[u];
            S.insert(z);
            queries[z].pb(query(u, v, i));
        }
    }
    for (int z : S) {
        ans = 0;
        for (query q : queries[z]) {
            right_bounds[q.v].pb(q);
        }
        dfs2(z, 0);
        for (query q : queries[z]) {
            right_bounds[q.v].clear();
        }
    }
    for (int i = 0; i < M; i++) {
        printf("%d\n", res[i]);
    }
}