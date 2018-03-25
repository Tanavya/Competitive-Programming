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

const int maxn = (int) 1e5+10;
int N, A[maxn];//, nxt[maxn];
vector <ii> nxt(maxn);
int main() {
    int M;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    int block_size = 300;
    for (int i = N-1; i >= 0; i--) {
        int b = i / block_size;
        if (A[i] + i < N) {
            if ((A[i] + i) / block_size > b) {
                nxt[i].fi = A[i] + i;
                nxt[i].se = 1;
            } else {
                ii adj = nxt[A[i] + i];
                nxt[i] = mp(adj.fi, adj.se + 1);
            }
        }
        else {
            nxt[i] = mp(INF, 1);
        }
    }
    while (M--) {
        int type;
        scanf("%d", &type);
        if (type == 0) {
            int i, x;
            scanf("%d %d", &i, &x);
            nxt[i-1].fi = i-1 + x;
            A[i-1] = x;
            do {
                i--;
                int b = i / block_size;
                if (A[i] + i < N) {
                    if ((A[i] + i) / block_size > b) {
                        nxt[i].fi = A[i] + i;
                        nxt[i].se = 1;
                    } else {
                        ii adj = nxt[A[i] + i];
                        nxt[i] = mp(adj.fi, adj.se + 1);
                    }
                }
                else {
                    nxt[i] = mp(INF, 1);
                }
            } while (i > 0 && i % block_size != 0);
        }
        else {
            int i;
            scanf("%d", &i);
            i--;
            int ans = 0, last = 0;
            while (i < N) {
                last = i;
                ii adj = nxt[i];
                ans += adj.se;
                i = adj.fi;
            }
            i = last;
            while (i < N) {
                last = i;
                i += A[i];
            }
            printf("%d %d\n", last+1, ans);
        }
    }
}