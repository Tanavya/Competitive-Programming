//Problem type: Data Structures (Disjoint Sets)
 
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
 
int s1, s2;
vi parent(20007), size(20007);
vector <vi> graph(20007);
vector <ii> cc;
bitset <20007> visited;
int root(int x) {
    while (parent[x] != x) {
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
    return x;
}
 
bool Find(int a, int b) {
    return root(a) == root(b);
}
int Subset(int x) {
    if (Find(x, s1)) return s1;
    else if (Find(x, s2)) return s2;
    else return 0;
}
void Union(int a, int b) {
    int root_a = root(a), root_b = root(b);
    if (root_a == root_b) return;
    parent[root_a] = root_b;
    size[root_b] += size[root_a];
    
}
int Compute(vector <ii> to_compute) {
    if (to_compute.size() == 0) return 0;
    int a,b;
    for (int i = 0; i <= 20000; i++) {
        parent[i] = i;
        size[i] = 1;
    }
    vector <ii> tmp;
    int prev_size = to_compute.size();
    for (int i = 0; i < to_compute.size(); i++) {
        a = to_compute[i].x, b = to_compute[i].y;
        if (i == 0) {
            s1 = a, s2 = b;
        }
        else {
            if (!Subset(a) && !Subset(b)) {
                Union(a, s1);
                Union(b, s2);
            }
            else if (Subset(a) && Subset(b)) {
                continue;
            }
            else {
                if (Find(a, s1)) {
                    Union(b, s2);
                }
                else if (Find(a, s2)) {
                    Union(b, s1);
                }
                if (Find(b, s1)) {
                    Union(a, s2);
                }
                else if (Find(b, s2)) {
                    Union(a, s1);
                }
            }
        }
    }
    return max(size[s1], size[s2]);
}

void dfs(int node) {
    visited[node] = true;
    for (int adj : graph[node]) {
        if (!visited[adj]) {
            cc.pb(mp(node, adj));
            dfs(adj);
        }
    }
} 

int main() {
    int T, N, a, b;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        scanf("%d", &N);
        bitset<20001> viz;
        viz.set();
        graph.clear(); graph.resize(20007); visited.reset();
        for (int i = 0; i < N; i++) {
            scanf("%d %d", &a, &b);
            graph[a].pb(b);
            graph[b].pb(a);
            viz[a] = viz[b] = 0;
        }
        queue <int> Q;
        int ans = 0;
        vector <int> color(20001, 0);
        for (int i = 1; i <= 20000; i++) {
            if (!viz[i]) {
                int cnt1 = 0, cnt2 = 0;
                viz[i] = 1;
                color[i] = 1;
                Q.push(i);
                while (!Q.empty()) {
                    int curr = Q.front();
                    if (color[curr] == 1) cnt1++;
                    if (color[curr] == 2) cnt2++;
                    Q.pop();
                    for (int adj : graph[curr]) {
                        if (!viz[adj]) {
                            color[adj] = (color[curr] == 1 ? 2 : 1); 
                            viz[adj] = 1;
                            Q.push(adj);
                        }
                    }
                }
                ans += max(cnt1, cnt2);
            }
        }
        /*
        int ans = 0;
        for (int i = 1; i <= 20000; i++) {
            if (!visited[i]) {
                cc.clear();
                dfs(i);
                ans += Compute(cc);
            }
        }*/
        printf("Case %d: %d\n", t, ans);
    }
}