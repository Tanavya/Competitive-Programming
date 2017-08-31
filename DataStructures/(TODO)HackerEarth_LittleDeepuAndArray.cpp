//Problem Link : https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/practice-problems/algorithm/little-deepu-and-array/description/

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

int tree[400007], A[100007], lazy[400007], N, Q, X, a, b;

inline int left(int x) { return (x << 1); }
inline int right(int x) { return (x << 1) + 1; }

void propagate(int i, int L, int R, int p) {
    tree[i] += p;
    if (L != R) {
        lazy[left(i)] += p;
        lazy[right(i)] += p;
    }
}

void build (int i, int L, int R) {
     if (L == R) {
         tree[i] = A[L];
     }
     else {
         int mid = (L+R)/2;
         build(left(i), L, mid);
         build(right(i), mid+1, R);
         tree[i] = min(tree[left(i)], tree[right(i)]);
     }
}
void updateRange(int i, int L, int R) {
    if (lazy[i] != 0) {
        propagate(i, L, R, lazy[i]);
        lazy[i] = 0;
    }
    if (tree[i] > X) {
        propagate(i, L, R, -1);
        return;
    }
    if (L != R) {
        int mid = (L+R)/2;
        updateRange(left(i), L, mid);
        updateRange(right(i), mid+1, R);
        tree[i] = min(tree[left(i)], tree[right(i)]);   
    }
}
int queryRange(int i, int L, int R) {
    if (lazy[i] != 0) {
        propagate(i, L, R, lazy[i]);
        lazy[i] = 0;
    }
    if (b < L || a > R)
        return INF;
    if (a <= L && b >= R)
        return tree[i];
    int mid = (L+R)/2;
    return min(queryRange(left(i), L, mid), queryRange(right(i), mid+1, R));
}

int main() {
    char q;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d", &A[i]);
    build(1, 1, N);
    scanf("%d", &Q);
    for (int i = 0; i < Q; i++) {
        scanf("%d", &X);
        updateRange(1, 1, N);
    }
    for (int i = 1; i <= N; i++) {
        a = b = i;
        printf("%d ", queryRange(1, 1, N));
    }
}