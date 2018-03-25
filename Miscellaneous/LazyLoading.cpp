#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <stdio.h>
#include <queue>
#include <set>
#include <cmath>
#include <set>
#include <assert.h>
#define print(arr) for (auto i = arr.begin(); i != arr.end(); ++i) cout << *i << " "; cout << endl;

using namespace std;

int main() {

	int T, N, val;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d", &N);
		//vector <int> vals_count(101, 0);
		int ans = 0;
		vector <int> vals;
		for (int i = 0; i < N; i++) {
			scanf("%d", &val);
			vals.push_back(val);
		}
		sort(vals.rbegin(), vals.rend());
		//print(vals);
		for (int i = 0; i < vals.size(); i++) {
			int reqd = ceil(50.0/(double)vals[i]);
			//cout << reqd << " " << i << " " << vals[i] << endl;
			int cnt = 1;
			for (int j = vals.size() - 1; j > i && cnt < reqd; j--) {
				vals.pop_back();
				cnt++;
			}
			if (cnt == reqd) ans++;
			//print(vals);
		}
		cout << "Case #" << t << ": " << ans << endl;
	}

}