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


#define MAX(a,b) ((a)>(b)?(a):(b))
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

using namespace std;

const int maxn = (int) 5e5+7;
vector <vi> graph(maxn);
int parent[maxn], cnt[maxn], heaviest[maxn], N, M;
vector <pair <ii, ii>> edges_org, edges_sort;


int root(int x) {
    while (parent[x] != x) {
        parent[x] = parent[parent[x]] = x;
    }
    return x;
}

bool Find(int a, int b) {
    return root(a) == root(b);
}
void Union(int a, int b) {
    parent[root(a)] = parent[root(b)];
}

void kruskals() {
    int x;
    for (int i = 0; i < M; i++) {
        x = edges_sort[i].fi.fi;
        bool same = true;
        vector <ii> to_union;
        while (same && i < M) {
            same = (edges_sort[i].fi.fi == x);
            pair <ii, ii> edge = edges_sort[i];
            int w = edge.fi.fi, j = edge.fi.se;
            int u = edge.se.fi, v = edge.se.se;
            if (Find(u, v)) {
                heaviest[j] = true;
            }
            else {
                to_union.pb({u, v});
            }
            i++;
        }
        while (!to_union.empty()) {
            ii p = to_union.back();
            to_union.pop_back();
            if (!Find(p.fi, p.se)) {
                cnt[x]++;
                Union(p.fi, p.se);
            }
        }
    }
}
int main() {
    int u, v, w;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &u, &v, &w);
        edges_org.pb({{w, i}, {u, v}});
    }
    for (int i = 1; i <= N; i++)
        parent[i] = i;
    edges_sort = edges_org;
    sort(edges_sort.begin(), edges_sort.end());
    kruskals();
    int n, x;
    for (int i = 0; i < M; i++) {
        scanf("%d", &n);
        bool ans = true;
        for (int j = 0; j < n; j++) {
            scanf("%d", &x);
            if (heaviest[x])
                ans = false;

        }
        if (ans) printf("YES\n");
        else printf("NO\n");
    }
}