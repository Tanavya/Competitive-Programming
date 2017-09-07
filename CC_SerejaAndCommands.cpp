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
 
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << endl;
#define debug(x) cout << x << endl;
#define debug2(x,y) cout << x << " " << y << endl;
typedef long long int ll;
typedef long double ld;
typedef unsigned long long int ull;
typedef std::pair <int, int> ii;
typedef std::vector <int> vi;
typedef std::vector <ll> vll;
const int INF = int(1e9);
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
using namespace std;


const int mod = (1e9)+7;
const int maxn = 1e5, maxm = 1e5;
ll treeA[4*maxn+7], treeC[4*maxn+7], lazyA[4*maxn+7], lazyC[4*maxn+7];
int N, M;
vector <pair<int, ii>> queries;

inline int left(int x) { return (x << 1); }
inline int right(int x) { return (x << 1) + 1; }

inline void propagate(ll *lazy, ll *tree, int i, int L, int R, int val) {
	tree[i] += (R - L + 1) * val;
	if (L != R) {
		//jaisa baap vaise bacche - lAZY
		lazy[left(i)] = (lazy[left(i)] + val) % mod;
		lazy[right(i)] = (lazy[right(i)] + val) % mod;
	}
}
void update(ll *lazy, ll *tree, int i, int L, int R, int li, int ri, int val) {
	if (lazy[i]) {
		propagate(lazy, tree, i, L, R, lazy[i]);
		lazy[i] = 0;
	}
	if (ri < L || li > R)
		return;
	if (L >= li && R <= ri) {
		propagate(lazy, tree, i, L, R, val);
		return;
	}
	int mid = (L+R)/2;
	update(lazy, tree, left(i), L, mid, li, ri, val);
	update(lazy, tree, right(i), mid+1, R, li, ri, val);
	tree[i] = ((tree[left(i)] * 1LL) + (tree[right(i)] * 1LL)) % mod;
}
ll query(ll *lazy, ll *tree, int i, int L, int R, int li, int ri) {
	if (lazy[i]) {
		propagate(lazy, tree, i, L, R, lazy[i]);
		lazy[i] = 0;
	}
	if (ri < L || li > R)
		return 0;
	if (L >= li && R <= ri)
		return tree[i];
	int mid = (L+R)/2;
	return ((query(lazy, tree, left(i), L, mid, li, ri) * 1LL) + query(lazy, tree, right(i), mid+1, R, li, ri)) % mod;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("inp.txt", "r", stdin);
	#endif
	int T;
	scanf("%d", &T);
	while (T--) {
		memset(treeA, 0, sizeof(treeA));
		memset(treeC, 0, sizeof(treeC));
		memset(lazyA, 0, sizeof(lazyA));
		memset(lazyC, 0, sizeof(lazyC));
		queries.clear();
		int t, l, r;
		scanf("%d %d", &N, &M);
		for (int i = 0; i < M; i++) {
			scanf("%d %d %d", &t, &l, &r);
			queries.pb(mp(t, mp(l, r)));
		}
		update(lazyC, treeC, 1, 1, M, 1, M, 1);
		for (int i = M-1; i >= 0; i--) {
			ll times = query(lazyC, treeC, 1, 1, M, i+1, i+1);
			assert(times);
			if (queries[i].x == 1) update(lazyA, treeA, 1, 1, N, queries[i].y.x, queries[i].y.y, times);
			else update(lazyC, treeC, 1, 1, M, queries[i].y.x, queries[i].y.y, times);
		}
		for (int i = 1; i <= N; i++) 
			printf("%lld ", query(lazyA, treeA, 1, 1, N, i, i));
		printf("\n");
	}
}