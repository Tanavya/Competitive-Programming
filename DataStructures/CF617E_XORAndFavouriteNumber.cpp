//Solution: Mooooo's Algorithm
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


#define all(x) x.begin(),x.end()
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

const int maxn = (int) 1e5+10;
int block_size, A[maxn], N, M, K;

ll cnt[1000010], res[maxn];

struct node {
    int L;
    int R;
    int i;
};
bool cmp (node a, node b) {
    if (a.L/block_size != b.L/block_size)
        return a.L/block_size < b.L/block_size;
    return a.R < b.R;
}

int main() {
    scanf("%d %d %d", &N, &M, &K);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &A[i]);
        A[i] ^= A[i - 1];
    }
    block_size = int(round(sqrt(M)));
    vector<node> queries(M);
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &queries[i].L, &queries[i].R);
        queries[i].i = i;
    }
    sort(all(queries), cmp);
    int L = 1, R = 0;
    ll ans = 0;
    cnt[0] = 1;
    for (int i = 0; i < M; i++) {
        int li = queries[i].L, ri = queries[i].R;
        while (L < li) {
            cnt[A[L - 1]]--;
            ans -= cnt[K ^ A[L - 1]];
            L++;
        }
        while (L > li) {
            ans += cnt[K ^ A[L - 2]];
            cnt[A[L - 2]]++;
            L--;

        }
        while (R < ri) {
            ans += cnt[K ^ A[R + 1]];
            cnt[A[R + 1]]++;
            R++;
        }
        while (R > ri) {
            cnt[A[R]]--;
            ans -= cnt[K ^ A[R]];
            R--;
        }
        res[queries[i].i] = ans;
    }
    for (int i = 0; i < M; i++) {
        printf("%lld\n", res[i]);
    }
}