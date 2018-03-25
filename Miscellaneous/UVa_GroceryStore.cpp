//Problem Link: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=643&page=show_problem&problem=2177
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
#include <iomanip> //cout << setprecision(n) << fixed << num

#define MAXN 1007
#define mp make_pair
#define ii pair<int, int>
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << "\n";
typedef long long int ll;
using namespace std;

int main() {
	//freopen("output.out", "w", stdout);
    int cunt = 0;
    for (int a = 1; a*4 <= 2000; a++) {
        for (int b = a; a+3*b <= 2000; b++) {
            for (int c = b; a+b+2*c <= 2000; c++) {
                ll x = a+b+c;
                ll y = a*b*c;
                if (y <= 1000000) continue;                
                ll d = (1000000*x)/(y-1000000);
                if (d < c || x + d > 2000) continue;
                if ( abs( (x + d) / 100.0 - ( y * d) / 100000000.0) < 1e-9 ) {
                    cout << setprecision(2) << fixed << a/100.0 <<  " " << b/100.0 << " " << c/100.0 << " " << d/100.0 << endl;
                    cunt++;
                }
			}
		}
	}
	return 0;
}