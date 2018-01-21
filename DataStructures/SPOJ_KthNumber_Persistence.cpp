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

const int maxn = (int) 1e5 + 10;

int A[maxn], B[maxn], RB[maxn];

struct node {
    int val;
    node *left, *right; //pointers to left and right nodes children of this node
    node() {
    }
    node (int v, node *l, node *r) {
        left = l;
        right = r;
        val = v;
    }
};

node* version[maxn];

#define null new node(0, NULL, NULL)

void build (node *n, int L, int R) {
    if (L == R) {
        n->val = A[L];
    }
    else {
        int mid = (L+R)/2;
        n->right = null;
        n->left = null;
        build(n->left, L, mid);
        build(n->right, mid+1, R);
        n->val = n->left->val + n->right->val;
    }
}

void update (node *prev, node *curr, int L, int R, int idx, int val) {
    if (L == R) {
        assert(idx == L);
        A[L] = val;
        curr->val = A[L];
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
        curr->val = curr->left->val + curr->right->val;
    }
}

int query (node *a, node *b, int L, int R, int K) {
    if (L == R) {
        return L;
    }
    int curr = a->left->val - b->left->val;
    int mid = (L+R)/2;
    if (K <= curr) {
        return query (a->left, b->left, L, mid, K);
    }
    else {
        return query (a->right, b->right, mid+1, R, K-curr);
    }
}

int main() {
    int N, Q;
    scanf("%d %d", &N, &Q);
    vi V = {0};
    map <int, int> M;
    int x;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &x);
        M[x] = i;
        V.pb(x);
    }
    int i = 1;
    for (auto it : M) {
        //debug2(it.second, i);
        B[it.second] = i;
        RB[i] = it.first;
        i++;
    }
    version[0] = null;
    build(version[0], 1, N);
    for (i = 1; i <= N; i++) {
        version[i] = null;
        update(version[i-1], version[i], 1, N, B[i], 1);
    }
    int j, k;
    while (Q--) {
        scanf("%d %d %d", &i, &j, &k);
        printf("%d\n", RB[query(version[j], version[i-1], 1, N, k)]);
    }

}