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
int A[maxn], N;

struct node {
    int val;
    node *left, *right;
    node (int val, node *left, node *right): val(val), left(left), right(right) {}
};

node *version[maxn];
#define null new node (0, NULL, NULL)
void update(node *prev, node *curr, int L, int R, int idx, int val) {
    if (L == R) {
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
        curr->val = curr->right->val + curr->left->val;
    }
}

int query(node *a, node *b, int L, int R, int k) {
    if (L == R)
        return L;
    int curr = b->left->val - a->left->val;
    int mid = (L+R)/2;
    if (curr >= k)
        return query(a->left, b->left, L, mid, k);
    else
        return query(a->right, b->right, mid+1, R, k-curr);
}

ll rec(int L, int R) {
    if (R <= L)
        return 0;
    int mid = A[query(version[L-1], version[R], 1, N, (R-L+2)/2)];
    return R-L+1 + rec(L, mid-1) + rec(mid+1, R);
}

int main() {
    scanf("%d", &N);
    vector <ii> V;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &A[i]);
        V.pb(mp(A[i], i));
    }
    sort(all(V));
    version[0] = null;
    version[0]->left = version[0];
    version[0]->right = version[0];
    for (int i = 1; i <= N; i++) {
        version[i] = null;
        update(version[i-1], version[i], 1, N, V[i-1].se, 1);
    }
    cout << rec(1, N) << endl;
}