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
 
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << endl;
#define debug(x) cout << x << endl;
#define debug2(x,y) cout << x << " " << y << endl;
typedef long long int ll;
typedef long double ld;
typedef std::pair <int, int> ii;
typedef std::vector <int> vi;
typedef std::vector <ll> vll;
const int INF = int(1e9);
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
using namespace std;
 
int main() {
    int t, n, d;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &d);
        vi D (n,0);
        vll T(n,0), S(n,0);
        vector <vi> days(d+7);
        ll sum = 0, total = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d %lld %lld", &D[i], &T[i], &S[i]);
            days[D[i]].pb(i);
            total += (T[i] * S[i]);
        }
        priority_queue <ii> trainers;
        for (int i = 1; i <= d; i++) {
            for (int trainer : days[i]) {
                trainers.push(mp(S[trainer], trainer));
            }
            if (!trainers.empty()) {
                ii top = trainers.top(); 
                int trainer = top.y;
                ll sadness = S[trainer]; assert(S[trainer] == top.x);
                sum += sadness;
                T[trainer]--;
                if (T[trainer] == 0) trainers.pop();
            }
        }
        cout << total - sum << endl;
    }
}