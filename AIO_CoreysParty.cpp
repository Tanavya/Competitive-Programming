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


const int maxn = 1007;
vector <set<int>> graph(maxn);
int N, deg[maxn];
bool rem[maxn];

set <ii> S;

void remove(int node) {
    vi to_remove;
    for (int adj : graph[node]) {
        to_remove.pb(adj);
    }
    rem[node] = true;
    N--;
    for (int e : to_remove) {
        graph[e].erase(node);
        graph[node].erase(e);
        deg[e]--;
        deg[node]--;
        S.insert(mp(deg[e], e));
    }
}

int main() {

    freopen("partyin.txt", "r", stdin);
    freopen("partyout.txt", "w", stdout);

    int M, A, B;
    scanf("%d %d %d %d", &N, &M, &A, &B);

    for (int i = 0; i < M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u].insert(v);
        graph[v].insert(u);
        deg[u]++;
        deg[v]++;
    }


    for (int i = 1; i <= N; i++) {
        S.insert(mp(deg[i], i));
        //debug2(i, deg[i]);
    }

    while (!S.empty()) {
        //cout << "N: " << N << endl;
        //cout << "S: \n";
        //for (ii e : S) debug2(e.se, e.fi);

        ii beg = *S.begin();
        ii last = *(prev(S.end()));

        int lo = beg.se;
        int d1 = beg.fi;
        int hi = last.se;
        int d2 = last.fi;

        if (rem[lo] || deg[lo] != d1) {
            S.erase(beg);
            continue;
        }
        if (rem[hi] || deg[hi] != d2) {
            S.erase(last);
            continue;
        }

        if (d1 < A) {
            S.erase(beg);
            remove(lo);
        }
        else if (N - d2 - 1 < B) {
            S.erase(last);
            remove(hi);
        }
        else {
            break;
        }
    }

    printf("%d\n", N);
}