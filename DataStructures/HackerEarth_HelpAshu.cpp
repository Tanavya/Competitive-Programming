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

const int maxn = 1e5;
int tree[maxn*4 + 7], A[maxn + 7], N, Q, a, b, i, x;

inline int left(int x) { return (x << 1); }
inline int right(int x) { return (x << 1) + 1; }
inline bool outside(int L, int R) { return (b < L || a > R); }
inline bool inside(int L, int R) { return (a <= L && b >= R); }
#define leftChild left(p),L,(L+R)/2
#define rightChild right(p),((L+R)/2)+1,R

void build(int p, int L, int R) {
    if (L == R) {
        if (A[L] % 2 == 0) tree[p] = 1;
        else tree[p] = 0;
    }
    else {
        build(leftChild);
        build(rightChild);
        tree[p] = tree[left(p)] + tree[right(p)];
    }
}
void update(int p, int L, int R) {
    if (L == R) {
        A[i] = x;
        if (x % 2 == 0) tree[p] = 1;
        else tree[p] = 0;
    }
    else {
        if (i <= (L+R)/2)
            update(leftChild);
        else
            update(rightChild);
        tree[p] = tree[left(p)] + tree[right(p)];
    }
}
int query(int p, int L, int R) {
    if (outside(L, R)) 
        return 0;
    if (inside(L, R))
        return tree[p];
    return query(leftChild) + query(rightChild);
}

int main() {
    int type;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) 
        scanf("%d", &A[i]);
    build(1, 1, N);
    scanf("%d", &Q);
    while (Q--) {
        scanf("%d", &type);
        if (type == 0) {
            scanf("%d %d", &i, &x);
            update(1, 1, N);
        }
        else if (type == 1) {
            scanf("%d %d", &a, &b);
            printf("%d\n", query(1, 1, N));
        }
        else {
            scanf("%d %d", &a, &b);
            printf("%d\n", (b-a+1)-query(1, 1, N));
        }
    }
}