//Problem Link: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=652&page=show_problem&problem=1557
//Problem type: Dynamic Programming
//Learning Exp: 

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <stdio.h>
#include <string.h>
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
int N, Q, D, M, t = 0;
ll DP[210][22][11];
ll A[210];

ll rec(int i, int v, int m) {
    ll ret = 0;
    if (DP[i][v][m] != -1) {
        return DP[i][v][m];
    }
    else if (m == M) {
        if (v == 0) ret = 1;
        else ret = 0;
    }
    else if (i >= N) {
        ret = 0;
    } 
    else {
        ll val = (v + A[i]);
        val %= D;
        if (val < 0) val += D;
        ret += rec(i+1, val, m+1); //Take this Value
        ret += rec(i+1, v, m); //Ignore this Value
    }
    DP[i][v][m] = ret;
    return ret;
}  
int main() {
    srand(time(NULL));
    while (true) {
        scanf("%d %d", &N, &Q);
        //N = 10; Q = 5; cout << "N = " << N << endl; if (t==100)break;
        if (N == 0 && Q == 0) break;
        //memset(A, -1, sizeof(A));
        for (int i = 0; i < N; i++) {
            scanf("%lld", &A[i]);
            //A[i] = (rand() % 2) ? (rand() % 2147483647) * -1 : rand() % 2147483647; cout << A[i] << " ";
        }
        //cout << endl;
        printf("SET %d:\n", ++t);
        for (int q = 1; q <= Q; q++) {
            scanf("%d %d", &D, &M);
            //D = (rand()%20) + 1; M = (rand() % N) + 1; cout << D << " " << M << endl;
            /*
            string bitset(M, 1);
            bitset.resize(N, 0);
            ll cunt = 0;
            do { 
                ll sum = 0;
                for (int i = 0; i < N; i++) {
                    if (bitset[i]) sum += A[i];
                }
                //cout << sum << endl;
                if (sum % D == 0) cunt++;
            } while (prev_permutation(bitset.begin(), bitset.end()));
            cout << "Count by Brute: " << cunt << endl;
            */
            memset(DP, -1, sizeof(DP));
            /*
            for (int k = 0; k <= N; k++) {
                for (int i = 0; i < D; i++) {
                    for (int j = 0; j <= M; j++) {
                        cout << DP[k][i][j];
                    }
                }
            }
            
            //for (int i = 0; i < N; i++) {
                //cout << i+1 << " " << A[i] % D << " " << 1 << endl;
                //DP[i+1][A[i] % D][1] = 1; 
            //}
            //DP[0][0] = 1;
            
            for (int i = 1; i <= N; i++) {
                for (int v = 0; v < D; v++) {
                    for (int m = 0; m <= M; m++) {
                        if (m == 0) DP[i][v][m] = 0;
                        else {

                            int val = (v - abs(A[i-1] % D));
                            //if (val >= D) continue;
                            val %= D;
                            if (val < 0) val += D;
                            
                            DP[i][v][m] += DP[i-1][val][m-1];
                            DP[i][v][m] += DP[i-1][v][m]; //NOT TAKING THIS ONE
                            //cout << "Val: " << val << "\n";
                        }
                        //printf("DP[%d][%d][%d] = %lld\n", i, v, m, DP[i][v][m]);
                    }
                }
            }
            */
            ll ans = rec(0, 0, 0);
            printf("QUERY %d: %lld\n", q, ans);
            //assert(cunt == ans);

        }
    }
}