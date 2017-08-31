//Problem Link: http://codeforces.com/problemset/problem/758/E
//Problem type: Dynamic Programming on Trees

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

int N, M;
vector <vector <pair <int, ii>>> tree(200007), min_tree(200007);
vector <pair <ii, ii>> edges;
unordered_map <int, unordered_map <int, ii>> final_tree;
vll dp(200007);

ll dfs1(int node, int parent) {
    ll sum = 0;
    for (int i = 0; i < tree[node].size(); i++) {
        auto edge = tree[node][i];
        int adj = edge.x, w = edge.y.x, p = edge.y.y;
        if (adj != parent) {
            ll temp = dfs1(adj, node);
            if (temp == -1) return -1;
            else if (temp <= p) {
                int w1 = w - (p - temp), p1 = temp;
                if (w1 < 1) {
                    p1 += (1 - w1);
                    w1 = 1;
                }
                sum += w1 + temp;
                min_tree[node][i] = mp(adj, mp(w1, p1));
            }
            else return -1;
        }
    }
    return dp[node] = sum;
}

int dfs2(int node, int parent, ll to_increase) {
    int total_used = 0;
    for (int i = 0; i < tree[node].size(); i++) {
        auto edge = tree[node][i], edge2 = min_tree[node][i];
        int adj = edge.x, w = edge.y.x, p = edge.y.y, w2 = edge2.y.x, p2 = edge2.y.y;
        if (adj != parent) {

            int increased = min(ll(w - w2), to_increase);
            total_used += increased;
            to_increase -= increased;
            w2 += increased;
            p2 += increased;
            
            //update value of weight left to increase
            int temp = dfs2(adj, node, min(to_increase, ll(p - dp[adj]))) ;
            total_used += temp;
            to_increase -= temp;

            //add it to our tree
            final_tree[adj][node] = final_tree[node][adj] = mp(w2, p2);
        }
    }
    return total_used;
}

int main() {
    scanf("%d", &N);
    int a, b, w, p;
    for (int i = 0; i < N-1; i++) {
        scanf("%d %d %d %d", &a, &b, &w, &p);
        tree[a].pb(mp(b, mp(w, p)));
        tree[b].pb(mp(a, mp(w, p)));
        edges.pb(mp(mp(a, b), mp(w, p)));
    }
    min_tree = tree;
    if (dfs1(1, -1) == -1) {
        printf("-1\n");
    }
    else {
        printf("%d\n", N);
        dfs2(1, -1, INF64);
        for (auto edge : edges) {
            a = edge.x.x, b = edge.x.y;
            w = final_tree[a][b].x, p = final_tree[a][b].y;
            printf ("%d %d %d %d\n", a, b, w, p);
        }
    }
}