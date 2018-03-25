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
using namespace std;

typedef pair <int, int> ii;
typedef pair <int, ii> iii;
vector <ii> fam;

int main() {

	int T, N, M, K, a, b, c;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d %d %d", &N, &M, &K);
		vector<vector<long> >graph(N+3,vector<long>(N+3,LONG_MAX));
		vector <vector<long>> DP(K+3, vector <long> (2, LONG_MAX));
		fam.clear();
		fam.resize(K+1);
		for (int i = 0; i < M; i++) {
			scanf("%d %d %d", &a, &b, &c);
			graph[a][b] = c;
			graph[b][a] = c;
		}

		for (int i = 1; i <= N; i++) {
			graph[i][i] = 0;
		}

		for (int k = 1; k <= N; k++) {
	        for (int i = 1; i <= N; i++) {
	            for (int j = 1; j <= N; j++) {
	            	if (graph[i][k] != LONG_MAX && graph[k][j] != LONG_MAX) graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
	            }
	        }
   	 	}
   	 	scanf("%d %d", &a, &b);
   	 	fam[1] = mp(a, b);
   	 	DP[0][0] = graph[1][a];
   	 	DP[1][0] = graph[1][a] + graph[a][b];
   	 	if (K == 1) {
   	 		if (DP[1][0] != LONG_MAX) printf("Case #%d: %ld\n", t, min(DP[K][0], DP[K][1]));
   	 		else printf("Case #%d: %d\n", t, -1);
   	 		continue;
   	 		
   	 	}
   	 	scanf("%d %d", &a, &b);
   	 	fam[2] = mp(a, b);
   	 	DP[2][0] = DP[1][0] + graph[fam[1].second][a] + graph[a][b];
   	 	DP[2][1] = graph[1][fam[1].first] + graph[fam[1].first][a] + graph[a][fam[1].second] + graph[fam[1].second][b];

   	 	long ans = LONG_MAX;
		for (int i = 3; i <= K; i++) {
			scanf("%d %d", &a, &b);
			if (graph[a][b] == LONG_MAX || graph[a][b] < 0) ans = -1;
			if (ans != -1)  {
				fam[i] = mp(a, b);
				DP[i][0] = min(DP[i-1][0], DP[i-1][1]) + graph[fam[i-1].second][a] + graph[a][b];
				DP[i][1] = min(DP[i-2][0], DP[i-2][1]) + graph[fam[i-2].second][fam[i-1].first] + graph[fam[i-1].first][a] + graph[a][fam[i-1].second] + graph[fam[i-1].second][b];
			}
		}
		assert(min(DP[K][0], DP[K][1]) > 0);
		printf("Case #%d: %ld\n", t, min(ans, min(DP[K][0], DP[K][1])));
	}
}