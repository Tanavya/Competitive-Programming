//Problem Link: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=645&page=show_problem&problem=2026
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

#define mp make_pair
#define ii pair<int, int>
#define PI 3.14159265
#define INF 1000000000000000000LL
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it+1 << " "; cout << "\n";
typedef long long int ll;
using namespace std;

vector <vector<int>> all_arrangements;
vector <int> row;
bitset <30> rw, ld, rd;
int cnt = 0;
void rec(int c) {
    if (c == 8) {
        all_arrangements.push_back(row);
    }
    else for (int r = 0; r < 8; r++) {
        if (!ld[r-c+8] && !rd[r+c] && !rw[r]) {
            ld[r-c+8] = rd[r+c] = rw[r] = 1;
            row.push_back(r);
            rec(c+1);
            ld[r-c+8] = rd[r+c] = rw[r] = 0;
            row.pop_back();
        }
    }
}

int main() {
    rec(0);
    int a, tc = 1;
    while (scanf("%d", &a) != EOF) {
        int row[8];
        row[0] = a;
        for (int i = 1; i < 8; i++) {
            scanf("%d", &row[i]);
        }
        int best = INT_MAX;
        for (vector <int> arrangement: all_arrangements) {
            int curr = 0;
            for (int i = 0; i < 8; i++) {
                if (arrangement[i]+1 != row[i]) curr++;
            }
            best = min(best, curr);
        }
        printf("Case %d: %d\n", tc, best);
        tc++;
    }
}