#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <assert.h>
#include <set>
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

const int INF = 2147483647;
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
using namespace std;

const int maxn = (int) 2e5+10;

bitset <maxn> used;
int N, ans[maxn], B[maxn];
struct node {
    int min, cnt, lazy;
    node (int min = 0, int cnt = 0, int lazy = 0) : min(min), cnt(cnt), lazy(lazy) {}
};
node T[4*maxn];
struct operation {
    int type, x, y1, y2, i;
    //type 0: add border
    //type 1: remove border
    //type 2: query rect
    operation(int type, int x, int y1, int y2, int i) : type(type), x(x), y1(y1), y2(y2), i(i) {}
};

bool cmp(operation a, operation b) {
    return a.x < b.x;
}

inline int left (int x) { return (x << 1); }
inline int right(int x) { return (x << 1) + 1; }

inline void propagate(int i, int L, int R) {
    T[i].min += T[i].lazy;
    if (L != R) {
        T[left(i)].lazy += T[i].lazy;
        T[right(i)].lazy += T[i].lazy;
    }
    T[i].lazy = 0;
}

node merge(node l, node r) {
    node ret(0,0,0);
    ret.min = min(l.min, r.min);
    if (l.min < r.min)
        ret.cnt = l.cnt;
    else if (r.min < l.min)
        ret.cnt = r.cnt;
    else
        ret.cnt = l.cnt + r.cnt;
    return ret;
}
void build(int i, int L, int R) {
    if (L == R) {
        T[i].cnt = 1;
    }
    else {
        int mid = (L+R)/2;
        build(left(i), L, mid);
        build(right(i), mid+1, R);
        T[i].cnt = T[left(i)].cnt + T[right(i)].cnt;
    }
}
void update(int i, int L, int R, int li, int ri, int val) {
    if (T[i].lazy)
        propagate(i, L, R);
    if (ri < L || li > R)
        return;
    if (li <= L && ri >= R) {
        T[i].lazy = val;
        propagate(i, L, R);
        return;
    }
    int mid = (L+R)/2;
    update(left(i), L, mid, li, ri, val);
    update(right(i), mid+1, R, li, ri, val);
    T[i] = merge(T[left(i)], T[right(i)]);
}

node query(int i, int L, int R, int li, int ri) {
    if (T[i].lazy)
        propagate(i, L, R);
    if (ri < L || li > R)
        return node(INF, 0, 0);
    if (li <= L && ri >= R)
        return T[i];
    int mid = (L+R)/2;
    return merge(query(left(i), L, mid, li, ri), query(right(i), mid+1, R, li, ri));
}

int main() {
    int U, Q, x1, y1, x2, y2;
    scanf("%d %d %d", &N, &U, &Q);
    vector <operation> queries;
    for (int i = 1; i <= U; i++) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        assert(!used[x1] && !used[x2]);
        used[x1] = used[x2] = true;
        queries.pb(operation(0, x1, y1, y2, -1));
        queries.pb(operation(1, x2, y1, y2, -1));
    }
    for (int i = 1; i <= Q; i++) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        assert(!used[x1] &&   !used[x2]);
        used[x1] = used[x2] = true;
        queries.pb(operation(2, x1, y1, y2, i));
    }
    sort(all(queries), cmp);
    build(1, 1, N);
    for (operation op : queries) {
        if (op.type == 0) {
            update(1, 1, N, op.y1, op.y2, 1);
        }
        else if (op.type == 1) {
            update(1, 1, N, op.y1, op.y2, -1);
        }
        else {
            node n = query(1, 1, N, op.y1, op.y2);
            if (n.min == 0)
                ans[op.i] = op.y2 - op.y1 + 1 - n.cnt;
            else
                ans[op.i] = op.y2 - op.y1 + 1;
        }
    }
    for (int i = 1; i <= Q; i++) printf("%d\n", ans[i]);
}
/*
100 3 1
2 1 5 3
7 2 8 5
1 4 6 8
3 6 4 7
 */