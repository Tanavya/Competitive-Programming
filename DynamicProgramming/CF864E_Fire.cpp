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

int dp[107][2007], N;
bool taken[107][2007];
ii nxt[107][2007];

struct item {
    int t, d, p, i;
};

vector <item> items;

bool cmp (item a, item b) {
    return a.d < b.d;
}

int rec(int i, int t) {

    if (dp[i][t] != -1)
        return dp[i][t];

    if (i == N)
        return 0;

    //ignore
    int ret = rec(i+1, t);
    nxt[i][t] = mp(i+1, t);

    //check if possible to take
    if (t + items[i].t < items[i].d) {
        int tmp = items[i].p + rec(i + 1, t + items[i].t);
        if (tmp > ret) {
            ret = tmp;
            nxt[i][t] = mp(i + 1, t + items[i].t);
            taken[i][t] = true;
        }
    }

    return dp[i][t] = ret;
}

int main() {

    scanf("%d", &N);
    items.resize(N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d %d", &items[i].t, &items[i].d, &items[i].p);
        items[i].i = i+1;
    }
    sort(all(items), cmp);
    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < 107; i++) {
        for (int j = 0; j < 2007; j++) {
            nxt[i][j] = mp(-1, -1);
        }
    }
    printf("%d\n", rec(0, 0));
    ii curr = mp(0, 0);
    int cnt = 0;
    vi chosen;
    while (curr.fi != -1) {

        int i = curr.fi, j = curr.se;
        if (taken[i][j]) {
            cnt++;
            chosen.pb(items[i].i);
        }
        curr = nxt[i][j];
    }
    printf("%d\n", cnt);
    print(chosen);
}