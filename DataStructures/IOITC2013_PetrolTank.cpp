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

const int maxn = (int) 1e5+10;
int N, size[maxn];
vi component[maxn];

//---------------------Peristent Segment Tree---------------------
struct node {
    int val;
    node *left, *right;
    node (int val = 0, node *left = nullptr, node *right = nullptr): val(val), left(left), right(right) {}
};
#define null new node()
void build(node *curr, int L, int R) {
    if (L == R) {
        curr->val = L;
    }
    else {
        int mid = (L+R)/2;
        curr->left = null;
        curr->right = null;
        build(curr->left, L, mid);
        build(curr->right, mid+1, R);
    }
}

void update(node *prev, node *curr, int L, int R, int idx, int val) {
    if (L == R) {
        curr->val = val;
    }
    else {
        int mid = (L+R)/2;
        if (idx <= mid) {
            curr->right = prev->right;
            curr->left = null;
            update(prev->left, curr->left, L, mid, idx, val);
        }
        else {
            curr->left = prev->left;
            curr->right = null;
            update(prev->right, curr->right, mid+1, R, idx, val);
        }
    }
}

void update(node *curr, int L, int R, int idx, int val) {
    if (L == R) {
        curr->val = val;
    }
    else {
        int mid = (L+R)/2;
        if (idx <= mid)
            update(curr->left, L, mid, idx, val);
        else
            update(curr->right, mid+1, R, idx, val);
    }
}

int query(node *curr, int L, int R, int idx) {
    if (!curr) assert(false);
    if (L == R) {
        return curr->val;
    }
    else {
        int mid = (L+R)/2;
        if (idx <= mid)
            return query(curr->left, L, mid, idx);
        else
            return query(curr->right, mid+1, R, idx);
    }
}
//--------------------------------------------------------------------

node *root[100*maxn];

int t = 0;
vector <ii> updates;
void Union(int a, int b, int w) {
    a = query(root[t], 1, N, a);
    b = query(root[t], 1, N, b);
    if (a == b) return;
    if (size[a] < size[b])
        swap(a, b);
    size[a] += size[b];
    for (int u : component[b]) {
        component[a].pb(u);
        t++;
        root[t] = null;
        update(root[t-1], root[t], 1, N, u, a);
    }
    updates.pb(mp(t, w));
}

inline bool Find(int a, int b, int x) {
    return query(root[x], 1, N, a) == query(root[x], 1, N, b);
}

int main() {
    int M;
    scanf("%d %d", &N, &M);
    vector <pair<int, ii>> edges;
    for (int i = 0; i < M; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        edges.pb(mp(w, mp(u, v)));
    }
    sort(all(edges));
    for (int i = 0; i <= N; i++) {
        size[i] = 1;
        component[i] = {i};
    }
    root[0] = null;
    build(root[0], 1, N);
    for (pair <int, ii> edge : edges) {
        int w = edge.fi, a = edge.se.fi, b = edge.se.se;
        Union(a, b, w);
    }
    int Q;
    scanf("%d", &Q);
    while (Q--) {
        int u, v;
        scanf("%d %d", &u, &v);
        int L = 0, R = (int)updates.size()-1, mid;
        while (L < R) {
            mid = (L+R)/2;
            if (!Find(u, v, updates[mid].fi)) {
                L = mid+1;
            }
            else {
                R = mid;
            }
        }
        assert(L == R);
        printf("%d\n", updates[L].se);
    }
}
/*
4 5
1 2 1
1 3 4
2 3 2
2 4 5
3 4 4
2
1 3
4 2
 */