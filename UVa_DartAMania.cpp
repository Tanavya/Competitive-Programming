//Problem Link: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=642&page=show_problem&problem=676
//Problem Type: Complete Search (Iterative)
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

inline bool achievable(int x) {
	return ( (x % 3 == 0 && x / 3 <= 20) || (x % 2 == 0 && x / 2 <= 20) || (x <= 20) || (x == 50));
}
int main() {
	int score = -1, a, b, c;
	while (true) {
		scanf("%d", &score);
		if (score <= 0) break;
		int permutation_count = 0;
		set <vector<int>> combinations;
		for (int i = 0; i <= 60; i++) {
			if (achievable(i)) {
				for (int j = 0; j <= 60; j++) {
					if (achievable(j)) {
						for (int k = 0; k <= 60; k++) {
							if (achievable(k)) {
								if (i + j + k == score) {
									permutation_count++;
									vector <int> combination = {i, j, k};
									sort(combination.begin(), combination.end());
									combinations.insert(combination);
								}
							}
						}	
					}
				}
			}
		}
		if (permutation_count) {
			printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n", score, (int)combinations.size());
			printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", score, permutation_count);
		}
		else printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", score);		
		printf("**********************************************************************\n");
	}
	printf("END OF OUTPUT\n");
}