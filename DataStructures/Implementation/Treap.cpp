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



mt19937 mt(1234);
uniform_int_distribution<int> dist;
//each node such that priority(parent) > priority(child)
//and value(left) <= value(node), value(right) > value(node)
//priority assigned randomly to maintain approx logN height
struct node {
    int val, priority, size;
    node *left, *right;
    node() {}
    node(int val, int priority, int size, node *left, node *right): val(val), priority(priority), size(size), left(left), right(right) {}
};

#define null new node(0,0,0,nullptr,nullptr);
#define sz(n) (n?n->size:0)

inline void resize(node *n) {
    if (n) n->size = sz(n->left) + sz(n->right) + 1;
}

//split always done by value NOT priority
//creates 2 new treaps L and R wrt to X, such that all value in L <= X and all value in R > x
void split(node* curr, node* &L, node* &R, int key) {
    if (!curr) {
        L = R = nullptr;
    }
    else if (curr->val <= key) {
        //split(curr->right) = L' and R'
        //curr->right = L'. L = curr
        //R = R'

        split(curr->right, curr->right, R, key);
        L = curr;
    }
    else {
        split(curr->left, L, curr->left, key);
        R = curr;
    }
    resize(curr);
}

//merge L and R to give new treap, provided max value in L < min value in R
//checks priority of L and R, and accordingly sets L above or below R
void merge(node* &curr, node *L, node *R) {
    if (!L || !R) {
        if (L) curr = L;
        else curr = R;
    }
    else if (L->priority > R->priority) {
        //merge(L->right, R) and add it to L
        merge(L->right, L->right, R);
        curr = L;
    }
    else {
        merge(R->left, L, R->left);
        curr = R;
    }
    resize(curr);
}

//normal BST traversal until you reach leaf, or you reach a node whose priority is lesser than inserted node's priority
void insert(node* &curr, node *nw) {
    if (!curr) {
        curr = nw;
    }
    else if (nw->priority > curr->priority) {
        //make nw the new root of subtree of curr
        split(curr, nw->left, nw->right, nw->val);
        curr = nw;
    }
    else {
        //BST traversal
        if (nw->val <= curr->val) insert(curr->left, nw);
        else insert(curr->right, nw);
    }
    resize(curr);
}

//BST traversal to find node with key, and then delete it by merging left and right children
void erase(node* &curr, int key) {
    if (!curr) {
        return;
    }
    if (curr->val == key) {
        node *tmp = curr;
        merge(curr, curr->left, curr->right);
        delete tmp;
    }
    else {
        if (key <= curr->val) erase(curr->left, key);
        else erase(curr->right, key);
    }
    resize(curr);
}

bool find(node *curr, int key) {
    if (!curr) {
        return false;
    }
    if (curr->val == key) {
        return true;
    }
    else if (key <= curr->val){
        return find(curr->left, key);
    }
    else {
        return find(curr->right, key);
    }
}

inline node *init(int val) {
    return new node(val, dist(mt), 1, nullptr, nullptr);
}
void traverse(node *curr) {
    if (!curr) return;
    cout << curr->val << endl;
    traverse(curr->left);
    traverse(curr->right);
}
int main() {
    int T;
    cin >> T;
    node *root = nullptr;
    while (T--) {
        string type;
        int val;
        cin >> type >> val;
        if (type == "insert") {
            insert(root, init(val));
        }
        else if (type == "erase") {
            erase(root, val);
        }
        else if (type == "find") {
            if (find(root, val)) {
                cout << "Found " <<  val << endl;
            }
            else {
                cout << "Not found " << val << endl;
            }
        }
        else {
            assert(false);
        }
    }
}