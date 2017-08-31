//Problem Link: 
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

int M[100][100] = {};

/*
int MemoizedKS(int n, int w) {
    if (M[n][w]) return M[n][w];
    int result;
    if (n==0 || w == 0) result = 0;
    else if (weights[n-1] > w) result = MemoizedKS(n-1, w);
    else result = max(MemoizedKS(n-1,w), values[n-1] + MemoizedKS(n-1,w-weights[n-1]));
    M[n][w] = result;
    return result;
}
*/
int IterativeMemoizedKS(int n, int w, vector <int> values, vector <int> weights) {
    /*
    //USES 2-D Array
    int K[n+1][w+1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= w; j++) {
            K[i][j] = 0;
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= w; j++) {
            if (i==0 || j==0) K[i][j] = 0;
            else if (weights[i-1] > j) {
                K[i][j] = K[i-1][j];
            }

            else {
                K[i][j] = max(K[i-1][j], values[i-1] + K[i-1][j-weights[i-1]]);
            }
            //printf("DP[%d][%d] = %d\n", i, j, K[i][j]);
        }
    }
    return K[n][w];
    */
    //USES 1-D Array
    vector <int> DP(w+1, 0);
    for (int i = 0; i < n; i++) {
        for (int j = w; j >= weights[i]; j--) {
            DP[j] = max(DP[j], values[i] + DP[j - weights[i]]);
        }
    }
    return DP[w];
}
int main() {
    /*
    weights = {10,20,30};
    values = {60,100,120};
    W = 50;
    N = (int) values.size();
    cout << MemoizedKS(N,W) << endl;
    cout << IterativeMemoizedKS(N,W) << endl;
    */
    int t, n, w;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        scanf("%d", &w);
        vector <int> values(n), weights(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &values[i]);
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &weights[i]);
        }
        printf("%d\n", IterativeMemoizedKS(n, w, values, weights));
    }
}



