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

const int maxn = (int) 1e5+10;
int sz[maxn], in[maxn], euler[maxn], out[maxn], nxt[maxn];
vi tree[maxn];

//slightly changes structure of tree array such that
//edge (node -> tree[node][0]) is the heavy edge, from node to heaviest child
void dfs_sz(int v, int par) {
    sz[v] = 1;
    for (int &u: tree[v]) {
        if (u != par) {
            dfs_sz(u, v);
            sz[v] += sz[u];
            if (sz[u] > sz[tree[v][0]])
                swap(u, tree[v][0]);
        }
    }
}
int t = 0;
//processes a euler tour array such that
//in[u] to out[u] gives subtree of u
//in[nxt[u]] to in[u] is segment giving path from
//u to nxt[u] i.e last vertex in ascending heavy path from u
void dfs_hld(int v, int par) {
    in[v] = ++t;
    euler[in[v]] = v;
    for (int u: tree[v]) {
        if (u != par) {
            nxt[u] = (u == tree[v][0] ? nxt[v] : u);
            dfs_hld(u, v);
        }
    }
    out[v] = t;
}
int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        tree[u].pb(v);
        tree[v].pb(u);
    }
    dfs_sz(1, 0);
    dfs_hld(1, 0);
    for (int i = 1; i <= N; i++) {
        printf("in[%d] = %d\n", i, in[i]);
        printf("out[%d] = %d\n", i, out[i]);
    }
    for (int i = 0; i < t; i++) cout << euler[i] << " "; cout << endl;
}