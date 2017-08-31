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

using namespace std;
typedef pair <int, int> ii;
typedef pair <int, ii> iii;
vector <ii> graph[MAXN];
int A[MAXN];
vector <vector<int>> dist(MAXN, vector<int> (1025, INT_MAX));
priority_queue <iii, vector <iii>, greater <iii>> pq;
int N, M, K, T, x, y, z;
int main() {

	scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i < N; i++) {
		scanf("%d", &T);
		bitset <10> tmp;
		for (int j = 0; j < T; j++) {
			scanf("%d", &x);
			tmp[x-1] = 1;
		}
		A[i] = (int)tmp.to_ulong();
	}
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &x, &y, &z);
		x--; y--;
		graph[x].push_back(make_pair(y,z));
		graph[y].push_back(make_pair(x,z));
	}
	pq.push(make_pair(0, make_pair(0, A[0])));
	while (!pq.empty()) {
		iii top = pq.top();
		pq.pop();
		int curr_dist = top.first;
		int curr_node = top.second.first;
		int curr_mask = top.second.second;
		for (auto it = graph[curr_node].begin(); it != graph[curr_node].end(); ++it) {
			int adj = (*it).first;
			int weight = (*it).second;
			int next_mask = curr_mask | A[adj];
			if (dist[adj][next_mask] > curr_dist+weight) {
				dist[adj][next_mask] = curr_dist+weight;
				pq.push(make_pair(curr_dist+weight, make_pair(adj, next_mask)));
			}
		}
	}
	int target = (1 << K) - 1;
	int ans = INT_MAX;
	for (int i = 0; i <= target; i++) {
		for (int j = 0; j <= target; j++) {
			if ((i | j) == target) {
				ans = min(ans, max(dist[N-1][i], dist[N-1][j]));
			}
		}
	}
	printf("%d\n", ans);

}