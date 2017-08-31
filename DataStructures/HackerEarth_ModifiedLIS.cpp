//Problem Link: https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-wayss/practice-problems/algorithm/modified-lis-1/
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

const int maxn = 1e5 + 1;
int A[maxn + 7], N, a, b, i, val;
ii negative_tree[maxn*4 +7], positive_tree[maxn*4 + 7];

inline int left(int x) { return (x << 1); }
inline int right(int x) { return (x << 1) + 1; }
inline bool outside(int L, int R) { return (b < L || a > R); }
inline bool inside(int L, int R) { return (a <= L && b >= R); }
#define leftChild left(p),L,(L+R)/2
#define rightChild right(p),((L+R)/2)+1,R
const ll MOD = 1e9 + 7;

inline int add(int xx, int yy) {
    return ((xx % MOD) + (yy % MOD)) % MOD;
}
inline ii best(ii xx, ii yy) {
    ii zz = max(xx, yy);
    if (xx.x == yy.x) zz.y = add(xx.y, yy.y);
    return zz;
}
ii query (int p, int L, int R, ii *tree) {
    if (outside(L, R))
        return mp(0, 0);
    if (inside(L, R))
        return tree[p];
    return best(query(leftChild, tree), query(rightChild, tree));
}
void update(int p, int L, int R, ii *tree) {
    if (L == R) {
        int len = tree[p].x;
        tree[p] = best(tree[p], mp(a, b));
    }
    else {
        if (i <= (L+R)/2)
            update(leftChild, tree);
        else
            update(rightChild, tree);
        tree[p] = best(tree[left(p)], tree[right(p)]);
    }
}

int main() {
    scanf("%d", &N);
    int isPos;
    while(N--) {
        scanf("%d", &val);
        
        isPos = (val > 0);
        val = abs(val);
        
        a = 1, b = val-1;
        ii call = query(1, 1, maxn, isPos ? negative_tree : positive_tree);
        
        i = val;
        a = call.x, b = call.y;
        if (b == 0) b++;
        a++;
        update(1, 1, maxn, isPos ? positive_tree : negative_tree);
    }
    ii ans = best(negative_tree[1], positive_tree[1]);
    printf("%d %d\n", ans.x, ans.y);
} 
