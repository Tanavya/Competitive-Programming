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
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip> //cout << setprecision(node) << fixed << num

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

const int INF = int(1e9);
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
using namespace std;

const int maxn = (int) 1e5+10;
int parent[maxn], deg[maxn];

inline int get(int u) {
    if (u == 1) {
        if (deg[u] % 2 == 0) return deg[u]/2;
        else return deg[u]/2+1;
    }
    return deg[u]/2;
}

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 2; i <= N; i++) {
        scanf("%d", &parent[i]);
        deg[parent[i]]++;
    }
    int ans = 0;
    for (int u = 1; u <= N; u++) {
        ans += get(u);
    }
    printf("%d\n", ans);
    int Q;
    scanf("%d", &Q);
    while (Q--) {
        int u, v;
        scanf("%d %d", &u, &v);
        ans -= get(parent[u]);
        deg[parent[u]]--;
        ans += get(parent[u]);
        ans -= get(v);
        deg[v]++;
        ans += get(v);
        parent[u] = v;
        printf("%d\n", ans);
    }
}
/*
5
3 1 3 3
3
4 2
2 3
5 4
 */