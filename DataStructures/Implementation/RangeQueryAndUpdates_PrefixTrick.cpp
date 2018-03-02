//Range Update, Point Query

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

const int maxn = (int) 1e5;
int A[maxn], V[maxn], tree[4*maxn], N;

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

int get (int i, int L, int R, int li, int ri) {
    if (ri < L || li > R)
        return 0;
    if (li <= L && ri >= R)
        return tree[i];
    int mid = (L+R)/2;
    return get(left(i), L, mid, li, ri) + get(right(i), mid+1, R, li, ri);
}

void update(int i, int L, int R, int idx, int val) {
    if (L == R) {
        tree[i] += val;
        A[L] += val;
    }
    else {
        int mid = (L+R)/2;
        if (idx <= mid) update(left(i), L, mid, idx, val);
        else update(right(i), mid+1, R, idx, val);
        tree[i] = tree[left(i)] + tree[right(i)];
    }
}

int brute_check (int L, int R) {
    int ret = 0;
    for (int i = L; i <= R; i++) {
        ret += V[i];
    }
    return ret;
}
int main() {
    //scanf("%d", &N);
    N = 10; cout << N << endl;
    for (int i = 1; i <= N; i++) {
        //scanf("%d", &V[i]);
        V[i] = rand() % 20;
        A[i] = V[i] - V[i-1];
    }
    for (int i = 1; i <= N; i++) cout << V[i] << " "; cout << endl;
    build(1, 1, N);
    int Q;
    Q = 20; cout << Q << endl;
    //scanf("%d", &Q);
    while (Q--) {
        int type;
        //scanf("%d", &type);
        type = rand() % 2;
        if (type == 0) {
            //update
            int i, j, v;
            //scanf("%d %d %d", &i, &j, &v);
            i = (rand() % N); j = (rand() % N); i++; j++; if (i > j) swap(i, j); v = rand() % 20; debug3(i, j, v);
            update(1, 1, N, i, v);
            if (j+1 <= N) update(1, 1, N, j+1, -v);

            for (int x = i; x <= j; x++) {
                V[x] += v;
            }

        }
        else {
            int i, j;
            //i == j for point query
            //scanf("%d %d", &i, &j);
            i = j = (rand() % N) + 1; cout << i << " " << j << endl;
            assert(i == j);
            int mine = get(1, 1, N, 1, i);
            int ac = brute_check(i, j);
            cout << "MINE: " << mine << endl;
            cout << "AC  : " << ac << endl;
            assert(mine == ac);
        }
    }
}