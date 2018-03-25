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
using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

int calc(string sub) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		if (sub[i] == '!') cnt++;
	}
	return cnt;
}
int main() {
	string s;
	cin >> s;
	int n = (int)s.length();
	string rep = s.substr(0, 4);
	for (int i = 0; i < n; i++) {
		if (s[i] != '!') rep[i % 4] = s[i];
	}
	if (n == 4) {
		if (calc(rep) == 1) {
			int in = 0;
			set <char> present = {'R', 'G', 'B', 'Y'} ;
			for (int i = 0; i < n; i++) {
				if (s[i] != '!') {
					present.erase(s[i]);
				}
				else in = i;
			}
			rep[in] = *present.begin();
		}
	}
	int ans[4] = {0, 0, 0, 0};
	for (int i = 0; i < n; i++) {
		if (s[i] == '!') {
			char c = rep[i % 4];
			if (c == 'R') ans[0]++;
			else if (c == 'B') ans[1]++;
			else if (c == 'Y') ans[2]++;
			else if (c == 'G') ans[3]++;
			else assert(false);
		}
	}
	for (int i = 0; i < 4; i++) printf("%d ", ans[i]);
	printf("\n");

}