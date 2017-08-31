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
 
const int max_time = 1e6 + 10007;
const int max_q = 1e5 + 7;
int main() {

    int N, Q;
    scanf("%d %d", &N, &Q);
    vector <vi> used(max_time);
    vi time_start(max_time, -1), num_servers(max_q, -1), time_needed(max_q, -1);
    priority_queue <int, vector <int>, greater<int>> pq;
    for (int i = 1; i <= N; i++) {
        pq.push(i);
    }
    for (int q = 0; q < Q; q++) {
        int t;
        scanf("%d %d %d", &t, &num_servers[q], &time_needed[q]);
        time_start[t] = q;
    }
    for (int t = 0; t < max_time; t++) {
        for (int to_add : used[t]) {
            pq.push(to_add);
        }
        if (time_start[t] != -1) {
            int q = time_start[t];
            int k = num_servers[q];
            int d = time_needed[q];
            int ans = 0;
            if (k > pq.size()) {
                ans = -1;
            }
            else {
                for (int i = 0; i < k; i++) {
                    int n = pq.top();
                    pq.pop();
                    ans += n;
                    used[t+d].pb(n);
                }
            }
            printf("%d\n", ans);
        }
    }
}