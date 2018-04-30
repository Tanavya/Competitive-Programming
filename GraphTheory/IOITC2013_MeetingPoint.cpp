#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <assert.h>
#include <queue>
#include <bitset>

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

const int INF = int(1e9);
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
using namespace std;

const int maxn = (int) 1e6+10;
vi graph[maxn];
int color[maxn];
bitset <maxn> visited;

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u].pb(v);
        graph[v].pb(u);
    }
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            ll size = 0;
            ll count[2] = {0, 0};
            visited[i] = true;
            queue <int> Q;
            Q.push(i);
            bool bipartite = true;
            while (!Q.empty()) {
                int curr = Q.front();
                count[color[curr]]++;
                size++;
                Q.pop();
                for (int adj : graph[curr]) {
                    if (!visited[adj]) {
                        visited[adj] = true;
                        color[adj] = !color[curr];
                        Q.push(adj);
                    }
                    else if (color[adj] == color[curr]) {
                        bipartite = false;
                    }
                }
            }
            if (!bipartite) {

                ans += size*size;
            }
            else {
                ans += count[0]*count[0];
                ans += count[1]*count[1];
            }
        }
    }
    printf("%lld\n", ans);
}
/*
2 1
0 1

4 3
0 1
1 2
2 0
 */