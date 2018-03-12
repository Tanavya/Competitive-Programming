//dynamic CHT in Data Structures folder
//Problem: SPOJ ACQUIRE
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

const int maxn = 50007;

vector <ll> M, B;
int pointer;
//checks if l2 is required now
//if intersection(l1, l3) is to the left of intersection(l1, l2), returns true
bool bad(int l1, int l2, int l3) {
    return (B[l3] - B[l1]) * (M[l1] - M[l2]) <= (B[l2] - B[l1]) * (M[l1] - M[l3]);
}

void add(ll m, ll b) {
    M.pb(m);
    B.pb(b);
    while (M.size() >= 3 && bad(M.size()-3, M.size()-2, M.size()-1)) {
        M.erase(M.end()-2);
        B.erase(B.end()-2);
    }
}

ll query(ll x) {
    pointer = min(pointer, (int)M.size()-1);
    while (pointer < M.size()-1 &&
           M[pointer+1] * x + B[pointer+1] < M[pointer] * x + B[pointer])
        pointer++;
    return M[pointer] * x + B[pointer];
}

int main() {
    int N;
    scanf("%d", &N);
    vector <ii> A(N), rect;
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &A[i].fi, &A[i].se);
    }
    sort(all(A));
    for (int i = 0; i < N; i++) {
        while (!rect.empty() && A[i].se >= rect.back().se) {
            rect.pop_back();
        }
        rect.pb(A[i]);
    }
    N = (int)rect.size();
    pointer = 0;
    ll cost;
    add(rect[0].se, 0);
    for (int i = 0; i < N; i++) {
        cost = query(rect[i].fi);
        if (i < N-1)
            add(rect[i+1].se, cost);
    }
    printf("%lld\n", cost);
}