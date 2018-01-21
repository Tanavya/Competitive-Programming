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

const int maxn = (int) 2e5 + 10;

const int max_blk = ceil(sqrt(maxn));
int tree[4*maxn], A[maxn], N, Q;

inline int left(int x) { return (x << 1); }
inline int right(int x) { return (x << 1) + 1; }

void build(int i, int L, int R) {
    if (L == R) {
        A[L] = tree[i] = 1;
    }
    else {
        int mid = (L+R)/2;
        build(left(i), L, mid);
        build(right(i), mid+1, R);
        tree[i] = tree[left(i)] + tree[right(i)];
    }
}

void update(int i, int L, int R, int idx, int val) {
    if (L == R) {
        assert(L == idx);
        A[L] = val;
        tree[i] = val;
    }
    else {
        int mid = (L+R)/2;
        if (idx <= mid) {
            update(left(i), L, mid, idx, val);
        }
        else {
            update(right(i), mid + 1, R, idx, val);
        }
        tree[i] = tree[left(i)] + tree[right(i)];
    }
}

int query (int i, int L, int R, int val) {
    //if (tree[i] > val) assert(false);
    if (L == R)
        return L;
    int mid = (L+R)/2;
    if (val <= tree[left(i)])
        return query(left(i), L, mid, val);
    else
        return query(right(i), mid+1, R, val - tree[left(i)]);
}


int main() {
    scanf("%d %d", &N, &Q);
    int block_size = int(sqrt(N));

    map <char, set <int>> M;
    string S;
    cin >> S;

    for (int i = 1; i <= N; i++) {
        M[S[i-1]].insert(i);
    }
    build(1, 1, N);

    int L, R;
    while (Q--) {
        scanf("%d %d", &L, &R);
        char c;
        cin >> c;
        vi to_erase;
        L = query(1, 1, N, L);
        R = query(1, 1, N, R);
        //debug2(L, R);
        for (auto it = M[c].lower_bound(L); it != M[c].end(); ++it) {
            if (*it > R)
                break;
            to_erase.pb(*it);
        }
        for (int x : to_erase) {
            M[c].erase(x);
            update(1, 1, N, x, 0);
        }

    }
    string ans;
    for (int i = 0; i < N; i++) {
        if (A[i+1]) ans += S[i];
    }
    cout << ans << endl;
}

/*
 50 6
RQQQQQQRRRRQQQQQRRQQRQRRRRRQRQQQRQQQRRRQQQQQRRQRRR
18 26 R
13 33 R
23 32 R
7 21 Q
18 21 R
14 20 R

 RQQQQQRRRRQQQQQQQQQQQRRR

 */