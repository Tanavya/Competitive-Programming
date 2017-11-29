//Initial solution for Lovers Gift. Was getting TLE in-contest because I used sets to find max1, max2. :(
//Offline DSU + Segtree
//Segtree for Query 2 - finding max1, max2 of all sets excluding current set of query node i.e 1 to C-1 and C+1 to N

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
vi T, T2, parent, size, max1, max2;
bitset <maxn> activated;
vector <set <int>> sets;
set <int> active_set;


vi AC;

struct node {
    int max1, max2;
    node (int a = -INF, int b = -INF) { max1 = a; max2 = b; }
};
vector <node> stree;

inline int left(int x) { return x << 1; }
inline int right(int x) { return (x << 1) + 1; }

node merge (node l, node r) {
    int arr[4] = {l.max1, l.max2, r.max1, r.max2};
    sort(arr, arr+4);
    int mx = arr[3];
    int mx2 = -INF;
    if(mx!=arr[2])mx2 = arr[2];
    else if(mx!=arr[1])mx2 = arr[1];
    else if(mx!=arr[0])mx2 = arr[0];
    return node(mx, mx2);
}

void build(int i, int L, int R) {
    if (L == R) {
        stree[i].max1 = max1[L];
        stree[i].max2 = max2[L];
    }
    else {
        int mid = (L+R)/2;
        build(left(i), L, mid);
        build(right(i), mid+1, R);
        stree[i] = merge(stree[left(i)], stree[right(i)]);
    }
}

void update(int i, int L, int R, int idx, int val1, int val2) {
    if (L == R) {
        assert(L == idx);
        max1[L] = val1;
        max2[L] = val2;
        stree[i].max1 = max1[L];
        stree[i].max2 = max2[L];
    }
    else {
        int mid = (L+R)/2;
        if (mid >= idx) {
            update(left(i), L, mid, idx, val1, val2);
        }
        else {
            update(right(i), mid+1, R, idx, val1, val2);
        }
        stree[i] = merge(stree[left(i)], stree[right(i)]);
    }
}
node query(int i, int L, int R, int li, int ri) {
    if (ri < L || li > R) {
        return node();
    }
    if (li <= L && ri >= R) {
        return stree[i];
    }
    int mid = (L+R)/2;
    return merge(query(left(i), L, mid, li, ri), query(right(i), mid+1, R, li, ri));
}

int root(int x) {
    while (parent[x] != x) {
        //update(1, 1, N, parent[x], max1[x], max2[x]);
        //update(1, 1, N, x, -INF, -INF);
        x = parent[x] = parent[parent[x]];
    }
    return x;
}
void Union(int a, int b) {
    int root_a = root(a), root_b = root(b);
    if (root_a == root_b) return;
    if (size[root_a] > size[root_b]) swap(root_a, root_b);

    parent[root_a] = root_b;
    size[root_b] += size[root_a];
    sets[root_b].insert(sets[root_a].begin(), sets[root_a].end());


    //update(1, 1, N, a, -INF, -INF);

    int arr[4] = {max1[root_a], max2[root_a], max1[root_b], max2[root_b]};
    sort(arr, arr+4);
    int mx = arr[3];
    int mx2 = -INF;
    if(mx!=arr[2])mx2 = arr[2];
    else if(mx!=arr[1])mx2 = arr[1];
    else if(mx!=arr[0])mx2 = arr[0];

    update(1, 1, N, root_a, -INF, -INF);
    update(1, 1, N, root_b, mx, mx2);


}
bool Find(int a, int b) {
    return root(a) == root(b);
}

void reset() {
    tree.assign(N+1, {});
    activated.reset();
    T.assign(M+1, 0);
    T2.assign(N+1, 0);
    parent.resize(N+1);
    sets.resize(N+1);
    max1.resize(N+1);
    max2.resize(N+1);
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
        sets[i] = {i};
        max1[i] = i;
        max2[i] = -INF;
    }
    size.assign(N+1, 1);
    stree.assign(4*N+10, node());
    active_set.clear();
    AC.clear();
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
        //N = M = 5;
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
        build(1, 1, N);
        for (int x = 1; x <= N; x++) {
            if (activated[x])
                active_set.insert(x);
        }
        vi ans;
        for (int i = M-1; i >= 0; i--) {
            type = queries[i].fi;
            c = queries[i].se;
            if (T[i]) {
                activated[c] = false;
                active_set.erase(c);
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

                    c = root(c);
                    node n;
                    //cout << c << ": ";print(sets[c]);
                    if (c == N) n = query(1, 1, N, 1, c-1);
                    else n = merge(query(1, 1, N, 1, c-1), query(1, 1, N, c+1, N));
                    node n2;
                    if (!active_set.empty())
                        n2.max1 = *prev(active_set.end());
                    if (active_set.size() > 1)
                        n2.max2 = *prev(prev(active_set.end()));
                    n = merge(n, n2);
                    if (n.max2 == -INF)
                        ans.pb(-1);
                    else ans.pb(n.max2);

                }
            }
        }
        int i = 0;
        while (!ans.empty()) {
            //cout << "Mine: " << ans.back() << endl;
            //cout << "AC  : " << AC[i] << endl;
            //assert(AC[i] == ans.back());
            //cout << "Mine: " << ans.back() << endl;
            //cout << "AC  : " << AC[i] << endl;
            //assert(AC[i] == ans.back());
            cout << ans.back() << endl;
            ans.pop_back();
            i++;
        }

    }
}