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

#define mp make_pair
#define pb push_back
#define x first
#define y second
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << endl;
#define debug(x) cout << x << endl;
#define debug2(x,y) cout << x << " " << y << endl;
typedef long long int ll;
typedef long double ld;
typedef std::pair <int, int> ii;
typedef std::vector <int> vi;
typedef std::vector <ll> vll;
const int INF = int(1e9);
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
using namespace std;

int E[107][107], dp[107][107];
vector <vector <int>> graph(107);
int N, M;
vi topo; vector <vi> level(107);


int f(int lvl, int m) {
    //debug2(lvl, m);
    int &val = dp[lvl][m];
    if (val != -1)
        return val;
    val = -INF;
    if (level[lvl].empty()) {
        val = 0;
        return val;
    }
    
    vector <vi> dp1(107, vi (107, -INF));
    vi dp_max(107, -INF);
    for (int i = m+1; i <= M; i++) {
        for (int n = 0; n < level[lvl].size(); n++) {
            dp_max[n] = max(dp_max[n], E[level[lvl][n]][i]);
            dp1[n][i] = dp_max[n];
            if (n) dp1[n][i] += dp1[n-1][i];
            if (dp1[n][i] < 0) dp1[n][i] = -INF;
        }
    }
    
    int n = level[lvl].size();
    for (int i = m+1; i <= M; i++) {
        int tmp = f(lvl+1, i);
        if (tmp == -INF) continue;
        val = max(val, dp1[n-1][i] + tmp);
        //cout << dp1[n-1][i] << endl; debug2("->", val); 
    }
    //printf("dp[%d][%d] = %d\n", lvl, m, val);
    return val;
}

int main() {
    memset(dp, -1, sizeof(dp));
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            scanf("%d", &E[i][j]);
            if (E[i][j] == -1) E[i][j] = -INF;
        }
    }
    int K, u, v;
    vi indegree(N+1, 0);
    bitset <107> viz;

    set <int> knodes;

    vector <int> knodesV;
    scanf("%d", &K);
    for (int i = 0; i < K; i++) {
        scanf("%d %d", &u, &v);
        graph[u].pb(v);
        indegree[v] += 1;
        knodes.insert(u);
        knodes.insert(v);
        
    }
    queue <int> Q;
    if (knodes.size() > 0) {
        for (int u : knodes) {
            if (indegree[u] == 0) {
                Q.push(u);
                viz[u] = true;
            }
        }
    }
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        topo.pb(u);
        for (int v : graph[u]) {
            if (!viz[v]) {
                indegree[v]--;
                viz[v] = true;
                Q.push(v);
            }
        }
    }

    queue <ii> QQ;
    viz.reset();
    if (!topo.empty()) {
        for (int i = 0; i < N; i++) {
            int start = topo[i];
            if (!viz[start]) {
                viz[start] = true;
                QQ.push(mp(start, 1));
                while (!QQ.empty()) {
                    int u = QQ.front().x, l = QQ.front().y; QQ.pop();
                    level[l].pb(u);
                    for (int v : graph[u]) {
                        if (!viz[v]) {
                            viz[v] = true;
                            QQ.push(mp(v, l+1));
                        }
                    }
                }
            }
        }
    }
    /*
    for (int i = 1; i <= N; i++) {
        if (level[i].empty()) break;
        print(level[i]);
    }*/
    int ans = f(1, 0);
    for (int i = 1; i <= N; i++) {
        if (!viz[v]) {
            int add = 0;
            for (int j = 1; j <= M; j++) {
                add = max(add, E[i][j]);
            }
            ans += add;
        }
    }
    cout << setprecision(2) << fixed << (double)ans / double(N) << endl;
}
/*
3 3 
10 70 100 
80 50 40 
80 20 40 
0
*/