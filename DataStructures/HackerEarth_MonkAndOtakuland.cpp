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

const int maxn = 200000;
int tree[maxn*4+7], lazy[maxn*4+7], A[maxn+7], a, b, N, Q, val; 

inline int left(int x) { return (x << 1); }
inline int right(int x) { return (x << 1) + 1; }
inline bool outside(int L, int R) { return (b < L || a > R); }
inline bool inside(int L, int R) { return (a <= L && b >= R); }
#define leftChild left(p),L,(L+R)/2
#define rightChild right(p),((L+R)/2)+1,R
inline int calc(int on, int L, int R) { return (R-L+1) - on; }

void propagate(int p, int L, int R, int t) {
    if (t % 2 == 1) 
        tree[p] = calc(tree[p], L, R);

    if (L != R) {
        lazy[right(p)] += t;
        lazy[left(p)] += t;
    }
}
void build(int p, int L, int R) {
    if (L == R) {
        tree[p] = A[L];
    }
    else {
        build(leftChild);
        build(rightChild);
        tree[p] = tree[left(p)] + tree[right(p)];
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
    tree[p] = tree[left(p)] + tree[right(p)];
}
int queryRange(int p, int L, int R) {
    if (lazy[p]) {
        propagate(p, L, R, lazy[p]);
        lazy[p] = 0;
    }
    if (outside(L, R))
        return 0;
    if (inside(L, R)) 
        return tree[p];
    return queryRange(leftChild) + queryRange(rightChild);
}

int main() {
    scanf("%d %d", &N, &Q);
    string edges;
    int type;
    cin >> edges;
    for (int i = 1; i < N; i++) {
        if (edges[i-1] == '>') A[i] = 1;
        else A[i] = 0;
    }
    N--;
    build(1, 1, N);
    while (Q--) {
        scanf("%d %d %d", &type, &a, &b);
        if (type == 1) {
            b--;
            updateRange(1, 1, N);
        }
        else {
            if (a == b) printf("0\n");
            else {
                if (a < b) {
                    b--;
                    printf("%d\n", calc(queryRange(1, 1, N), a, b));
                }
                else {
                    swap(a, b);
                    b--;
                    printf("%d\n", queryRange(1, 1, N));
                }
            }
        }
    }
}