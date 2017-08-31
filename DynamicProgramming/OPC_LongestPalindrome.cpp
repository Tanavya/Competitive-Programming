//Problem Link: http://opc.iarcs.org.in/index.php/problems/LONGPALIN
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
    int N;
    string S;
    scanf("%d", &N);
    vector <vector <int>> dp (N+1, vector <int> (N+1, 0));
    cin >> S;
    int ans_length = 1, start = 0;
    for (int i = 0; i < N; i++) {
        dp[i][i] = 1;
        for (int j = 0; j < i; j++) {
            if (j == i-1) {
                if (S[i] == S[j]) dp[i][j] = 2;
            }
            else if (S[i] == S[j] && dp[i-1][j+1]) {
                dp[i][j] = dp[i-1][j+1] + 2;
            }
            if (ans_length < dp[i][j]) {
                ans_length = dp[i][j];
                start = j;
            }
        }
    }
    cout << ans_length << endl;
    cout << S.substr(start, ans_length) << endl;
}
