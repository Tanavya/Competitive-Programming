#include <iostream>
#include <vector>
#include <stdio.h>
#include <assert.h>
#include <bitset>
#include <algorithm>

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

const int INF = 2147483647;
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
using namespace std;

const int maxn = (int)1e6+10;
int A[maxn], parent[maxn];
ll size[maxn];

int root(int x) {
    while (parent[x] != x) {
        x = parent[x] = parent[parent[x]];
    }
    return x;
}
void Union(int a, int b) {
    a = root(a); b = root(b);
    if (a == b) return;
    if (size[a] < size[b]) swap(a, b);
    size[a] += size[b];
    parent[b] = a;
}

int main() {
    int N;
    scanf("%d", &N);
    vector <pair <int, ii>> edges;
    for (int i = 1; i < N; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        edges.pb(mp(w, mp(u, v)));
    }
    sort(edges.rbegin(), edges.rend());
    ll ans = 0;
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
        size[i] = 1;
    }
    for (pair <int, ii> edge : edges) {
        int w = edge.fi, u = edge.se.fi, v = edge.se.se;
        ans += (ll)w * (size[root(u)] * size[root(v)]);
        Union(u, v);
    }
    printf("%lld\n", ans);
}
/*
4
1 2 2
2 3 1
2 4 3
*/