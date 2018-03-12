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

const int maxn = (int) 1e5+10;
int N, ST[maxn], EN[maxn], euler[maxn], size[maxn], cnt[maxn], cnt2[maxn], max_cnt, t = 0;
ll ans[maxn], C[maxn], S[maxn];
vi tree[maxn];

void dfs0(int node, int par) {
    ST[node] = ++t;
    euler[ST[node]] = node;
    size[node] = 1;
    for (int &adj : tree[node]) {
        if (adj != par) {
            dfs0(adj, node);
            size[node] += size[adj];
            if (par == tree[node][0] || size[adj] > size[tree[node][0]])
                swap(adj, tree[node][0]);
        }
    }
    EN[node] = t;
}


void add(int n) {
    S[cnt[C[n]]] -= C[n];
    cnt2[cnt[C[n]]]--;
    cnt[C[n]]++;
    cnt2[cnt[C[n]]]++;
    max_cnt = max(max_cnt, cnt[C[n]]);
    S[cnt[C[n]]] += C[n];
}

void remove(int n) {
    S[cnt[C[n]]] -= C[n];
    cnt2[cnt[C[n]]]--;
    if (cnt[C[n]] == max_cnt && cnt2[cnt[C[n]]] == 0)
        max_cnt--;
    cnt[C[n]]--;
    cnt2[cnt[C[n]]]++;
    S[cnt[C[n]]] += C[n];
}

void dfs(int node, int par, int keep) {
    for (int i = 1; i < tree[node].size(); i++) {
        if (tree[node][i] != par) {
            dfs(tree[node][i], node, 0);
        }
    }
    if (tree[node][0] != par) {
        dfs(tree[node][0], node, 1);
    }
    add(node);
    for (int i = 1; i < tree[node].size(); i++) {
        int adj = tree[node][i];
        if (adj != par) {
            for (int p = ST[adj]; p <= EN[adj]; p++) {
                add(euler[p]);
            }
        }
    }
    ans[node] = S[max_cnt];
    if (!keep) {
        for (int p = ST[node]; p <= EN[node]; p++) {
            remove(euler[p]);
        }
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%lld", &C[i]);
    }
    for (int i = 1; i < N; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        tree[u].pb(v);
        tree[v].pb(u);
    }
    dfs0(1, 0);
    dfs(1, 0, 0);
    for (int i = 1; i <= N; i++) {
        printf("%lld ", ans[i]);
    }
}