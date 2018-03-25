//Problem Link: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=661&page=show_problem&problem=3344
//Problem type: Greedy (Load Balancing)
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

int main() {
    
    int n,d,r;
    while (true) {
        scanf("%d %d %d", &n, &d, &r);
        if (!n && !d && !r) break;
        vector <int> morn(n), eve(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &morn[i]);
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &eve[i]);
        }
        sort(morn.begin(), morn.end());
        sort(eve.begin(), eve.end());
        int overtime = 0;
        for (int i = 0; i < n; i++) {
            int val = morn[i] + eve[n-1-i];
            if (val > d) {
                overtime += (val-d) * r;
            }
        }
        printf("%d\n", overtime);
    }
}