#include <vector>
#include <stdio.h>
#include <queue>
#include <iostream>
#include <map>
#include <assert.h>
#include <set>
#include <bitset>
#include <algorithm>
#include <cstring>

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

const int maxn = (int) 400007;
int N, A[maxn], depth[maxn], parent[maxn];
vi tree[maxn];
ll ans = 0;

struct node {
    int val;
    node *left, *right;
    node() : val(-INF), left(nullptr), right(nullptr) {}
};
#define null new node()
node *root[maxn];

void update(node *curr, node *prev, int L, int R, int idx, int val) {
    if (L == R) {
        curr->val = val;
    }
    else {
        int mid = (L+R)/2;
        if (idx <= mid) {
            curr->right = prev->right;
            curr->left = null;
            update(curr->left, prev->left, L, mid, idx, val);
        }
        else {
            curr->left = prev->left;
            curr->right = null;
            update(curr->right, prev->right, mid+1, R, idx, val);
        }
        curr->val = max(curr->left->val, curr->right->val);
    }
}

int query(node *curr, int L, int R, int li, int ri) {
    if (!curr || ri < L || li > R)
        return -INF;
    if (li <= L && ri >= R)
        return curr->val;
    int mid = (L+R)/2;
    return max(query(curr->left, L, mid, li, ri), query(curr->right, mid+1, R, li, ri));
}
int t = 0;
int IN[maxn], euler[maxn];

void dfs(int n, int par) {
    IN[n] = ++t;
    euler[IN[n]] = n;
    int nxt = query(root[par], 1, N, A[n] + 1, N);
    if (nxt == -INF) nxt = 0;
    nxt = euler[nxt];
    parent[n] = nxt;
    depth[n] = depth[parent[n]] + 1;

    nxt = query(root[par], 1, N, A[n], N);
    if (nxt == -INF) nxt = 1;
    nxt = euler[nxt];
    ans += (ll) (depth[par] - depth[nxt] + 1);

    root[n] = null;
    update(root[n], root[par], 1, N, A[n], IN[n]);

    for (int adj : tree[n]) {
        if (adj != par) {
            dfs(adj, n);
        }
    }
}
vi path;
ll cnt = 0;
void brute_dfs(int node, int par) {
    int curr = 0;
    for (int i = (int)path.size()-1; i >= 0; i--) {
        int x = path[i];
        if (A[x] > A[curr]) {
            curr = x;
            cnt++;
            if (A[curr] >= A[node]) break;
        }
    }
    path.pb(node);
    for (int adj : tree[node]) {
        if (adj != par) {
            brute_dfs(adj, node);
        }
    }
    path.pop_back();
}

ll brute() {
    brute_dfs(1, 0);
    return cnt;
}

int main() {
    freopen("inp.txt", "r", stdin);
    scanf("%d", &N);
    for (int i = 1; i < N; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        tree[u].pb(v);
        tree[v].pb(u);
    }
    int t = 0;
    map <int, int> HASH;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &A[i]);
        HASH[A[i]] = 0;
    }
    for (auto it : HASH) {
        HASH[it.first] = ++t;
    }
    for (int i = 1; i <= N; i++) {
        A[i] = HASH[A[i]];
    }
    root[0] = null;
    root[0]->left = root[0];
    root[0]->right = root[0];
    dfs(1, 0);
//    for (int i = 1; i <= N; i++) printf("parent[%d] = %d\n", i, parent[i]);
//    ll AC = brute();
//    cout << "AC   : " << AC << endl;
//    cout << "MINE : " << ans << endl;
//    assert(AC == ans);
    printf("%lld\n", ans);
}
/*
5
1 2
3 4
2 3
2 5
5 1 3 2 9
 */