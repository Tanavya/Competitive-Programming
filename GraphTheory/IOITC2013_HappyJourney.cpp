#include <vector>
#include <algorithm>
#include <stdio.h>
#include <assert.h>
#include <bitset>
#include <queue>

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

typedef long long int ll;
typedef long double ld;
typedef unsigned long long int ull;
typedef std::pair <int, int> ii;
typedef std::vector <int> vi;
typedef std::vector <ll> vll;
typedef std::vector <ld> vld;
typedef std::vector <ii> vii;

const int INF = 2147483647;
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
using namespace std;

const int maxn = 100007;
bitset <maxn> visited;
vector <ii> graph[maxn];
int dist[maxn];

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    int src, dest;
    scanf("%d %d", &src, &dest);
    for (int i = 0; i < M; i++) {
        int u, v;
        char c;
        scanf("%d %c %d", &u, &c, &v);
        graph[u].pb(mp(v, (int)c));
        graph[v].pb(mp(u, (int)c));
    }
    queue <int> Q;
    Q.push(dest);
    visited[dest] = true;
    while (!Q.empty()) {
        int curr = Q.front();
        Q.pop();
        for (ii edge : graph[curr]) {
            int adj = edge.fi;
            if (!visited[adj]) {
                visited[adj] = true;
                Q.push(adj);
                dist[adj] = dist[curr] + 1;
            }
        }
    }
    visited.reset();
    int curr_min = INF, nxt_min = INF;
    string path;
    vii layer = {mp(src, 0)};
    int d = 0;
    while (!layer.empty()) {
        vii nxt_layer = {};
        for (ii tmp : layer) {
            int curr = tmp.fi;
            if (curr == dest) {
                printf("%s\n", path.c_str());
                return 0;
            }
            if (tmp.se > curr_min) continue;
            if (visited[curr]) continue;
            visited[curr] = true;
            for (ii edge : graph[curr]) {
                int adj = edge.fi, c = edge.se;
                if (!visited[adj] && d + dist[adj] + 1 <= dist[src]) {
                    //assert(d + dist[adj] + 1 == dist[src]);
                    nxt_min = min(nxt_min, c);
                    nxt_layer.pb(mp(adj,c));
                }
            }
        }
        path += char(nxt_min);
        curr_min = nxt_min;
        nxt_min = INF;
        layer = nxt_layer;
        d++;
    }
    assert(false);
}
/*
6 6
1 6
1 a 2
2 a 3
3 a 6
1 a 4
4 a 5
5 b 6

10 11
1 10
1 a 2
1 a 4
1 b 3
2 a 5
3 a 6
4 a 7
7 a 8
8 a 9
5 b 10
6 a 10
9 a 10
 */