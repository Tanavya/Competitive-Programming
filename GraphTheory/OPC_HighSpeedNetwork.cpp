//Problem Link: http://opc.iarcs.org.in/index.php/problems/HISPDNET
//Problem type: Graph Theory

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
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip> //cout << setprecision(node) << fixed << num
 
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << endl;
 
typedef long long int ll;
typedef long double ld;
typedef std::pair <int, int> ii;
typedef std::vector <int> vi;
typedef std::vector <ll> vll;
const int INF = int(1e9);
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
using namespace std;

int parent[2007], size[2007], grid[2007][2007];
int root(int x) {
    while (parent[x] != x) {
        x = parent[x] = parent[parent[x]];
    }
    return x;
}
bool Find(int a, int b) {
    return root(a) == root(b);
}
void Union(int a, int b) {
    int root_a = root(a), root_b = root(b);
    if (root_a != root_b) {
        if (size[root_a] < size[root_b]) {
            parent[root_a] = root_b;
            size[root_b] += size[root_a];
        }
        else {
            parent[root_b] = root_a;
            size[root_a] += size[root_b];
        }
    }
}
int main() {
    int N, w;
    scanf("%d", &N);
    vector <pair<int, ii>> edges;
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
        size[i] = 1;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%d", &w);
            if (i > 1 && j > 1 && i < j) {
                edges.pb(mp(w, mp(i, j)));
            }
        }
    }
    sort(edges.begin(), edges.end());
    ll ans = 0;
    for (pair <int, ii> p : edges) {
        int w = p.x, a = p.y.x, b = p.y.y;
        if (!Find(a, b)) {
            Union(a, b);
            ans += w;
        }
    }
    printf("%lld\n", ans);
}