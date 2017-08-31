#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <stdio.h>
#include <queue>
#include <set>
#include <bitset>
#include <cmath>
#include <assert.h>

using namespace std;
int T, n, cnt;
string line;
string forbidden[16];
bitset <30> rw, ld, rd;

void rec(int c) {
	if (c == n) cnt++;
	else for (int r = 0; r < n; r++) {
        if (!ld[r-c+n] && !rd[r+c] && !rw[r] && forbidden[r][c] == '.') {
            ld[r-c+n] = rd[r+c] = rw[r] = 1;
            rec(c+1);
            ld[r-c+n] = rd[r+c] = rw[r] = 0;
        }
	}
}
int main() {
	
	n = 1000;
	int t = 1;
	while (n) {
		scanf("%d", &n);
		if (n) {
			assert(n < 13);
			for (int i = 0; i < n; i++) {
				cin >> forbidden[i];
			}	
			cnt = 0;
			
			rec(0);
			printf("Case %d: %d\n", t, cnt);
			t++;
		}
	}
}
//..............