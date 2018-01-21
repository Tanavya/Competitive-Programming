//Offline + (Dynamic altho not reqd) segtree -> AC

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

const int maxn = (int) 1e5+7;
int N, ST[maxn], ET[maxn];
vector <vector <ii>> tree;
vi euler;

struct node {
    int val;
    node *left, *right;
    node (int v, node* l, node* r) {
        val = v;
        left = l;
        right = r;
    }
};

struct event {
    int k, type, u, v, val, idx;
    event (int t, int a, int b, int c, int i = 0) {
        type = t, k = a, u = b;
        if (t == 0) val = c;
        else {
            v = c;
            idx = i;
        }
    }
};
vector <event> events;

bool cmp (event a, event b) {
    if (a.k == b.k)
        return a.type < b.type;
    return a.k < b.k;
}

#define null new node (0, NULL, NULL);

node *version[maxn];
void build (node *curr, int L, int R) {
    if (L == R) {
        curr->val = euler[L];
    }
    else {
        int mid = (L+R)/2;
        curr->left = null;
        curr->right = null;
        build(curr->left, L, mid);
        build(curr->right, mid+1, R);
        curr->val = curr->left->val ^ curr->right->val;
    }
}
void update(node *curr, int L, int R, int idx, int val) {
    if (L == R) {
        assert(idx == L);
        euler[L] = curr->val = val;
    }
    else {
        int mid = (L+R)/2;
        if (idx <= mid) {
            update(curr->left, L, mid, idx, val);
        }
        else {
            update(curr->right, mid+1, R, idx, val);
        }
        curr->val = curr->left->val ^ curr->right->val;
    }
}

int query (node *curr, int L, int R, int li, int ri) {
    if (ri < L || li > R)
        return 0;
    if (li <= L && ri >= R)
        return curr->val;
    int mid = (L+R)/2;
    return query(curr->left, L, mid, li, ri) ^ query(curr->right, mid+1, R, li, ri);
}

void dfs(int node, int par, int w) {
    events.pb(event(0, w, node, w));
    euler.pb(0);
    ST[node] = (int)euler.size() - 1;
    for (ii edge : tree[node]) {
        int adj = edge.fi;
        if (adj != par) {
            dfs(adj, node, edge.se);
        }
    }
    euler.pb(0);
    ET[node] = (int)euler.size() - 1;
}

int main() {

    int T;
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &N);
        tree.assign(N+7, {});
        memset(ST, 0, sizeof(ST));
        memset(ET, 0, sizeof(ET));
        euler = {0};
        events.clear();
        for (int i = 0; i < N-1; i++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            tree[u].pb(mp(v, w));
            tree[v].pb(mp(u, w));
        }
        dfs(1, 0, 0);
        int Q;
        scanf("%d", &Q);
        for (int i = 1; i <= Q; i++) {
            int u, v, k;
            scanf("%d %d %d", &u, &v, &k);
            events.pb(event(1, k, u, v, i));
        }
        sort(all(events), cmp);
        node *root = null;
        build(root, 1, 2*N);
        vi ans(Q+1, 0);
        for (event e : events) {
            if (e.type == 0) {
                update(root, 1, 2*N, ST[e.u], e.val);
                update(root, 1, 2*N, ET[e.u], e.val);
            }
            else {
                ans[e.idx] = query(root, 1, 2*N, 1, ST[e.u]) ^ query(root, 1, 2*N, 1, ST[e.v]);
            }
        }
        for (int i = 1; i <= Q; i++) {
            printf("%d\n", ans[i]);
        }
    }

}


//This is an online solution with pers segtree -> Gives TLE

/*
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

const int maxn = (int) 1e5+7;
int N, ST[maxn], ET[maxn];
vector <vector <ii>> tree;
vi euler, P[maxn], A;

struct node {
    int val;
    node *left, *right;
    node (int v, node* l, node* r) {
        val = v;
        left = l;
        right = r;
    }
};
#define null new node (0, NULL, NULL);

node *version[maxn];
void build (node *curr, int L, int R) {
    if (L == R) {
        curr->val = euler[L];
    }
    else {
        int mid = (L+R)/2;
        curr->left = null;
        curr->right = null;
        build(curr->left, L, mid);
        build(curr->right, mid+1, R);
        curr->val = curr->left->val ^ curr->right->val;
    }
}
void update(node *prev, node *curr, int L, int R, int idx, int val) {
    if (L == R) {
        assert(idx == L);
        euler[L] = curr->val = val;
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
        curr->val = curr->left->val ^ curr->right->val;
    }
}

int query (node *curr, int L, int R, int li, int ri) {
    if (ri < L || li > R)
        return 0;
    if (li <= L && ri >= R)
        return curr->val;
    int mid = (L+R)/2;
    return query(curr->left, L, mid, li, ri) ^ query(curr->right, mid+1, R, li, ri);
}

void dfs(int node, int par, int w) {
    P[lower_bound(all(A), w)-A.begin()].pb(node);
    euler.pb(0);
    ST[node] = (int)euler.size() - 1;
    for (ii edge : tree[node]) {
        int adj = edge.fi;
        if (adj != par) {
            dfs(adj, node, edge.se);
        }
    }
    euler.pb(0);
    ET[node] = (int)euler.size() - 1;
}

int main() {

    int T;
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &N);
        tree.assign(N+7, {});
        euler = {0};
        A.clear();
        for (int i = 0; i < N-1; i++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            tree[u].pb(mp(v, w));
            tree[v].pb(mp(u, w));
            A.pb(w);
        }
        sort(all(A));
        for (int i = 0; i <= A.size(); i++)
            P[i].clear();
        dfs(1, 0, 0);
        version[0] = null;
        build(version[0], 1, 2*N);
        int n = 0;
        vi V = {0};
        for (int j = 0; j < A.size(); j++) {
            n++;
            int w = A[j];
            V.pb(w);
            version[n] = version[n-1];
            for (int i : P[j]) {
                node *nxt = null;
                update(version[n], nxt, 1, 2*N, ST[i], w);
                version[n] = nxt;
                nxt = null;
                update(version[n], nxt, 1, 2*N, ET[i], w);
                version[n] = nxt;
            }
        }
        int Q;
        scanf("%d", &Q);

        while (Q--) {
            int u, v, k;
            scanf("%d %d %d", &u, &v, &k);
            auto it = upper_bound(all(V), k);
            if (it != V.begin()) it = prev(it);
            int i = int(it - V.begin());
            int ans = query(version[i], 1, 2*N, 1, ST[u]) ^ query(version[i], 1, 2*N, 1, ST[v]);
            printf("%d\n", ans);
        }
    }

}
 */