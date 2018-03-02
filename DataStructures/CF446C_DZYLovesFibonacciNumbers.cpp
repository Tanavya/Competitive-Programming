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

const int maxn = 300007, mod = (int) 1e9 + 9;

int N;
ll A[maxn], S[maxn], pre[maxn], fib[maxn], pre_fib[maxn];
vector <ii> updates;

#define add(a, b) a += b; if (a < 0) a += mod; if (a > mod) a -= mod;
/*
inline void add(ll &a, ll b){
    a += b;
    if(a < 0)
        a += mod;
    if(a > mod)
        a -= mod;
}*/
inline void build() {
    memset(S, 0, sizeof(S));
    for (ii upd : updates) {
        int L = upd.fi, R = upd.se;
        add(S[L], 1);
        add(S[R+1], -fib[R-L+2]);
        add(S[R+2], -fib[R-L+1]);
    }
    updates.clear();
    ll res = 0;
    for (int i = 1; i <= N; i++) {
        add(S[i], S[i - 1]);
        if (i-2 >= 0) add(S[i], S[i - 2]);
        add(res, S[i]);
        add(pre[i], res);
    }
}

int main() {
    int M;
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++) {
        scanf("%lld", &A[i]);
        //pre[i] = add(pre[i-1], A[i]);
        pre[i] = pre[i-1];
        add(pre[i], A[i]);
    }
    fib[1] = fib[2] = 1;
    pre_fib[1] = 1;
    pre_fib[2] = 2;
    for (int i = 3; i <= N; i++) {
        add(fib[i], fib[i-1]);
        add(fib[i], fib[i-2]);
        pre_fib[i] = pre_fib[i-1];
        add(pre_fib[i], fib[i]);
    }
    int BLOCK = (int)sqrt(M);
    for (int i = 0; i < M; i++) {
        if (updates.size() == BLOCK)
            build();
        int type, L, R;
        scanf("%d %d %d", &type, &L, &R);
        if (type == 1) {
            updates.pb(mp(L, R));
        }
        else {
            ll res = pre[R];
            add(res, -pre[L-1]);
            for (ii upd : updates) {
                int ri = min(upd.se, R);
                int li = max(upd.fi, L);
                if (li <= ri) {
                    add(res, pre_fib[ri-upd.fi+1]);
                    add(res, -pre_fib[li-upd.fi]);
                }
            }
            printf("%lld\n", res);
        }
    }
}