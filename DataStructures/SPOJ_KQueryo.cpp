//Tutorial Link : https://www.commonlounge.com/discussion/d871499b49e443259cfbea9b16f9b958/main

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

#define mp make_pair
#define pb push_back
#define x first
#define y second
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << "\n";
#define all(v) v.begin(),v.end()

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
int A[maxn+7], a, b, K, N;
vector<int> tree[4*maxn+7];

inline int left(int x) { return (x << 1); }
inline int right(int x) { return (x << 1) + 1; }
inline bool outside(int L, int R) { return (b < L || a > R); }
inline bool inside(int L, int R) { return (a <= L && b >= R); }
#define leftChild left(p),L,(L+R)/2
#define rightChild right(p),((L+R)/2)+1,R

void build(int p, int L, int R) {
    if (L == R) {
        tree[p].pb(A[L]);
    }
    else {
        build(leftChild);
        build(rightChild);
        merge(all(tree[left(p)]), all(tree[right(p)]), back_inserter(tree[p]));
    }
}
int query(int p, int L, int R) {
    if (outside(L, R))
        return 0;
    if (inside(L, R))
        return distance(upper_bound(all(tree[p]), K), tree[p].end());
    return query(leftChild) + query(rightChild);
}
int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d", &A[i]);
    build(1, 1, N);
    int Q;
    scanf("%d", &Q);
    int last_ans = 0;
    while (Q--) {
        scanf("%d %d %d", &a, &b, &K);
        a ^= last_ans;
        b ^= last_ans;
        K ^= last_ans;
        last_ans = query(1, 1, N);
        printf("%d\n", last_ans);
    }
}