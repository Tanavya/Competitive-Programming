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

int tree[400007], A[100007], N, Q;
inline int left(int p) { return (p << 1); }
inline int right(int p) { return (p << 1) + 1; }
void build(int p, int L, int R) { //O(N)
    if (L == R) {
        tree[p] = A[L];
    
    else {
        int mid = (L+R) / 2;
        build(left(p), L, mid);
        build(right(p), mid+1, R);
        tree[p] = min(tree[left(p)], tree[right(p)]);
    }
}
int query(int p, int L, int R, int i, int j) { //O(logN)
    if (L > j || R < i) return INF;
    if (L >= i && R <= j) return tree[p]; 
    int mid = (L+R)/2;
    int p1 = query(left(p), L, mid, i, j);
    int p2 = query(right(p), mid+1, R, i, j);
    return min(p1, p2);
}
void update(int p, int L, int R, int i, int val) { //O(logN)
    if (L == R) {
        A[i] = val;
        tree[p] = val;
    }
    else {
        int mid = (L+R)/2;
        if (mid >= i)        
            update(left(p) , L    , mid, i, val);
        else
            update(right(p), mid+1, R  , i, val);
        tree[p] = min(tree[left(p)], tree[right(p)]);
    }
}


int main() {
    char q;
    int a, b;
    scanf("%d %d", &N, &Q);
    for (int i = 1; i <= N; i++) 
        scanf("%d", &A[i]);
    build(1, 1, N);
    for (int i = 0; i < Q; i++) {
        cin >> q >> a >> b;
        if (q == 'q') 
            printf("%d\n", query(1, 1, N, a, b));
        else 
            update(1, 1, N, a, b);
    }
}