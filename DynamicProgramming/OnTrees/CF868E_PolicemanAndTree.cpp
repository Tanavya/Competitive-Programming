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

const int maxn = 57;
vi tree[maxn], leavesDown[maxn], leavesUp[maxn], leaves;
int dp[maxn][maxn], dpUp[maxn][maxn], cnt[maxn], parent[maxn];

void dfs1(int node, int par) {
    parent[node] = par;
    for (int adj : tree[node]) {
        if (adj != par) {
            dfs1(adj, node);
            cnt[node] += cnt[adj];
        }
    }
}

void dfs2(int node, int par) {
    int child_count = 0;
    for (int adj : tree[node]) {
        if (adj != par) {
            dfs2(adj, node);
            child_count++;
        }
    }
    if (!child_count)
        leaves.pb(node);
}

int main() {
    int N, M, root;
    scanf("%d", &N);
    for (int i = 0; i < N-1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        tree[u].pb(v);
        tree[v].pb(u);
    }
    scanf("%d", &root);
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        int x;
        scanf("%d", &x);
        if (x == root) continue;
        cnt[x]++;
    }
    dfs1(root, 0);
    for (int i = 1; i <= N; i++) {
        leaves.clear();
        dfs2(i, parent[i]);
        leavesDown[i] = leaves;
        leaves.clear();
        dfs2(parent[i], i);
        leavesUp[i] = leaves;
    }
    for (int subtree : tree[root]) {

    }
}