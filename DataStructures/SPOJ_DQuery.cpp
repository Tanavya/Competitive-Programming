//GHANTA LEARNING EXPERIENCE.. USE LIST OVER QUEUE WTF?!

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

const int MAXN = 1e6 + 7;

inline int left(int x) {return x << 1; }
inline int right(int x) { return (x<<1)+1;}

int tree[120007], distinct[30007], A[30007];
vector <list<int>> occ (MAXN);
map <int, map <int, int>> ans;

void build(int p, int L, int R) {
    if (L == R) {
        tree[p] = distinct[L];
    }
    else {
        build(left(p), L, (L+R)/2);
        build(right(p), (L+R)/2+1, R);
        tree[p] = tree[left(p)] + tree[right(p)];
    }
}
void update(int p, int L, int R, int idx, int val) {
    if (L == R) {
        distinct[idx] = val;
        tree[p] = val;
    }
    else {
        int mid = (L+R)/2;
        if (idx <= mid) 
            update(left(p), L, mid, idx, val);
        else
            update(right(p), mid+1, R, idx, val);
        tree[p] = tree[left(p)] + tree[right(p)];
    }
}
int query(int p, int L, int R, int a, int b) {
    if (b < L || a > R)
        return 0;
    if (a <= L && b >= R)
        return tree[p];
    return query(left(p), L, (L+R)/2, a, b) + query(right(p), (L+R)/2+1, R, a, b);
}
int main() {
    int N;
    scanf("%d", &N);
    vi A(N+1);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &A[i]);
        if (occ[A[i]].empty()) distinct[i] = 1;
        occ[A[i]].push_back(i);
    }
    build(1, 1, N);
    int Q;
    scanf("%d", &Q);
    vector <ii> queries;
    int i, j;
    for (int q = 0; q < Q; q++) {
        scanf("%d %d", &i, &j);
        //queries.pb(mp(i, j));
    }
    vector <ii> original = queries;
    sort(queries.begin(), queries.end());
    int prevL = 1, currL, currR;
    for (int q = 0; q < Q; q++) {
        currL = queries[q].x, currR = queries[q].y;
        for (int i = prevL; i < currL; i++) {
            occ[A[i]].pop_front();
            if (!occ[A[i]].empty()) {
                int next = occ[A[i]].front();
                update(1, 1, N, next, 1);
            }
        }
        ans[currL][currR] = query(1, 1, N, currL, currR);
        prevL = currL;
    }
    for (ii q : original) {
        printf("%d\n", ans[q.x][q.y]);
    }
}
