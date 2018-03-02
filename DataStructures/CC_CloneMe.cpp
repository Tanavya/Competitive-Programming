//wrong solution

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

const int maxn = (int)1e5+10;
int N, A[maxn];

inline int left(int x) { return (x << 1); }
inline int right(int x) { return (x << 1) + 1; }

struct node {
    int val;
    node *left, *right;
    node (int val, node *left, node *right): val(val), left(left), right() {}
};
#define null new node (0, NULL, NULL)

node *BIT[maxn], *tree[maxn];
int RMQ[4*maxn][2];

void build(int i, int L, int R) {
    if (L == R) {
        RMQ[i][0] = RMQ[i][1] = A[L];
    }
    else {
        int mid = (L+R)/2;
        build(left(i), L, mid);
        build(right(i), mid+1, R);
        RMQ[i][0] = min(RMQ[left(i)][0], RMQ[right(i)][0]);
        RMQ[i][1] = max(RMQ[left(i)][1], RMQ[right(i)][1]);
    }
}

int minmax(int i, int L, int R, int li, int ri, int t) {
    if (ri < L || li > R) {
        if (!t) return INF;
        else return -INF;
    }
    if (li <= L && ri >= R)
        return RMQ[i][t];
    int mid = (L+R)/2;
    if (!t) return min(minmax(left(i), L, mid, li, ri, t), minmax(right(i), mid+1, R, li, ri, t));
    else return max(minmax(left(i), L, mid, li, ri, t), minmax(right(i), mid+1, R, li, ri, t));
}

int queryDST(node *curr, int L, int R, int li, int ri) {
    if (curr == nullptr || ri < L || li > R)
        return 0;
    if (li <= L && ri >= R)
        return curr->val;
    return queryDST(curr->left, L, (L+R)/2, li, ri) + queryDST(curr->right, (L+R)/2+1, R, li, ri);
}

void updateDST(node *curr, int L, int R, int idx, int val) {
    if (L == R) {
        assert(idx == L);
        curr->val += val;
    }
    else {
        int mid = (L+R)/2;
        if (curr->left == nullptr)
            curr->left = null;
        if (curr->right == nullptr)
            curr->right = null;
        if (idx <= mid)
            updateDST(curr->left, L, mid, idx, val);
        else
            updateDST(curr->right, mid+1, R, idx, val);

        curr->val = curr->left->val + curr->right->val;
    }
}

void update(int i) {
    for (; i <= N; i += (i & -i)) {
        BIT[i] = tree[A[i]];
        //updateDST(BIT[i], 1, N, idx, val);
    }
}
int query(int a, int b, int c, int d) {
    int ret = 0;
    for (int i = b; i > 0; i -= (i & -i))
        ret += queryDST(BIT[i], 1, N, c, d);
    for (int i = a-1; i > 0; i -= (i & -i))
        ret += queryDST(BIT[i], 1, N, c, d);
    return ret;
}

vi occ[maxn];
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int Q;
        for (int i = 1; i < maxn; i++) {
            //tree[i] = null;
            //BIT[i] = null;
            occ[i].clear();
        }
        scanf("%d %d", &N, &Q);
        for (int i = 1; i <= N; i++) {
            scanf("%d", &A[i]);
            occ[A[i]].pb(i);
        }
        for (int i = 1; i < maxn; i++) {
            tree[i] = null;
            for (int j : occ[i]) {
                updateDST(tree[i], 1, N, j, 1);
            }
        }
        for (int i = 1; i <= N; i++) {
            update(i);
        }
        for (int i = 0; i < Q; i++) {
            int a, b, c, d;
            scanf("%d %d %d %d", &a, &b, &c, &d);
            int ret = query(a, b, c, d);
            cout << ret << endl;
            int minL = minmax(1, 1, N, a, b, 0), maxL = minmax(1, 1, N, a, b, 1), minR = minmax(1, 1, N, c, d, 0), maxR = minmax(1, 1, N, c, d, 1);
            if (minmax(1, 1, N, a, b, 0) == minmax(1, 1, N, c, d, 0) || minmax(1, 1, N, a, b, 1) == minmax(1, 1, N, c, d, 1)) {
                if (ret >= b - a)
                    printf("YES\n");
                else
                    printf("NO\n");
            }
            else printf("NO\n");
        }
    }
}