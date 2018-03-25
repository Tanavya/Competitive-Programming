#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <assert.h>
#include <set>

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

const int INF = 2147483647;
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
using namespace std;

const int maxn = 1000007;
int N;
multiset <ii> edges;
ii get_new_edge() {
    int u, v;
    while (true) {
        u = (rand() % N) + 1;
        v = (rand() % N) + 1;
        if (u > v) swap(u, v);
        if (u != v && edges.find(mp(u, v)) == edges.end()) return mp(u, v);
    }
}

int main() {
    freopen("inp.txt", "w", stdout);
    int M, Q;
    cin >> N >> M >> Q;
    debug3(N, M, Q);
    for (int i = 0; i < M; i++) {
        ii e = get_new_edge();
        debug2(e.fi, e.se);
        edges.insert(e);
    }
    while (Q--) {
        int type = rand() % 3, u, v;
        if (edges.size() == 0) {
            if (type == 1) {
                if (rand() % 2) type--;
                else type++;
            }
        }
        if (type == 0) {
            ii e = get_new_edge();
            u = e.fi, v = e.se;
            edges.insert(e);
        }
        else if (type == 1) {
            int i = int(rand() % edges.size());
            auto it = edges.begin();
            while (i--) it++;
            assert(it != edges.end());
            u = it->fi, v = it->se;
            edges.erase(edges.find(mp(u, v)));
        }
        else {
            u = (rand() % N) + 1, v = (rand() % N) + 1;
        }
        debug3(type, u, v);
    }
    int x; cin >> x;
}