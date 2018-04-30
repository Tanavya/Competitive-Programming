#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <assert.h>
#include <map>
#include <queue>
#include <set>


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

const int INF = int(1e9);
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
using namespace std;

const int maxn = 50007;
vi tree[maxn], downValues[maxn];
int N, K, parent[maxn], dpDown[maxn], dpUp[maxn];

void dfs1(int node, int par) {
    parent[node] = par;
    dpDown[node] = 1;
    for (int adj : tree[node]) {
        if (adj != par) {
            dfs1(adj, node);
            downValues[node].pb(dpDown[adj]);
        }
    }
    sort(downValues[node].rbegin(), downValues[node].rend());
    dpDown[node] = 1 + (downValues[node].empty() ? 0 : downValues[node][0]);
}

void dfs2(int node, int par) {
    if (node != 1)
        dpUp[node] = max(dpUp[node], dpUp[par] + 1);
    for (int adj : tree[node]) {
        if (adj != par) {
            if (downValues[node].size() >= 2) {
                if (downValues[node][0] == dpDown[adj])
                    dpUp[adj] = 1 + downValues[node][1];
                else
                    dpUp[adj] = 1 + downValues[node][0];
            }
            dfs2(adj, node);
        }
    }
}

int main() {
    scanf("%d %d", &N, &K);
    for (int i = 1; i < N; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u++; v++;
        tree[u].pb(v);
        tree[v].pb(u);
    }
    dfs1(1, 0);
    dfs2(1, 0);
    int ans = 0;
    for (int node = 1; node <= N; node++) {
        vi values = {dpUp[node]};
        for (int adj : tree[node]) {
            if (adj != parent[node]) {
                values.pb(dpDown[adj]);
            }
        }
        sort(values.rbegin(), values.rend());
        int tmp = 1;
        for (int i = 0; i < K && i < values.size(); i++)
            tmp += values[i];
        ans = max(ans, tmp);
    }
    assert(ans <= N);
    printf("%d\n", ans);
}
/*
6 3
0 1
1 2
1 3
3 4
3 5
 */