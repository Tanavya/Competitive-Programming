//Problem Link: http://www.spoj.com/problems/ORDERSET/
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

const int maxn = 2*1e5;
int tree[maxn*4 + 7], A[maxn + 7], a, b, idx, val, K;

inline int left(int x) { return (x << 1); }
inline int right(int x) { return (x << 1) + 1; }
inline bool outside(int L, int R) { return (b < L || a > R); }
inline bool inside(int L, int R) { return (a <= L && b >= R); }
#define leftChild left(p),L,(L+R)/2
#define rightChild right(p),((L+R)/2)+1,R

void update(int p, int L, int R) {
    if (L == R) {
        tree[p] = val;
    }
    else {
        if (idx <= (L+R)/2)
            update(leftChild);
        else
            update(rightChild);
        tree[p] = tree[right(p)] + tree[left(p)];
    }
} 
int query(int p, int L, int R) {
    if (outside(L, R)) 
        return 0;
    if (inside(L, R))
        return tree[p];
    return query(leftChild) + query(rightChild);
}
int kth(int p, int L, int R) {
    
    if (K > tree[p]) 
        return -1;
    if (L == R)
        return A[L];
    if (K <= tree[left(p)])
        return kth(leftChild);
    else {
        K -= tree[left(p)];
        return kth(rightChild);
    }
}
int main() {
    char type;
    int Q, param;
    vector <ii> queries;
    set <int> values_set;
    unordered_map <int, int> values_map;
    scanf("%d", &Q);
    for (int q = 0; q < Q; q++) {
        cin >> type >> param;
        if (type == 'I') {
            queries.pb(mp(0, param));
            values_set.insert(param);
        }
        else if (type == 'D') queries.pb(mp(1, param));
        else if (type == 'K') queries.pb(mp(2, param));
        else if (type == 'C') queries.pb(mp(3, param));
    }
    //print(values_set);
    int N = 1;
    for (int num : values_set) {
        values_map[num] = N;
        A[N] = num;
        N++;
    }
    for (ii q : queries) {
        if (q.x == 0) {
            idx = values_map[q.y];
            if (!idx) assert(false);
            val = 1;
            update(1, 1, N);
        }
        else if (q.x == 1) {
            idx = values_map[q.y];
            if (idx) {
                val = 0;
                update(1, 1, N);
            }
        }
        else if (q.x == 2) {
            K = q.y;
            int ret = kth(1, 1, N);
            //returns the kth smallest number in range [0, N]
            if (ret == -1) printf("invalid\n");
            else printf("%d\n", ret);
        }
        else if (q.x == 3) {
            auto it = values_set.lower_bound(q.y);
            if (it == values_set.begin())
                printf("%d\n", 0);
            else {
                a = 1;
                b = values_map[*prev(it)];
                printf("%d\n", query(1, 1, N));
            }
        }
    }
}
/*
19
I 5
I 6
I 3
I 10
I 12
I 2
C 15
C 1
C 3
D 3
K 10
D 4
K 3
D 5
K 1
C 15
C 3
C 7
K 0
//2 6 10 12
*/