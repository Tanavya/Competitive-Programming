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


struct line {
    ll m, b;
    line (ll m = 0, ll b = 0): m(m), b(b) {}
    ll get(ll x) {
        return m*x+b;
    }
};
vector <line> lines;
const int maxn = (int)1e5+10;
int pointer = 0;
ll D[maxn], T[maxn], S[maxn];
int H[maxn];

inline bool bad(int l1, int l2, int l3) {
    return (lines[l3].b - lines[l1].b) * ld(lines[l1].m - lines[l2].m) <=
           (lines[l2].b - lines[l1].b) * ld(lines[l1].m - lines[l3].m);

}

void add(line l) {
    lines.pb(l);
    while (lines.size() >= 3 && bad(lines.size()-3, lines.size()-2, lines.size()-1))
        lines.erase(lines.end()-2);
}

ll query(ll x) {
    pointer = min(pointer, (int) lines.size() - 1);
    while (pointer < lines.size()-1 && lines[pointer+1].get(x) < lines[pointer].get(x))
        pointer++;
    return lines[pointer].get(x);
}

int main() {
    int N, M, P;
    scanf("%d %d %d", &N, &M, &P);
    for (int i = 2; i <= N; i++) {
        scanf("%lld", &D[i]);
        D[i] += D[i - 1];
    }
    vector<ll> A = {-INF64};
    for (int i = 1; i <= M; i++) {
        scanf("%d %lld", &H[i], &T[i]);
        A.pb(T[i] - D[H[i]]);
    }
    sort(all(A));
    for (int i = 1; i <= M; i++) {
        S[i] = S[i-1] + A[i];
    }
    add(line(0, 0));
    vector <line> prev_lines;
    ll cost = 0;
    for (int p = 1; p <= P; p++) {
        vector <line> next_lines = {line(0, 0)};
        for (int i = 1; i <= M; i++) {
            cost = query(A[i]) + i * A[i] - S[i];
            if (p != 1) add(prev_lines[i]);
            next_lines.pb(line(-i, cost + S[i]));
        }
        pointer = 0;
        prev_lines = next_lines;
        lines.clear();
        add(line(0, 0));
    }
    printf("%lld\n", cost);
}