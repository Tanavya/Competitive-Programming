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

const int maxn = (int) 1e5+7;
vector <vi> tree(maxn);
int lvl[maxn], dist[maxn], P[maxn][25], N;
bool mark[maxn], visited[maxn];

void dfs(int node, int par) {
    lvl[node] = lvl[par] + 1;
    P[node][0] = par;
    for (int adj : tree[node]) {
        if (adj != par) {
            dfs(adj, node);
        }
    }
}
void bfs() {
    queue <int> Q;
    for (int n = 1; n <= N; n++) {
        if (mark[n]) {
            dist[n] = 0;
            visited[n] = true;
            Q.push(n);
        }
        else {
            dist[n] = INF;
            visited[n] = false;
        }
    }
    while (!Q.empty()) {
        int curr = Q.front();
        Q.pop();
        for (int adj : tree[curr]) {
            if (!visited[adj]) {
                visited[adj] = true;
                dist[adj] = dist[curr] + 1;
                Q.push(adj);
            }
        }
    }
}
int lca(int u, int v) {
    if (lvl[u] < lvl[v])
        swap(u, v);
    int k = (int)ceil(log2(lvl[u]));
    for (int i = k; i >= 0; i--) {
        if (P[u][i] != -1 && lvl[P[u][i]] >= lvl[v]) {
            u = P[u][i];
        }
    }
    assert(lvl[u] == lvl[v]);
    if (u == v)
        return u;
    for (int i = k; i >= 0; i--) {
        if (P[u][i] != -1 && P[u][i] != P[v][i]) {
            u = P[u][i];
            v = P[v][i];
        }
    }
    assert(P[u][0] == P[v][0]);
    return P[u][0];
}
int main() {
	int M;
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N-1; i++) {
        int u, v;
	    scanf("%d %d", &u, &v);
	    tree[u].pb(v);
	    tree[v].pb(u);
	}
    memset(P, -1, sizeof(P));
    dfs(1, 0);
    for (int i = 1; i < 25; i++) {
        for (int u = 1; u <= N; u++) {
            if (P[u][i-1] != -1) {
                P[u][i] = P[P[u][i-1]][i-1];
            }
        }
    }
    //vector <ii> queries;
    int type, n;

    int block_size = (int)ceil(sqrt(M));
    mark[1] = true;
    for (int i = 0; i < M; i += block_size) {
        bfs();
        int lim = min(i+block_size, M);
        vi marked;
        for (int j = i; j < lim; j++) {
            scanf("%d %d", &type, &n);
            if (type == 1) {
                mark[n] = true;
                marked.pb(n);
            }
            else {
                int ans = dist[n];
                for (int x : marked) {
                    ans = min(ans, lvl[x] + lvl[n] - 2 * lvl[lca(x, n)]);
                }
                printf("%d\n", ans);
            }
        }
    }
    return 0;
}