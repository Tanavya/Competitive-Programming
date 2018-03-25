#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <assert.h>

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

const int INF = (int)1e9;
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
using namespace std;

const int maxn = (int) 3e5+10, mod = (int) 1e9+7;
int tree[4*maxn], max_right[maxn], min_left[maxn], MAP[maxn], RMAP[maxn], A[maxn], N;
ll idx[maxn];
inline int left(int p) { return (p << 1); }
inline int right(int p) { return (p << 1) + 1; }

void build(int i, int L, int R) {
    if (L == R) {
        tree[i] = RMAP[L];
    }
    else {
        int mid = (L+R)/2;
        build(left(i), L, mid);
        build(right(i), mid+1, R);
        tree[i] = min(tree[left(i)], tree[right(i)]);
    }
}
int query(int i, int L, int R, int li, int ri) {
    if (ri < L || li > R)
        return INF;
    if (li <= L && ri >= R)
        return tree[i];
    int mid = (L+R)/2;
    return min(query(left(i), L, mid, li, ri), query(right(i), mid+1, R, li, ri));
}
void update(int i, int L, int R, int idx, int val) {
    if (L == R) {
        tree[i] = val;
    }
    else {
        int mid = (L+R)/2;
        if (idx <= mid)
            update(left(i), L, mid, idx, val);
        else
            update(right(i), mid+1, R, idx, val);
        tree[i] = min(tree[left(i)], tree[right(i)]);
    }
}

#define add(a, b) a = b; if (a > mod) a -= mod;
#define gc getchar_unlocked
inline void scanint(int &x) {
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}
inline void set_child(int nxt, int node, bool b) {
    if (nxt != INF) {
        add(idx[nxt], idx[node] * 2 + b);
        max_right[nxt] = max_right[node];
        min_left[nxt] = min_left[node];
        if (b) max_right[nxt] = max(max_right[nxt], MAP[node]);
        else min_left[nxt] = min(min_left[nxt], MAP[node]);
    }
}

int main() {
    scanint(N);
    vector <ii> data;
    for (int i = 1; i <= N; i++) {
        scanint(A[i]);
        data.pb(mp(A[i], i));
    }
    sort(all(data));
    for (int i = 0; i < N; i++) {
        MAP[data[i].se] = i+1;
        RMAP[i+1] = data[i].se;
    }
    build(1, 1, N);
    idx[1] = 1;
    for (int i = 1; i <= N; i++)
        min_left[i] = INF;
    for (int i = 1; i <= N; i++) {
        int j = MAP[i];
        update(1, 1, N, j, INF);
        int m1 = max_right[i], m2 = min_left[i], L, R;
        L = m1+1, R = min(m2, j)-1;
        set_child(query(1, 1, N, L, R), i, false);
        L = max(m1, j)+1, R = m2-1;
        set_child(query(1, 1, N, L, R), i, true);
    }
    for (int i = 1; i <= N; i++) {
        printf("%lld ", idx[i]);
    }
}
/*
3
4 2 7

 10
1 9 5 4 3 7 8 11 2 6
 */