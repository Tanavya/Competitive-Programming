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

const int maxn = (int) 1e5+10;
int N, M, block_size, parent[maxn], size[maxn], mark[maxn], buffer;

vector <int> graph[maxn];
bitset<640> visited;


vi removed, added;
int curr_edge = 1, modified[maxn], mat[640][640], all_edges[maxn];
map <int, map <int, int>> edges_map;
vector <ii> edges = {mp(0, 0)};

inline int scan() {
    int n = 0;
    int ch = getchar_unlocked();
    while (ch < 48) ch = getchar_unlocked();
    while (ch > 47)
        n = (n << 3) + (n << 1) + ch - '0', ch = getchar_unlocked();
    return n;
}

struct query {
    int type, edge;
    query (int t, int e) {
        type = t, edge = e;
    }
};
vector <query> queries;

int root(int x) {
    while (parent[x] != x) {
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
    return x;
}
inline int Find(int a, int b) {
    return root(a) == root(b);
}
void Union(int a, int b) {
    a = root(a);
    b = root(b);
    if (size[a] > size[b]) swap(a, b);
    size[b] += size[a];
    parent[a] = b;
}
//bool cmp(ii a, ii b) { return a.fi < b.fi;  }
void create_graph() {
    buffer = 0;
    memset(mat, 0, sizeof(mat));
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
        size[i] = 1;
        graph[i].clear();
        mark[i] = 0;
    }
    for (int edge = 1; edge <= curr_edge; edge++) {
        if (all_edges[edge] && !modified[edge]) {
            if (!Find(edges[edge].fi, edges[edge].se)) {
                Union(edges[edge].fi, edges[edge].se);;
            }
        }
    }

    while (!removed.empty()) {
        int edge = removed.back();
        removed.pop_back();
        modified[edge] = false;
        //cout << "edge : "; debug2(edge.fi, edge.se);
        int a = root(edges[edge].fi), b = root(edges[edge].se);
        //cout << "nodes: "; debug2(a, b);
        if (!mark[a])
            mark[a] = ++buffer;
        a = mark[a];
        if (!mark[b])
            mark[b] = ++buffer;
        b = mark[b];
        assert(buffer <= 640);
        //cout << "Compressed: "; debug2(a, b);
        mat[a][b]++;
        mat[b][a]++;
        if (mat[a][b] == 1) {
            graph[a].pb(b);
            graph[b].pb(a);
        }
    }
    while (!added.empty()) {
        int edge = added.back();
        added.pop_back();
        modified[edge] = false;
        int a = root(edges[edge].fi), b = root(edges[edge].se);
        if (!mark[a])
            mark[a] = ++buffer;
        if (!mark[b])
            mark[b] = ++buffer;
        a = mark[a];
        b = mark[b];
        if (!mat[a][b]) {
            graph[a].pb(b);
            graph[b].pb(a);
        }
    }
}
bool bfs(int node, int target) {
    if (node == target) return true;
    visited.reset();
    queue <int> Q;
    Q.push(node);
    while (!Q.empty()) {
        int curr = Q.front();
        Q.pop();
        if (curr == target) return true;
        visited[curr] = true;
        for (int adj : graph[curr]) {
            if (!visited[adj] && mat[adj][curr]) {
                visited[adj] = true;
                Q.push(adj);
            }
        }
    }
    return false;
}
void print_graph() {
    for (int n = 1; n <= N; n++) {
        cout << n << ": ";
        for (int adj : graph[n]) {
            cout << adj << " ";
        }
        cout << endl;
    }
}
int main() {
    //std::ios::sync_with_stdio(false);
    //cin.tie(NULL);

    int A, B;
    char type[6];
    scanf("%d %d", &N, &M);

    block_size = int(round(sqrt(M)));
    for (int i = 0; i < M; i += block_size) {
        for (int j = i; j < i + block_size && j < M; j++) {
            scanf("%s", type);
            scanf("%d %d", &A, &B);

            if (A > B) swap(A, B);

            if (!edges_map[A][B]) {
                edges.pb({A, B});
                edges_map[A][B] = curr_edge++;
            }
            int edge = edges_map[A][B];

            if (!strcmp(type, "add")) {
                modified[edge] = true;
                added.pb(edge);
                queries.pb(query(1, edge));
            }
            else if (!strcmp(type, "rem")) {
                if (!modified[edge]) {
                    removed.pb(edge);
                    modified[edge] = true;
                }
                queries.pb(query(2, edge));
            }
            else {
                queries.pb(query(3, edge));
            }
        }
        create_graph();
        //print_graph();

        for (int j = i; j < i + block_size && j < M; j++) {
            int edge = queries[j].edge;
            A = edges[edge].fi;
            B = edges[edge].se;
            if (queries[j].type == 1) {
                all_edges[edge] = 1;
                A = mark[root(A)];
                B = mark[root(B)];
                mat[A][B]++;
                mat[B][A]++;
            }
            else if (queries[j].type == 2) {
                all_edges[edge] = 0;
                A = mark[root(A)];
                B = mark[root(B)];
                mat[A][B]--;
                mat[B][A]--;
            }
            else {
                //cout << "Original Query  : "; debug2(A, B);
                //cout << "Roots of Query  : "; debug2(root(A), root(B));
                //cout << "Compressed Query: "; debug2(mark[root(A)], mark[root(B)]);
                if (Find(A, B)) printf("YES\n");
                else if (bfs(mark[root(A)], mark[root(B)])) printf("YES\n");
                else printf("NO\n");
            }
        }
    }
}
