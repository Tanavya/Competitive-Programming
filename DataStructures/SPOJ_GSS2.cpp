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
int A[maxn];
ll ans[maxn];
map <int, int> occ;

inline int left (int x) { return (x << 1); }
inline int right (int x) { return (x << 1) + 1; }

struct node {
    ll best, curr, lazy, best_lazy;
    node() { best = 0, lazy = 0, best_lazy = 0, curr = 0; }
};

node tree[4*maxn];

void build (int i, int L, int R) {
    if (L == R) {
        tree[i] = node();
    }
    else {
        int mid = (L+R)/2;
        build(left(i), L, mid);
        build(right(i), mid+1, R);
        tree[i] = node();
    }
}

void propagate(int i, int L, int R) {
    //maintain best_lazy invariant that when a node's ancestors have no queued updates, the bestlazy value is the greatest prefix sum of the updates queued at this node.
    if (L != R) {
        for (int child : {left(i), right(i)}) {
            tree[child].best_lazy = max(tree[child].best_lazy, tree[child].lazy + tree[i].best_lazy);
            tree[child].lazy += tree[i].lazy;
            tree[child].best = max(tree[child].best, tree[child].curr + tree[i].best_lazy);
            tree[child].curr += tree[i].lazy;
        }
    }
    tree[i].lazy = tree[i].best_lazy = 0;
}

void updateRange(int i, int L, int R, int li, int ri, int val) {
    if (tree[i].lazy)
        propagate(i, L, R);
    if (ri < L || li > R)
        return;
    if (li <= L && ri >= R) {
        tree[i].lazy = tree[i].best_lazy = val;
        tree[i].curr += val;
        tree[i].best = max(tree[i].best, tree[i].curr);
        propagate(i, L, R);
        return;
    }
    int mid = (L+R)/2;
    updateRange(left(i), L, mid, li, ri, val);
    updateRange(right(i), mid+1, R, li, ri, val);
    tree[i].curr = max(tree[left(i)].curr, tree[right(i)].curr);
    tree[i].best = max(tree[i].best, tree[i].curr);
}

ll queryRange(int i, int L, int R, int li, int ri) {
    if (tree[i].lazy)
        propagate(i, L, R);
    if (ri < L || li > R)
        return -INF;
    if (li <= L && ri >= R)
        return tree[i].best;
    int mid = (L+R)/2;
    return max(queryRange(left(i), L, mid, li, ri), queryRange(right(i), mid+1, R, li, ri));
}

int main() {
    vector <pair <ii, ii>> events;
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &A[i]);
        events.pb(mp(mp(i, 0), mp(i, -1)));
    }
    build(1, 1, N);
    int Q;
    scanf("%d", &Q);
    for (int i = 0; i < Q; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        events.pb(mp(mp(y, 1), mp(x, i)));
    }
    sort(all(events));
    for (pair <ii, ii> e: events) {
        int type = e.fi.se;
        //cout << type << " ";
        if (type == 0) {
            int idx = e.fi.fi, val = A[idx];
            //cout << idx << endl;
            updateRange(1, 1, N, occ[val] + 1, idx, val);
            occ[val] = idx;
        }
        else {
            int x = e.se.fi, y = e.fi.fi, idx = e.se.se;
            //cout << y << endl;
            ans[idx] = queryRange(1, 1, N, x, y);
        }
    }
    for (int i = 0; i < Q; i++) {
        printf("%lld\n", ans[i]);
    }
}