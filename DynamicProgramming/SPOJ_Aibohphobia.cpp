//Problem Link: http://www.spoj.com/problems/AIBOHP/
//Problem type: Dynamic Programming

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
#define pb push_back
#define x first
#define y second
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " ";

typedef long long int ll;
typedef long double ld;
typedef std::pair <int, int> ii;
typedef std::vector <int> vi;
typedef std::vector <ll> vll;
const int INF = int(1e9);
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        string S;
        cin >> S;
        int N = (int)S.size();
        vector <vector <int>> dp (N+1, vector <int> (N+1, 0));
        for (int i = 1; i < N; i++) {
            for (int j = i-1; j >= 0; j--) {
                if (j == i-1) {
                    if (S[i] != S[j]) dp[i][j] = 1;
                }
                else if (S[i] == S[j]) {
                    dp[i][j] = dp[i-1][j+1];
                }
                else {
                    dp[i][j] = min(dp[i-1][j] + 1, dp[i][j+1] + 1);
                }
            }
        }
        cout << dp[N-1][0] << endl;
    }
}