//Problem Link: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=652&page=show_problem&problem=1557
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
    int N, Q, D, M, t = 0;
    while (true) {
        scanf("%d %d", &N, &Q);
        if (N == 0 && Q == 0) break;
        ll A[N];
        for (int i = 0; i < N; i++) {
            scanf("%lld", &A[i]);
        }
        printf("SET %d:\n", ++t);
        for (int q = 1; q <= Q; q++) {
            scanf("%d %d", &D, &M);
            /*
            string bitset(m, 1);
            bitset.resize(N, 0);
            int cunt = 0;
            do { 
                ll sum = 0;
                for (int i = 0; i < N; i++) {
                    if (bitset[i]) sum += A[i];
                }
                //cout << sum << endl;
                if (sum % d == 0) cunt++;
            } while (prev_permutation(bitset.begin(), bitset.end()));
            */
            ll DP[N+1][D][M+1];
            for (int k = 0; k <= N; k++) {
                for (int i = 0; i < D; i++) {
                    for (int j = 0; j <= M; j++) {
                        DP[k][i][j] = 0;
                    }
                }
            }
            for (int i = 0; i < N; i++) {
                DP[i+1][A[i] % D][1] = 1; 
            }
            //DP[0][0] = 1;
            for (int i = 1; i <= N; i++) {
                for (int m = 0; m <= M; m++) {
                    for (int v = 0; v < D; v++) {
                        if (m == 0) DP[i][v][m] = 0;
                        else {

                            int val = (v - (A[i-1] % D)) % D;
                            if (val < 0) val += D;
                            
                            DP[i][v][m] += DP[i-1][val][m-1];
                            DP[i][v][m] += DP[i-1][v][m]; //NOT TAKING THIS ONE
                            //cout << "Val: " << val << "\n";
                        }
                        //printf("DP[%d][%d][%d] = %d\n", i, v, m, DP[i][v][m]);
                    }
                }
            }
            printf("QUERY %d: %lld\n", q, DP[N][0][M]);
        }
    }
}