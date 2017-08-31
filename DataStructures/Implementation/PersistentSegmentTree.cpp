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

#define mp make_pair
#define pb push_back
#define x first
#define y second
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << endl;
#define debug(x) cout << x << endl;
#define debug2(x,y) cout << x << " " << y << endl;
typedef long long int ll;
typedef long double ld;
typedef std::pair <int, int> ii;
typedef std::vector <int> vi;
typedef std::vector <ll> vll;
const int INF = int(1e9);
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
using namespace std;

int A[100];

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
node* version[100];

#define null new node(0, NULL, NULL)

void build(node *n, int L, int R) {
    if (L == R) {
        n->val = A[L];
    }
    else {
        int mid = (L+R)/2;
        n->left = null;
        n->right = null;
        build(n->left, L, mid);
        build(n->right, mid+1, R);
        n->val = n->left->val + n->right->val;
    }
}

int query(node *n, int L, int R, int a, int b) {
    if (b < L || a > R) 
        return 0;
    if (a <= L && b >= R) 
        return n->val;
    int mid = (L+R)/2;
    return query(n->left, L, mid, a, b) + query(n->right, mid+1, R, a, b);
}

void update(node *prev, node *cur, int L, int R, int idx, int value) {
    if (idx > R || idx < L || L > R)
        assert(false);
    if (L == R) {
        A[idx] = value;
        cur->val = value;
    }
    else {
        int mid = (L+R)/2;
        if (idx <= mid) {
            //index to be updated in left child's subtree

            // link to right child of previous version
            cur->right = prev->right;
            // create new node in current version
            cur->left = null;
            update(prev->left, cur->left, L, mid, idx, value);
        }
        else {
            cur->left = prev->left;
            cur->right = null;
            update(prev->right, cur->right, mid+1, R, idx, value);
        }
        cur->val = cur->left->val + cur->right->val;
    }
}
int main() {
    int N, Q;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &A[i]);
    }

    node* root = null;
    version[0] = root;
    build(version[0], 1, N);
    //build version-0

    scanf("%d", &Q);

    char type;
    int l, r, idx, value, t;
    int i = 1;

    while (Q--) {
        cin >> type;
        if (type == 'u') {
            scanf("%d %d", &idx, &value);
            version[i] = null;
            update(version[i-1], version[i], 1, N, idx, value);
            i++;
            for (int i = 1; i <= N; i++) cout << A[i] << " "; cout << endl;
        }
        if (type == 'q') { 
            scanf("%d %d %d", &t, &l, &r);
            if (t > i) {
                printf("invalid\n");
            }
            else {
                printf("%d\n", query(version[t], 1, N, l, r));
            }
        }
    }
}