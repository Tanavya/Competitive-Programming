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
using namespace std;;;;


const int maxn = (int) 6e5+10;
vector <vi> tree(maxn);
vector <vector <ii>> stree(4*maxn);
int size[maxn], ST[maxn], ET[maxn];
vi euler;

inline int left(int x) { return x << 1; }
inline int right(int x) { return (x << 1) + 1; }

bool cmp (ii p1, ii p2) {
    return p1.first < p2.first;
}
void dfs(int node, int par) {
    size[node] = 1;
    euler.pb(node);
    ST[node] = (int)euler.size()-1;
    for (int adj : tree[node]) {
        if (adj != par) {
            dfs(adj, node);
            size[node] += size[adj];
        }
    }
    euler.pb(node);
    ET[node] = (int)euler.size()-1;
}
void build(int i, int L, int R) {
    if (L == R) {
        stree[i] = {{size[euler[L]], euler[L]}};
    }
    else {
        int mid = (L+R)/2;
        build(left(i), L, mid);
        build(right(i), mid+1, R);
        merge(stree[left(i)].begin(), stree[left(i)].end(), stree[right(i)].begin(), stree[right(i)].end(), back_inserter(stree[i]));
    }
}
ii query(int i, int L, int R, int li, int ri, int x) {
    if (ri < L || li > R)
        return {INF, 0};
    if (li <= L && ri >= R) {
        auto it = lower_bound(stree[i].begin(), stree[i].end(), ii(x, 0), cmp);
        //debug2(it->fi, it->se);
        if (it != stree[i].end()) return *it;
        else return {INF, 0};
    }

    int mid = (L+R)/2;
    ii p1 = query(left(i), L, mid, li, ri, x);
    ii p2 = query(right(i), mid+1, R, li, ri, x);
    return min(p1, p2);
}
int main() {
    int N, Q, x;
    scanf("%d %d", &N, &Q);
    for (int i = 2; i <= N; i++) {
        scanf("%d", &x);
        tree[x].pb(i);
        tree[i].pb(x);
    }
    size[0] = INF;
    euler = {0};
    dfs(1, -1);
    N = (int)euler.size()-1;
    build(1, 1, N);
    while (Q--) {
        scanf("%d", &x);
        cout << query(1, 1, N, ST[x], ET[x], (size[x]+1)/2).second << endl;
    }
}