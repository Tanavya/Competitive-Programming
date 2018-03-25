//Problem Link: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=643&problem=1601&mosmsg=Submission+received+with+ID+18687614
//Problem type: Complete Search

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
#include <map>
#include <unordered_map>
#include <iomanip> //cout << setprecision(n) << fixed << num

#define MAXN 1007
#define mp make_pair
#define ii pair<int, int>
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << "\n";
typedef long long int ll;
using namespace std;

inline int calc(int a, int b) {
	int x1 = a/5, y1 = a%5, x2 = b/5, y2 = b%5;
	return abs(x1-x2) + abs(y1-y2);
}
int main() {
	//freopen("inp.in","r",stdin);
    //freopen("output.txt","w",stdout);
	int t, x, y, m;
	scanf("%d", &t);
	while (t--) {
		vector <int> grid (25, 0);
		scanf("%d", &m);
		for (int i = 0; i < m; i++) {
			scanf("%d %d", &x, &y);
			scanf("%d", &grid[x*5 + y]);
		}
		vector <int> ans;
		int min_dist = INT_MAX;
		for (int a = 0; a < 25; a++) {
			for (int b = a+1; b < 25; b++) {
				for (int c = b+1; c < 25; c++) {
					for (int d = c+1; d < 25; d++) {
						for (int e = d+1; e < 25; e++) {
							int total_dist = 0;
							for (int area = 0; area < 25; area++) {
								int dist = INT_MAX;
								if (!grid[area]) continue;
								for (int office: {a,b,c,d,e}) {
									dist = min(dist, calc(area, office));
								}
								total_dist += (dist * grid[area]);
							}
							if (total_dist < min_dist) {
								min_dist = total_dist;
								ans = {a,b,c,d,e};
							}
						}
					}
				}
			}
		}
		for (int i = 0; i < 5; i++) {
			printf("%d", ans[i]);
			if (i < 4) printf(" ");
			else printf("\n");
		}
	}
}
