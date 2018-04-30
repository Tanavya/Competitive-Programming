#include <vector>
#include <stdio.h>
#include <queue>
#include <iostream>
#include <map>
#include <set>
#include <bitset>
#include <algorithm>
#include <cstring>

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << endl;
#define debug(x) cout << x << endl;
#define debug2(x,y) cout << x << " " << y << endl;
#define debug3(x,y,z) cout << x << " " << y << " " << z << endl;

typedef long long int ll;
typedef long double ld;
typedef unsigned long long int ull;
typedef std::pair <int, int> ii;
typedef std::vector <int> vi;
typedef std::vector <ll> vll;
typedef std::vector <ld> vld;

const int INF = 2147483647;
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
using namespace std;

const int maxn = (int) 2e5+10;
#define X maxn
#define Y maxn
struct node {
    ll val;
    node *left, *right;
    node() : val(0), left(nullptr), right(nullptr) {}
};
#define null new node()

node *BIT[maxn+10];

void update_DST(node *curr, int L, int R, int idx, ll val) {
    if (L == R) {
        curr->val += val;
    }
    else {
        int mid = (L+R)/2;
        if (!curr->left) curr->left = null;
        if (!curr->right) curr->right = null;
        if (idx <= mid)
            update_DST(curr->left, L, mid, idx, val);
        else
            update_DST(curr->right, mid+1, R, idx, val);
        curr->val = curr->left->val + curr->right->val;
    }
}

ll query_DST(node *curr, int L, int R, int li, int ri) {
    if (ri < L || li > R || !curr)
        return 0;
    if (li <= L && ri >= R)
        return curr->val;
    int mid = (L+R)/2;
    return query_DST(curr->left, L, mid, li, ri) + query_DST(curr->right, mid+1, R, li, ri);
}

void update(int i, int idx, ll val) {
    for (; i <= X; i += (i & -i)) {
        if (!BIT[i]) BIT[i] = null;
        update_DST(BIT[i], 1, Y, idx, val);
    }
}

ll query(int L, int R, int li, int ri) {
    ll sum = 0;
    for (int i = R; i >= 1; i -= (i & -i)) {
        sum += query_DST(BIT[i], 1, Y, li, ri);
    }
    for (int i = L-1; i >= 1; i -= (i & -i)) {
        sum -= query_DST(BIT[i], 1, Y, li, ri);
    }
    return sum;
}

int main() {
    int T;
    //scanf("%d", &T);
    T = 1;
    while (T--) {
        int N;
        scanf("%d", &N);
        for (int i = 0; i <= N+10; i++) {
            BIT[i] = null;
        }
        map <int, int> compress;
        vector<ii> P(N);
        for (int i = 0; i < N; i++) {
            scanf("%d %d", &P[i].fi, &P[i].se);
            compress[P[i].fi] = 0;
            compress[P[i].se] = 0;
        }
        int t = 0;
        for (auto it : compress) {
            compress[it.first] = ++t;
        }
        for (int i = 0; i < N; i++) {
            P[i].fi = compress[P[i].fi];
            P[i].se = compress[P[i].se];
        }
        for (int i = 0; i < N; i++) {
            update(P[i].fi, P[i].se, 1);
        }
        ll ans = 0;
        for (int i = 0; i < N; i++) {
            int x = P[i].fi, y = P[i].se;
            ll s1 = query(x, X, y, Y)-1;
            ll s2 = query(x, X, 1, y)-1;
            ll s3 = query(1, x, y, Y)-1;
            ll s4 = query(1, x, 1, y)-1;
            ans += s1 * s4;
            ans += s2 * s3;
        }
        map<int,ll> freq;
        for (int i = 0; i < N; i++) freq[P[i].fi]++;
        for (auto it: freq) {
            long long cnt = it.second;
            ans -= (cnt * (cnt - 1) * (cnt - 2)) / 6;
        }
        freq.clear();
        for (int i = 0; i < N; i++) freq[P[i].se]++;
        for (auto it: freq) {
            long long cnt = it.second;
            ans -= (cnt * (cnt - 1) * (cnt - 2)) / 6;
        }
        printf("%lld\n", ans * 2);
    }
}
/*
3
0 0
1 1
2 2

3
0 0
1 2
2 1
 */