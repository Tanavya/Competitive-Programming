#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <assert.h>

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
typedef long double LLD;
typedef unsigned long long int ull;
typedef std::pair <int, int> ii;
typedef std::vector <int> vi;
typedef std::vector <ll> vll;

const int INF = (int)1e9;
const ll INF64 = ll(1e18);
using namespace std;

const int maxn = (int) 1e5+10;
int N, t = 0, euler[maxn*2], IN[maxn], OUT[maxn], parent[maxn];
ll sum[maxn], depth[maxn];
ll A[maxn];
ll B[maxn];
vi tree[maxn];
struct node {
    ll a[2]={0,0}, d[2]={0,0}, ld[2] = {0,0}, la[2] = {0,0}, l2d[2] = {0,0};
};
node T[4*maxn];

inline int left(int x) { return (x << 1); }
inline int right(int x) { return (x << 1) + 1; }

inline void set_child(int i, int child) {
    T[child].a[1] += T[i].a[1];
    T[child].d[1] += T[i].d[1];
    T[child].ld[1] += T[i].ld[1];
    T[child].la[1] += T[i].la[1];
    T[child].l2d[1] += T[i].l2d[1];
}

void propagate(int i, int L, int R) {
    if (L == R) {
        T[i].a[0] += T[i].a[1];
        T[i].d[0] += T[i].d[1];
        T[i].ld[0] += T[i].ld[1];
        T[i].la[0] += T[i].la[1];
        T[i].l2d[0] += T[i].l2d[1];
    }
    else {
        set_child(i, left(i));
        set_child(i, right(i));
    }
    T[i].a[1] = T[i].d[1] = T[i].ld[1] = T[i].la[1] = T[i].l2d[1] = 0;
}
void update(int i, int L, int R, int li, int ri, ll a, ll d, ll l) {
    if (T[i].a[1] || T[i].d[1])
        propagate(i, L, R);
    if (ri < L || li > R)
        return;
    if (li <= L && ri >= R) {
        T[i].a[1] = a;
        T[i].d[1] = d;
        T[i].ld[1] = l*d;
        T[i].la[1] = l*a;
        T[i].l2d[1] = l*l*d;
        propagate(i, L, R);
        return;
    }
    int mid = (L+R)/2;
    update(left(i), L, mid, li, ri, a, d, l);
    update(right(i), mid+1, R, li, ri, a, d, l);
}

node query(int i, int L, int R, int idx) {
    if (T[i].a[1] || T[i].d[1])
        propagate(i, L, R);
    if (L == R)
        return T[i];
    else {
        int mid = (L+R)/2;
        if (idx <= mid)
            return query(left(i), L, mid, idx);
        else
            return query(right(i), mid+1, R, idx);
    }
}

ll get_value(int v) {
    node n = query(1, 1, N, IN[v]);
    ll ans = sum[v] + ((2 * n.a[0] * (depth[v] + 1))
             + (n.d[0] * depth[v] * (depth[v] + 1))
             - (n.ld[0] * (2*depth[v] + 1)) - (2 * n.la[0]) + (n.l2d[0])) / 2;
    return ans;
}
void update(int node, ll a, ll d) {
    update(1, 1, N, IN[node], OUT[node], a, d, depth[node]);
}

void dfs(int node, int par) {
    IN[node] = ++t;
    euler[IN[node]] = node;
    sum[node] = sum[par] + A[node];
    depth[node] = depth[par] + 1;
    parent[node] = par;
    for (int adj : tree[node]) {
        if (adj != par) {
            dfs(adj, node);
        }
    }
    OUT[node] = t;
}

int main() {
    //freopen("inp.txt", "r", stdin);
    int Q;
    scanf("%d %d", &N, &Q);
    for (int i = 1; i < N; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        tree[u].pb(v);
        tree[v].pb(u);
    }
    for (int i = 1; i <= N; i++) {
        scanf("%lld", &A[i]);
        B[i] = A[i];
    }
    dfs(1, 0);
    while (Q--) {
        int type;
        scanf("%d", &type);
        if (type == 1) {
            int node;
            ll a, d;
            scanf("%d %lld %lld", &node, &a, &d);
            update(node, a, d);
        }
        else {
            int node;
            scanf("%d", &node);
            cout << get_value(node) << endl;
        }
    }
}
