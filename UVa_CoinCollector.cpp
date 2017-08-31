//Problem Link: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=661&page=show_problem&problem=3344
//Problem type: Greedy
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

int t, n;
int withdraw(ll x, vector <int> coins) {
    int used = 0;
    for (int i = n-1; i >= 0; i--) {
        if (coins[i] <= x) {
            used++;
            x %= coins[i];
        }
    }
    return used;
}
int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        ll x = 0;
        vector <int> coins(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &coins[i]);
        }
        ll amt = coins[0];
        int used = 1;
        for (int i = 1; i < n-1; i++) {
            if (amt + coins[i] < coins[i+1]) { //take this coin
                used++;
                amt += coins[i];
            }
        }
        printf("%d\n", used+1);
    }
}