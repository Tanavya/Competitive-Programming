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

int main() {
    int N;
    ll ans = 0;
    priority_queue <int> pq;
    scanf("%d", &N);
    //f(i,x) = y <= x, min(f(i-1,y)) + abs(y-ai)
    //f(i,x) = min(f(i,x-1), f(i-1,x) + abs(x-ai))
    //maintain set of slopes in pq, with values representing start of slope
    //last element is index of segment of slope 0
    //second last, segment of slope -1
    //and so on
    //hence forms a curve who's slope decreases to zero
    //slope of ith line at x is g(i,x) = f(i,x+1) - f(i,x)
    //update ith line if i-1th line is known
    //opt(i) is the optimum value of x such that f(i) is minimised
    /*
    There are two cases to consider :

    Case 1 : Opt(i - 1) ≤ ai
    Here, the slope at every point before ai decreases by 1. Thus,
    we push ai into the slope array as this indicates that we decreases
    the slope at all the slope changing points by 1, and the slope
    changing point for slope = 0 is ai, i.e. Opt(i) = ai. Thus, this
    case is settled. Cost doesn't change because optimum value of
    x is ai.

    Case 2 : Opt(i - 1) > ai
    Now, we insert ai into the set, since it decreases the slope at all
    the slope changing points before ai by 1. Furthermore, we insert
    ai again because it increases the slope at the slope changing points
    between ai and Opt(i - 1) by 1. Now, we can just take Opt(i) = Opt(i - 1)
    since the slope at Opt(i - 1) is still 0. Finally, we remove Opt(i - 1)
    from the set because it's no longer the first point where the slope
    changes to 0. (it's the previous point where the slope changes
    to  - 1 and the slope now becomes 0 because of the addition of ai)
    Thus, the set of slope changing points is maintained. We have
    fi(Opt(i)) = fi - 1(Opt(i - 1)) + |Opt(i - 1) - ai|.
    */
    for (int i = 1; i <= N; i++) {
        int x;
        scanf("%d", &x);
        x -= i;
        pq.push(x);
        if (!pq.empty() && pq.top() > x) {
            ans += pq.top() - x;
            pq.pop();
            pq.push(x);
        }
    }
    printf("%lld\n", ans);
}