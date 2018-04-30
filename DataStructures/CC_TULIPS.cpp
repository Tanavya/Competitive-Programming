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

const int INF = 2147483647;
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
using namespace std;

const int maxn = (int)2e5+10;
int I, N, X, parent[maxn], label[maxn], P[maxn][25];
struct t_node {
    int n, left, right, L = 0, R = 0, idx = 0;
    t_node(int n = 0, int left = 0, int right = 0) : n(n), left(left), right(right) {
        parent[n] = n;
    }
};
struct node {
    int min, cnt, lazy;
    node(int min = 0, int cnt = 0, int lazy = 0) : min(min), cnt(cnt), lazy(lazy) {}
};
struct event {
    int type, d, L, R;
    event(int type, int d, int L, int R) : type(type), d(d), L(L), R(R) {}
};

bool cmp(event a, event b) {
    if (a.d != b.d) return a.d < b.d;
    return a.type < b.type;
}

t_node tree[maxn];
node ST[2*maxn];

int n = 0;

void reset() {
    memset(parent, 0, sizeof(parent));
    memset(label, 0, sizeof(label));
    memset(P, 0, sizeof(P));
    I = n = 0;
}

//----------- Create Reachability Tree ------------


int root(int x) {
    while (parent[x] != x) {
        x = parent[x] = parent[parent[x]];
    }
    return x;
}

void Union(int a, int b, int k) {
    a = root(a); b = root(b);
    if (a == b) return;
    n++;
    tree[n] = t_node(n, parent[a], parent[b]);
    parent[a] = parent[b] = n;
    label[n] = k;
}

//----------- Process Reachability Tree -----------

void dfs(int node, int par) {
    P[node][0] = par;
    if (tree[node].left && tree[node].right) {
        dfs(tree[node].left, node);
        tree[node].L = tree[tree[node].left].L;
        dfs(tree[node].right, node);
        tree[node].R = tree[tree[node].right].R;
    }
    else {
        tree[node].L = tree[node].R = node;
        tree[node].idx = ++I;
    }
}

void preprocess() {
    dfs(tree[n].n, 0);
    assert(I == N);
    for (int i = 1; i < 25; i++) {
        for (int u = 1; u <= n; u++) {
            P[u][i] = P[P[u][i-1]][i-1];
        }
    }
    label[0] = INF;
}

int calc(int u, int k) {
    for (int i = 24; i >= 0; i--) {
        if (label[P[u][i]] <= k) {
            u = P[u][i];
        }
    }
    assert(label[u] <= k);
    assert(label[P[u][0]] > k);
    return u;
}

//--------------- Lazy Segment Tree ---------------

inline int left(int x) { return (x << 1); }
inline int right(int x) { return (x << 1) + 1; }

void propagate(int i, int L, int R) {
    ST[i].min += ST[i].lazy;
    if (L != R) {
        ST[left(i)].lazy += ST[i].lazy;
        ST[right(i)].lazy += ST[i].lazy;
    }
    ST[i].lazy = 0;
}

node merge(node l, node r) {
    node ret(0,0,0);
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
    ST[i] = node();
    if (L == R) {
        ST[i].cnt = 1;
    }
    else {
        int mid = (L+R)/2;
        build(left(i), L, mid);
        build(right(i), mid+1, R);
        ST[i].cnt = ST[left(i)].cnt + ST[right(i)].cnt;
    }
}

void update(int i, int L, int R, int li, int ri, int val) {
    if (ST[i].lazy)
        propagate(i, L, R);
    if (ri < L || li > R)
        return;
    if (li <= L && ri >= R) {
        ST[i].lazy = val;
        propagate(i, L, R);
        return;
    }
    int mid = (L+R)/2;
    update(left(i), L, mid, li, ri, val);
    update(right(i), mid+1, R, li, ri, val);
    ST[i] = merge(ST[left(i)], ST[right(i)]);
}

node query(int i, int L, int R, int li, int ri) {
    if (ST[i].lazy)
        propagate(i, L, R);
    if (ri < L || li > R)
        return node();
    if (li <= L && ri >= R)
        return ST[i];
    int mid = (L+R)/2;
    return merge(query(left(i), L, mid, li, ri), query(right(i), mid+1, R, li, ri));
}

//-------------------------------------------------

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        reset();
        scanf("%d", &N);
        vector <pair <int, ii>> edges;
        for (int i = 1; i < N; i++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            edges.pb(mp(w, mp(u, v)));
        }
        sort(all(edges));
        for (int i = 1; i <= N; i++) {
            tree[i] = t_node(++n, 0, 0);
        }
        for (pair <int, ii> edge : edges) {
            int u = edge.se.fi, v = edge.se.se, k = edge.fi;
            Union(u, v, k);
        }
        preprocess();
        build(1, 1, N);
        //for (int i = 1; i <= n; i++) { cout << i << ":-"; debug2(tree[i].left, tree[i].right); }
        int Q;
        scanf("%d %d", &Q, &X);
        vector <event> E;
        for (int i = 0; i < Q; i++) {
            int d, u, k;
            scanf("%d %d %d", &d, &u, &k);
            u = calc(u, k);
            int L = tree[tree[u].L].idx;
            int R = tree[tree[u].R].idx;
            E.pb(event(0, d+X, L, R)); //decrease
            E.pb(event(1, d, L, R)); //query
            E.pb(event(2, d, L, R)); //increase
        }
        sort(all(E), cmp);
        for (event e: E) {
            if (e.type == 0) {
                update(1, 1, N, e.L, e.R, -1);
            }
            else if (e.type == 1) {
                node ans = query(1, 1, N, e.L, e.R);
                if (ans.min == 0)
                    printf("%d\n", ans.cnt);
                else
                    printf("%d\n", 0);
            }
            else {
                update(1, 1, N, e.L, e.R, 1);
            }
        }
    }
}
/*
1
9
1 3 16
2 3 19
3 4 10
4 5 20
5 6 8
5 7 12
5 8 15
8 9 7
 */