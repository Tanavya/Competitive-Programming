#include <iostream>
#include <vector>
#include <stdio.h>
#include <set>
#include <queue>
#include <assert.h>


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

const int maxn = (int) 2e5+10, mod = (int) 1e9+7;
int N, P[maxn];
vi tree[maxn];
ll dp1[maxn], dp2[maxn], size[maxn], depth[maxn];

void dfs(int node) {
    size[node] = 0;
    if (node) depth[node] = depth[P[node]] + 1;
    for (int adj : tree[node]) {
        dfs(adj);
        dp2[node] += ((size[node] * size[adj]) % mod);
        dp2[node] %= mod;
        size[node] += size[adj];
    }
    for (int adj : tree[node]) {
        ll x = (dp2[node] - (((size[node] - size[adj]) * size[adj]) % mod)) % mod;
        if (x < 0) x += mod;
        assert(x >= 0);
        assert(x < mod);
        dp1[node] += (depth[node] * ((dp2[adj] * x) % mod)) % mod;
        dp1[node] %= mod;
    }
    for (int adj : tree[node]) {
        dp2[node] += dp2[adj];
        dp2[node] %= mod;
    }
    size[node] += 1;
}

int main() {
    //freopen("inp.txt", "r", stdin);
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        int x;
        scanf("%d", &x);
        tree[x].pb(i);
        P[i] = x;
    }
    ll ans = 0;
    dfs(0);
    for (int i = 1; i <= N; i++) {
        ans += dp1[i];
        ans %= mod;
        //printf("dp1[%d] = %lld\n", i, dp1[i]);
        //printf("dp2[%d] = %lld\n", i, dp2[i]);
    }
    printf("%lld\n", ans);
}
/*
7
0 1 2 2 2 5 5

16
0 0 2 2 2 4 0 4 7 2 10 11 9 0 1 0
*/