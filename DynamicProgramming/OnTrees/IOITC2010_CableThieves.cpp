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

const int maxn = 100007, mod = 100000;
vi tree[maxn];
vector <vll> dpDown(maxn, vll(6, 0)), dpUp(maxn, vll(6, 0));
int choose[6][6], parent[maxn], D;

int binomial(int d, vll &A, vll &B) {
    ll val = 0;
    for (int i = 0; i <= d; i++) {
        val += (A[i] * B[d-i] * choose[d][i]);
        val %= mod;
    }
    return (int) val;
}

void dfs(int node, int par) {
    parent[node] = par;
    dpDown[node][0] = 1;
    for (int adj : tree[node]) {
        if (adj != par) {
            dfs(adj, node);
            vll tmp(D+1, 1);
            for (int d = 0; d <= D; d++) {
                dpDown[node][d] += binomial(d, dpDown[adj], tmp);
                dpDown[node][d] %= mod;
            }
        }
    }
    for (int adj : tree[node]) {
        if (adj != par) {
            vll tmp(D+1, 1);
            for (int d = 0; d <= D; d++) {
                dpUp[adj][d] = dpDown[node][d] - binomial(d, dpDown[adj], tmp);
                dpUp[adj][d] += mod;
                dpUp[adj][d] %= mod;
            }
        }
    }
}

void dfs2(int node, int par) {
    for (int adj : tree[node]) {
        if (adj != par) {
            for (int d = 0; d <= D; d++) {
                dpUp[adj][d] += dpUp[node][d];
                dpUp[adj][d] %= mod;
            }
            vll tmp(D+1, 1);
            for (int d = D; d >= 0; d--) {
                dpUp[adj][d] = binomial(d, dpUp[adj], tmp);
            }
            dfs2(adj, node);
        }
    }
}

int main() {
    choose[0][0] = 1;
    for (int n = 1; n <= 5; n++) {
        for (int k = 0; k <= 5; k++) {
            choose[n][k] = (k ? choose[n-1][k-1] : 0) + choose[n-1][k];
        }
    }
    int N;
    scanf("%d %d", &N, &D);
    vector <ii> edges;
    for (int i = 1; i < N; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        tree[u].pb(v);
        tree[v].pb(u);
        edges.pb(mp(u, v));
    }
    dfs(1, 0);
    dfs2(1, 0);
    for (ii edge : edges) {
        int u = edge.fi, v = edge.se;
        if (parent[v] == u) swap(u, v);
        int ans = binomial(D, dpDown[u], dpUp[u]);
        printf("%d\n", ans);
    }
}
/*
5 1
1 2
2 3
2 4
4 5
 */

/*
6 3
1 2
3 2
2 4
4 5
1 6
 */