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
#include <iomanip> //cout << setprecision(n) << fixed << num
#include <unordered_map>
#define MAXN 1007
#define mp make_pair
#define ii pair<int, int>
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << "\n";
typedef long long int ll;
using namespace std;

int main() {
	int m;
	string col;
	while (scanf("%d", &m) != EOF) {
		vector <ii> start, end;
		for (int i = 0; i < m; i++) {
			cin >> col;
			for (int j = 0; j < m; j++) {
				if (col[j] == '1') start.push_back(mp(i,j));
				else if (col[j] == '3') end.push_back(mp(i,j));
			}
		}
		int min_required = -1;
		for (int i = 0; i < start.size(); i++) {
			int closest = INT_MAX;
			for (int j = 0; j < end.size(); j++) {
				int a = start[i].first, b = start[i].second, c = end[j].first, d = end[j].second;
				closest = min(closest, abs(a-c) + abs(b-d));
			}
			min_required = max(min_required, closest);
		}
		printf("%d\n", min_required);
	}
}