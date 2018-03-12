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

const int maxn = 50007, block_size = 350;
vector <pair<ll, ll>> block, all_lines, cyclists(maxn);
vector <ll> M, B;
int pointer = 0;

bool bad(int l1, int l2, int l3) {
    return (B[l3] - B[l1]) * (ld)(M[l1] - M[l2]) <= (B[l2] - B[l1]) * (ld)(M[l1] - M[l3]);
}

void add(ll m, ll b) {
    M.pb(m);
    B.pb(b);
    while (M.size() >= 3 && bad(M.size()-3, M.size()-2, M.size()-1)) {
        M.erase(M.end()-2);
        B.erase(B.end()-2);
    }
}

inline ll get(ll x, int i) {
    return M[i] * x + B[i];
}

ll query(ll x) {
    if (M.empty()) return 0;
    pointer = min(pointer, (int)M.size()-1);
    while (pointer < M.size() - 1 && get(x, pointer+1) > get(x, pointer))
        pointer++;
    return get(x, pointer);
}

void rebuild() {
    vector <pair<ll, ll>> tmp;
    sort(all(block));
    merge(all(block), all(all_lines), back_inserter(tmp));
    all_lines = tmp;
    M.clear();
    B.clear();
    block.clear();
    pointer = 0;
    for (int i = 1; i < all_lines.size(); i++) {
        assert(all_lines[i].fi >= all_lines[i-1].fi);
    }
    for (pair <ll, ll> line : all_lines) {
        add(line.fi, line.se);
    }
}

int main() {
    int N, Q;
    scanf("%d %d", &N, &Q);
    for (int i = 1; i <= N; i++) {
        cyclists[i] = mp(0, 0);
    }
    while (Q--) {
        if (block.size() % block_size == 0) {
            rebuild();
        }
        int type;
        scanf("%d", &type);
        if (type == 1) {
            int i;
            ll t, newSpeed;
            scanf("%lld %d %lld", &t, &i, &newSpeed);
            ll d = cyclists[i].fi * t + cyclists[i].se;
            cyclists[i].fi = newSpeed;
            cyclists[i].se = d - newSpeed * t;
            block.pb(cyclists[i]);
        }
        else {
            ll t, ans = 0;
            scanf("%lld", &t);
            for (pair <ll, ll> c : block) {
                ans = max(ans, c.fi * t + c.se);
            }
            ans = max(ans, query(t));
            printf("%lld\n", ans);
        }
    }
}