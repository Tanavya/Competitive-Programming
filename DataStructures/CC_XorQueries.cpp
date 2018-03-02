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

const int maxn = (int) 5e5+10;
int N;

struct trie_node {
    int added;
    trie_node *zero, *one;
    trie_node (int added, trie_node *zero, trie_node *one): added(added), zero(zero), one(one) {}
};
struct node {
    int val;
    node *left, *right;
    trie_node *trie;
    node (int val, node *left, node *right, trie_node *trie): trie(trie), val(val), left(left), right(right) {}
};
#define null new node (0, NULL, NULL, NULL)
#define null_trie new trie_node (0, nullptr, nullptr)
node *version[maxn];

void insert (trie_node *prev, trie_node *curr, int n, int t) {
    for (int i = 21; i >= 0; i--) {
        if (n & (1 << i)) {
            curr->zero = prev->zero;
            curr->one = null_trie;
            curr->one->added = t;
            curr = curr->one;
            prev = prev->one;
        }
        else {
            curr->one = prev->one;
            curr->zero = null_trie;
            curr->zero->added = t;
            curr = curr->zero;
            prev = prev->zero;
        }
    }
}

void update (node *prev, node *curr, int L, int R, int idx, int val) {
    if (L == R) {
        assert(idx == L);
        curr->val = prev->val + val;
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
int maximise_xor (node *curr, int L, int x) {
    int y = 0;
    trie_node *pos = curr->trie;
    for (int i = 21; i >= 0; i--) {
        if (x & (1 << i)) {
            if (pos->zero == nullptr || pos->zero->added < L) {
                assert(pos->one != nullptr);
                assert(pos->one->added >= L);
                pos = pos->one;
                y |= (1 << i);
            }
            else {
                assert(pos->zero != nullptr);
                assert(pos->zero->added >= L);
                pos = pos->zero;
            }
        }
        else {
            if (pos->one == nullptr || pos->one->added < L) {
                assert(pos->zero != nullptr);
                assert(pos->zero->added >= L);
                pos = pos->zero;
            }
            else {
                assert(pos->one != nullptr);
                assert(pos->one->added >= L);
                pos = pos->one;
                y |= (1 << i);
            }
        }
    }
    return y;
}


int query (node *curr, int L, int R, int li, int ri) {
    if (curr == nullptr || ri < L || li > R)
        return 0;
    if (li <= L && ri >= R)
        return curr->val;
    return query(curr->left, L, (L+R)/2, li, ri) + query(curr->right, (L+R)/2+1, R, li, ri);
}

int get_kth (node *L, node *R, int li, int ri, int k) {
    if (li == ri)
        return li;
    int val = R->left->val - L->left->val, mid = (li+ri)/2;
    if (val >= k)
        return get_kth (L->left, R->left, li, mid, k);
    else
        return get_kth (L->right, R->right, mid+1, ri, k-val);
}

int main() {
    int M, N = 0;
    scanf("%d", &M);
    version[0] = null;
    version[0]->left = version[0];
    version[0]->right = version[0];
    version[0]->trie = null_trie;
    version[0]->trie->zero = version[0]->trie;
    version[0]->trie->one = version[0]->trie;
    for (int i = 0; i < M; i++) {
        int type;
        scanf("%d", &type);
        if (type == 0) {
            N++;
            int x;
            scanf("%d", &x);
            version[N] = null;
            update(version[N-1], version[N], 1, maxn, x, 1);
            version[N]->trie = null_trie;
            insert(version[N-1]->trie, version[N]->trie, x, N);
        }
        else if (type == 1) {
            int L, R, x;
            scanf("%d %d %d", &L, &R, &x);
            printf("%d\n", maximise_xor(version[R], L, x));
        }
        else if (type == 2) {
            int k;
            scanf("%d", &k);
            N -= k;
        }
        else if (type == 3) {
            int L, R, x;
            scanf("%d %d %d", &L, &R, &x);
            printf("%d\n", query(version[R], 1, maxn, 1, x) - query(version[L-1], 1, maxn, 1, x));

        }
        else {
            int L, R, x;
            scanf("%d %d %d", &L, &R, &x);
            printf("%d\n", get_kth(version[L-1], version[R], 1, maxn, x));
        }
    }
}