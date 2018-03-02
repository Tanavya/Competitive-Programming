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
#include <stack>
#include <sstream>


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

const int INF = int(1e9);
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
using namespace std;

const int maxn = (int) 1e5 + 10;
ll A[maxn], tree[4*maxn];

inline int left(int x) { return (x << 1); }
inline int right(int x) { return (x << 1) + 1; }

void build (int i, int L, int R) {
    if (L == R) {
        tree[i] = A[L];
    }
    else {
        int mid = (L+R)/2;
        build(left(i), L, mid);
        build(right(i), mid+1, R);
        tree[i] = tree[left(i)] + tree[right(i)];
    }
}

void update (int i, int L, int R, int idx, ll val) {
    if (L == R) {
        tree[i] = A[L] = val;
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

ll query (int i, int L, int R, int li, int ri) {
    if (ri < L || li > R)
        return 0;
    if (li <= L && ri >= R)
        return tree[i];
    int mid = (L+R)/2;
    return query(left(i), L, mid, li, ri) + query(right(i), mid+1, R, li, ri);
}

int main() {
    int N;
    int case_number = 1;
    while (scanf("%d", &N) != EOF) {
        memset(A, 0, sizeof(A));
        memset(tree, 0, sizeof(tree));
        set <int> S;
        for (int i = 1; i <= N; i++) {
            scanf("%lld", &A[i]);
            if (A[i] != 1)
                S.insert(i);
        }
        build(1, 1, N);
        int Q;
        scanf("%d", &Q);
        printf("Case #%d:\n", case_number++);
        while (Q--) {
            int type, x, y;
            scanf("%d %d %d", &type, &x, &y);
            if (x > y) swap(x, y);
            if (type == 0) {
                auto it = S.lower_bound(x);
                vi to_remove;
                while (*it <= y && it != S.end()) {
                    ll root = (ll)sqrt(A[*it]);
                    if (root == 1)
                        to_remove.pb(*it);
                    update(1, 1, N, *it, root);
                    it++;
                }
                for (int e : to_remove)
                    S.erase(e);
            }
            else {
                printf("%lld\n", query(1, 1, N, x, y));
            }
        }
        printf("\n");
    }
}