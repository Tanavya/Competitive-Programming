//Problem Link: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=646&page=show_problem&problem=515
//Problem type: Complete Search

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
#include <unordered_map>
#include <unordered_set>
#include <iomanip> //cout << setprecision(n) << fixed << num

using namespace std;

int n = -1, t;
int nums[12];
vector <int> ans;
set <vector<int>> ans_set;
void rec(int i, int sum) {
    if (i == n && sum != 0) return;
    else if (i == n) {
        if (ans_set.find(ans) == ans_set.end()) {
            for (int j = 0; j < ans.size(); j++) {
                if (j) printf("+");
                printf("%d", ans[j]);
            }
            printf("\n");
            ans_set.insert(ans);
        }
    }
    else if (sum < nums[i]) rec(i+1, sum);
    else {
        ans.push_back(nums[i]);
        rec(i+1, sum-nums[i]);
        ans.pop_back();
        rec(i+1, sum);
    }
}
int main() {
    while (true) {
        scanf("%d %d", &t, &n);
        if (!n) break;
        for (int i = 0; i < n; i++) {
            scanf("%d", &nums[i]);
        }
        printf("Sums of %d:\n", t);
        ans_set.clear();
        rec(0, t);
        if (ans_set.empty()) printf("NONE\n");
    }
}