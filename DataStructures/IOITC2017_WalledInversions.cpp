#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <assert.h>
#include <map>
#include <iostream>
#include <set>

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << endl;
#define debug(x) cout << x << endl;
#define debug2(x,y) cout << x << " " << y << endl;
#define debug3(x,y,z) cout << x << " " << y << " " << z << endl;
#define debug4(a,b,c,d) cout << a << " " << b << " " << c << " " << d << endl;
#define debug5(a,b,c,d,e) cout << a << " " << b << " " << c << " " << d << " " << e << endl;
#define trace(x) cout << #x << ": " << x << endl;


typedef long long int ll;
typedef long double ld;
typedef unsigned long long int ull;
typedef std::pair <int, int> ii;
typedef std::vector <int> vi;
typedef std::vector <ll> vll;
typedef std::vector <ld> vld;

const int INF = int(1e9);
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
using namespace std;

const int maxn = (int) 1e5+10;
int N, A[maxn], RA[maxn];

struct node {
    int val;
    node *left, *right;
    node (int val, node *left, node *right) : val(val), left(left), right(right) {}
};
#define null new node(0, nullptr, nullptr)

node *root[maxn];

void build(node *curr, int L, int R) {
    if (L != R) {
        int mid = (L+R)/2;
        curr->left = null;
        curr->right = null;
        build(curr->left, L, mid);
        build(curr->right, mid+1, R);
    }
}

void update(node *prev, node *curr, int L, int R, int idx) {
    if (L == R) {
        curr->val = 1;
    }
    else {
        int mid = (L+R)/2;
        if (idx <= mid) {
            curr->right = prev->right;
            curr->left = null;
            update(prev->left, curr->left, L, mid, idx);
        }
        else {
            curr->left = prev->left;
            curr->right = null;
            update(prev->right, curr->right, mid+1, R, idx);
        }
        curr->val = curr->left->val + curr->right->val;
    }
}

int query(node *curr, int L, int R, int li, int ri) {
    if (!curr || ri < L || li > R)
        return 0;
    if (li <= L && ri >= R)
        return curr->val;
    int mid = (L+R)/2;
    return query(curr->left, L, mid, li, ri) + query(curr->right, mid+1, R, li, ri);
}

int query(int x, int L, int R) {
    return query(root[x-1], 1, N, L, R);
}

int main() {
    int Q;
    scanf("%d %d", &N, &Q);
    vector <ii> srt;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &A[i]);
        srt.pb(mp(A[i], i));
    }
    sort(all(srt));

    root[0] = null;
    build(root[0], 1, N);

    for (int i = 1; i <= N; i++) {
        int idx = srt[i-1].se;
        A[idx] = i;
        RA[i] = A[idx];
        root[i] = null;
        update(root[i-1], root[i], 1, N, idx);
    }

    ll ans = 0;
    for (int i = 1; i <= N; i++) {
        ans += query(A[i], i+1, N);
    }
    set <int> walls;
    while (Q--) {
        int W;
        scanf("%d", &W);
        walls.insert(W);
        int prv = 0, nxt = N;
        auto it = walls.lower_bound(W);
        if (it != walls.begin()) prv = *prev(it);
        it = walls.upper_bound(W);
        if (it != walls.end()) nxt = *it;
        int l = W - prv, r = nxt - W;
        if (l < r) {
            for (int i = prv+1; i <= W; i++) {
                ans -= query(A[i], W+1, nxt);
            }
        }
        else {
            for (int i = W+1; i <= nxt; i++) {
                ans -= ((W-prv) - query(A[i], prv+1, W));
            }
        }
        printf("%lld\n", ans);
    }
}
/*
6 5
3 5 1 6 4 2
3
5
1
2
4

10 9
3 7 1 9 4 10 8 2 6 5
9
8
7
6
5
4
3
2
1
 */