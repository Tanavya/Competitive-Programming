#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <assert.h>

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

const int maxn = 300007;
ll M[maxn], P[maxn], tree[maxn*4][2], dp[maxn][2];

inline int left(int x) { return (x << 1); }
inline int right(int x) { return (x << 1) + 1; }

void build(int i, int L, int R) {
    if (L == R) {
        if (L == 0) tree[i][0] = tree[i][1] = 0;
        else tree[i][0] = tree[i][1] = INF;
    }
    else {
        int mid = (L+R)/2;
        build(left(i), L, mid);
        build(right(i), mid+1, R);
        tree[i][0] = tree[i][1] = min(tree[left(i)][0], tree[right(i)][0]);
    }
}

void update(int i, int L, int R, int idx, ll val0, ll val1) {
    if (L == R) {
        tree[i][0] = val0;
        tree[i][1] = val1;
    }
    else {
        int mid = (L+R)/2;
        if (idx <= mid)
            update(left(i), L, mid, idx, val0, val1);
        else
            update(right(i), mid+1, R, idx, val0, val1);
        tree[i][0] = min(tree[left(i)][0], tree[right(i)][0]);
        tree[i][1] = min(tree[left(i)][1], tree[right(i)][1]);
    }
}

inline ll query(int x) {
    return tree[1][x];
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    for (int i = 1; i <= N; i++) {
        scanf("%lld", &M[i]);
        M[i] += M[i-1]; //1
    }
    for (int i = 1; i <= N; i++) {
        scanf("%lld", &P[i]);
        P[i] += P[i-1]; //0
    }
    build(1, 0, N);
    for (int i = 1; i <= N; i++) {
        if (i-K-1 >= 0) update(1, 0, N, i-K-1, INF, INF);
        dp[i][0] = query(1) + P[i];
        dp[i][1] = query(0) + M[i];
        update(1, 0, N, i, dp[i][0] - M[i], dp[i][1] - P[i]);
    }
    printf("%lld\n", min(dp[N][0], dp[N][1]));
}
/*
5 2
1 1 1 7 9
4 3 5 6 2
 */