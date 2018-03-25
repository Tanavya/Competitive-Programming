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

const int INF = 2147483647;
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
using namespace std;

const int maxn = 1000007;
int A[maxn], B[maxn];

/*
struct node {
    ll sum = 0, cnt = 0;
    int max = 0, second = 0, lazy = INF;
    node() {
        sum = 0, cnt = 0, max = 0, second = 0, lazy = INF;
    }
};
node T[4*maxn];*/
ll sum[4*maxn], cnt[4*maxn];
int max1[4*maxn], max2[4*maxn], lazy[4*maxn];

inline int left(int x) { return (x << 1); }
inline int right(int x) { return (x << 1) + 1; }

inline bool break_condition(int i, int L, int R, int li, int ri, int x) {
    return (ri < L || li > R || x >= max1[i]);
}
inline bool tag_condition(int i, int L, int R, int li, int ri, int x) {
    return (li <= L && ri >= R && max2[i] < x && x < max1[i]);
}

inline void propagate(int i, int L, int R, int x) {
    lazy[i] = x = min(x, lazy[i]);
    if (max1[i] <= x) return;
    sum[i] -= cnt[i] * ll(max1[i] - x);
    max1[i] = x;
    if (L != R) {
        lazy[left(i)] = min(lazy[left(i)], lazy[i]);
        lazy[right(i)] = min(lazy[right(i)], lazy[i]);
    }
    lazy[i] = INF;
}

inline void merge(int i) {
    max1[i] = max(max1[left(i)], max1[right(i)]);
    if (max1[left(i)] == max1[right(i)]) {
        max2[i] = max(max2[left(i)], max2[right(i)]);
        cnt[i] = cnt[left(i)] + cnt[right(i)];
    }
    else if (max1[left(i)] > max1[right(i)]) {
        max2[i] = max(max2[left(i)], max1[right(i)]);
        cnt[i] = cnt[left(i)];
    }
    else {
        max2[i] = max(max2[right(i)], max1[left(i)]);
        cnt[i] = cnt[right(i)];
    }
    sum[i] = sum[left(i)] + sum[right(i)];
}

void build(int i, int L, int R) {
    sum[i] = 0, cnt[i] = 0, max1[i] = 0, max2[i] = 0, lazy[i] = INF;
    if (L == R) {
        cnt[i] = 1;
        max1[i] = A[L];
        sum[i] = A[L];
    }
    else {
        int mid = (L+R)/2;
        build(left(i), L, mid);
        build(right(i), mid+1, R);
        merge(i);
    }
}

void update(int i, int L, int R, int li, int ri, int x) {
    if (lazy[i] != INF)
        propagate(i, L, R, lazy[i]);
    if (ri < L || li > R || x >= max1[i])
        return;
    if (li <= L && ri >= R && max2[i] < x && x < max1[i]) {
        propagate(i, L, R, x);
        return;
    }
    int mid = (L+R)/2;
    update(left(i), L, mid, li, ri, x);
    update(right(i), mid+1, R, li, ri, x);
    merge(i);
}

ll query(int i, int L, int R, int li, int ri, int type) {
    if (lazy[i] != INF)
        propagate(i, L, R, lazy[i]);
    if (ri < L || li > R)
        return 0;
    if (li <= L && ri >= R)
        return (type == 0 ? max1[i]: sum[i]);
    int mid = (L+R)/2;
    if (type == 0)
        return max(query(left(i), L, mid, li, ri, type), query(right(i), mid+1, R, li, ri, type));
    else
        return query(left(i), L, mid, li, ri, type) + query(right(i), mid+1, R, li, ri, type);
}

int main() {
    int TC;
    scanf("%d", &TC);
    while (TC--) {
        int N, M;
        scanf("%d %d", &N, &M);
        for (int i = 1; i <= N; i++) {
            scanf("%d", &A[i]);
        }
        build(1, 1, N);
        while (M--) {
            int type, li, ri;
            scanf("%d %d %d", &type, &li, &ri);
            if (type == 0) {
                int x;
                scanf("%d", &x);
                update(1, 1, N, li, ri, x);
            }
            else if (type == 1) {
                printf("%lld\n", query(1, 1, N, li, ri, 0));
            }
            else {
                printf("%lld\n", query(1, 1, N, li, ri, 1));
            }
        }
    }
}