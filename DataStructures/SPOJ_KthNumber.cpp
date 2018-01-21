//Problem Link : http://www.spoj.com/problems/MKTHNUM/

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
vi segment;
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
        return distance(tree[p].begin(), lower_bound(all(tree[p]), K));
    return query(leftChild) + query(rightChild);
}
int main() {
    int Q;
    vector <ii> V;
    scanf("%d %d", &N, &Q);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &A[i]);
        V.pb(mp(A[i], i));
    }
    sort(all(V));
    build(1, 1, N);
    while (Q--) {
        int a1, b1, target, mid;
        scanf("%d %d %d", &a, &b, &target);

        target--;

        a1 = 0, b1 = N-1;
        int ans = 0;
        while (a1 <= b1) { //binary search the answer.. SO annoying and difficult to debug. :/
            mid = (a1+b1)/2;
            K = V[mid].x;
            int que = query(1, 1, N);
            if (que == target) {
                if (V[mid].y >= a && V[mid].y <= b) {
                    ans = K;
                    break;
                }
                else {
                    a1 = mid+1;
                }
            }
            else if (que < target) 
                a1 = mid+1;
            else
                b1 = mid-1;
        }
        printf("%d\n", ans);
    }
}