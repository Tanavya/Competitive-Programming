//Got WA
//Solution: https://discuss.codechef.com/questions/100120/captciti-editorial
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <stdio.h>
#include <queue>
#include <set>
#include <list>
#include <cstring>
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

ll f(int, bool);
ll g(int, int);

vector <vi> tree;
vi C, first_child, sib, deg, parent;
vll P;
const int nmax = 5e4 + 7;
ll dp1[nmax][2];
vector <vector<ll>> dp2;
int N;

ll g(int node, int rem) {
    if (node < 0) return 0;
    if (rem < 0) assert(false);
    ll &val = dp2[parent[node]][rem];
    if (val != -1)
        return val;

    if (sib[node] == -1) {
        if (rem > 1)
            val = INF;
        else if (rem == 1)
            val = f(node, true);
        else 
            val = f(node, false);
    }
    else {
        if (rem == 0) val = g(sib[node], rem) + f(node, false);
        else val = min(g(sib[node], rem-1) + f(node, true), g(sib[node], rem) + f(node, false));
    }
    
    //printf("g(%d, %d) = %d\n", node, rem, val);
    return val;
}
int root;
ll f(int node, bool mark) {
    ll &val = dp1[node][mark];
    if (val != -1)
        return val;
    //int k = C[node] - parent_marked;
    int k = C[node];
    if (node != root) k--;
    if (mark) {
        val = g(first_child[node], 0) + P[node];
    }
    else {
        val = g(first_child[node], k);
    }
    //printf("f(%d, %d) = %d\n", node, mark, val);
    return val;
}

void dfs(int node, int papa) {
    if (node <= 0) return;
    //cout << C[papa] << endl;
    //dp2[node].assign(C[papa]+7, -1);
    parent[node] = papa;
    assert(papa >= 0);
    int p = -1;
    for (int adj : tree[node]) {
        if (adj != papa) {
            deg[node]++;
            sib[adj] = p;
            p = adj;
            dfs(adj, node);
        }
    }
    first_child[node] = p;
}
int main() {

    int T, u, v;
    scanf("%d", &T);
    while (T--) {

        scanf("%d", &N);

        memset(dp1,-1,sizeof(dp1));
        dp2.resize(N+7);
        tree.assign(N+7, {});
        P.assign(N+7, 0);
        C.assign(N+7, 0);
        sib.assign(N+7, 0);
        deg.assign(N+7, 0);
        parent.assign(N+7, 0);

        first_child.assign(N, -1);

        for (int i = 0; i < N-1; i++) {
            scanf("%d %d", &u, &v);
            tree[u].pb(v);
            tree[v].pb(u);
        }
        for (int i = 1; i <= N; i++) {
            scanf("%lld", &P[i]);
        }
        root = 5;
        dfs(root, 0);
        for (int i = 1; i <= N; i++) {
            scanf("%d", &C[i]);
            dp2[i].assign(C[i]+1, -1);
        }
        
        cout << min(f(root, true), f(root, false)) << endl;
    }
}