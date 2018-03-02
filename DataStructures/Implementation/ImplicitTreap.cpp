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
    int val, priority, size;
    node *left, *right;
    node(int val, int priority, int size) : val(val), priority(priority), size(size) {
        left = right = nullptr;
    }
};

inline int size(node *n) {
    return n ? n->size : 0;
}

inline void resize(node *n) {
    if (n) n->size = size(n->left) + size(n->right) + 1;
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
    resize(curr);
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
    resize(res);
}

inline node *init(int val) {
    return new node(val, rand_gen(mt), 1);
}

int find(node *curr, int pos, int add = 0) {
    if (!curr)
        return -1;
    int curr_pos = add + size(curr->left) + 1;
    if (curr_pos == pos)
        return curr->val;
    else if (pos < curr_pos)
        return find(curr->left, pos, add);
    else
        return find(curr->right, pos, curr_pos);
}

void print_array(node *T, int N) {
    for (int i = 1; i <= N; i++) cout << find(T, i) << " "; cout << endl;
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

void traverse(node *curr) {
    if (!curr) return;
    debug2(curr->val, curr->size);
    traverse(curr->left);
    traverse(curr->right);
}

int main() {
    int Q, N = 0;
    scanf("%d", &Q);
    node *treap = nullptr;
    while (Q--) {
        string type;
        cin >> type;
        if (type == "insert") {
            int pos, x;
            scanf("%d %d", &pos, &x);
            assert(pos <= N+1);
            insert(treap, pos, x);
            N++;
        }
        else if (type == "erase"){
            int pos;
            scanf("%d", &pos);
            assert(pos <= N);
            erase(treap, pos);
            N--;
        }
        cout << "Array: "; print_array(treap, N);
    }
}