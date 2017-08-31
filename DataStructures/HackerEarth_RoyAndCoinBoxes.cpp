//Problem Link : https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/roy-and-coin-boxes-1/

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
const int maxn = 1000005;
int tree[4 * maxn], A[maxn], lazy[4 * maxn], cnt[maxn], N, M, Q, a, b;

inline int left(int x) { return (x << 1); }
inline int right(int x) { return (x << 1) + 1; }
inline bool outside(int L, int R) { return (a > R || b < L); }
inline bool within(int L, int R) { return (a <= L && b >= R); }

void propagate(int i, int L, int R, int p) {
    tree[i] += (R - L + 1) * p;
    if (L != R) {
        lazy[left(i)] += p;
        lazy[right(i)] += p;
    }
}

void build(int i, int L, int R) {
    //unrequired, but coded cuz ynot
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
    if (lazy[i]) {
        propagate(i, L, R, lazy[i]);
        lazy[i] = 0;
    }
    if (outside(L, R))
        return;
    if (within(L, R)) {
        propagate(i, L, R, 1);
        return;
    }
    int mid = (L+R)/2;
    updateRange(left(i), L, mid);
    updateRange(right(i), mid+1, R);
    tree[i] = tree[left(i)] + tree[right(i)];
}

int queryRange(int i, int L, int R) {
    if (lazy[i]) {
        propagate(i, L, R, lazy[i]);
        lazy[i] = 0;
    }
    if (outside(L, R))
        return 0;
    if (within(L, R))
        return tree[i];
    int mid = (L+R)/2;
    return queryRange(left(i), L, mid) + queryRange(right(i), mid+1, R);
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &a, &b);
        updateRange(1, 1, N);
    }
    for (int i = 1; i <= N; i++) {
        a = b = i;
        A[i] = queryRange(1, 1, N);
        cnt[A[i]]++;
    }
    for (int x = N; x >= 1; x--) {
        cnt[x] += cnt[x+1];
    }
    scanf("%d", &Q);
    int x;
    for (int i = 0; i < Q; i++) {
        scanf("%d", &x);
        printf("%d\n", cnt[x]);
    }
}

