#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <assert.h>
#include <set>
#include <bitset>
#include <queue>

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

const int maxn = (int) 1e5+10, mod = (int) 1e9+7, mod_inv = 500000004;
int N, parent[maxn], size[maxn], head[maxn], color[maxn], color_cnt[maxn][2][3];
vi S[2][maxn];
bitset <maxn> invalid; int invalid_cnt = 0;
int prod[maxn]; ll ans = 1;

int root(int u) {
    while (parent[u] != u) {
        u = parent[u] = parent[parent[u]];
    }
    return u;
}

int ways(int u) {
    u = root(u);
    if (color_cnt[u][0][1] && color_cnt[u][0][2]) return 0; //different colors in set 0
    if (color_cnt[u][1][1] && color_cnt[u][1][2]) return 0; //different colors in set 1
    if (color_cnt[u][0][1] && color_cnt[u][1][1]) return 0; //same color in set 0 and set 1
    if (color_cnt[u][0][2] && color_cnt[u][1][2]) return 0; //same color in set 0 and set 1
    if (color_cnt[u][0][0] + color_cnt[u][1][0] == size[u]) return 2; // all are uncolored
    return 1; //only 1 type of color in set 0, and only 1 type of color in set 1
}
void update_prod(int u, int val) {
    u = root(u);
    if (!prod[u]) {
        invalid[u] = false;
        invalid_cnt--;
    }
    if (prod[u] == 2) ans = (ans * mod_inv) % mod;
    prod[u] = val;
    if (prod[u] == 2) ans = (ans * 2) % mod;
    if (!prod[u]) {
        invalid[u] = true;
        invalid_cnt++;
    }
}

void change_color(int u, int col) {
    color_cnt[root(u)][head[u]][color[u]]--;
    color[u] = col;
    color_cnt[root(u)][head[u]][color[u]]++;
    update_prod(u, ways(u));
}

void Union(int u, int v) {
    int a = root(u), b = root(v);
    if (a == b) return;
    if (size[a] > size[b]) {
        swap(a, b);
        swap(u, v);
    }
    size[b] += size[a]; // a merged into b
    update_prod(a, 1);
    parent[a] = b;
    int S1 = head[u], S2 = !head[u];
    for (int x : S[S1][a]) {
        S[!head[v]][b].pb(x);
        color_cnt[b][!head[v]][color[x]]++;
        head[x] = !head[v];
    }
    for (int x : S[S2][a]) {
        S[head[v]][b].pb(x);
        color_cnt[b][head[v]][color[x]]++;
        head[x] = head[v];
    }
    update_prod(b, ways(b));
}

int main() {
    int M, Q, k1, k2;
    scanf("%d %d %d %d %d", &N, &M, &Q, &k1, &k2);
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
        size[i] = 1;
        prod[i] = 2;
        S[0][i] = {i};
        head[i] = 0;
        color_cnt[i][0][0] = 1;
        ans = (ans * 2) % mod;
    }
    for (int i = 0; i < k1; i++) {
        int u;
        scanf("%d", &u);
        change_color(u, 1);
    }
    for (int i = 0; i < k2; i++) {
        int u;
        scanf("%d", &u);
        change_color(u, 2);
    }
    for (int x = 0; x < M; x++) {
        int u, v;
        scanf("%d %d", &u, &v);
        Union(u, v);
    }
    while (Q--) {
        int type;
        scanf("%d", &type);
        if (type == 0) {
            int u; char col;
            scanf("%d %c", &u, &col);
            if (col == 'A') change_color(u, 1);
            else if (col == 'B') change_color(u, 2);
            else change_color(u, 0);
        }
        else if (type == 1) {
            int u, v;
            scanf("%d %d", &u, &v);
            Union(u, v);
        }
        else {
            /*
            ll ans = 1;
            for (int i = 1; i <= N; i++) {
                ans *= prod[i];
                ans %= mod;
            }*/
            if (invalid_cnt) printf("%d\n", 0);
            else printf("%lld\n", ans);
        }
    }
}
/*
6 3 6 2 1
1 3
5
1 5
5 3
3 6
2
0 5 A
2
0 5 U
1 4 5
2
 */