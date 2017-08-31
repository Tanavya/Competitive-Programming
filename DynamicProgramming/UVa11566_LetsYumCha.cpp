    //Problem Link: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=652&page=show_problem&problem=2613
    //Problem type: Dynamic Programming
    //Learning Exp: Lmao changed double to float to finally get AC

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

    int N, x, T, K, weights[207];
    float dp[25][205][3000], values[207];

    float rec(int used, int n, int cost) {
        if (dp[used][n][cost] != -1) return dp[used][n][cost];
        float ret = 0;
        if (used >= 2*N || n >= 2*K) {
            float mean_cost = (1.1 * (cost + N*T)) / (N);
            if (ceil(mean_cost) <= x) ret = 0;
            else ret = -2;
        }
        else {
            float x = rec(used+1, n+1, cost+weights[n]); // Check if you can take this one

            if (x == -2) ret = rec(used, n+1, cost); //Ignore this one
            else ret = max(rec(used, n+1, cost), x + values[n]); // Take this one
        }
        dp[used][n][cost] = ret;
        //cout << used << " " << n << " " << cost << ": " << ret << endl;
        return ret;
    }

    int main() {
        //cout << ceil(25.000001f) << endl;
        while (true) {
            scanf("%d %d %d %d", &N, &x, &T, &K);
            if (!N && !x && !T && !K) break;
            N++;
            for (int i = 0; i < 25; i++) {
                for (int j = 0; j < 205; j++) {
                    for (int k = 0; k < 3000; k++) {
                        dp[i][j][k] = -1;
                    }
                }
            }
            for (int i = 0; i < K; i++) {
                scanf("%d", &weights[i]);
                int tmp, sum = 0;
                for (int i = 0; i < N; i++) {
                    scanf("%d", &tmp);
                    sum += tmp;
                }
                values[i] = float(sum) / float(N);
            }
            for (int i = 0; i < K; i++) {
                weights[i+K] = weights[i];
                values[i+K] = values[i];
            }

            float ans = rec(0,0,0);
            assert(ans > 0);
            cout << setprecision(2) << fixed << ans << endl;
        }

    }