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

int main() {
    //2100 * 40 * 
    int p,q,r,s,t,u;
    //cout << log2(1/EPS) << endl;
    while (scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) != EOF) {
        //double x = 0.7554;
        //double val = p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
        //cout << val << endl;
        //p∗e^−x +q∗sin(x)+r∗cos(x)+s∗tan(x)+t∗x2 +u=0
        
        
        double lo = 0.0, hi = 1.0, x, val;
        for (int i = 0; i < 50; i++) {
            x = (lo + hi) / 2;
            val = p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
            //cout << "x: " << x << " val: " << val << endl;
            if (val > 0) lo = x;
            else hi = x;
        }
        
        if (val > EPS || val < -EPS) printf("No solution\n");
        else cout << setprecision(4) << fixed << x << endl;

        //cout << p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u << endl;
        

    }
}