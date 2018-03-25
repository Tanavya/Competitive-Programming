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

int n, m;
bool sim(vector <int> &vals, int c) {
    int cap = c, used = 0;

    for (int i = 0; i < n-1 && used < m; i++) {
        cap -= vals[i];
        if (cap < 0) return false;
        if (cap - vals[i+1] < 0) {
            //cout << "Used at index " << i << endl;
            cap = c;
            used++;
        }
    }
    used++;
    //cout << "Number used: " << used << endl;
    if (used > m || cap - vals[n-1] < 0) return false;
    else return true;
}

int main() {
    
    while (scanf("%d %d", &n, &m) != EOF) {
        
        vector <int> vals(n);
        int hi = 0, lo = 0, mid, ans;
        for (int i = 0; i < n; i++) {
            scanf("%d", &vals[i]);
            hi += vals[i];
        }
        while (hi >= lo) {
            mid = (hi+lo)/2;
            //cout << "hi: " << hi << " lo: " << lo << " mid: " << mid << endl;
            if (sim(vals, mid)) {
                hi = mid-1;
                ans = mid;
            }
            else lo = mid+1;
        }
        printf("%d\n", ans);
        //cout << "hi: " << hi << " lo: " << lo << " mid: " << (hi+lo)/2 << endl;

    }


}
