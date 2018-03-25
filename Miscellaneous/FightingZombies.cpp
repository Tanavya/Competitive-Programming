#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <stdio.h>
#include <queue>
#include <set>
#include <unordered_set>
#include <cmath>
#include <assert.h>
#include <bitset>
#define MAXN 1007
#define mp make_pair
#define print(arr) for(auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << endl;
using namespace std;
typedef pair <int, int> ii;

vector <ii> points;
vector <unordered_set<int>> sets;
int main() {
	freopen("fighting_the_zombies.txt","r",stdin);
    freopen("out1.txt","w",stdout);
	int T, N, R, a, b;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d %d", &N, &R);
		points.clear();
		sets.clear();
		for (int i = 0; i < N; i++) {
			scanf("%d %d", &a, &b);
			points.push_back(mp(a,b));
		}
		for (int i = 0; i < N; i++) {
			for (int j = i+1; j < N; j++) {
				if (abs(points[i].first - points[j].first) <= R && abs(points[i].second - points[j].second) <= R) {
					float x = (float)(points[i].first + points[j].first)/2.0;
					float y = (float)(points[i].second + points[j].second)/2.0;
					unordered_set <int> s;
					for (int k = 0; k < N; k++) {
						if (abs(points[k].first - x) <= (float)R/2.0 && abs(points[k].second - y) <= (float)R/2.0) s.insert(k);
					}
					sets.push_back(s);
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < sets.size(); i++) {
			for (int j = i+1; j < sets.size(); j++) {
				if (sets[i].size() + sets[j].size() > ans) { 
					unordered_set <int> s = sets[i];
					for (auto it = sets[j].begin(); it != sets[j].end(); ++it) {
						s.insert(*it);
					}
					ans = max(ans, (int)s.size());
				}
			}
		}
		if (ans == 0) ans = 2;
		printf("Case #%d: %d\n", t, ans);
	}
}