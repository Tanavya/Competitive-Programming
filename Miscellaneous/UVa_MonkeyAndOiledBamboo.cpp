//Problem Link: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=661&page=show_problem&problem=3344
//Problem type: D&C Bisection Method
//Learning Exp: 

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
#define EPS 1e-9
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << "\n";
typedef long long int ll;
using namespace std;

int T, n;
bool sim(vector <int> vals, int k) {
    if (vals[0] > k) return false;
    if (k == vals[0]) k--;
    for (int i = 1; i < n; i++) {
        if (vals[i] - vals[i-1] > k) return false;
        if (vals[i] - vals[i-1] == k) k--;
        //if (k <= 0) return false;
    }

    return true;
}
int main() {
    //n = 5;
    //cout << sim({3,7,9,10,11}, 3) << endl;
    //return 0;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        scanf("%d", &n);
        vector <int> vals(n);
        int lo, hi = 0, ans, mid;
        for (int i = 0; i < n; i++) {
            scanf("%d", &vals[i]);
            if (i == 0) hi = vals[i];
            else hi = max(hi, vals[i]-vals[i-1]);
        }
        hi += n;
        lo = vals[0];
        while (hi >= lo) {
            mid = (hi+lo)/2;
            if (sim(vals,mid)) {
                ans = mid;
                hi = mid-1;
            }
            else {
                lo = mid+1;
            }
        }
        printf("Case %d: %d\n", t, ans);
        //if (t < T) printf("\n");
    }
}
/*
2
60 90
21
99 125 173 266 328 332 377 381 461 556 651 736 819 876 965 1013 1038 1064 1137 1186 1197
7
8 50 93 187 284 356 362
*/