//wrong solution lmao

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

const int maxn = 100007;
int N;

inline int left(int x) { return (x << 1); }
inline int right(int x) { return (x << 1) + 1; }
struct node {
    int val, lazy;
    node (int v = 0, int l = 0) {
        val = v, lazy = l;
    }
};

node tree[4*maxn];



void propagate(int i, int L, int R, int val) {
    tree[i].val = (R-L+1) * val;
    if (L != R) {
        tree[left(i)].lazy += val;
        tree[right(i)].lazy += val;
    }
}

node merge (node left, node right) {
    node ret(0,0);
    ret.val = left.val + right.val;
    return ret;
}

void update(int i, int L, int R, int li, int ri, int val) {
    if (tree[i].lazy) {
        propagate(i, L, R, tree[i].lazy);
        tree[i].lazy = 0;
    }
    if (ri < L || li > R)
        return;
    if (li <= L && ri >= R) {
        propagate(i, L, R, val);
        return;
    }
    int mid = (L+R)/2;
    update(left(i), L, mid, li, ri, val);
    update(right(i), mid+1, R, li, ri, val);
    tree[i] = merge(tree[left(i)], tree[right(i)]);
}

node query(int i, int L, int R, int li, int ri) {
    if (tree[i].lazy) {
        propagate(i, L, R, tree[i].lazy);
        tree[i].lazy = 0;
    }
    if (ri < L || li > R)
        return node(0,0);
    if (li <= L && ri >= R)
        return tree[i];
    int mid = (L+R)/2;
    return merge(query(left(i), L, mid, li, ri), query(right(i), mid+1, R, li, ri));
}

int main() {
    int U;
    scanf("%d %d", &N, &U);
    int ans = 0;
    for (int i = 0; i < U; i++) {
        int L, R;
        scanf("%d %d", &L, &R);
        update(1, 1, N, L, R, 1);
        //cout << query(1, 1, N, 1, N).val << endl;
        //for (int j = 1; j <= N; j++) cout << query(1, 1, N, j, j).val << " "; cout << endl;
        ans = max(ans, query(1, 1, N, 1, N).val);
    }
    for (int i = 1; i <= N; i++) {
        if (query(1, 1, N, i, i).val % 2 == 1) cout << 1;
        else cout << 0;
    }
    cout << endl;
}