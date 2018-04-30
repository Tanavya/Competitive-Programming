#include <vector>
#include <algorithm>
#include <stdio.h>
#include <assert.h>
//#include <iostream>

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
typedef std::vector <ii> vii;
typedef std::vector <ll> vll;
typedef std::vector <ld> vld;

const int INF = int(1e9)+10;
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
using namespace std;

const int maxn = 1007;
vi graph[maxn], tree[4*maxn];
ll dp[maxn], c[maxn];

inline int left(int x) { return (x << 1); }
inline int right(int x) { return (x << 1) + 1; }

void build(int i, int L, int R) {
    if (L == R) {
        tree[i] = graph[L];
        sort(all(tree[i]));
    }
    else {
        int mid = (L+R)/2;
        build(left(i), L, mid);
        build(right(i), mid+1, R);
        merge(all(tree[left(i)]), all(tree[right(i)]), back_inserter(tree[i]));
    }
    //debug2(L, R); cout << i << ": "; print(tree[i]);
}

bool query(int i, int L, int R, int li, int ri, int lii, int rii) {
    if (ri < L || li > R)
        return false;
    if (li <= L && ri >= R) {
        auto it = lower_bound(all(tree[i]), lii);
        if (it == tree[i].end()) return false;
        return *it <= rii;
    }
    int mid = (L+R)/2;
    return query(left(i), L, mid, li, ri, lii, rii) ||
           query(right(i), mid+1, R, li, ri, lii, rii);
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u].pb(v);
    }
    for (int i = 1; i <= N; i++) {
        scanf("%lld", &c[i]);
        dp[i] = INF64;
    }
    build(1, 1, N);
    for (int i = 1; i <= N; i++) {
        for (int g = 1; i+g-1 <= N; g++) {
            dp[i+g-1] = min(dp[i+g-1], dp[i-1] + c[g]);
            for (int l = i+g; l+g-1 <= N; l += g) {
                int r = l+g-1;
                if (!query(1, 1, N, i, i+g-1, l, r)) break;
                dp[r] = min(dp[r], dp[i-1] + c[g]);
            }
        }
        //printf("dp[%d] = %lld\n", i, dp[i]);
    }
    printf("%lld\n", dp[N]);
}
/*
5 2
1 3
2 5
5 4 10 6 11

6 9
1 2
1 3
2 3
2 4
3 4
3 5
4 5
4 6
5 6
10 8 6 8 10 12

 */