#include <iostream>
#include <vector>
#include <random>
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

mt19937 mt(6969);
uniform_int_distribution <int> gen_rand;

struct node {
    int val, priority, size;
    node *left, *right;
    node() {}
    node(int val, int priority, int size, node *left, node *right): val(val), priority(priority), size(size), left(left), right(right) {}
};

#define null new node(0,0,0,nullptr,nullptr);
#define sz(n) (n?n->size:0)

inline void resize(node *n) {
    if (n != nullptr) n->size = sz(n->left) + sz(n->right) + 1;
}

void split(node *curr, node *&L, node *&R, int key) {
    if (!curr)
        L = R = nullptr;
    else if (curr->val <= key) {
        split(curr->right, curr->right, R, key);
        L = curr;
    }
    else {
        split(curr->left, L, curr->left, key);
        R = curr;
    }
    resize(curr);
}

void merge(node *&res, node *L, node *R) {
    if (!L || !R) {
        res = L?L:R;
    }
    else if (L->priority > R->priority) {
        merge(L->right, L->right, R);
        res = L;
    }
    else {
        merge(R->left, L, R->left);
        res = R;
    }
    resize(res);
}

void insert(node *&curr, node *nw) {
    assert(nw);
    if (!curr)
        curr = nw;
    else if (curr->priority < nw->priority) {
        split(curr, nw->left, nw->right, nw->val);
        curr = nw;
    }
    else {
        if (nw->val <= curr->val) insert(curr->left, nw);
        else insert(curr->right, nw);
    }
    resize(curr);
}

void erase(node *&curr, int key) {
    if (!curr)
        return;
    if (curr->val == key) {
        //node *tmp = curr;
        merge(curr, curr->left, curr->right);
        //delete tmp;
    }
    else {
        if (key <= curr->val) erase(curr->left, key);
        else erase(curr->right, key);
    }
    resize(curr);
}

bool find(node *curr, int key) {
    if (!curr)
        return false;
    if (curr->val == key)
        return true;
    if (key < curr->val)
        return find(curr->left, key);
    else
        return find(curr->right, key);
}

int kth(node *curr, int k) {
    assert(k);
    if (!curr)
        return -1;
    int cnt_left = sz(curr->left) + 1;
    if (cnt_left == k) {
        return curr->val;
    }
    if (k <= cnt_left) {
        return kth(curr->left, k);
    }
    else {
        return kth(curr->right, k - cnt_left);
    }
}

int count(node *curr, int x) {
    if (!curr)
        return 0;
    if (curr->val < x) {
        return 1 + sz(curr->left) + count(curr->right, x);
    }
    else {
        return count(curr->left, x);
    }
}

inline node *init(int val) {
    return new node(val, gen_rand(mt), 1, nullptr, nullptr);
}

int main() {
    int Q;
    node *root = nullptr;
    scanf("%d", &Q);
    while (Q--) {
        string type;
        cin >> type;
        int x;
        scanf("%d", &x);
        if (type == "I") {
            if (!find(root, x))
                insert(root, init(x));
        }
        else if (type == "D") {
            if (find(root, x))
                erase(root, x);
        }
        else if (type == "K") {
            int ret = kth(root, x);
            if (ret == -1) printf("invalid\n");
            else printf("%d\n", ret);
        }
        else {
            printf("%d\n", count(root, x));
        }
    }
}