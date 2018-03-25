#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <stdio.h>
#include <queue>
#include <set>
#include <list>
#include <cstring>
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
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << "\n";

typedef long long int ll;
typedef long double ld;
typedef std::pair <int, int> ii;
typedef std::vector <int> vi;
typedef std::vector <ll> vll;
const int INF = int(1e9);
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

using namespace std;


int N, M;
vector <vi> graph;
vector <pair<int, ii>> edges;
vi deg;
vi parent;
int dsu_count;
int root(int x) {
    while (parent[x] != x) {
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
    return x;
}
bool Find(int a, int b) {
    return root(a) == root(b);
}
void Union(int a, int b) {
    int root_a = root(a), root_b = root(b);
    if (root_a == root_b) return;
    parent[root_a] = root_b;
    dsu_count--;
    assert(dsu_count > 0);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &N, &M);

        graph.assign(N+7, {});
        deg.assign(N+7, 0);
        parent.assign(N+7, 0);
        edges.clear();
        dsu_count = N;

        int u,v;
        for (int i = 0; i < M; i++) {
            scanf("%d %d", &u, &v);
            graph[u].pb(v);
            graph[v].pb(u);
            deg[u]++;
            deg[v]++;
            edges.pb({0, {u, v}});
        }
        for (int i = 0; i < M; i++) {
            edges[i].x = min(deg[edges[i].y.x], deg[edges[i].y.y]);
        }
        sort(edges.begin(), edges.end());
        //for (int i = 0; i < M; i++) cout << edges[i].x << " "<< edges[i].y.x << " " << edges[i].y.y << endl;
        for (int x = 1; x <= N; x++) {
            parent[x] = x;
        }
        vi ans(N+7, 0);
        for (int d = N; d >= 1; d--) {
            while (!edges.empty()) {
                ii edge = edges.back().y;
                if (edges.back().x == d) {
                    edges.pop_back();
                    u = edge.x, v = edge.y;
                    Union(u, v);
                }
                else break;
            }
            ans[d-1] = dsu_count - 1;
            //cout << dsu_count-1 << " ";
        }
        //cout << endl;
        for (int i = 0; i < N; i++) printf("%d ", ans[i]); printf("\n");
    }  
}