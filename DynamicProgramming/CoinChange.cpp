//Problem Link: https://www.hackerrank.com/challenges/coin-change
//Problem type: Dynamic Programming
//Learning Exp: The parameters of the DP recurrence must be in same order

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
    int n, m;
    int MAX = 100000000;
    scanf("%d %d", &n, &m);
    vector <int> coins(m);
    vector <int> change(n+1, MAX);
    for (int i = 0; i < m; i++) {
        scanf("%d", &coins[i]);
    }
    //Coin Change Problem, Variant 1: Find the smallest number of coins used to represent a value
    change[0] = 0;
    for (int i = 0; i < m; i++) {
        for (int j = coins[i]; j <= n; j++) {
            change[j] = min(change[j], change[j-coins[i]] + 1);    
            printf("change[%d][%d] = %d\n", i, j, change[j]);
        }
    }
    printf("Smallest number of coins used to represent %d is %d\n", n, change[n]);

    //Coin Change Problem, Variant 2: Find the number of ways to represent a value using the coins
    
    vector <ll> ways(n+1, 0);
    //1D DP Array
    ways[0] = 1;
    for (int i = 0; i < m; i++) { //ORDER MATTERS
        for (int j = coins[i]; j <= n; j++) {
            ways[j] += ways[j-coins[i]];
            printf("ways[%d][%d] = %lld\n", i, j, ways[j]);
        }
    }
    printf("Number of ways to form %d is %lld\n", n, ways[n]);
    
    
    //2D DP Array
    vector <vector <ll>> ways2(m+1, vector <ll> (n+1, 0));
    for (int i = 0; i < m; i++) { //ORDER DOESN'T MATTER
        for (int j = 0; j <= n; j++) {
           if (j == 0) ways2[i][j] = 1;
           else {
               if (i > 0) ways2[i][j] += ways2[i-1][j];
               if (coins[i] <= j) ways2[i][j] += ways2[i][j-coins[i]];
           }
           printf("ways2[%d][%d] = %lld\n", i, j, ways2[i][j]);
        }
    }
    printf("Number of ways to form %d is %lld\n", n, ways2[m-1][n]);

}