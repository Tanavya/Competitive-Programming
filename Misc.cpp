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

const int maxn = (int) 1e5+10;
ll V[maxn], T[maxn], S[maxn];

int last[maxn], lolol[maxn*2];

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        cin >> V[i];
    }
    vector <ll> lol;
    for (int i = 1; i <= N; i++) {
        cin >> T[i];
        S[i] = S[i-1] + T[i];
        lol.pb(S[i]);
    }
    for (int i = 1; i <= N; i++) {
        last[i] = 1+int(lower_bound(all(lol), V[i] + S[i-1]) - lol.begin());
        lolol[last[i]] = i;
    }
    priority_queue <pair<int,ll>, vector <pair<int,ll>>, greater<pair<int,ll>>> pq;
    vector <ll> ans;
    for (int i = 1; i <= N; i++) {
        pq.push(mp(last[i],i));
        ll sum = 0;
        while (!pq.empty() && last[pq.top().second] == i) {
            sum += V[pq.top().second];
            pq.pop();
        }
        sum += pq.size() * T[i];
        cout << sum << endl;
    }
    print(ans);
}