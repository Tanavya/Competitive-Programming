//Problem Link: https://uva.onlinejudge.org/external/105/p10576.pdf
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
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << "\n";
typedef long long int ll;
using namespace std;

vector <int> report;
int best = INT_MIN;
int s,d;
void rec(int m, int curr) {
    if (m >= 5 && report[m-1] + report[m-2] + report[m-3] + report[m-4] + report[m-5] > 0) return;
    if (m == 12) {
        best = max(curr, best);
    }
    else {
        for (int i: {s,d}) {
            report.push_back(i);
            rec(m+1, curr+i);
            report.pop_back();
        }
    }
}
int main() {
    while (scanf("%d %d", &s, &d) != EOF) {
        report = {};
        best = INT_MIN;
        d *= -1;
        rec(0, 0);        
        if (best < 0) cout << "Deficit\n";
        else cout << best << endl;
    }
}