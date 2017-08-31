//Tutorial Link : https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/tutorial/

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

const int maxn = 1e5 + 5;
int tree[4 * maxn], lazy[4 * maxn], A[maxn], N, Q, a, b, val;

inline int left(int x) { return x << 1; }
inline int right(int x) { return (x << 1) + 1; } 
inline bool within(int L, int R) { return (a <= L && b >= R); }
inline bool outside(int L, int R) { return (b < L || a > R); }

void propagate(int i, int L, int R) {
    tree[i] += (R - L + 1) * lazy[i];
    if (L != R) {
        //mark children as lazy
        lazy[left(i)] += lazy[i];
        lazy[right(i)] += lazy[i];
    }
    lazy[i] = 0;
}
void build(int i, int L, int R) {
    if (L == R) {
        tree[i] = A[L];
    }
    else {
        int mid = (L+R)/2;
        build(left(i), L, mid);
        build(right(i), mid+1, R);
        tree[i] = tree[left(i)] + tree[right(i)];
    }
}
void updateRange(int i, int L, int R) {
    if (lazy[i]) // current range not up-to-date
        propagate(i, L, R);
    if (outside(L, R)) // current range is not within required range
        return; 
    if (within(L, R)) { // current range fully within required range
        // update current range with val
        tree[i] += (R - L + 1) * val;
        if (L != R) {
            lazy[left(i)] += val;
            lazy[right(i)] += val;
        }
        return;
    }
    // current range partially within required range
    int mid = (L+R)/2;
    updateRange(left(i), L, mid); //update left child
    updateRange(right(i), mid+1, R); //update right child
    tree[i] = tree[left(i)] + tree[right(i)]; //update root with sum of children
}
int queryRange(int i, int L, int R) {
    if (lazy[i]) 
        propagate(i, L, R);
    if (outside(L, R))
        return 0;
    if (within(L, R)) 
        return tree[i];
    int mid = (L+R)/2;
    int p1 = queryRange(left(i), L, mid);
    int p2 = queryRange(right(i), mid+1, R);
    return p1 + p2;
}
int main() {
    char q; 
    //r = range update, q = query interval sum, u = update single
    scanf("%d %d", &N, &Q);
    for (int i = 1; i <= N; i++)
        scanf("%d", &A[i]);
    build(1, 1, N);
    for (int i = 0; i < Q; i++) {
        cin >> q;
        if (q == 'q') {
            scanf("%d %d", &a, &b);
            printf("%d\n", queryRange(1, 1, N));
        }
        else if (q == 'u') {
            scanf("%d %d", &a, &val);
            b = a;
            updateRange(1, 1, N);
        }
        else if (q == 'r') {
            scanf("%d %d %d", &a, &b, &val);
            updateRange(1, 1, N);
        }
    }
}
/*
5 8
1 2 3 4 5
q 1 4
q 2 5
q 3 5
u 2 10
q 1 3
r 1 5 3
*/