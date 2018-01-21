//DQuery
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

const int maxn = 30010, maxai = (int)1e6+10;
int A[maxn], cnt[maxai], res[200010], block_size;

bool cmp (pair <ii, int> a, pair <ii, int> b) {
    if (a.fi.fi/block_size != b.fi.fi/block_size) {
        return a.fi.fi/block_size < b.fi.fi/block_size;
    }
    return a.fi.se < b.fi.se;
}

int main() {
    int N, Q;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    scanf("%d", &Q);
    vector <pair<ii, int>> queries(Q);
    for (int i = 0; i < Q; i++) {
        scanf("%d %d", &queries[i].fi.fi, &queries[i].fi.se);
        queries[i].se = i;
    }
    block_size = round(sqrt(Q));
    int L = 0, R = -1, ans = 0;
    sort(queries.begin(), queries.end(), cmp);
    for (int i = 0; i < Q; i++) {
        int li = queries[i].fi.fi, ri = queries[i].fi.se;
        li--; ri--;
        while (L < li) {
            cnt[A[L]]--;
            if (cnt[A[L]] == 0)
                ans--;
            L++;
        }
        while (L > li) {
            cnt[A[L-1]]++;
            if (cnt[A[L-1]] == 1)
                ans++;
            L--;
        }
        while (R < ri) {
            cnt[A[R+1]]++;
            if (cnt[A[R+1]] == 1)
                ans++;
            R++;
        }
        while (R > ri) {
            cnt[A[R]]--;
            if (cnt[A[R]] == 0)
                ans--;
            R--;
        }
        res[queries[i].se] = ans;

    }
    for (int i = 0; i < Q; i++) {
        printf("%d\n", res[i]);
    }
}