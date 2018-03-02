//ONLINE
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

const int maxn = 30007, maxai = (int) 1e6 + 10;
int A[maxn], occ[maxai], nxt[maxn], distinct[maxn];

struct node {
    int val;
    node *left, *right;
    node (int val, node *left, node *right): val(val), left(left), right(right) {}
};
node *version[maxn];
#define null new node (0, NULL, NULL)

void build (node *curr, int L, int R) {
    if (L == R) {
        curr->val = distinct[L];
    }
    else {
        curr->left = null;
        curr->right = null;
        build(curr->left, L, (L+R)/2);
        build(curr->right, (L+R)/2+1, R);
        curr->val = curr->left->val + curr->right->val;
    }
}

int query (node *curr, int L, int R, int li, int ri) {
    if (curr == nullptr || ri < L || li > R)
        return 0;
    if (li <= L && ri >= R)
        return curr->val;
    return query (curr->left, L, (L+R)/2, li, ri) + query (curr->right, (L+R)/2+1, R, li, ri);
}

void update (node *prev, node *curr, int L, int R, int idx, int val) {
    if (L == R) {
        assert(idx == L);
        distinct[idx] = val;
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
        curr->val = curr->left->val + curr->right->val;
    }
}

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &A[i]);
        nxt[occ[A[i]]] = i;
        if (!occ[A[i]])
            distinct[i] = 1;
        occ[A[i]] = i;
    }

    version[0] = null;
    build(version[0], 1, N);
    for (int i = 1; i <= N; i++) {
        if (nxt[i]) {
            version[i] = null;
            update(version[i-1], version[i], 1, N, nxt[i], 1);
        }
        else {
            version[i] = version[i-1];
        }
    }
    int Q;
    scanf("%d", &Q);
    for (int i = 0; i < Q; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%d\n", query(version[l-1], 1, N, l, r));
    }
}