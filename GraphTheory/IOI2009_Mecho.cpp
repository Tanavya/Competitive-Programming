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


int N, S, reachTime[640007], start, dest;
string forest;
char graph[640007];
vi hives;

vi adjacent(int n) {
    int i = n/N, j = n%N;
    vi ret;
    if (i-1 >= 0) ret.pb(N*(i-1)+j);
    if (i+1 < N) ret.pb(N*(i+1)+j);
    if (j-1 >= 0) ret.pb(N*i+(j-1));
    if (j+1 < N) ret.pb(N*i+(j+1));
    return ret;
}
bool canReach(int t) {
    if (reachTime[start] <= t)
        return false;
    bitset <640007> visited;
    queue <ii> Q;
    Q.push(mp(start, 0));
    visited[start] = true;
    while (!Q.empty()) {
        int currNode = Q.front().x, dist = Q.front().y; Q.pop();
        for (int adj : adjacent(currNode)) {
            if (!visited[adj] && forest[adj] != 'T' && reachTime[adj] > t+(dist+1)/S) {
                visited[adj] = true;
                Q.push(mp(adj, dist+1));
            }
            if (adj == dest)
                return true;
        }
    }
    return false;
}

void bfs() {
    bitset <640007> visited;
    queue <ii> Q;
    for (int hive : hives) {
        Q.push(mp(hive, 0));
        visited[hive] = true;
    }
    int t = 0;
    while (!Q.empty()) {
        while (Q.front().y == t) {
            int currNode = Q.front().x, currT = Q.front().y; Q.pop();
            reachTime[currNode] = currT;
            //debug2(currNode, currT);
            for (int adj : adjacent(currNode)) {
                if (!visited[adj] && forest[adj] == 'G') {
                    Q.push(mp(adj, currT+1));
                    visited[adj] = true;
                }
            }
        }
        t++;
    }
}

int main() {
    
    string row;
    string temp;
    scanf("%d %d", &N, &S);
    for (int i = 0; i < N; i++) {
        cin >> temp;
        forest += temp;
        for (int j = 0; j < N; j++) {
            if (forest[N*i+j] == 'H') 
                hives.pb(N*i+j);
            if (forest[N*i+j] == 'M') {
                start = N*i+j;
                forest[N*i+j] = 'G';
            }
            if (forest[N*i+j] == 'D')
                dest = N*i+j;
            if (forest[N*i+j] == 'H' || forest[N*i+j] == 'T')
                reachTime[N*i+j] = -1;
        }
    }
    //precompute
    //print(hives);
    bfs();
    int L = -1, R = N*N, mid, ans = -1;
    while (L <= R) {
        mid = (L+R)/2;
        if (canReach(mid)) {
            L = mid+1;
            ans = mid;
        }
        else
            R = mid-1;
    }
    printf("%d\n", ans);

}