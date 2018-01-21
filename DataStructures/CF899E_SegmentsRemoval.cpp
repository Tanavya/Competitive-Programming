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

const int maxn = 200007;
int A[maxn], dp[maxn];

bool cmp (ii a, ii b) {
    if (a.fi != b.fi) return a.fi > b.fi;
    return a.se < b.se;
}

int main() {

    int N;
    scanf("%d", &N);
    set <ii> S;
    int curr_start = 0, curr_val = 0, curr_size = 0;

    //priority_queue <ii, vector <ii>, cmp> pq;

    map <int, set <int>> M;
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
        S.insert(mp(i, A[i]));
        if (!i) {
            dp[i] = 1;
        }
        else {
            if (A[i] == A[i-1]) dp[i] = dp[i-1] + 1;
            else {
                M[dp[i-1]].insert(i-dp[i-1]+1);
                dp[i] = 1;
            }
        }
    }
    M[dp[N-1]].insert(N-dp[N-1]);

    while (!M.empty()) {
        auto it = prev(M.end());
        int pos = *((it->second).begin());
        auto it2 = S.find(mp(pos, A[pos]));
        int len = it->first;
        vector <ii> to_remove;
        while (len && it2 != S.end()) {
            to_remove.pb(*it2);
            it2++;
            len--;
        }
        if (pos) {
            if (A[pos-1] == A[pos+it->first]) {

            }
        }
    }

    return 0;
}