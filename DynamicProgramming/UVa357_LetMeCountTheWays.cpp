//Problem Link: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3836
//Problem type: Dynamic Programming
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
    vector <int> coins = {1, 5, 10, 25, 50};
    int m = 5, n;
    while (scanf("%d", &n) != EOF) {
        vector <ll> ways(n+1, 0);
        ways[0] = 1;
        for (int i = 0; i < m; i++) { //ORDER MATTERS2
            for (int j = coins[i]; j <= n; j++) {
                ways[j] += ways[j-coins[i]];
                //printf("ways[%d][%d] = %lld\n", i, j, ways[j]);
            }
        }
        //printf("Number of ways to form %d is %lld\n", n, ways[n]);
        if (ways[n] == 1) printf("There is only 1 way to produce %d cents change.\n", n);
        else printf("There are %lld ways to produce %d cents change.\n", ways[n], n);
    }
    
}