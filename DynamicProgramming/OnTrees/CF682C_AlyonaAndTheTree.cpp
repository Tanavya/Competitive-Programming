//Problem Link: http://codeforces.com/problemset/problem/682/C
//Problem type: Dynamic Programming (on Trees)
//Learning Exp: 

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <stdio.h>
#include <queue>
#include <set>
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
#define EPS 1e-5
#define MOD 1000000007
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << "\node";
typedef long long int ll;
using namespace std;

vector <pair <int, ll>> tree [100007];
int N, A[100007], dp[100007];

int dfs(int node, ll dist, int parent) {
    if (dp[node] != -1) {
        return dp[node];
    }
    int ret = 0;
    if (A[node] >= dist) {
        ret = 1;
        for (auto adj = tree[node].begin(); adj != tree[node].end(); ++adj) {
            int u = (*adj).first;
            ll weight = (*adj).second;
            if (u == parent) continue;
            ret += dfs(u,  max(dist + weight, weight), node);
        }
    }
    dp[node] = ret;
    return ret;
}

int main() {
    int a;
    ll b;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i+1]);
        dp[i+1] = -1;
    }
    for (int i = 2; i <= N; i++) {
        scanf("%d %lld", &a, &b);
        tree[a].push_back(mp(i, b));
        tree[i].push_back(mp(a, b));
    }
    /*
    for (int node = 1; node <= N; node++) {
        for (auto adj = tree[node].begin(); adj != tree[node].end(); ++adj) {
            printf("(%d,%d)->%d->(%d,%d)\n", node, A[node], (*adj).second, (*adj).first, A[(*adj).first]);
        }
    }*/
    cout << N - dfs(1, 0, 0) << endl;

}