//Tutorial Link : http://codeforces.com/blog/entry/16221

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
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip> //cout << setprecision(node) << fixed << num

#define mp make_pair
#define pb push_back
#define x first
#define y second
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << "\n";

typedef long long int ll;
typedef long double ld;
typedef std::pair <int, int> ii;
typedef std::vector <int> vi;
typedef std::vector <ll> vll;
const int INF = int(1e9);
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

using namespace std;

vi euler = {INF}, height(1007), level = {INF}, occ(1007, INF), st(4007);
//vi euler, height, level, occ, st;
int A, B;
vector <vi> tree(1007);

inline int left(int x) { return (x << 1); }
inline int right(int x ) { return (x << 1) + 1; }
#define leftChild left(p),L,(L+R)/2
#define rightChild right(p),(L+R)/2+1,R

inline void reset(int N) {
    euler = {INF};
    height.assign(N, 0);
    level = {INF};
    occ.assign(N, INF);
    st.assign(9*N, 0);
}

void dfs(int v,int p = -1){
	euler.push_back(v);
	for(auto u : tree[v]) {
        if (p - u) {
            height[u] = height[v] + 1;
		    dfs(u,v);
            euler.push_back(v);
        }
    }
}
void build(int p, int L, int R) {
    if (L == R) {
        st[p] = L;
    }
    else {
        build(leftChild);
        build(rightChild);
        int l = st[left(p)], r = st[right(p)];
        st[p] = (level[l] < level[r]) ? l : r; 
    }
}
int query(int p, int L, int R) {
    if (B < L || A > R)
        return 0;
    if (A <= L && B >= R)
        return st[p];
    int l = query(leftChild), r = query(rightChild);
    return (level[l] < level[r]) ? l : r;
}
int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        int N, M, adj;
        scanf("%d", &N);
        reset(N+7);
        
        for (int i = 0; i < N; i++) {
            scanf("%d", &M);
            tree[i+1] = {};
            for (int j = 0; j < M; j++) {
                scanf("%d", &adj);
                tree[i+1].pb(adj);
            }
        }
        dfs(1);
        for (int i = 1; i < euler.size(); i++) {
            level.pb(height[euler[i]]);
            occ[euler[i]] = min(occ[euler[i]], i);
        }
        build(1, 1, 2*N-1);
        
        int Q, x, y;
        scanf("%d", &Q);
        printf("Case %d:\n", t);
        while (Q--) {
            scanf("%d %d", &x, &y);
            A = min(occ[x], occ[y]), B = max(occ[x], occ[y]);
            printf("%d\n", euler[query(1, 1, 2*N-1)]);
        }
    }
}
/*
9
1 2
1 3
2 4
2 5
3 6
3 7
5 8
5 9
*/