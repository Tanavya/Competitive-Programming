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

void gentcs (int T) {
    srand(time(NULL));
    cout << T << endl;
    while (T--) {
        int p = (rand() % 21);
        int r = (rand() % 21);
        int q = (rand() % 21) * -1;
        int s = (rand() % 21) * -1;
        int t = (rand() % 21) * -1;
        assert (p <= 20);
        cout << p << " " << q << " " << r << " " << s << " " << t << endl;
    }
}


int main() {
    /*
    for (int i = 0; i <= 5; i++) {
        string loc = "input/" + to_string(i) + ".txt";
        freopen(loc.c_str(), "w", stdout);
        if (i == 0) {
            cout << 3 << endl;
            cout << "0 0 0 0 -2 1\n
1 0 0 0 -1 2\n
1 -1 1 -1 -1 1\n";
        }
        if (i == 1)
            gentcs(800);
        else
            gentcs(1e6);
    }
    for (int i = 0; i <= 5; i++) {
        freopen("")
    }

    #ifndef ONLINE_JUDGE 
        freopen("inp.txt", "r", stdin);
    #endif
    */
    int p,q,r,s,t,u;
    while (scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) != EOF) {
        
        double lo = 0.0, hi = 1.0, x, val;
        for (int i = 0; i < 50; i++) {
            x = (lo + hi) / 2;
            val = p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
            if (val > 0) lo = x;
            else hi = x;
        }
        
        if (val > EPS || val < -EPS) printf("No solution\n");
        else cout << setprecision(4) << fixed << x << endl;

    }
}