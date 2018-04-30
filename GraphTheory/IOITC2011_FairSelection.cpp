#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <assert.h>
#include <map>
#include <queue>
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
int A[maxn], parent[maxn], dp[maxn], dp2[maxn], ans_sum = 0;
vector <ii> lowest(maxn, mp(INF, INF)), lowest_mark(maxn, mp(INF, INF));
vi tree[maxn];
set <int> ans;
bool marked[maxn], ok = true;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd (b, a%b);
}

void dfs(int node) {
    lowest[node] = mp(A[node], node);
    for (int adj : tree[node]) {
        dfs(adj);
        dp[node] += dp[adj];
        if (dp[adj]) lowest_mark[node] = lowest_mark[adj];
        if (lowest[adj] < lowest[node]) lowest[node] = lowest[adj];
    }
    if (dp[node] == 0)
        lowest_mark[node] = lowest[node];
    if (marked[node]) {
        if (dp[node] == 0) {
            ans.insert(lowest[node].se);
            dp[node] = 1;
        }
        else if (dp[node] > 1)
            ok = false;
    }
}

int main() {
//    freopen("inp.txt", "r", stdin);
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d", &A[i]);
    for (int i = 2; i <= N; i++) {
        scanf("%d", &parent[i]);
        tree[parent[i]].pb(i);
    }
    int M;
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        int x;
        scanf("%d", &x);
        marked[x] = true;
    }
    dfs(1);
    int F;
    scanf("%d", &F);
    if (ok) printf("YES\n");
    else {
        printf("NO\n");
        return 0;
    }
    for (int x: ans) {
        ans_sum += A[x];
    }
    if (F == 1) return 0;
    else if (F == 2) {
        printf("%d\n", ans_sum);
    }
    else if (F == 3) {
        int n = (int)ans.size();
        int GCD = gcd(n, ans_sum);
        printf("%d %d\n", ans_sum/GCD, n/GCD);
    }
    else if (F == 4) {
        printf("%d\n", ans_sum);
        printf("%d ", (int)ans.size());
        print(ans);
    }
    else {
        int n = (int)ans.size();
        int GCD = gcd(n, ans_sum);
        printf("%d %d\n", ans_sum/GCD, n/GCD);
        printf("%d ", (int)ans.size());
        print(ans);
    }
}
/*
5
10 12 15 10 13
1 1 1 1
3
2 3 5
1
 */