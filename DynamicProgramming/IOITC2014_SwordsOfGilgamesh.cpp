#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <assert.h>
#include <queue>
#include <set>

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
int D[maxn], T[maxn], dp[maxn];

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d %d", &T[i], &D[i]);
    }
    priority_queue <ii> pq;
    for (int i = 1; i <= N; i++) {
        dp[i] = max(dp[i], dp[i-1]);
        while (!pq.empty()) {
            int j = pq.top().se, val = pq.top().fi;
            if (D[j] > i-j-T[j]) {
                dp[i] = max(dp[i], val + i);
                break;
            }
            else pq.pop();
        }
        int nxt = min(maxn-1,i+T[i]+D[i]);
        dp[nxt] = max(dp[nxt], dp[i-1] + D[i]);
        pq.push(mp(dp[i-1]-i-T[i],i));
    }
    printf("%d\n", dp[N]);
}