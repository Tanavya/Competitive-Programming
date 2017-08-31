//Problem Link: http://codeforces.com/blog/entry/20935?locale=en
//Problem type: Dynamic Programming On Trees
//Given a tree T of N nodes and an integer K, find number of different sub trees of size (less than or) equal to K.

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


int N, K, ans = 0;
vector <vi> dp(50007, vi (507, 0)); //dp[v][k] Number of sub trees with v as root and k nodes
vector <vi> tree(50007);


void rec(int curr_node, int parent) {

    vector <int> dp_prev (507, 0);
    dp_prev[0] = 1;
    for (auto it = tree[curr_node].begin(); it != tree[curr_node].end(); ++it) {
        if (*it != parent) {
            vector <int> dp_this (507, 0);
            int v = *it;
            rec(v, curr_node);
            for (int i = 0; i <= K; i++) {
                for (int j = 0; j <= K-i; j++) {
                    dp_this[i+j] += (dp_prev[i] * dp[v][j]);
                }
            }
            dp_prev = dp_this;
        }
    }
    
    dp[curr_node][0] = 1;
    for (int i = 0; i <= K; i++) {
        dp[curr_node][i+1] = dp_prev[i];
    }
    ans += dp[curr_node][K];
}

int main() {

    scanf("%d %d", &N, &K);
    int a, b;
    for (int i = 0; i < N-1; i++) {
        scanf("%d %d", &a, &b);
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    for (int i = 1; i <= N; i++) {
        dp[i][1] = 1;
    }
    rec(1, 0);
    cout << ans << endl;
}
/*
9 4
1 2
1 3
1 4
2 5
2 6
4 8
8 9
3 7
*/
