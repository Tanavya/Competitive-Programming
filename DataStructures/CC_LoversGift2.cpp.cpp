//Offline + DSU
//But efficient computation of query 2. Trick is to notice max1, max2 will always be <= previous after merging

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


#define MAX(a,b) ((a)>(b)?(a):(b))
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

const int maxn = (int)1e5+10;
vector <vi> tree;
int N, M;
vi T, T2, parent, size, m1, m2;
bitset <maxn> activated;
vector <set <int>> sets;


int root(int x) {
    while (parent[x] != x) {
        x = parent[x] = parent[parent[x]];
    }
    return x;
}
void Union(int a, int b) {
    int root_a = root(a), root_b = root(b);
    if (root_a == root_b) return;
    if (size[root_a] >= size[root_b]) swap(root_a, root_b);

    assert(size[root_a] <= size[root_b]);
    parent[root_a] = root_b;
    size[root_b] += size[root_a];
    //print(sets[root_a]); cout << ": " << m1[root_a] << " " << m2[root_a] << endl;
    //print(sets[root_b]); cout << ": " << m1[root_b] << " " << m2[root_b] << endl;
    sets[root_b].insert(sets[root_a].begin(), sets[root_a].end());
    //print(sets[root_b]); cout << ": " << m1[root_b] << " " << m2[root_b] << endl;
    int cnt = 0;
    if (sets[root_b].find(m1[root_b]) == sets[root_b].end()) {
        cnt++;
    }
    if (sets[root_b].find(m2[root_b]) == sets[root_b].end()) {
        if (!cnt) m1[root_b] = m2[root_b];
        cnt++;
    }
    //else m2[root_b] = -1;

    if (cnt < 2) {
        int x = m1[root_b] - 1;
        while (x >= 1) {
            if (cnt == 2) break;
            if (sets[root_b].find(x) == sets[root_b].end()) {
                if (!cnt) m1[root_b] = x;
                else m2[root_b] = x;
                cnt++;
            }
            x--;
        }
    }
    if (cnt == 0) m1[root_b] = -1;
    else if (cnt == 1) m2[root_b] = -1;
    if (sets[root_b].find(m2[root_b]) != sets[root_b].end()) {
        m2[root_b] = -1;
    }
    assert(sets[root_b].find(m1[root_b]) == sets[root_b].end());
    assert(sets[root_b].find(m2[root_b]) == sets[root_b].end());

}
bool Find(int a, int b) {
    return root(a) == root(b);
}

void reset() {
    tree.assign(N+1, {});
    activated.reset();
    T.assign(M+1, 0);
    T2.assign(N+1, 0);
    m1.assign(N+1, -1);
    m2.assign(N+1, -1);
    parent.resize(N+1);
    sets.resize(N+1);
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
        sets[i] = {i};
        if (i == N) {
            m1[i] = N-1;
            m2[i] = N-2;
        }
        else {
            m1[i] = N;
            if (i == N-1) m2[i] = N-2;
            else m2[i] = N-1;
        }
    }
    size.assign(N+1, 1);
}

void dfs(int node, int par) {
    for (int adj : tree[node]) {
        if (adj != par) {
            if (!activated[node] && !activated[adj]) {
                Union(node, adj);
            }
            dfs(adj, node);
        }
    }
}

set <int> end_points;
void brute(int node, int par, bool bank) {
    if (activated[node]) bank = true;
    for (int adj : tree[node]) {
        if (adj != par) {
            brute(adj, node, bank);
        }
    }
    if (bank) {
        end_points.insert(node);
    }
}
int main() {

    int tc;
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d %d", &N, &M);
        //N = M = 10;
        //cout << N << " " << M << endl;
        reset();

        int u, v;
        /*
        for (int i = 2; i <= N; i++) {
            u = i;
            v = (rand() % (i - 1)) + 1;
            cout << u << " " << v << endl;
            tree[u].pb(v);
            tree[v].pb(u);
        }*/

        for (int i = 0; i < N-1; i++) {
            scanf("%d %d", &u, &v);
            tree[u].pb(v);
            tree[v].pb(u);
        }

        //vi AC;

        int type, c;
        vector <ii> queries;
        for (int i = 0; i < M; i++) {
            scanf("%d %d", &type, &c);
            //type = (rand() % 2) + 1; c = (rand() % N) + 1; cout << type << " " << c << endl;
            queries.pb({type, c});
            if (type == 1) {
                activated[c] = true;
                if (!T2[c]) {
                    T2[c] = i+1;
                    T[i] = c;
                }
            }
            /*
        else {
            end_points.clear();
            brute(c, 0, false);
            if (end_points.size() >= 2) {
                AC.pb(*prev(prev(end_points.end())));
                //cout << *prev(prev(end_points.end())) << endl;
            } else {
                AC.pb(-1);
                //cout << -1 << endl;
            }
        }*/
        }

        dfs(1, 0);
        vi ans;
        for (int i = M-1; i >= 0; i--) {
            ii query = queries[i];
            type = query.fi, c = query.se;
            if (T[i]) {
                activated[c] = false;
                for (int adj : tree[c]) {
                    if (!activated[adj]) {
                        Union(adj, c);
                    }
                }
            }
            else if (type == 2) {
                if (N == 1) {
                    ans.pb(-1);
                    continue;
                }
                if (activated[c]) {
                    if (N >= 2) {
                        ans.pb(N-1);
                    }
                    else ans.pb(-1);
                }
                else {
                    if (N == 2) {
                        ans.pb(-1);
                        continue;
                    }
                    //set <int> S = sets[root(c)];
                    //cout << "S: "; print(S);
                    c = root(c);
                    ans.pb(m2[c]);
                }
            }
        }
        int i = 0;
        while (!ans.empty()) {
            //cout << "Mine: " << ans.back() << endl;
            //cout << "AC  : " << AC[i] << endl;
            //assert(AC[i] == ans.back());
            cout << ans.back() << endl;
            ans.pop_back();
            i++;
        }
    }
} 