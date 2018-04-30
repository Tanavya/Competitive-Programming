#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <assert.h>
#include <iostream>

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << endl;
#define debug(x) cout << x << endl;
#define debug2(x,y) cout << x << " " << y << endl;
#define debug3(x,y,z) cout << x << " " << y << " " << z << endl;
#define debug4(a,b,c,d) cout << a << " " << b << " " << c << " " << d << endl;
#define debug5(a,b,c,d,e) cout << a << " " << b << " " << c << " " << d << " " << e << endl;
#define trace(x) cout << #x << ": " << x << endl;

using namespace std;

vector<pair<int, int> > G[1001];
int C[1001];
int S[1001], rev_S[1001], jmp[1001];
int dist[1001]; // dist[i] = length of edge between par(i) and i
int timer = 0;
long long dp[30002][1002];  // dp[i][j] = min distance to collect i coins starting at jth preorder number

void dfs(int i, int p, int d) {
    dist[i] = d;
    S[i] = ++timer;
    rev_S[S[i]] = i;

    for(auto it: G[i]) {
        int v = it.first, w = it.second;
        if(v == p) continue;

        dfs(v, i, w);
    }

    jmp[S[i]] = timer + 1;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int N, D; cin >> N >> D;
    D /= 2;

    for(int i = 1; i <= N; i++) cin >> C[i];

    for(int i = 0; i < N - 1; i++) {
        int u, v, w; cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }

    dfs(1, 0, 0);
    int ans = 0;
    for(int i = 1; i <= 30000; i++) {
        dp[i][N + 1] = LLONG_MAX/2;
        for(int j = N; j >= 1; j--) {
            dp[i][j] = LLONG_MAX/2;
            dp[i][j] = min(dp[i][j], dp[i][jmp[j]]);
            int u = rev_S[j];
            if(i - C[u] >= 0) dp[i][j] = min(dp[i][j], dist[u] + dp[i - C[u]][j + 1]);
        }
        if(dp[i][1] != LLONG_MAX/2 && dp[i][1] <= D) ans = i;
    }
    cout << ans << endl;
}