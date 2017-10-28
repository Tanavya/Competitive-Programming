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
 

#define MAX(a,b) ((a)>(b)?(a):(b))
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << endl;
#define debug(x) cout << x << endl;
#define debug2(x,y) cout << x << " " << y << endl;
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

 
const int mod = 1e9+7;

long double cross(pair<ll, ll> a, pair<ll, ll> b)
{
    return abs((a.first*b.second)-(b.first*a.second))/2.;
}
void solve()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //cout.tie(0);
    
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector< pair<ll, ll> > v(n+7);
        for(ll i = 0;i<n;i++)
            cin>>v[i].first>>v[i].second;
        long double dp[(1<<n)+7][n+7];
        memset(dp, 0, sizeof(dp));
        for(ll i = 0;i < (1<<n);i++)
            for(ll j = 0;j<n;j++)
                if(i&(1<<j))
                    for(ll k = 0;k<n;k++)
                        if((i&(1<<k))&&k!=j)
                            dp[i][j] = max(dp[i][j], dp[i^(1<<j)][k]+cross(v[j], v[k]));
        long double ans = 0;
        for(ll i = 0;i<n;i++)
            ans = max(ans, dp[(1<<n)-1][i]);
        cout<<fixed<<setprecision(9)<<ans<<endl;
    }
}

void gentc(int t) {

	int T = 5;
	cout << T << endl;
	while (T--) {
		int N;
		if (t < 5) {
			N = 9;
		}
		else {
			N = 15;
		}
		cout << N << endl;
		for (int i = 0; i < N; i++) {
			int x = (rand() % 1000);
			if (rand() % 2) x *= -1;
			int y = (rand() % 1000);
			if (rand() % 2) y *= -1;
			printf("%d %d\n", x, y);
		}
	}
}


int main() {
	srand(time(NULL));
    
    for (int i = 0; i < 10; i++) {
        string loc = "input/input" + to_string(i) + ".txt";
        freopen(loc.c_str(), "w", stdout);
        gentc(i);
    }
    
    for (int i = 0; i < 10; i++) {
        string loc = "input/input" + to_string(i) + ".txt";
        freopen(loc.c_str(), "r", stdin);
        loc = "output/output" + to_string(i) + ".txt";
        freopen(loc.c_str(), "w", stdout);
        solve();
    }

}