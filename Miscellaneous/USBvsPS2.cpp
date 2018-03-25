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
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << "\n";
typedef long long int ll;
using namespace std;

int main() {
	int u, p, b, m, equiped = 0;
	string type;
	ll val, cost = 0;
	vector <int> USB, PS2, rest;
	vector <pair<int, int>> vals;
	scanf("%d %d %d %d", &u, &p, &b, &m);
	for (int i = 0; i < m; i++) {
		scanf("%lld", &val);
		cin >> type;
		if (type == "USB") vals.push_back(make_pair(val, 0));
		else vals.push_back(make_pair(val, 1));

	}
	sort(vals.begin(), vals.end());
	int u_count = u;
	int b_count = b;
	int p_count = p;
	for (int i = 0; i < m; i++) {
		if (vals[i].second == 0 && u_count > 0) {
			cost += vals[i].first;
			u_count--;
			equiped++;
		}
		else if (vals[i].second == 0 && b_count > 0) {
			cost += vals[i].first;
			b_count--;
			equiped++;
		}
		else if (vals[i].second == 1 && p_count > 0) {
			cost += vals[i].first;
			p_count--;
			equiped++;
		}
		else if (vals[i].second == 1 && b_count > 0) {
			cost += vals[i].first;
			b_count--;
			equiped++;
		}
	}
	printf("%d %lld\n", equiped, cost);
}