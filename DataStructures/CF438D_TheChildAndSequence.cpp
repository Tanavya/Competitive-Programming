#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <assert.h>
#include <bitset>

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

const int INF = INT_MAX;
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
using namespace std;

const int maxn = (int)1e6+10;
ll A[maxn], B[maxn];
struct node {
    ll sum = 0, cnt = 0, max = 0, min = INF, upd = -1;
    node() {
        sum = 0, cnt = 0, max = 0, min = INF, upd = -1;
    }
};
node T[4*maxn];

inline int left(int x) { return (x << 1); }
inline int right(int x) { return (x << 1) + 1; }

inline bool break_condition(int i, int L, int R, int li, int ri, ll x) {
    return (ri < L || li > R || T[i].max < x);
}
inline bool tag_condition(int i, int L, int R, int li, int ri, ll x) {
    return (li <= L && ri >= R && T[i].min == T[i].max);
}

void merge(int i, int L, int R) {
    int l_child = left(i), r_child = right(i);
    T[i].max = max(T[l_child].max, T[r_child].max);
    T[i].min = min(T[l_child].min, T[r_child].min);
    T[i].cnt = T[l_child].cnt + T[r_child].cnt;
    T[i].sum = T[l_child].sum + T[r_child].sum;
}

void puttag(int i, int L, int R, ll x) {
    T[i].sum = ll(R-L+1) * ll(x);
    T[i].min = T[i].max = x;
}

void build(int i, int L, int R) {
    T[i] = node();
    if (L == R) {
        T[i].sum = T[i].max = T[i].min = A[L];
        T[i].cnt = 1;
    }
    else {
        int mid = (L+R)/2;
        build(left(i), L, mid);
        build(right(i), mid+1, R);
        merge(i, L, R);
    }
}

void pushdown(int i) {
    int l_child = left(i), r_child = right(i);
    if (T[i].upd != -1) {
        T[l_child].sum = T[i].upd * T[l_child].cnt;
        T[r_child].sum = T[i].upd * T[r_child].cnt;
        T[l_child].min = T[l_child].max = T[l_child].upd = T[i].upd;
        T[r_child].min = T[r_child].max = T[r_child].upd = T[i].upd;
        T[i].upd = -1;
    }
}

void modUpdate(int i, int L, int R, int li, int ri, ll x) {
    if (break_condition(i, L, R, li, ri, x))
        return;
    if (tag_condition(i, L, R, li, ri, x)) {
        T[i].upd = T[i].min % x;
        puttag(i, L, R, T[i].min % x);
        pushdown(i);
        return;
    }
    pushdown(i);
    int mid = (L + R) / 2;
    modUpdate(left(i), L, mid, li, ri, x);
    modUpdate(right(i), mid + 1, R, li, ri, x);
    merge(i, L, R);
}

void setUpdate(int i, int L, int R, int idx, ll x) {
    if (L == R) {
        T[i].upd = x;
        puttag(i, L, R, x);
        pushdown(i);
        T[i].upd = -1;
    }
    else {
        pushdown(i);
        int mid = (L+R)/2;
        if (idx <= mid)
            setUpdate(left(i), L, mid, idx, x);
        else
            setUpdate(right(i), mid+1, R, idx, x);
        merge(i, L, R);
    }
}

ll query(int i, int L, int R, int li, int ri) {
    if (ri < L || li > R)
        return 0;
    if (li <= L && ri >= R)
        return T[i].sum;
    pushdown(i);
    int mid = (L+R)/2;
    return query(left(i), L, mid, li, ri) + query(right(i), mid+1, R, li, ri);
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++) {
        scanf("%lld", &A[i]);
        B[i] = A[i];
    }
    build(1, 1, N);
    while (M--) {
        int type;
        scanf("%d", &type);
        if (type == 1) {
            int L, R;
            scanf("%d %d", &L, &R);
            printf("%lld\n", query(1, 1, N, L, R));
        }
        else if (type == 2) {
            int L, R, x;
            scanf("%d %d %d", &L, &R, &x);
            modUpdate(1, 1, N, L, R, x);
        }
        else {
            int k, x;
            scanf("%d %d", &k, &x);
            setUpdate(1, 1, N, k, x);
        }
    }
}