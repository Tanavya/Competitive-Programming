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
int T, a, b, cnt = 1;
vector <int> row;
bitset <30> rw;
bitset <30> ld[2];
bitset <30> rd[2];
bool place(int r, int c) {
	for (int prev = 0; prev < c; prev++) {
		if (row[prev] == r || abs(row[prev] - r) == abs(prev - c)) return false;
	}
	return true;
}

void rec(int c) {
	if (c == 8) {
		printf("%2d     ", cnt);
		cnt++;
		for (int i = 0; i < 8; i++) printf(" %d", row[i]+1);
		printf("\n");
	} 
	for (int r = 0; r < 8; r++) {
		if (place(r,c)) {
			if (c == b && r != a) continue;
			row.push_back(r);
			rec(c+1);
			row.pop_back();
		}
	}
}
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &a, &b);
		a--; b--;
		printf("SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n\n");
		cnt = 1;
		row = {};
		rec(0);
		if (T) printf("\n");
	}
}