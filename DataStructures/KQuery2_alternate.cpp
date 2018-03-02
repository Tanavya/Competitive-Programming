//Refer to CC Give Away for all possible solutions

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
const int maxn = (int)30007, maxk = 10007;
int A[maxn], N, B[maxn];

inline int left (int x) { return (x << 1); }
inline int right (int x) { return (x << 1) + 1; }

struct node {
    int val;
    node *left, *right;
    node(int val, node *left, node *right) : val(val), left(left), right(right) {}
};

node *tree[4*maxn]; //Dynamic Segment Tree in each node of Segment Tree
#define null new node (0, NULL, NULL);

void build (int i, int L, int R) {
    tree[i] = null;
    if (L != R) {
        int mid = (L+R)/2;
        build (left(i), L, mid);
        build(right(i), mid+1, R);
    }
}

void updateDST (node *curr, int L, int R, int idx, int val) {
    if (L == R) {
        curr->val += val;
    }
    else {
        if (curr->left == nullptr)
            curr->left = null;
        if (curr->right == nullptr)
            curr->right = null;
        int mid = (L+R)/2;
        if (idx <= mid)
            updateDST(curr->left, L, mid, idx, val);
        else
            updateDST(curr->right, mid+1, R, idx, val);
        curr->val = curr->left->val + curr->right->val;
    }
}

void update (int i, int L, int R, int idx, int n, int val) {
    updateDST(tree[i], 1, maxk, n, val);
    if (L != R) {
        int mid = (L+R)/2;
        if (idx <= mid)
            update(left(i), L, mid, idx, n, val);
        else
            update(right(i), mid+1, R, idx, n, val);
    }
}

int queryDST (node *curr, int L, int R, int li, int ri) {
    if (curr == nullptr || ri < L || li > R)
        return 0;
    if (li <= L && ri >= R)
        return curr->val;
    int mid = (L+R)/2;
    return queryDST (curr->left, L, mid, li, ri) + queryDST (curr->right, mid+1, R, li, ri);
}

int query (int i, int L, int R, int li, int ri, int lii, int rii) {
    if (ri < L || li > R)
        return 0;
    if (li <= L && ri >= R)
        return queryDST (tree[i], 1, maxk, lii, rii);
    int mid = (L+R)/2;
    return query (left(i), L, mid, li, ri, lii, rii) + query (right(i), mid+1, R, li, ri, lii, rii);
}

void brute_update (int i, int x) {
    B[i] = x;
}
int brute_check (int L, int R, int k) {
    int cnt = 0;
    for (int i = L; i <= R; i++) {
        if (B[i] > k)
            cnt++;
    }
    return cnt;
}

int main() {
    scanf("%d", &N);
    build(1, 1, N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &A[i]);
        //cout << tree[1]->val << endl;
        update(1, 1, N, i, A[i], 1);
    }
    //cout << tree[1]->val << endl;
    int Q;
    scanf("%d", &Q);
    while (Q--) {
        int type;
        scanf("%d", &type);
        if (type == 1) {
            int l, r, k;
            scanf("%d %d %d", &l, &r, &k);
            printf("%d\n", query(1, 1, N, l, r, k+1, maxk));
        }
        else {
            int i, k;
            scanf("%d %d", &i, &k);
            update(1, 1, N, i, A[i], -1);
            A[i] = k;
            update(1, 1, N, i, k, 1);
        }
    }
}