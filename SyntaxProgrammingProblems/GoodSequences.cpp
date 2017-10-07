//Problem Link: http://codeforces.com/problemset/problem/414/B
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
#define MAX 1e9
#define EPS 1e-5
#define MOD 1000000007
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << "\n";
typedef long long int ll;
using namespace std;

ll dp[2007][2007];

void gen_tc(int i) {
    
    if (i > 2) { 
        int n = (rand() % 1500) + 500;
        int k = (rand() % 1500) + 500;
        cout << n << " " << k << endl;
    }
    else {
        int n = (rand() % 150) + 250;
        int k = (rand() % 150) + 250;
        cout << n << " " << k << endl;
    }


}

void solve() {
    int T;
    scanf("%d", &T);
    while (T--) {
        memset(dp, 0, sizeof(dp));
        int N, K;
        scanf("%d %d", &N, &K);
        dp[1][1] = 1;
        for (int len = 1; len <= K; len++) {
            for (int i = 1; i <= N; i++) {
                if (len == 1) dp[len][i] = 1;
                else {
                    for (int j = i; j <= N; j += i) {
                        dp[len][j] = ((dp[len][j] % MOD) + (dp[len-1][i] % MOD)) % MOD;
                    } 
                }
            }
        }
        ll ans = 0;
        for (int i = 1; i <= N; i++) {
            ans = ((ans % MOD) + (dp[K][i] % MOD)) % MOD;
        }
        printf("%lld\n", ans);
    }
}
int main() {
    srand(time(NULL));
    for (int i = 0; i < 11; i++) {
        string loc = "GoodSequences/input/input" + to_string(i) + ".txt";
        freopen(loc.c_str(), "w", stdout);
        if (i == 0) {
            cout << 3 << endl;
            cout << "3 2\n6 4\n2 1\n";
        }
        else {
            cout << 5 << endl;
            for (int t = 0; t < 5; t++) 
                gen_tc(i);
        }
        freopen(loc.c_str(), "r", stdin);
        loc = "GoodSequences/output/output" + to_string(i) + ".txt";
        freopen(loc.c_str(), "w", stdout);
        solve();
    }
}