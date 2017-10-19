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

vector <vector <ll>> pre;
vector <ll> total;
ll best(int i, int a, int b) {
	ll ret = min(abs(pre[i][a] - pre[i][b]), total[i] - abs(pre[i][a] - pre[i][b]));
	//assert(ret >= 0);
	return ret;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("inp.txt", "r", stdin);
	#endif
	int T;
	scanf("%d", &T);
	while (T--) {
		int N, Q;
		scanf("%d %d", &N, &Q);
		pre.assign(N+7, {});
		total.assign(N+7, 0);
		int an;
		for (int i = 1; i <= N; i++) {
			scanf("%d", &an);
			pre[i] = vll(an+1, 0);
			for (int j = 2; j <= an; j++) {
				scanf("%lld", &pre[i][j]);
				pre[i][j] += pre[i][j-1];
			}
			scanf("%lld", &total[i]);
			total[i] += pre[i][an];
		}
		vector <pair<ii, ll>> f_conn(N+7), b_conn(N+7);
		vector <ll> f_pre_conn (N+1, 0);
		int u,v;
		ll w;
		for (int i = 1; i <= N; i++) {
			scanf("%d %d %lld", &u, &v, &w);
			f_conn[i] = mp(mp(u,v),w);
		}
		for (int i = 1; i <= N; i++) {
			if (i == 1)
				b_conn[i] = mp(mp(f_conn[N].x.y, f_conn[N].x.x), f_conn[N].y);
			else
				b_conn[i] = mp(mp(f_conn[i-1].x.y, f_conn[i-1].x.x), f_conn[i].y);
		}


		for (int i = 1; i <= N; i++) {
			int out1 = f_conn[i].x.x;
			int out2 = b_conn[i].x.x;
			//assert(out1 != out2);
			//printf("total[%d] = %lld\n", i, total[i]);
			f_pre_conn[i] = best(i, out1, out2);
			//cout << pre[i][out1] << " " << pre[i][out2] << endl;
			//cout << out1 << " " << out2 << endl;
			//cout << best << endl;
			f_pre_conn[i] += f_pre_conn[i-1] + f_conn[i].y;
		}

		//for (int i = 1; i <= N; i++) cout << f_pre_conn[i] << " "; cout << endl;

		//cout << f_conn[2].x.x << endl;
		int v1, v2, c1, c2;
		for (int q = 0; q < Q; q++) {


			scanf("%d %d %d %d", &v1, &c1, &v2, &c2);

			if (c2 < c1) {
				swap(c1, c2);
				swap(v1, v2);
			}


			//assert(c1 != c2);
			int e11 = f_conn[c1].x.x;
			int e12 = b_conn[c1].x.x;

			int e21 = f_conn[c2].x.x;
			int e22 = b_conn[c2].x.x;

			ll opt1 = abs(f_pre_conn[c2-1] - f_pre_conn[c1-1]) 
			- best(c1, e11, e12) + best(c1, e11, v1) 
			+ best(c2, e22, v2);

			ll opt2 = f_pre_conn[N] - abs(f_pre_conn[c2-1] - f_pre_conn[c1-1])
			+ best(c1, e12, v1)
			- best(c2, e21, e22) + best(c2, e21, v2);
			//cout << abs(f_pre_conn[c2-1] - f_pre_conn[c1-1]) << " " << best(c1, e11, e12) << " " << best(c1, e11, v1) <<
			//  " "  << best(c2, e21, e22) << " " << best(c2, e21, v2) << endl;
			//cout << opt1 << " " << opt2 << endl;

			//cout << f_pre_conn[N] << " " << abs(f_pre_conn[c2-1] - f_pre_conn[c1-1]) << endl;
			//cout << f_pre_conn[N] - abs(f_pre_conn[c2-1] - f_pre_conn[c1-1]) << endl;
			assert(opt1 > 0 && opt2 > 0);
			cout << min(abs(opt1), abs(opt2)) << endl;
		}
	}
}