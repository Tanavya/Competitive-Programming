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

const int maxn = (int) 2e6+10;
int T[maxn], N, M;
vi tree[4*maxn];
vll pref_tree[4*maxn];
ll pref[maxn];

inline int left(int x) { return (x << 1); }
inline int right(int x) { return (x << 1) + 1; }

void build(int i, int L, int R) {
    if (L == R) {
        tree[i] = {T[L]};
        pref_tree[i] = {T[L]};
    }
    else {
        int mid = (L+R)/2;
        build(left(i), L, mid);
        build(right(i), mid+1, R);
        merge(all(tree[left(i)]), all(tree[right(i)]), back_inserter(tree[i]));
        ll s = 0;
        for (int j = 0; j < tree[i].size(); j++) {
            s += tree[i][j];
            pref_tree[i].pb(s);
        }
    }
}

ll query(int i, int L, int R, int li, int ri, ll val) {
    if (ri < L || li > R)
        return 0;
    if (li <= L && ri >= R) {
        auto it = upper_bound(all(tree[i]), val);
        if (it == tree[i].begin())
            return 0;
        return -pref_tree[i][(int)distance(tree[i].begin(), it) - 1] + val * (ll) distance(tree[i].begin(), it);
    }
    int mid = (L+R)/2;
    return query(left(i), L, mid, li, ri, val) + query(right(i), mid+1, R, li, ri, val);
}
ll calc(int i, ll d) {
    return pref[i] - d * i + query(1, 1, M, 1, i, d);
}
int main() {

    scanf("%d %d", &N, &M);
    for (int i = 1; i <= M; i++) {
        scanf("%d", &T[i]);
        pref[i] = pref[i-1] + T[i];
    }
    build(1, 1, M);
    ll d;
    int r;
    for (int i = 0; i < N; i++) {
        scanf("%lld %d", &d, &r);
        int L = 1, R = M, ans = 0;
        while (L <= R) {
            int mid = (L+R)/2;
            if (calc(mid, d) < r) {
                L = mid+1;
            }
            else {
                R = mid-1;
                ans = mid;
            }
        }
        printf("%d ", ans);
    }
    cout << endl;
}