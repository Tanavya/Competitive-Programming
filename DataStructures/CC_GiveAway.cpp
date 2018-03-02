//Stupid test data, A[i] could be 0. Costed me so many WAs :(
//Dynamic Segtree in BIT

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

const int maxn = (int)5e5+10, maxk = (int)1e9;
int A[maxn], N, B[maxn];

inline int left (int x) { return (x << 1); }
inline int right (int x) { return (x << 1) + 1; }

struct node {
    int val;
    node *left, *right;
    node(int val, node *left, node *right) : val(val), left(left), right(right) {}
};

node *BIT[maxn]; //Dynamic Segment Tree in each node of Segment Tree
#define null new node (0, NULL, NULL);

void build () {
    for (int i = 0; i < maxn; i++) {
        BIT[i] = null;
    }
}

void updateDST (node *curr, int L, int R, int idx, int val) {
    if (L == R) {
        //assert(idx == L);
        curr->val += val;
    }
    else {
        if (curr->left == nullptr)
            curr->left = null;
        if (curr->right == nullptr)
            curr->right = null;
        int mid = (L+R)/2;
        if (idx <= mid)
            updateDST(curr->left, L, mid, idx, val);
        else
            updateDST(curr->right, mid+1, R, idx, val);
        curr->val = curr->left->val + curr->right->val;
    }
    if (curr->val < 0) assert(false);
}

int queryDST (node *curr, int L, int R, int li, int ri) {
    if (curr == nullptr || ri < L || li > R)
        return 0;
    if (li <= L && ri >= R)
        return curr->val;
    int mid = (L+R)/2;
    return queryDST (curr->left, L, mid, li, ri) + queryDST (curr->right, mid+1, R, li, ri);
}

void update (int i, int n, int val) {
    for(; i <= N; i += i & -i) {
        updateDST(BIT[i], 0, maxk, n, val);
    }
}

int query (int L, int R, int k) {
    int ans = 0;
    for (int i = R; i > 0; i -= (i & -i)) {
        ans += queryDST (BIT[i], 0, maxk, k, maxk);
    }
    if (L == 1) return ans;
    for (int i = L-1; i > 0; i -= (i & -i)) {
        ans -= queryDST (BIT[i], 0, maxk, k, maxk);
    }
    return ans;
}

void brute_update (int i, int x) {
    B[i] = x;
}
int brute_check (int L, int R, int k) {
    int cnt = 0;
    for (int i = L; i <= R; i++) {
        if (B[i] >= k)
            cnt++;
    }
    return cnt;
}

int main() {
    scanf("%d", &N);
    assert(N < maxn);
    build();
    for (int i = 1; i <= N; i++) {
        scanf("%d", &A[i]);
        assert(A[i] <= maxk);
        assert(A[i] >= 0);
        //if (A[i] < 1) A[i] = 0;
        update(i, A[i], 1);
    }
    int Q;
    scanf("%d", &Q);
    while (Q--) {
        int type;
        scanf("%d", &type);
        if (type == 0) {
            int l, r, k;
            scanf("%d %d %d", &l, &r, &k);
            assert(l <= N);
            assert(r <= N);
            assert(k <= maxk);
            assert(k >= 1);
            printf("%d\n", query(l, r, k));
        }
        else {
            int i, k;
            scanf("%d %d", &i, &k);
            assert(i <= N);
            assert(k >= 1);
            assert(k <= maxk);
            update(i, A[i], -1);
            A[i] = k;
            update(i, k, 1);
        }
    }
}


//merge sort tree + policy based DS -> AC

/*
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
const int maxn = (int)5e5, maxk = (int)1e9+1;
int A[maxn], N, B[maxn];

#include <ext/pb_ds/assoc_container.hpp>
typedef __gnu_pbds::tree<ii, __gnu_pbds::null_type, less<ii>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;


inline int left (int x) { return (x << 1); }
inline int right (int x) { return (x << 1) + 1; }

ordered_set BIT[maxn];

int t = 1;
inline void updateSet(ordered_set &S, int idx, int val) {
    if (val > 0) S.insert(mp(idx, t++));
    else S.erase(S.lower_bound(mp(idx, 0)));
}

inline int querySet (ordered_set &S, int k) {
    return S.size() - S.order_of_key(mp(k, 0));
}

void update (int i, int n, int val) {
    for(; i <= N; i += i & -i) {
        updateSet(BIT[i], n, val);
    }
}

int query (int L, int R, int k) {
    int ans = 0;
    for (int i = R; i > 0; i -= (i & -i)) {
        ans += querySet (BIT[i], k);
    }
    for (int i = L-1; i > 0; i -= (i & -i)) {
        ans -= querySet (BIT[i], k);
    }
    return ans;
}

void brute_update (int i, int x) {
    B[i] = x;
}
int brute_check (int L, int R, int k) {
    int cnt = 0;
    for (int i = L; i <= R; i++) {
        if (B[i] > k)
            cnt++;
    }
    return cnt;
}

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &A[i]);
        update(i, A[i], 1);
    }
    int Q;
    scanf("%d", &Q);
    while (Q--) {
        int type;
        scanf("%d", &type);
        if (type == 0) {
            int l, r, k;
            scanf("%d %d %d", &l, &r, &k);
            printf("%d\n", query(l, r, k));
        }
        else {
            int i, k;
            scanf("%d %d", &i, &k);
            update(i, A[i], -1);
            A[i] = k;
            update(i, k, 1);
        }
    }
}
*/

//dynamic segment tree + merge sort tree
/*
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

const int maxn = (int)5e5, maxk = (int)1e9+1;
int A[maxn], N, B[maxn];

inline int left (int x) { return (x << 1); }
inline int right (int x) { return (x << 1) + 1; }

struct node {
    int val;
    node *left, *right;
    node(int val, node *left, node *right) : val(val), left(left), right(right) {}
};

node *tree[4*maxn]; //Dynamic Segment Tree in each node of Segment Tree
#define null new node (0, NULL, NULL);

void build (int i, int L, int R) {
    tree[i] = null;
    if (L != R) {
        int mid = (L+R)/2;
        build (left(i), L, mid);
        build(right(i), mid+1, R);
    }
}

void updateDST (node *curr, int L, int R, int idx, int val) {
    if (L == R) {
        curr->val += val;
    }
    else {
        if (curr->left == nullptr)
            curr->left = null;
        if (curr->right == nullptr)
            curr->right = null;
        int mid = (L+R)/2;
        if (idx <= mid)
            updateDST(curr->left, L, mid, idx, val);
        else
            updateDST(curr->right, mid+1, R, idx, val);
        curr->val = curr->left->val + curr->right->val;
    }
}

void update (int i, int L, int R, int idx, int n, int val) {
    updateDST(tree[i], 1, maxk, n, val);
    if (L != R) {
        int mid = (L+R)/2;
        if (idx <= mid)
            update(left(i), L, mid, idx, n, val);
        else
            update(right(i), mid+1, R, idx, n, val);
    }
}

int queryDST (node *curr, int L, int R, int li, int ri) {
    if (curr == nullptr || ri < L || li > R)
        return 0;
    if (li <= L && ri >= R)
        return curr->val;
    int mid = (L+R)/2;
    return queryDST (curr->left, L, mid, li, ri) + queryDST (curr->right, mid+1, R, li, ri);
}

int query (int i, int L, int R, int li, int ri, int lii, int rii) {
    if (ri < L || li > R)
        return 0;
    if (li <= L && ri >= R)
        return queryDST (tree[i], 1, maxk, lii, rii);
    int mid = (L+R)/2;
    return query (left(i), L, mid, li, ri, lii, rii) + query (right(i), mid+1, R, li, ri, lii, rii);
}

void brute_update (int i, int x) {
    B[i] = x;
}
int brute_check (int L, int R, int k) {
    int cnt = 0;
    for (int i = L; i <= R; i++) {
        if (B[i] > k)
            cnt++;
    }
    return cnt;
}

int main() {
    scanf("%d", &N);
    build(1, 1, N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &A[i]);
        update(1, 1, N, i, A[i], 1);
    }
    int Q;
    scanf("%d", &Q);
    while (Q--) {
        int type;
        scanf("%d", &type);
        if (type == 0) {
            int l, r, k;
            scanf("%d %d %d", &l, &r, &k);
            printf("%d\n", query(1, 1, N, l, r, k, maxk));
        }
        else {
            int i, k;
            scanf("%d %d", &i, &k);
            update(1, 1, N, i, A[i], -1);
            A[i] = k;
            update(1, 1, N, i, k, 1);
        }
    }
}*/

//persistent segment tree + sqrt decomposition
/*
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

const int maxn = (int)5e5+10;
int A[maxn], upd[maxn], N;

struct node {
    int val;
    int left, right;
    node() : val(0), left(0), right(0) {}
    node(int val) : val(val), left(0), right(0) {}
    node(int val, int l, int r) : val(val), left(l), right(r) {}
};

bool cmp (ii a, ii b) {
    return a.fi < b.fi;
}
node stree[35*maxn];
int root[maxn], nodeCnt = 0;

void update(int old, int &curr, int L, int R, int idx, int val) {
    curr = ++nodeCnt;
    stree[curr] = stree[old];
    if (L == R) {
        assert(idx == L);
        stree[curr].val += val;
    }
    else {
        int mid = (L+R)/2;
        if (idx <= mid) {
            update(stree[old].left, stree[curr].left, L, mid, idx, val);
        }
        else {
            update(stree[old].right, stree[curr].right, mid+1, R, idx, val);
        }
        stree[curr].val = stree[stree[curr].left].val + stree[stree[curr].right].val;
    }
}

int query (int curr, int L, int R, int li, int ri) {
    if (curr == 0 || ri < L || li > R)
        return 0;
    if (li <= L && ri >= R)
        return stree[curr].val;
    int mid = (L+R)/2;
    return query(stree[curr].left, L, mid, li, ri) + query(stree[curr].right, mid+1, R, li, ri);
}

//map <int, int> occ;
vector <ii> occ;
void build () {
    //cout << "building..\n";
    vector <ii> V;
    for (int i = 1; i <= N; i++) {
        V.pb(mp(A[i], i));
    }
    sort(all(V));
    occ.clear();
    memset(root, 0, sizeof(root));
    nodeCnt = 0;
    for (int i = 1; i <= N; i++) {
        ii e = V[i-1];
        occ.pb(mp(e.fi, i));
        update(root[i-1], root[i], 1, N, e.se, 1);
    }
    sort(all(occ), cmp);
}

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &A[i]);
    }
    int Q;
    scanf("%d", &Q);
    int block = (int)sqrt(Q);
    for (int i = 0; i < Q; i += block) {
        build();
        vector <pair <int, ii>> updates;
        memset(upd, 0, sizeof(upd));
        for (int j = i; j < i+block && j < Q; j++) {
            int type;
            scanf("%d", &type);
            if (type == 0) {
                int a, b, c;
                scanf("%d %d %d", &a, &b, &c);
                auto it = lower_bound(all(occ), mp(c, 0), cmp);
                int cnt = 0;
                if (it != occ.begin()) {
                    it = prev(it);
                    cnt = query(root[it->second], 1, N, a, b);
                }
                int ans = b-a+1-cnt;
                for (pair <int, ii> update : updates) {
                    int idx = update.fi;
                    int pre = A[idx];
                    int nw = update.se.fi;
                    if (upd[idx] != update.se.se) continue;
                    if (a <= idx && idx <= b) {
                        if (nw >= c && pre < c)
                            ans++;
                        if (nw < c && pre >= c)
                            ans--;
                    }
                }
                printf("%d\n", ans);
            }
            else {
                int a, b;
                scanf("%d %d", &a, &b);
                updates.pb(mp(a, mp(b, j)));
                upd[a] = j;
            }
        }
        for (pair <int, ii> update : updates) {
            A[update.fi] = update.se.fi;
        }
    }
}*/

//With policy based data structures in segment tree
/*
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
const int maxn = (int)5e5, maxk = (int)1e9+1;
int A[maxn], N, B[maxn];

#include <ext/pb_ds/assoc_container.hpp>
typedef __gnu_pbds::tree<ii, __gnu_pbds::null_type, less<ii>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;


inline int left (int x) { return (x << 1); }
inline int right (int x) { return (x << 1) + 1; }

ordered_set tree[4*maxn];

void build (int i, int L, int R) {
    tree[i] = ordered_set();
    if (L != R) {
        int mid = (L+R)/2;
        build (left(i), L, mid);
        build(right(i), mid+1, R);
    }
}
int t = 1;
void updateSet(ordered_set &S, int idx, int val) {
    if (val > 0) S.insert(mp(idx, t++));
    else S.erase(S.lower_bound(mp(idx, 0)));
}

int querySet (ordered_set &S, int k) {
    return S.size() - S.order_of_key(mp(k, 0));
}

void update (int i, int L, int R, int idx, int n, int val) {
    updateSet(tree[i], n, val);
    if (L != R) {
        int mid = (L+R)/2;
        if (idx <= mid)
            update(left(i), L, mid, idx, n, val);
        else
            update(right(i), mid+1, R, idx, n, val);
    }
}


int query (int i, int L, int R, int li, int ri, int k) {
    if (ri < L || li > R)
        return 0;
    if (li <= L && ri >= R)
        return querySet (tree[i], k);
    int mid = (L+R)/2;
    return query (left(i), L, mid, li, ri, k) + query (right(i), mid+1, R, li, ri, k);
}

void brute_update (int i, int x) {
    B[i] = x;
}
int brute_check (int L, int R, int k) {
    int cnt = 0;
    for (int i = L; i <= R; i++) {
        if (B[i] > k)
            cnt++;
    }
    return cnt;
}

int main() {
    scanf("%d", &N);
    build(1, 1, N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &A[i]);
        update(1, 1, N, i, A[i], 1);
    }
    int Q;
    scanf("%d", &Q);
    while (Q--) {
        int type;
        scanf("%d", &type);
        if (type == 0) {
            int l, r, k;
            scanf("%d %d %d", &l, &r, &k);
            printf("%d\n", query(1, 1, N, l, r, k));
        }
        else {
            int i, k;
            scanf("%d %d", &i, &k);
            update(1, 1, N, i, A[i], -1);
            A[i] = k;
            update(1, 1, N, i, k, 1);
        }
    }
}

 //with dynamic segment tree, without pointers + sqrt decomp
/*
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

const int maxn = (int)5e5+10;
int A[maxn], upd[maxn], N;

struct node {
    int val;
    int left, right;
    node() : val(0), left(0), right(0) {}
    node(int val) : val(val), left(0), right(0) {}
    node(int val, int l, int r) : val(val), left(l), right(r) {}
};

bool cmp (ii a, ii b) {
    return a.fi < b.fi;
}
node stree[35*maxn];
int root[maxn], nodeCnt = 0;

void update(int old, int &curr, int L, int R, int idx, int val) {
    curr = ++nodeCnt;
    stree[curr] = stree[old];
    if (L == R) {
        assert(idx == L);
        stree[curr].val += val;
    }
    else {
        int mid = (L+R)/2;
        if (idx <= mid) {
            update(stree[old].left, stree[curr].left, L, mid, idx, val);
        }
        else {
            update(stree[old].right, stree[curr].right, mid+1, R, idx, val);
        }
        stree[curr].val = stree[stree[curr].left].val + stree[stree[curr].right].val;
    }
}

int query (int curr, int L, int R, int li, int ri) {
    if (curr == 0 || ri < L || li > R)
        return 0;
    if (li <= L && ri >= R)
        return stree[curr].val;
    int mid = (L+R)/2;
    return query(stree[curr].left, L, mid, li, ri) + query(stree[curr].right, mid+1, R, li, ri);
}

//map <int, int> occ;
vector <ii> occ;
void build () {
    //cout << "building..\n";
    vector <ii> V;
    for (int i = 1; i <= N; i++) {
        V.pb(mp(A[i], i));
    }
    sort(all(V));
    occ.clear();
    memset(root, 0, sizeof(root));
    nodeCnt = 0;
    for (int i = 1; i <= N; i++) {
        ii e = V[i-1];
        occ.pb(mp(e.fi, i));
        update(root[i-1], root[i], 1, N, e.se, 1);
    }
    sort(all(occ), cmp);
}

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &A[i]);
    }
    int Q;
    scanf("%d", &Q);
    int block = (int)sqrt(Q);
    for (int i = 0; i < Q; i += block) {
        build();
        vector <pair <int, ii>> updates;
        memset(upd, 0, sizeof(upd));
        for (int j = i; j < i+block && j < Q; j++) {
            int type;
            scanf("%d", &type);
            if (type == 0) {
                int a, b, c;
                scanf("%d %d %d", &a, &b, &c);
                auto it = lower_bound(all(occ), mp(c, 0), cmp);
                int cnt = 0;
                if (it != occ.begin()) {
                    it = prev(it);
                    cnt = query(root[it->second], 1, N, a, b);
                }
                int ans = b-a+1-cnt;
                for (pair <int, ii> update : updates) {
                    int idx = update.fi;
                    int pre = A[idx];
                    int nw = update.se.fi;
                    if (upd[idx] != update.se.se) continue;
                    if (a <= idx && idx <= b) {
                        if (nw >= c && pre < c)
                            ans++;
                        if (nw < c && pre >= c)
                            ans--;
                    }
                }
                printf("%d\n", ans);
            }
            else {
                int a, b;
                scanf("%d %d", &a, &b);
                updates.pb(mp(a, mp(b, j)));
                upd[a] = j;
            }
        }
        for (pair <int, ii> update : updates) {
            A[update.fi] = update.se.fi;
        }
    }
}*/