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
	int k = -1, cnt = 0;
	while (true) {
		scanf("%d", &k);
		if (!k) break;
		if (cnt) printf("\n");
		cnt++;
		int S[k];
		for (int i = 0; i < k; i++) {
			scanf("%d", &S[i]);
		}
		for (int a = 0; a < k; a++) 
			for (int b = a+1; b < k; b++) 
				for (int c = b+1; c < k; c++) 
					for (int d = c+1; d < k; d++)
						for (int e = d+1; e < k; e++)
							for (int f = e+1; f < k; f++)
								printf("%d %d %d %d %d %d\n", S[a], S[b], S[c], S[d], S[e], S[f]);
	}
}