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
	int f, r, cnt = 0;
	while (true) {
		scanf("%d", &f);
		if (!f) break;
		//if (cnt > 0) cout << endl;
		//cnt++;
		scanf("%d", &r);
		int front[f], rear[r];
		double best = -1.0f;
		vector <double> drive_ratios;
		for (int i = 0; i < f; i++) {
			scanf("%d", &front[i]);
		}
		for (int i = 0; i < r; i++) {
			scanf("%d", &rear[i]);
		}

		for (int i = 0; i < f; i++) {
			for (int j = 0; j < r; j++) {
				drive_ratios.push_back((double)rear[j]/(double)front[i]);
			}
		}
		sort(drive_ratios.begin(), drive_ratios.end());
		for (int i = 0; i < drive_ratios.size()-1; i++) {
			if (drive_ratios[i+1] > drive_ratios[i]) best = max(best, drive_ratios[i+1]/drive_ratios[i]);
		}
		cout << setprecision(2) << fixed << best << endl;
	}
}