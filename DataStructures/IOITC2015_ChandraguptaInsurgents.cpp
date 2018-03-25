#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <assert.h>
#include <set>
#include <queue>
#include <bitset>

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

const int maxn = (int)1e5+10;
int N;
struct node {
    int min = 0, cnt = 0, lazy = 0;
    node(int min = 0, int cnt = 0, int lazy = 0): min(min), cnt(cnt), lazy(lazy) {}
};
node T[4*maxn];

int left(int x) { return (x << 1); }
int right(int x) { return (x << 1) + 1; }

//brute functions
multiset <int> graph[maxn];
multiset <ii> edges;

void erase(int u, int val) {
    graph[u].erase(graph[u].find(val));
}
void brute_insert(int u, int v) {
    if (u > v) swap(u, v);
    graph[u].insert(v);
    graph[v].insert(u);
    edges.insert(mp(u, v));
}
void brute_erase(int u, int v) {
    if (u > v) swap(u, v);
    erase(u, v);
    erase(v, u);
    edges.erase(edges.find(mp(u, v)));
}
bool can_reach(int u, int v) {
    queue <int> Q;
    Q.push(u);
    bitset <maxn> visited;
    visited[u] = true;
    while (!Q.empty()) {
        int curr = Q.front();
        if (curr == v) return true;
        Q.pop();
        for (int adj : graph[curr]) {
            if (!visited[adj]) {
                visited[adj] = true;
                Q.push(adj);
            }
        }
    }
    return false;
}
int brute_query(int u, int v) {
    int cnt = 0;
    for (ii edge : edges) {
        int i = edge.fi, j = edge.se;
        erase(i, j);
        erase(j, i);
        if (!can_reach(u, v))
            cnt++;
        graph[i].insert(j);
        graph[j].insert(i);
    }
    return cnt;
}
//brute end

void propagate(int i, int L, int R) {
    T[i].min += T[i].lazy;
    if (L != R) {
        T[left(i)].lazy += T[i].lazy;
        T[right(i)].lazy += T[i].lazy;
    }
    T[i].lazy = 0;
}

node merge(node l, node r) {
    node ret;
    ret.min = min(l.min, r.min);
    if (l.min < r.min)
        ret.cnt = l.cnt;
    else if (r.min < l.min)
        ret.cnt = r.cnt;
    else
        ret.cnt = l.cnt + r.cnt;
    return ret;
}

void build(int i, int L, int R) {
    if (L == R) {
        T[i] = node(0, 1, 0);
    }
    else {
        int mid = (L+R)/2;
        build(left(i), L, mid);
        build(right(i), mid+1, R);
        T[i] = merge(T[left(i)], T[right(i)]);
    }
}

void update(int i, int L, int R, int li, int ri, int val) {
    if (T[i].lazy)
        propagate(i, L, R);
    if (ri < L || li > R)
        return;
    if (li <= L && ri >= R) {
        T[i].lazy = val;
        propagate(i, L, R);
        return;
    }
    int mid = (L+R)/2;
    update(left(i), L, mid, li, ri, val);
    update(right(i), mid+1, R, li, ri, val);
    T[i] = merge(T[left(i)], T[right(i)]);
}

void insert_edge(int u, int v) {
    if (u > v) swap(u, v);
    update(1, 1, N, u, v-1, 1);
}
void erase_edge(int u, int v) {
    if (u > v) swap(u, v);
    update(1, 1, N, u, v-1, -1);
}

node query(int i, int L, int R, int li, int ri) {
    if (T[i].lazy)
        propagate(i, L, R);
    if (ri < L || li > R)
        return node(INF, 0, 0);
    if (li <= L && ri >= R)
        return T[i];
    int mid = (L+R)/2;
    return merge(query(left(i), L, mid, li, ri), query(right(i), mid+1, R, li, ri));
}

int main() {
    //freopen("inp.txt", "r", stdin);
    int M, Q;
    scanf("%d %d %d", &N, &M, &Q);
    for (int i = 2; i <= N; i++) {
        //brute_insert(i, i-1);
    }
    build(1, 1, N);
    for (int i = 0; i < M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        if (u > v) swap(u, v);
        //brute_insert(u, v);
        insert_edge(u, v);
    }
    while (Q--) {
        int type, u, v;
        scanf("%d %d %d", &type, &u, &v);
        if (u > v) swap(u, v);
        if (type == 0) {
            //brute_insert(u, v);
            insert_edge(u, v);
        }
        else if (type == 1) {
            //brute_erase(u, v);
            erase_edge(u, v);
        }
        else {
            node n = query(1, 1, N, u, v-1);
            int mine = n.min == 0 ? n.cnt : 0;
            assert(n.min >= 0);
            printf("%d\n", mine);
         }
    }
}