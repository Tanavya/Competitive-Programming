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

const int maxn = (int) 1e5+7, maxk = (int)1e9+1;
int N;
vector <vector <ii>> tree;

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

void update(node *prev, node *curr, int L, int R, int idx, int val) {
    curr->val = prev->val;
    if (L == R) {
        assert(idx == L);
        curr->val ^= val;
    }
    else {
        if (prev->left == nullptr) prev->left = null;
        if (prev->right == nullptr) prev->right = null;
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
    if (curr == nullptr || ri < L || li > R)
        return 0;
    if (li <= L && ri >= R)
        return curr->val;
    int mid = (L+R)/2;
    return query(curr->left, L, mid, li, ri) ^ query(curr->right, mid+1, R, li, ri);
}

void dfs(int n, int par) {
    for (ii edge : tree[n]) {
        int adj = edge.fi, w = edge.se;
        if (adj != par) {
            version[adj] = null;
            update(version[n], version[adj], 1, maxk, w, w);
            dfs(adj, n);
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &N);
        tree.assign(N+7, {});
        for (int i = 0; i < N-1; i++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            tree[u].pb(mp(v, w));
            tree[v].pb(mp(u, w));
        }
        version[1] = null;
        dfs(1, 0);
        int Q;
        scanf("%d", &Q);

        while (Q--) {
            int u, v, k;
            scanf("%d %d %d", &u, &v, &k);
            int ans = query(version[u], 1, maxk, 1, k) ^ query(version[v], 1, maxk, 1, k);
            printf("%d\n", ans);
        }
    }
}