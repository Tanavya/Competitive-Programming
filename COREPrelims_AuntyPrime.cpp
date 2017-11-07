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
typedef unsigned long long int ull;
typedef std::pair <int, int> ii;
typedef std::vector <int> vi;
typedef std::vector <ll> vll;
//const int INF = int(1e9);
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
using namespace std;


const int INF = int(2e9+7);
int N;
ll dp[15][2000];
ll power[50][60];
vector <int> primes = {2,3,5,7,11,13,17,19,23,29,31,37,41};
ll rec(int pf, int div) {
    ll &ret = dp[pf][div];
    if (ret != 0) return ret;
    ret = INF;
    for (int i = 0; i <= 60; i++) {
        if (power[primes[pf]][i] != 0) {
            if (pf == 0) {
                if (div == (i+1)) 
                    ret = min(ret, power[primes[pf]][i]);
            }
            else {
                if (div % (i+1) == 0) {
                	if (power[primes[pf]][i] * rec(pf-1, div/(i+1)) <= INF) 
                    	ret = min(ret, power[primes[pf]][i] * rec(pf-1, div/(i+1)));
                    else 
                    	ret = INF;
                }
            }
        }
    }
    return ret;
}
int main() {
	#ifndef ONLINE_JUDGE
		freopen("inp.txt", "r", stdin);
	#endif
	scanf("%d", &N);

	for (int x = 0; x < 10; x++) {
        int prime = primes[x];
        power[prime][0] = 1;
        for (int p = 1; p <= 60; p++) {
            if (power[prime][p-1] * prime <= INF)
                power[prime][p] = power[prime][p-1] * prime;
            else 
                power[prime][p] = 0;
        }
    }

    /*
    int n = 0;
    int div = 1;
    int ans = 0;
    while (true) {
    	div++;
    	if (div > 1600) break;
    	n = rec(9, div);
    	//if (n <= N)
    	//	ans = n;
    	//else {
    		cout << n << " " << div << endl;
    	//	break;
    	//}
    }
    cout << ans << endl;
    */
}