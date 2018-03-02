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

const int maxn = (int)1e6+10;
vi tree[maxn], tree2[maxn];
int A[maxn], parent[maxn], size[maxn];
bool visited[maxn];
ll maxima_sum = 0, minima_sum = 0;

inline void init(int x) {
    parent[x] = x;
    size[x] = 1;
    visited[x] = false;
}

inline int root(int x) {
    while (parent[x] != x) {
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
    return x;
}

inline void Union(int a, int b) {
    a = root(a), b = root(b);
    if (a == b) return;
    if (size[a] < size[b]) swap(a, b);
    size[a] += size[b];
    parent[b] = a;

}

int main() {
    int N;
    scanf("%d", &N);
    vector <ii> V;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &A[i]);
        V.pb(mp(A[i], i));
    }
    for (int i = 0; i < N-1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        tree[u].pb(v);
        tree[v].pb(u);
    }
    sort(all(V));
    for (int i = 1; i <= N; i++) init(i);
    for (int i = N-1; i >= 0; i--) {
        int node = V[i].se;
        visited[node] = true;
        ll s = 1;
        for (int adj : tree[node]) {
            if (visited[adj]) {
                s += size[root(adj)];
                minima_sum += size[root(adj)] * 1LL * A[node] * (s - size[root(adj)]);
                Union(node, adj);
            }
        }
    }
    for (int i = 1; i <= N; i++) init(i);
    for (int i = 0; i < N; i++) {
        int node = V[i].se;
        visited[node] = true;
        ll s = 1;
        for (int adj : tree[node]) {
            if (visited[adj]) {
                s += size[root(adj)];
                maxima_sum += size[root(adj)] * 1LL * A[node] * (s - size[root(adj)]);
                Union(node, adj);
            }
        }
    }
    printf("%lld\n", maxima_sum - minima_sum);
 }