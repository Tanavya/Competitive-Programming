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

const int maxn = 100007;
ll A[maxn];

inline int left(int x) { return (x << 1); }
inline int right(int x) { return (x << 1) + 1; }

struct node {
    ll val, s, lazys, lazy1, lazy2;
    node(): val(0), lazy1(0), s(0), lazys(0), lazy2(0) {}
    node (ll a, ll b, ll c, ll d, ll e): val(a), lazy1(b), lazy2(c), lazys(d), s(e) {}
};

node tree[4*maxn];

void propagate(int i, int L, int R, ll val1, ll val2, ll val3) {
    assert(!(val1 && val2));
    if (val1) {
        tree[i].s = val1 * (R-L+1);
        tree[i].val = (R-L+1) * val1 * val1;
        if (L != R) {
            for (int child = 2*i; child <= 2*i+1; child++) {
                tree[child].lazys = val3;
                tree[child].lazy1 = val1;
                tree[child].lazy2 = 0;
            }
        }
    }
    if (val2) {
        tree[i].val += 2*tree[i].s*val2 + val2*val2*(R-L+1);
        tree[i].s += val3 * (R-L+1);
        if (L != R) {
            for (int child = 2*i; child <= 2*i+1; child++) {
                tree[child].lazys += val3;
                tree[child].lazy1 = 0;
                tree[child].lazy2 += val2;
            }
        }
    }
}

void build(int i, int L, int R) {
    tree[i].lazy1 = tree[i].lazy2 = tree[i].lazys = 0;
    if (L == R) {
        tree[i].val = A[L] * A[L];
        tree[i].s = A[L];
    }
    else {
        build(left(i), L, (L+R)/2);
        build(right(i), (L+R)/2+1, R);
        tree[i].val = tree[left(i)].val + tree[right(i)].val;
        tree[i].s = tree[left(i)].s + tree[right(i)].s;
    }
}

void update(int i, int L, int R, int li, int ri, ll val1, ll val2) {
    if (tree[i].lazy1 || tree[i].lazy2 || tree[i].lazys) {
        propagate(i, L, R, tree[i].lazy1, tree[i].lazy2, tree[i].lazys);
        tree[i].lazy1 = tree[i].lazy2 = tree[i].lazys = 0;
    }
    if (ri < L || li > R)
        return;
    if (li <= L && ri >= R) {
        propagate(i, L, R, val1, val2, val2);
        return;
    }
    int mid = (L+R)/2;
    update(left(i), L, mid, li, ri, val1, val2);
    update(right(i), mid+1, R, li, ri, val1, val2);
    tree[i].val = tree[left(i)].val + tree[right(i)].val;
    tree[i].s = tree[left(i)].s + tree[right(i)].s;
}

ll query(int i, int L, int R, int li, int ri) {
    if (tree[i].lazy1 || tree[i].lazy2 || tree[i].lazys) {
        propagate(i, L, R, tree[i].lazy1, tree[i].lazy2, tree[i].lazys);
        tree[i].lazy1 = tree[i].lazy2 = tree[i].lazys = 0;
    }
    if (ri < L || li > R)
        return 0;
    if (li <= L && ri >= R)
        return tree[i].val;
    return query(left(i), L, (L+R)/2, li, ri) + query(right(i), (L+R)/2+1, R, li, ri);
}


int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        printf("Case %d:\n", t);
        int N, Q;
        //scanf("%d %d", &N, &Q);
        N = 5, Q = 100; debug2(N, Q);
        for (int i = 1; i <= N; i++) {
            //scanf("%lld", &A[i]);
            A[i] = (rand() % 20) + 1;
            if (rand() % 2) A[i] *= -1;
            cout << A[i] << " ";
        }
        cout << endl;
        build(1, 1, N);
        while (Q--) {
            int type;
            //scanf("%d", &type);
            for (int i = 1; i <= N; i++) cout << query(1, 1, N, i, i) << " "; cout << endl;
            for (int i = 1; i <= N; i++) cout << A[i] << " "; cout << endl;
            type = rand() % 3; cout << type << " ";
            if (type == 0) {
                int L, R;
                ll x;
                //scanf("%d %d %lld", &L, &R, &x);
                L = (rand() % N)+1; R = (rand() % 3)+1; if (L > R) swap(L, R); x = rand() % 20; x++; if (rand() % 2) x *= -1; debug3(L, R, x);
                debug3(L, R, x);
                update(1, 1, N, L, R, x, 0);
                for (int i = L; i <= R; i++) {
                    A[i] = x;
                }
            }
            else if (type == 1) {
                int L, R;
                ll x;
                //scanf("%d %d %lld", &L, &R, &x);
                L = (rand() % N)+1; R = (rand() % 3)+1; if (L > R) swap(L, R); x = rand() % 20; x++; if (rand() % 2) x *= -1; debug3(L, R, x);
                debug3(L, R, x);
                update(1, 1, N, L, R, 0, x);
                for (int i = L; i <= R; i++) {
                    A[i] += x;
                }
            }
            else {
                int L, R;
                //scanf("%d %d", &L, &R);
                L = (rand() % N)+1; R = (rand() % 3)+1; if (L > R) swap(L, R); debug2(L, R);
                debug2(L, R);
                ll ans = query(1, 1, N, L, R);
                ll ac = 0;
                for (int i = L; i <= R; i++) {
                    ac += A[i] * A[i];
                }
                cout << "MINE: " << ans << endl;
                cout << "AC  : " << ac << endl;
                assert(ans == ac);
                //printf("%lld\n", query(1, 1, N, L, R));
            }
        }
    }
}