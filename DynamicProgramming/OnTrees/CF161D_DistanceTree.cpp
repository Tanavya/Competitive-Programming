//Problem Link: http://codeforces.com/problemset/problem/161/D
//Problem type: Dynamic Programming
//Learning Exp: 

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
#define ii pair<int, int>
#define PI 3.14159265
#define INF 1000000000000000000LL
#define MAX 1e9
#define MAXN 10000010
#define EPS 1e-5
#define MOD 1000000007
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << "\n";
typedef long long int ll;
using namespace std;

int N, K, parent[500007];
ll dp[50007][507];
vector <vector <int>> tree(50007);

ll rec(int n, int k, int baap) {
    ll ret = 0;
    if (dp[n][k] != -1) {
        return dp[n][k];
    }
    else if (k == 0) ret = 1;
    else {
        for (auto it = tree[n].begin(); it != tree[n].end(); ++it) {
            if (*it != baap) {
                ret += rec(*it, k-1, n);
            }
        }
    }
    return dp[n][k] = ret;
}
void dfs(int n, int baap) {
    parent[n] = baap;
    for (auto it = tree[n].begin(); it != tree[n].end(); ++it) {
        if (*it != baap) {
            dfs(*it, n);
        }
    }
}

int main() {
    scanf("%d %d", &N, &K);
    int a, b;
    for (int i = 0; i < N-1; i++) {
        scanf("%d %d", &a, &b);
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= K; j++) {
            dp[i][j] = -1;
        }
    }
    dfs(1, 0);
    ll ans = 0;
    for (int n = 1; n <= N; n++) {
        ll a = rec(n, K, parent[n]), b = 0;
        for (auto it = tree[n].begin(); it != tree[n].end(); ++it) {
            if (*it != parent[n]) {
                for (int x = 1; x < K; x++) {
                    b += (rec(*it, x-1, n) * (rec(n, K-x, parent[n]) - rec(*it, K-x-1, n)));
                }
            }
        }
        ans += (a + 0.5 * b);
    }
    cout << ans << endl;

}
/*
10 3
2 1
3 1
4 3
5 4
6 5
7 1
8 6
9 2
10 6
*/
