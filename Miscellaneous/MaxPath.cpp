#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <stdio.h>
#include <queue>
#include <set>
#include <cmath>
#include <assert.h>
#include <bitset>
#define MAXN 1007
#define mp make_pair
#define ii pair<int, int>
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << "\n";
typedef long long int ll;
using namespace std;

long grid[3][100007] = {0};
vector <vector <long>> dist (3, vector <long> (100007, LONG_MAX));
priority_queue <pair<long, ii >, vector<pair<long, ii > >, greater<pair<long, ii > > > pq;

int main() {

	int n;
	scanf("%d", &n);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%ld", &grid[i][j]);
		}
	}
	dist[0][0] = 0;
	pq.push(mp(0, mp(0,0)));	
	while (!pq.empty()) {
		pair <long, ii> top = pq.top();
		pq.pop();
		long curr_dist = top.first;
		int a = top.second.first;
		int b = top.second.second;
		if (a == 2 && b == n-1) {
			printf("ld\n", curr_dist);
			return 0;
		}
		if (a > 0) {
			if (dist[a-1][b] > curr_dist + grid[a-1][b]) {
				dist[a-1][b] = curr_dist + grid[a-1][b];
				pq.push(mp(dist[a-1][b], mp(a-1, b)));
			}
		}
		if (a < 2) {
			if (dist[a+1][b] > curr_dist + grid[a+1][b]) {
				dist[a+1][b] = curr_dist + grid[a+1][b];
				pq.push(mp(dist[a+1][b], mp(a+1, b)));
			}
		}
		if (b > 0) {
			if (dist[a][b-1] > curr_dist + grid[a][b-1]) {
				dist[a][b-1] = curr_dist + grid[a][b-1];
				pq.push(mp(dist[a][b-1], mp(a, b-1)));
			}
		}
		if (b < n-1) {
			if (dist[a][b+1] > curr_dist + grid[a][b+1]) {
				dist[a][b+1] = curr_dist + grid[a][b+1];
				pq.push(mp(dist[a][b+1], mp(a, b+1)));
			}
		}
	}



}