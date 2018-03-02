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
#include <random>
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

mt19937 mt(6969);
uniform_int_distribution <int> rand_gen;

struct node {
    int val, priority, size, dp[2][2];
    node *left, *right;
    node() { val = -1; }
    node(int val, int priority, int size) : val(val), priority(priority), size(size) {
        dp[0][0] = dp[0][1] = dp[1][0] = dp[1][1] = val;
        left = right = nullptr;
    }
};

inline int size(node *n) {
    return n ? n->size : 0;
}

inline void reset(node *&n) {
    if (n) {
        n->dp[0][0] = n->dp[0][1] = n->dp[1][0] = n->dp[1][1] = n->val;
        n->size = size(n->left) + size(n->right) + 1;
    }
}

/*
node* find(node *curr, int pos, int add = 0) {
    if (!curr)
        return new node();
    int curr_pos = add + size(curr->left) + 1;
    if (curr_pos == pos)
        return curr;
    else if (pos < curr_pos)
        return find(curr->left, pos, add);
    else
        return find(curr->right, pos, curr_pos);
}

void print_array(node *T, int N) {
    for (int i = 1; i <= N; i++) cout << find(T, i)->val << " "; cout << endl;
}

void traverse(node *curr) {
    if (!curr) return;
    debug2("traversing...", curr->val);
    traverse(curr->left);
    traverse(curr->right);
}*/

inline void combine(node *&res, node *L, node *R) {
    if (!L || !R) {
        res = L ? L : R;
        return;
    }
    int dp[2][2];
    dp[1][1] = L->dp[1][1] + R->dp[1][1];
    dp[0][0] = max(L->dp[0][1] + R->dp[1][0], max(L->dp[0][0], R->dp[0][0]));
    dp[0][1] = max(R->dp[0][1], L->dp[0][1] + R->dp[1][1]);
    dp[1][0] = max(L->dp[1][0], L->dp[1][1] + R->dp[1][0]);
    res->dp[0][0] = dp[0][0];
    res->dp[0][1] = dp[0][1];
    res->dp[1][0] = dp[1][0];
    res->dp[1][1] = dp[1][1];
}

inline void operation(node *curr) {
    if (!curr) return;
    reset(curr);
    combine(curr, curr->left, curr);
    combine(curr, curr, curr->right);
}

void split(node *curr, node *&L, node *&R, int pos, int add = 0) {
    if (!curr) {
        L = R = nullptr;
        return;
    }
    int curr_pos = add + size(curr->left) + 1;
    if (curr_pos <= pos) {
        split(curr->right, curr->right, R, pos, curr_pos);
        L = curr;
    }
    else {
        split(curr->left, L, curr->left, pos, add);
        R = curr;
    }
    operation(curr);
}
void merge(node *&res, node *L, node *R) {
    if (!L || !R) {
        res = L ? L : R;
    }
    else if (L->priority > R->priority) {
        merge(L->right, L->right, R);
        res = L;
    }
    else {
        merge(R->left, L, R->left);
        res = R;
    }
    operation(res);
}


inline node *init(int val) {
    return new node(val, rand_gen(mt), 1);
}

void insert(node *&treap, int pos, int x) {
    node *L = nullptr, *R = nullptr;
    split(treap, L, R, pos-1);
    merge(L, L, init(x));
    merge(treap, L, R);
}

void erase(node *&treap, int pos) {
    node *L = nullptr, *R = nullptr;
    split(treap, L, R, pos-1);
    node *tmp;
    split(R, tmp, R, 1);
    delete tmp;
    merge(treap, L, R);
}

void update(node *&treap, int pos, int x) {
    node *L = nullptr, *R = nullptr;
    split(treap, L, R, pos-1);
    node *tmp;
    split(R, tmp, R, 1);
    tmp->val = x;
    reset(tmp);
    merge(R, tmp, R);
    merge(treap, L, R);
}

int query(node *treap, int l, int r) {
    node *L = nullptr, *mid = nullptr, *R = nullptr;
    split(treap, L, mid, l-1);
    split(mid, treap, R, r-l+1);
    int ret = treap->dp[0][0];
    merge(mid, L, treap);
    merge(treap, mid, R);
    return ret;
}

int main() {
    int N;
    node *treap = nullptr;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        int x;
        scanf("%d", &x);
        insert(treap, i, x);
    }
    int Q;
    scanf("%d", &Q);
    while (Q--) {
        char type;
        cin >> type;
        if (type == 'I') {
            int i, x;
            scanf("%d %d", &i, &x);
            insert(treap, i, x);
            N++;
        }
        else if (type == 'D') {
            int i;
            scanf("%d", &i);
            erase(treap, i);
            N--;
        }
        else if (type == 'R') {
            int i, x;
            scanf("%d %d", &i, &x);
            update(treap, i, x);
        }
        else {
            int x, y;
            scanf("%d %d", &x, &y);
            printf("%d\n", query(treap, x, y));
        }
    }
}