#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <stdio.h>
#include <queue>
#include <set>
#include <cmath>
#include <assert.h>

using namespace std;
vector <vector<int> > grid;
int T, d, n, r, c, size;

int main() {

	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		grid = vector <vector<int> > (1030, vector<int> (1030, 0));
		scanf("%d", &d);
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d %d %d", &c, &r, &size);
			for (int j = max(0, r-d); j <= r+d && j < 1025; j++) {
				for (int k = max(0, c-d); k <= c+d && k < 1025; k++) {
					grid[j][k] += size;
				}
			}
		}
		int best_val = -1, best_r = 0, best_c = 0;
		for (int j = 0; j < 1025; j++) {
			for (int i = 0; i < 1025; i++) {
				if (grid[i][j] > best_val) {
					best_val = grid[i][j];
					best_r = i;
					best_c = j;
				}
			}
		}
		printf("%d %d %d\n", best_c, best_r, best_val);
	}
}

