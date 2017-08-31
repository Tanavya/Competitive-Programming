//Problem Link: http://codeforces.com/contest/771/problem/C
//Problem type: Dynamic Programming

//TODO 765E

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


int N, K;
vector <vi> tree(200007);
ll ans = 0;
int total_subtree[200007], distance_mod[200007][5], parent[200007];
void dfs(int curr, int papa, int depth) {
    parent[curr] = papa;
    total_subtree[curr] = distance_mod[curr][depth % K] = 1;
    for (int adj : tree[curr]) {
        if (adj != papa) {
            dfs(adj, curr, depth+1);
            for (int i = 0; i < K; i++) {
                for (int j = 0; j < K; j++) {
                    int rem = (i + j - 2 * depth) % K;
                    if (rem < 0) rem += K;
                    int need = (K - rem) % K;
                    ans += (ll) need * distance_mod[curr][i] * distance_mod[adj][j];
                }
            }
            for (int i = 0; i < K; i++) {
                distance_mod[curr][i] += distance_mod[adj][i];
            }
            total_subtree[curr] += total_subtree[adj];
        }
    }
    ans += (ll) total_subtree[curr] * (N - total_subtree[curr]);
}

int main() {
    int a,b;
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N-1; i++) {
        scanf("%d %d", &a, &b);
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs(1, 0, 0);
    cout << ans / K << endl;
}