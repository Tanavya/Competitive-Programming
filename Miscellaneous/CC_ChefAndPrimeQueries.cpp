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
#include <cstring>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip> //cout << setprecision(node) << fixed << num
 
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << endl;
#define debug(x) cout << x << endl;
#define debug2(x,y) cout << x << " " << y << endl;
typedef long long int ll;
typedef long double ld;
typedef std::pair <int, int> ii;
typedef std::vector <int> vi;
typedef std::vector <ll> vll;
const int INF = int(1e9);
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
using namespace std;
 
const int nmax = 1e5+7, aimax = 1e6+7, vmax = 3e6+7;
int A[nmax], N, lpf[aimax], primeN, version_map[aimax], prime_map[aimax];
bitset <aimax> sieve;
unordered_map<int, int> pre[nmax];
vi primes;

//Persistent Segtree
struct node {
    int val;
    node *left, *right;
    node() {}
    node(int v, node *l, node *r) {
        val = v, left = l, right = r;
    }
};
#define null new node(0, NULL, NULL);
node *version[vmax];
 
void update(node *prev, node *cur, int L, int R, int idx, int value) {
    if (L == R) {
        cur->val = prev->val + value;
    }
    else {
        int mid = (L+R)/2;
        if (idx <= mid) {
            cur->right = prev->right;
            cur->left = null;
            update(prev->left, cur->left, L, mid, idx, value);
        }
        else {
            cur->left = prev->left;
            cur->right = null;
            update(prev->right, cur->right, mid+1, R, idx, value);
        }
        cur->val = cur->right->val + cur->left->val;
    }
}
 
void build(node *n, int L, int R) {
    if (L == R) {
        n->val = pre[1][primes[L]];
    }
    else {
        int mid = (L+R)/2;
        n->left = null;
        n->right = null;
        build(n->left, L, mid);
        build(n->right, mid+1, R);
        n->val = n->left->val + n->right->val;
    }
}
 
int query(node *n, int L, int R, int a, int b) {
    if (b < L || a > R)
        return 0;
    if (a <= L && b >= R)
        return n->val;
    int mid = (L+R)/2;
    return query(n->left, L, mid, a, b) + query(n->right, mid+1, R, a, b);
}
//Persistent SegTree

int f(int L, int R, int X, int Y) {
    auto lb = lower_bound(primes.begin(), primes.end(), X);
    auto ub = prev(upper_bound(primes.begin(), primes.end(), Y));
    if (lb == primes.end()) 
        return 0;
    else {
        int i = distance(primes.begin(), lb);
        int j = distance(primes.begin(), ub);
        int p1 = 0, p2 = 0;
        p1 = query(version[version_map[R]], 0, primeN-1, i, j);
        if (L > 1) p2 = query(version[version_map[L-1]], 0, primeN-1, i, j);
        return p1 - p2;
    }
}
 
void precompute() {
    int cnt = 0;
    sieve[1] = true;
    for (int i = 2; i <= aimax; i+=2) {
        if (!sieve[i]) {
            lpf[i] = i;
            for (int j = i+i; j <= aimax; j += i) {
                sieve[j] = true;
                lpf[j] = i;
            }
            primes.pb(i);
            prime_map[i] = cnt;
            cnt++;
        }
        if (i == 2) i = 1;
    }
}
int main() {
    precompute();
    primeN = primes.size();
 
    int Q, L, R, X, Y;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &A[i]);
    }
    node *root = null;
    version[0] = root;
    //cout << nmax * log2(aimax) * log2(primeN) << endl; Max complexity of creating the Segment Trees
    int v = 0;
    for (int i = 1; i <= N; i++) {
        int num = A[i];
        set <int> factors;
        while (num > 1) {
            int factor = lpf[num];
            pre[i][factor]++;
            factors.insert(factor);
            num /= factor;
            assert(factor < aimax);
        }
        if (i == 1) {
            build(version[0], 0, primeN-1);
            v++;
        }
        else {
            for (int factor : factors) {
                version[v] = null;
                update(version[v-1], version[v], 0, primeN-1, prime_map[factor], pre[i][factor]);
                v++;
            }
            version_map[i] = v-1;
        }
    }
    scanf("%d", &Q);
    for (int q = 0; q < Q; q++) {
        scanf("%d %d %d %d", &L, &R, &X, &Y);
        printf("%d\n", f(L, R, X, Y));
    }
} 