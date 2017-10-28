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

const int maxn = 2e5+7;
int T[maxn], R[maxn], P[maxn][21];
int main() {

	#ifndef ONLINE_JUDGE
		freopen("inp.txt", "r", stdin);
	#endif

	int N, M;
	scanf("%d %d", &N, &M);

	vector <ii> contests;

	map <int, int> times;
	map <int, int> MAP;

	int x, p, t, r;
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &T[i], &R[i]);
		contests.pb({T[i], R[i]});
		times[T[i]] = i;
	}
	
	sort(contests.begin(), contests.end());

	for (int i = 0; i < N; i++) {
		MAP[times[contests[i].x]] = i;
	}

	/*
	for (int i = 0; i < N; i++) debug2(contests[i].x, contests[i].y); cout << endl;
	for (int i = 0; i < N; i++) debug2(i, MAP[i]); 	cout << endl;*/

	
	for (int i = 0; i <= 21; i++) {
		for (int u = 0; u < N; u++) {
			P[u][i] = -1;
		}
	}
	
	vector <vi> tree(N+1);
	
	priority_queue <ii, vector <ii>, greater <ii>> pq;
	for (int i = 0; i < N; i++) {
		while (!pq.empty()) {
			ii curr = pq.top();
			if (curr.x < contests[i].y) {
				pq.pop();
				P[curr.y][0] = i;
				tree[i].pb(curr.y);
			}
			else break;
		}
		pq.push({contests[i].y, i});
	}
	
	
	for (int i = 1; i < 21; i++) {
		for (int u = 0; u < N; u++) {
			if (P[u][i-1] != -1) {
				P[u][i] = P[P[u][i-1]][i-1];
 			}
		}
	}

	
	for (int i = 0; i < M; i++) {

		scanf("%d %d", &x, &p);
		x--;
		int u = MAP[x];
		int s = 0;
		for (int i = 21; i >= 0; i--) {
			if (P[u][i] != -1 && s + (1 << i) <= p) {
				s += (1 << i);	
				u = P[u][i];	
			}
		}
		printf("%d\n", contests[u].y);
	}
}