//Problem Link: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3836
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
string gen(int n) {
    string s = "";
    for (int i = 0; i < n; i++) {
        if (rand() % 3) s += ".";
        else s+= "#";
    }
    return s;
}
int main() {
    //srand(time(NULL));
    int T, n;
    string field;
    scanf("%d", &T);
    //T = 10;
    for (int t = 1; t <= T; t++) {
        scanf("%d", &n);
        //n = rand() % 16;
        //cout << n << endl;
        cin >> field;
        //field = gen(n);
        //cout << field << endl;
        int used = 0;
        bitset <107> covered;
        for (int i = 0; i < n; i++) {
            if (field[i] == '#') covered[i] = 1;
        }
        for (int i = 0; i < n; i++) {
            if (!covered[i]) {
                covered[i] = covered[i+1] = covered[i+2] = 1;
                used++;
            }
        }
        printf("Case %d: %d\n", t, used);
    }
}