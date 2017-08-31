//Problem Link: https://www.codechef.com/problems/MULTQ3
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
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip> //cout << setprecision(node) << fixed << num

#define mp make_pair
#define pb push_back
#define x first
#define y second
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << "\n";

typedef long long int ll;
typedef long double ld;
typedef std::pair <int, int> ii;
typedef std::vector <int> vi;
typedef std::vector <ll> vll;
const int INF = int(1e9);
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

using namespace std;

const int maxn = 111111;
int tree[maxn*4+7][3], lazy[maxn*4+7], A[maxn], N, Q, a, b;

inline int left(int x) { return (x << 1); }
inline int right(int x) { return (x << 1) + 1; }
inline bool outside(int L, int R) { return (b < L || a > R); }
inline bool inside(int L, int R) { return (a <= L && b >= R); }
#define leftChild left(p),L,(L+R)/2
#define rightChild right(p),((L+R)/2)+1,R

void shift(int &x, int &y, int &z, int times) {
    for (int i = 0; i < times; i++) {
        int temp = x;
        x = z;
        z = y;
        y = temp;
    }
}

void propagate(int p, int L, int R, int times) {
    shift(tree[p][0], tree[p][1], tree[p][2], times % 3);
    if (L != R) {
        lazy[left(p)] += times;
        lazy[right(p)] += times;
    }
}

void build(int p, int L, int R) {
    if (L == R) {
        tree[p][0] = 1;
    }
    else {
        build(leftChild);
        build(rightChild);
        tree[p][0] = tree[left(p)][0] + tree[right(p)][0];
    }
}
void updateRange(int p, int L, int R) {
    if (lazy[p]) {
        propagate(p, L, R, lazy[p]);
        lazy[p] = 0;
    }
    if (outside(L, R))
        return;
    if (inside(L, R)) {
        propagate(p, L, R, 1);
        return;
    }
    updateRange(leftChild);
    updateRange(rightChild);
    tree[p][0] = tree[left(p)][0] + tree[right(p)][0];
    tree[p][1] = tree[left(p)][1] + tree[right(p)][1];
    tree[p][2] = tree[left(p)][2] + tree[right(p)][2];
}
int queryRange(int p, int L, int R) {
    if (lazy[p]) {
        propagate(p, L, R, lazy[p]);
        lazy[p] = 0;
    }
    if (outside(L, R)) 
        return 0;
    if (inside(L, R))
        return tree[p][0];
    return queryRange(leftChild) + queryRange(rightChild);
}
int main() {
    
    scanf("%d %d", &N, &Q);
    build(1, 1, N);
    int type;
    while (Q--) {
        scanf("%d %d %d", &type, &a, &b);
        a++; b++;
        if (type == 1) 
            printf("%d\n", queryRange(1, 1, N));
        else
            updateRange(1, 1, N);
    }
}