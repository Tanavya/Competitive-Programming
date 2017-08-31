//Problem Link: http://codeforces.com/problemset/problem/4/D
//Problem type: Dynamic Programming
//Learning Exp: For grids, start loops from i = 1 and j = 1. Gives SHORTER code!

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <stdio.h>
#include <queue>
#include <set>
#include <list>
#include <cmath>
#include <assert.h>
#include <bitset>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip> //cout << setprecision(node) << fixed << num

#define mp make_pair
#define ii pair<int, int>
#define PI 3.14159265
#define INF 1000000000000000000LL
#define MAX 1e9
#define MAXN 10000010
#define EPS 1e-5
#define MOD 1000000007
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << "\n";
typedef long long int ll;
using namespace std;

int N, M;
ll A[1007][1007], dpTL[1007][1007], dpBL[1007][1007], dpTR[1007][1007], dpBR[1007][1007];
int main() {

    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%lld", &A[i][j]);
        }
    }
    //starting from top left corner
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (i == 0 && j == 0) dpTL[i][j] = A[i][j];
            if (i) dpTL[i][j] = max(dpTL[i][j], dpTL[i-1][j] + A[i][j]);
            if (j) dpTL[i][j] = max(dpTL[i][j], dpTL[i][j-1] + A[i][j]);
        }
    }
    //cout << dpTL[N-1][M-1] << endl;

    //starting from bottom left corner
    for (int i = N-1; i >= 0; i--) {
        for (int j = 0; j < M; j++) {
            if (i == N-1 && j == 0) dpBL[i][j] = A[i][j];
            if (i < N-1) dpBL[i][j] = max(dpBL[i][j], dpBL[i+1][j] + A[i][j]);
            if (j) dpBL[i][j] = max(dpBL[i][j], dpBL[i][j-1] + A[i][j]);

        }
    }
    //cout << dpBL[0][M-1] << endl;
    
    //starting from top right corner
    for (int i = 0; i < N; i++) {
        for (int j = M-1; j >= 0; j--) {
            if (i == 0 && j == M-1) dpTR[i][j] = A[i][j];
            if (i) dpTR[i][j] = max(dpTR[i][j], dpTR[i-1][j] + A[i][j]);
            if (j < M-1) dpTR[i][j] = max(dpTR[i][j], dpTR[i][j+1] + A[i][j]);
        }
    }
    //cout << dpTR[N-1][0] << endl;
    
    //starting from bottom right corner
    for (int i = N-1; i >= 0; i--) {
        for (int j = M-1; j >= 0; j--) {
            if (i == N-1 && j == M-1) dpBR[i][j] = A[i][j];
            if (i < N-1) dpBR[i][j] = max(dpBR[i][j], dpBR[i+1][j] + A[i][j]);
            if (j < M-1) dpBR[i][j] = max(dpBR[i][j], dpBR[i][j+1] + A[i][j]);
        }
    }
    //cout << dpBR[0][0] << endl;
    
    ll ans = 0, curr = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (i && j && i < N-1 && j < M-1) {
                curr = dpTL[i][j-1] + dpBL[i+1][j] + dpTR[i-1][j] + dpBR[i][j+1];
                ans = max(ans, curr);
                curr = dpTL[i-1][j] + dpBL[i][j-1] + dpTR[i][j+1] + dpBR[i+1][j];
                ans = max(ans, curr);
            }
        }
    }
    cout << ans << endl;
}
/*
3 4
10 2 3 4
5 6 7 8
3 4 5 9
*/