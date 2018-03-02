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

const int maxn = (int) 1e5+10;
int N, M, size[maxn], parent[maxn];
vector <ii> edges[maxn];
vi components[maxn];
bool used[maxn], big_groups[700][maxn];
map <int, int> cnt[maxn];

/*
struct query {
    int u, v, i;
    query() {}
    query(int u, int v, int i): u(u), v(v), i(i) {}
};

bool cmp (query a, query b) {
    if (a.u != b.u)
        return a.u < b.u;
    return a.v < b.v;
}*/

inline int root(int x) {
    while (parent[x] != x) {
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
    return x;
}

void Union(int a, int b) {
    a = root(a), b = root(b);
    if (a == b) return;
    if (size[a] < size[b]) swap(a, b);
    size[a] += size[b];
    parent[b] = a;
    components[a].insert(components[a].end(), all(components[b]));
}

int main() {
    scanf("%d %d", &N, &M);
    int block_size = 450;
    set <int> S;
    for (int i = 0; i < M; i++) {
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);
        edges[c].pb(mp(u, v));
        S.insert(c);
    }
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
        size[i] = 1;
        components[i] = {i};
    }
    int b = 0;
    for (int c: S) {
        vi modified;
        for (ii edge : edges[c]) {
            int u = edge.fi, v = edge.se;
            modified.pb(u);
            modified.pb(v);
            Union(u, v);
        }
        for (int n : modified) {
            n = root(n);
            if (!used[n]) {
                used[n] = true;
                vi comp = components[n];
                if (comp.size() < block_size) {
                    for (int u : comp) {
                        for (int v : comp) {
                            cnt[u][v]++;
                        }
                    }
                }
                else {
                    for (int u : comp) big_groups[b][u] = true;
                    b++;
                }
            }
        }
        for (int u : modified) {
            parent[u] = u;
            size[u] = 1;
            used[u] = false;
            components[u] = {u};
        }
    }
    int Q;
    scanf("%d", &Q);
    for (int i = 0; i < Q; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        int ans = 0;
        for (int j = 0; j < b; j++) {
            if (big_groups[j][u] && big_groups[j][v]) ans++;
        }
        ans += cnt[u][v];
        printf("%d\n", ans);
    }
}