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
#include <random>
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
int intersect[500][maxn], heavy_id[maxn], B = 350;
vector <vi> heavy, sets;
bool exists[maxn];
ll A[maxn], update[500], ans[500];
inline void fast_lookup(vi &V, bool b) {
    for (int x : V) exists[x] = b;
}

int main() {
    int N, M, Q;
    scanf("%d %d %d", &N, &M, &Q);
    for (int i = 1; i <= N; i++) {
        scanf("%lld", &A[i]);
    }
    for (int i = 0; i < M; i++) {
        int k;
        scanf("%d", &k);
        vi S(k);
        ll sum = 0;
        for (int j = 0; j < k; j++) {
            scanf("%d", &S[j]);
            sum += A[S[j]];
        }
        if (k > B) {
            heavy_id[i] = (int)heavy.size();
            heavy.pb(S);
            ans[heavy_id[i]] = sum;
        }
        else {
            heavy_id[i] = -1;
        }
        sets.pb(S);
    }
    for (int i = 0; i < heavy.size(); i++) {
        fast_lookup(heavy[i], true);
        for (int __j = 0; __j < M; __j++) {
            for (int el : sets[__j]) {
                intersect[i][__j] += exists[el];
            }
        }
        fast_lookup(heavy[i], false);
    }
    while (Q--) {
        char type;
        cin >> type;
        if (type == '?') {
            int k;
            scanf("%d", &k);
            k--;
            ll res = 0;
            if (sets[k].size() <= B) {
                //light set
                for (int i : sets[k]) {
                    res += A[i];
                }
                for (int i = 0; i < heavy.size(); i++) {
                    res += ((ll)intersect[i][k] * update[i]);
                }
            }
            else {
                res = ans[heavy_id[k]];
                for (int i = 0; i < heavy.size(); i++) {
                    res += ((ll)intersect[i][k] * update[i]);
                }
            }
            printf("%lld\n", res);
        }
        else {
            int k, x;
            scanf("%d %d", &k, &x);
            k--;
            if (sets[k].size() <= B) {
                for (int i : sets[k]) {
                    A[i] += x;
                }
                for (int i = 0; i < heavy.size(); i++) {
                    ans[i] += ((ll)intersect[i][k] * x);
                }
            }
            else {
                update[heavy_id[k]] += x;
            }
        }
    }
}