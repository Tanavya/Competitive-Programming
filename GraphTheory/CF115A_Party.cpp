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
#include <stack>
#include <sstream>


#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << endl;
#define debug(x) cout << x << endl;
#define debug2(x,y) cout << x << " " << y << endl;
#define debug3(x,y,z) cout << x << " " << y << " " << z << endl;

typedef long long int ll;
typedef long double ld;
typedef unsigned long long int ull;
typedef std::pair <int, int> ii;
typedef std::vector <int> vi;
typedef std::vector <ll> vll;
typedef std::vector <ld> vld;

const int INF = int(1e9);
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
using namespace std;

const int maxn = 2007;
int N;

vector <vi> graph(maxn);
bitset <maxn> visited;
int in_deg[maxn];
int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        int u;
        scanf("%d", &u);
        if (u == -1) continue;
        graph[u].pb(i);
        in_deg[i]++;
    }
    int ans = 0;
    for (int u = 1; u <= N; u++) {
        if (!in_deg[u]) {
            assert(!visited[u]);
            queue <ii> Q;
            Q.push(mp(u, 1));
            visited[u] = true;
            while (!Q.empty()) {
                int curr = Q.front().fi;
                int lvl = Q.front().se;
                Q.pop();
                ans = max(ans, lvl);
                for (int adj : graph[curr]) {
                    if (!visited[adj]) {
                        visited[adj] = true;
                        Q.push(mp(adj, lvl+1));
                    }
                }
            }
        }
    }
    printf("%d\n", ans);
}