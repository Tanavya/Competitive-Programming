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

int main() {
	int t, d, q, l, h, p;
	char s[21];
	string name;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &d);
		vector <pair<char[21], ii>> database(d);
		for (int i = 0; i < d; i++) {
			cin >> database[i].first;
			scanf("%d %d", &database[i].second.first, &database[i].second.second); 
		}
		scanf("%d", &q);
		for (int i = 0; i < q; i++) {
			scanf("%d", &p);
			int state = 0;
			for (int j = 0; j < d; j++) {
				int lb = database[j].second.first, ub = database[j].second.second;
				if (lb <= p && ub >= p) {
					if (state == 1) {
						printf("UNDETERMINED\n");
						state = 2;
						break;
					}
					else if (!state) {
						state = 1;
						name = database[j].first;
					}
				}
			}
			if (state == 0) printf("UNDETERMINED\n");
			else if (state == 1) cout << name << "\n";
		}
		if (t) printf("\n");
	}
}