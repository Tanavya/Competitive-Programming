//Problem Link: http://codeforces.com/problemset/problem/440/D
//Problem type: Dynamic Programming On Trees

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
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " ";

typedef long long int ll;
typedef long double ld;
typedef std::pair <int, int> ii;
typedef std::vector <int> vi;
typedef std::vector <ll> vll;
const int INF = int(1e9);
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

using namespace std;

vector <vi> tree(407);

vector <vector <int>> dp(407, vector <int> (407, INF)); //Each subtree 
int roads[407][407];
int parents[407];
int d[401][401][401];
int N, K;

void rec(int curr, int parent) {
    dp[curr][0] = 1;
    dp[curr][1] = 0;
    parents[curr] = parent;
    for (int i = 0; i < tree[curr].size(); i++) {
        if (tree[curr][i] != parent) {
            int child = tree[curr][i];
            rec(child, curr);
            for (int k = N; k ; k--) {
                int tmp = INF;
                for (int b = 0; b < k; b++) {
                    int a = k-b;
                    if (tmp > dp[curr][a] + dp[child][b]) {
                        tmp = dp[curr][a] + dp[child][b];
                        d[curr][k][i] = b;
                    }
                }
                dp[curr][k] = tmp;
            }
        }
    }
}


void dfs(int curr, int papa, int size) {
    for (int i = tree[curr].size() - 1; i >= 0; i--) {
        if (tree[curr][i] != papa) {
            //printf("d[%d][%d][%d] = %d\n", curr, size, i, d[curr][size][i]);
            int child = tree[curr][i];
            if (d[curr][size][i]) {
                dfs(child, curr, d[curr][size][i]);
            }
            else {
                cout << roads[curr][child] << " ";
            }
            size -= d[curr][size][i];
        }
    }
}
int main() {

    scanf("%d %d", &N, &K);
    int a,b;
    for (int i = 1; i <= N-1; i++) {
        scanf("%d %d", &a, &b);
        tree[a].push_back(b);
        tree[b].push_back(a);
        roads[a][b] = i;
        roads[b][a] = i;

    }
    rec(1, 0);
    int ans = dp[1][K], best = 1;
    for (int i = 2; i <= N; i++) {
        if (ans > dp[i][K] + 1) {
            ans = dp[i][K] + 1;
            best = i;
        }
    }
    cout << ans << endl;
    if (ans) {
        if (best != 1) cout << roads[best][parents[best]] << " ";
        dfs(best, parents[best], K);
    }
}