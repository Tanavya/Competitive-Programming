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

const int maxn = 1e5+7;
int N;
vector <vector <ii>> tree(maxn);
ll max_dist = -1;
void dfs(int node, int parent, ll dist) {
    //if (tree[node].size() == 1) 
        max_dist = max(max_dist, dist);
    
    for (ii edge : tree[node]) {
        int adj = edge.x, w = edge.y;
        if (adj != parent) 
            dfs(adj, node, w + dist);
    }
}

void solve() {
    int T;
    cin >> T;
    while (T--) {
        tree.clear();
        tree.resize(maxn);
        max_dist = -1;
        int u, v, w;
        scanf("%d", &N);
        ll total = 0;
        for (int i = 0; i < N-1; i++) {
            scanf("%d %d %d", &u, &v, &w);
            tree[u].pb({v, w});
            tree[v].pb({u, w});
            total += 2*w;
        }
        dfs(1, 0, 0);
        cout << total - max_dist << endl;
    }
}

void gen_tc() {
    int N = (rand() % 50000) + 50000;
    cout << N << endl;
    for (int i = 2; i <= N; i++) {
        cout << i << " " << (rand() % (i-1)) + 1 << " " << (rand() % (20001)) << endl;
    }

}
int main() {
    srand(time(NULL));
    
    for (int i = 0; i < 11; i++) {
        string loc = "MinimumPossibleTraverse/input/input" + to_string(i) + ".txt";
        freopen(loc.c_str(), "w", stdout);
        if (i == 0) {
            cout << 2 << endl;
            cout << "3\n1 2 3\n2 3 4\n";
            cout << "3\n1 2 3\n1 3 3\n";
        }
        else {
            cout << 10 << endl;
            for (int t = 0; t < 10; t++) 
                gen_tc();
        }
    }
    
    for (int i = 0; i < 11; i++) {
        string loc = "MinimumPossibleTraverse/input/input" + to_string(i) + ".txt";
        freopen(loc.c_str(), "r", stdin);
        loc = "MinimumPossibleTraverse/output/output" + to_string(i) + ".txt";
        freopen(loc.c_str(), "w", stdout);
        solve();
    }

}