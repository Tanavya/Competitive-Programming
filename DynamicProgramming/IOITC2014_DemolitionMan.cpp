#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cmath>
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

const int INF = int(1e9);
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
using namespace std;

const int maxn = 18, INC = (int) 1e6+10;
int dp[maxn][1<<maxn], dp2[maxn][1<<maxn], dp3[maxn][1<<maxn], pop_count[1<<maxn], too_close[maxn][maxn], ans = 0, B, N, K, D;
vi tree[maxn], floors[maxn];
int MAP[maxn][INC+INC];

#define gc getchar_unlocked
void scanint(int &x) {
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

struct bomb {
    ll x,y,z,floor;
    bomb(int x = 0, int y = 0, int z = 0, int floor = 0) : x(x), y(y), z(z), floor(floor) {}
};
vector <bomb> bombs[maxn];

inline ll distance(int b, int i, int j) {
    return abs(bombs[b][i].x - bombs[b][j].x) +
           abs(bombs[b][i].y - bombs[b][j].y) +
           abs(bombs[b][i].z - bombs[b][j].z);
}

inline int get_floor_mask(int b, int msk) {
    int ret = 0;
    for (int i = 0; i < N; i++) {
        if (msk & (1 << i)) {
            ret |= (1 << bombs[b][i].floor);
        }
    }
    return ret;
}

void dfs(int node, int par) {
    for (int i = 0; i < (1 << N); i++) {
        dp3[node][i] = dp2[node][i];
    }
    for (int adj : tree[node]) {
        if (adj != par) {
            dfs(adj, node);
            for (int i = 0; i < (1 << N); i++) {
                int flip = (1 << N) - 1;
                for (int j = 0; j < floors[node].size(); j++) {
                    if (i & (1 << j)) {
                        int f = floors[node][j];
                        if (MAP[adj][f]) {
                            flip &= ~(1 << (MAP[adj][f]-1));
                        }
                    }
                }
                dp3[node][i] = max(dp3[node][i], dp3[node][i] + dp3[adj][flip]);
            }
        }
    }
}

int main() {
    //scanf("%d", &B);
    //scanf("%d %d %d", &N, &K, &D);
    scanint(B);
    scanint(N);
    scanint(K);
    scanint(D);
    for (int i = 0; i < (1 << maxn); i++) {
        pop_count[i] = __builtin_popcount(i);
    }
    for (int b = 1; b <= B; b++) {
        int t = 1;
        for (int i = 1; i <= N; i++) {
            int x, y, z;
            //scanf("%d %d %d", &x, &y, &z);
            scanint(x);
            scanint(y);
            scanint(z);
            z += INC;
            assert(z >= 0);
            if (!MAP[b][z]) {
                MAP[b][z] = t++;
                floors[b].pb(z);
            }
            bombs[b].pb(bomb(x, y, z, MAP[b][z]-1));
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i != j && distance(b, i, j) <= D) {
                    too_close[b][i] |= (1 << j);
                }
            }
        }
        for (int i = 0; i < (1 << N); i++) {
            dp[b][i] |= (i == 0);
            for (int j = 0; j < N; j++) {
                if (!(i & (1 << j))) {
                    int intersect = i & too_close[b][j];
                    if (pop_count[intersect] <= K) {
                        dp[b][i|(1 << j)] |= dp[b][i];
                    }
                }
            }
            int msk = get_floor_mask(b,i);
            if (dp[b][i]) {
                dp2[b][msk] = max(dp2[b][msk], pop_count[i]);
            }
        }
        for (int i = 0; i < (1 << N); i++) {
            for (int j = 0; j < N; j++) {
                if (i & (1 << j)) {
                    dp2[b][i] = max(dp2[b][i], dp2[b][i & ~(1 << j)]);
                }
            }
        }
    }
    for (int i = 1; i < B; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        tree[u].pb(v);
        tree[v].pb(u);
    }
    dfs(1, 0);
    for (int i = 0; i < (1 << N); i++) {
        ans = max(ans, dp3[1][i]);
    }
    printf("%d\n", ans);
}
/*
1
4 1 1
0 0 0
1 0 0
0 1 0
1 1 0

4
3 1 7
6 3 5
7 1 5
3 0 3
5 9 1
9 0 5
5 3 9
7 8 7
7 4 5
7 7 7
9 1 9
5 2 6
7 6 1
3 1
3 4
1 2
 */