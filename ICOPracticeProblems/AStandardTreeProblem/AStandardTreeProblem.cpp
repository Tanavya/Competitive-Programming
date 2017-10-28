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

using namespace std;
#define int long long int
 
const int mod = 1e9+7;
 
vector< set<int> > v;
int qval = 0, out = 0, t[20][200005], subtree[10002];
map< pair<int, int>, int > wt;
 
void update(int in, int val, int depth)
{
    in+=100;
    while(in)
    {
        t[depth][in]+=val;
        in>>=1;
    }
}
int read(int l, int r, int depth)
{
    int ret = 0;
    for(l+=100, r+=100; l<r; l>>=1, r>>=1)
    {
        if(l&1)ret += t[depth][l++];
        if(r&1)ret += t[depth][--r];
    }
    return ret;
}
void dfsinit(int u, int p)
{
    subtree[u] = 1;
    for(int i: v[u])
    {
        if(i==p)continue;
        dfsinit(i, u);
        subtree[u] += subtree[i];
    }
}
int findcentroid(int u, int p, int root)
{
    int ret = u;
    for(int i: v[u])
        if(i!=p&&subtree[i]>subtree[root]/2)
            ret = findcentroid(i, u, root);
    return ret;
 
}
void dfschange(int u, int p, int val, int change, int k, int depth)
{
    if(p>=0)
        update(val, change, depth);
    for(int i: v[u])    
        if(i!=p)
            dfschange(i, u, val+k*wt[{i, u}], change, k, depth);
}
int dfsans(int u, int p, int val, int k, int depth)
{
    int ret = 0;
    if(k*val>qval)return 0;
    if(k*val==qval)return 2;
    ret = read(1, (qval-k*val)/k+1, depth)+2;
    for(int i: v[u])
        if(i!=p)
            ret = (ret + dfsans(i, u, val+wt[{i, u}], k, depth))%mod;
    return ret;
}
void decompose(int u, int depth, int k)
{
    dfsinit(u, -1);
    int centroid = findcentroid(u, -1, u);
    dfschange(u, -1, 0, 1, k, depth);
    int cur = 0;
    for(int i: v[u])
    {
        dfschange(i, u, wt[{i, u}], -1, k, depth);
        cur += dfsans(i, u, wt[{i, u}], k, depth);
        dfschange(i, u, wt[{i, u}], 1, k, depth);
    }
    out += cur/2;
    out %= mod;
    for(int i: v[u])
    {
        v[i].erase(u);
        decompose(i, depth+1, k);
        v[i].insert(u);
    }
    memset(t[depth], 0, sizeof(t[depth]));
}
 
void solve()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int n, q;
    cin>>n>>q;
    v.resize(n);
    memset(t, 0, sizeof(t));
    for(int i = 0;i<n-1;i++)
    {
        int x, y, c;
        cin>>x>>y>>c;
        v[x-1].insert(y-1);
        v[y-1].insert(x-1);
        wt[{x-1, y-1}] = wt[{y-1, x-1}] = c;
    }
    while(q--)
    {
        memset(t, 0, sizeof(t));
        out = 0;
        int k = 0;
        cin>>qval>>k;
        decompose(0, 0, k);
        cout<<out<<endl;
    }
} 

void gentc(int t) {
    int N, Q = 10;
    if (t == 0) {
        N = 10;
        Q = 5;
    }
    else if (t < 5) {
        N = (rand() % 80) + 20;
    }
    else {
        N = (rand() % 900) + 100;
    }
    cout << N << " " << Q << endl;

    for (int i = 2; i <= N; i++) {
        cout << i << " " << (rand() % (i-1)) + 1 << " " << (rand() % (10000)) + 1 << endl;
    }
    for (int i = 0; i < Q; i++) {
        int X, K;
        X = (rand() % 1000000) + 1;
        if (t >= 5 && t < 10) K = 1;
        else K = (rand() % 20) + 1;
        cout << X << " " << K << endl;
    }
}
signed main() {
    srand(time(NULL));
    
    for (int i = 0; i < 15; i++) {
        string loc = "input/input" + to_string(i) + ".txt";
        freopen(loc.c_str(), "w", stdout);
        gentc(i);
    }
    
    for (int i = 0; i < 15; i++) {
        string loc = "input/input" + to_string(i) + ".txt";
        freopen(loc.c_str(), "r", stdin);
        loc = "output/output" + to_string(i) + ".txt";
        freopen(loc.c_str(), "w", stdout);
        solve();
    }
    return 0;
}