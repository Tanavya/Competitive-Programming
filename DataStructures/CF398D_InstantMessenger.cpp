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

const int maxn = 50007;
bitset <maxn> online;
set <ii> edges;
vi graph[maxn];
unordered_map <int, int> mat[maxn];
int deg[maxn], ans[maxn];

int main() {
    int N, M, Q;
    scanf("%d %d %d", &N, &M, &Q);
    int O;
    scanf("%d", &O);
    vector <pair <char, ii>> queries;
    for (int i = 0; i < O; i++) {
        int x;
        scanf("%d", &x);
        queries.pb(mp('O', mp(x, -1)));
    }
    for (int i = 0; i < M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        if (u > v) swap(u, v);
        edges.insert(mp(u, v));
        queries.pb(mp('A', mp(u, v)));
    }
    for (int i = 0; i < Q; i++) {
        char type;
        scanf(" %c", &type);
        if (type == 'O' || type == 'F' || type == 'C') {
            int u;
            scanf("%d", &u);
            queries.pb(mp(type, mp(u, -1)));
        }
        else if (type == 'A' || type == 'D') {
            int u, v;
            scanf("%d %d", &u, &v);
            if (u > v) swap(u, v);
            edges.insert(mp(u, v));
            queries.pb(mp(type, mp(u, v)));
        }
    }
    M = 0;
    for (ii edge : edges) {
        int u = edge.fi, v = edge.se;
        deg[u]++;
        deg[v]++;
        graph[u].pb(v);
        graph[v].pb(u);
        M++;
    }
    int lim = (int) sqrt(M);
    vi heavy;
    for (int i = 1; i <= N; i++) {
        if (deg[i] > lim) {
            heavy.pb(i);
        }
    }
    for (pair <char, ii> query : queries) {
        char type = query.fi;
        if (type == 'O') {
            int u = query.se.fi;
            online[u] = true;
            if (deg[u] <= lim) {
                for (int v : graph[u]) {
                    if (mat[u][v]) {
                        ans[v]++;
                    }
                }
            }
        }
        else if (type == 'F') {
            int u = query.se.fi;
            online[u] = false;
            if (deg[u] <= lim) {
                for (int v : graph[u]) {
                    if (mat[u][v]) {
                        ans[v]--;
                    }
                }
            }
        }
        else if (type == 'A') {
            int u = query.se.fi, v = query.se.se;
            if (deg[u] > deg[v]) swap(u, v);
            if (deg[u] <= lim && deg[v] > lim) {
                if (online[u]) ans[v]++;
            }
            mat[u][v] = mat[v][u] = true;
        }
        else if (type == 'D') {
            int u = query.se.fi, v = query.se.se;
            if (deg[u] > deg[v]) swap(u, v);
            if (deg[u] <= lim && deg[v] > lim) {
                if (online[u]) ans[v]--;
            }
            mat[u][v] = mat[v][u] = false;
        }
        else {
            int u = query.se.fi;
            int res = 0;
            if (deg[u] <= lim) {
                for (int v : graph[u]) {
                    if (mat[u][v] && online[v]) {
                        res++;
                    }
                }
            }
            else {
                for (int v : heavy) {
                    if (mat[u][v] && online[v]) {
                        res++;
                    }
                }
                res += ans[u];
            }
            printf("%d\n", res);
        }
    }
}