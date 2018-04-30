#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <assert.h>
#include <set>
#include <bitset>
#include <queue>

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

const int maxn = (int) 2e6+10, start = (int)1e6;
int A[maxn], tree[4*maxn];
bitset <maxn> used;

inline int left(int x) { return (x << 1); }
inline int right(int x) { return (x << 1) + 1; }

void update(int i, int L, int R, int idx, int val) {
    if (L == R) {
        tree[i] += val;
    }
    else {
        int mid = (L+R)/2;
        if (idx <= mid)
            update(left(i), L, mid, idx, val);
        else
            update(right(i), mid+1, R, idx, val);
        tree[i] = tree[left(i)] + tree[right(i)];
    }
}

int query(int i, int L, int R, int k) {
    if (L == R) {
        return L;
    }
    else {
        int mid = (L+R)/2;
        if (tree[left(i)] >= k)
            return query(left(i), L, mid, k);
        else
            return query(right(i), mid+1, R, k-tree[left(i)]);
    }
}

int main() {
    //freopen("inp.txt", "r", stdin);
    int N, M;
    scanf("%d %d", &N, &M);
    N += (start-1);
    for (int i = start; i <= N; i++) {
        update(1, 0, N, i, 1);
    }
    bool ok = true;
    int cnt = 0;
    for (int i = 0; i < M; i++) {
        int x, k;
        scanf("%d %d", &x, &k);
        cnt++;
        int pos = query(1, 0, N, k);
        update(1, 0, N, start-cnt, 1);
        update(1, 0, N, pos, -1);
        if (!A[pos]) A[pos] = x;
        else if (A[pos] != x) ok = false;
        if (pos >= start && used[x]) ok = false;
        used[x] = true;
    }
    int j = 1;
    if (ok) {
        for (int i = start; i <= N; i++) {
            if (!A[i]) {
                while (used[j]) j++;
                A[i] = j;
                used[j] = false;
                j++;
            }
            printf("%d ", A[i]);
        }
        printf("\n");
    }
    else {
        printf("-1\n");
    }
}
/*
3 2
1 2
1 1

3 3
1 3
2 3
1 3

 4 10 6 1 8 3 9 2 5 7

 */