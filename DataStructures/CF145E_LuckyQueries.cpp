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

//non decreasing:-
//0s...0s
//0s...1s
//1s...1s

//non increasing
//1s...0s

inline int left(int x) { return (x << 1); }
inline int right(int x) { return (x << 1) + 1; }

const int maxn = (int) 1e6+10;
int A[maxn];

struct node {
    int inc00, inc01, inc11, dec10, lazy;
    node(): inc00(0), inc01(0), inc11(0), dec10(0), lazy(0) {}
    node(int inc00, int inc01, int inc11, int dec10, int lazy): dec10(dec10), inc00(inc00), inc01(inc01), inc11(inc11), lazy(lazy) {}
};

node tree[4*maxn];

inline node merge(node left, node right) {
    node ret;
    ret.inc00 = left.inc00 + right.inc00;
    ret.inc11 = left.inc11 + right.inc11;
    ret.inc01 = max(max(max(left.inc01, right.inc01), left.inc00 + right.inc01), max(left.inc00 + right.inc11, left.inc01 + right.inc11));
    ret.dec10 = max(max(max(left.dec10, right.dec10), left.inc11 + right.dec10), max(left.inc11 + right.inc00, left.dec10 + right.inc00));
    return ret;
}
void build(int i, int L, int R) {
    if (L == R) {
        if (A[L] == 0) tree[i].inc00 = 1;
        else tree[i].inc11 = 1;
    }
    else {
        build(left(i), L, (L+R)/2);
        build(right(i), (L+R)/2+1, R);
        tree[i] = merge(tree[left(i)], tree[right(i)]);
    }
}

inline void propagate(int i, int L, int R, int val) {
    if (val % 2 == 1) {
        //cout << "here\n";
        node tmp = tree[i];
        tree[i].inc00 = tmp.inc11;
        tree[i].inc01 = tmp.dec10;
        tree[i].inc11 = tmp.inc00;
        tree[i].dec10 = tmp.inc01;
    }
    if (L != R) {
        tree[left(i)].lazy += val;
        tree[right(i)].lazy += val;
    }
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
    update(left(i), L, (L+R)/2, li, ri, val);
    update(right(i), (L+R)/2+1, R, li, ri, val);
    tree[i] = merge(tree[left(i)], tree[right(i)]);
}

node query(int i, int L, int R, int li, int ri) {
    if (tree[i].lazy) {
        propagate(i, L, R, tree[i].lazy);
        tree[i].lazy = 0;
    }
    if (ri < L || li > R)
        return node();
    if (li <= L && ri >= R)
        return tree[i];
    return merge(query(left(i), L, (L+R)/2, li, ri), query(right(i), (L+R)/2+1, R, li, ri));
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    string S, q;
    cin >> S;
    for (int i = 1; i <= N; i++) {
        if (S[i-1] == '4') A[i] = 0;
        else A[i] = 1;
    }
    build(1, 1, N);
    for (int i = 0; i < M; i++) {
        cin >> q;
        if (q == "count") {
            node ans = query(1, 1, N, 1, N);
            printf("%d\n", max(max(ans.inc00, ans.inc01), ans.inc11));
        }
        else {
            int L, R;
            scanf("%d %d", &L, &R);
            update(1, 1, N, L, R, 1);
        }
    }
}