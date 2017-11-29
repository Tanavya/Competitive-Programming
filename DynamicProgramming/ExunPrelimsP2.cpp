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
#include <cstring>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip> //cout << setprecision(node) << fixed << num
#include <stack>
#include <sstream>


#define MAX(a,b) ((a)>(b)?(a):(b))
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << endl;
#define debug(x) cout << x << endl;
#define debug2(x,y) cout << x << " " << y << endl;
#define debug3(x,y,z) cout << x << " " << y << " " << z << endl;
typedef long long int ll;
typedef long double ld;
typedef unsigned long long int ull;
typedef std::pair <int, int> ii;
typedef std::vector <int> vi;
typedef std::vector <ll> vll;
typedef std::vector <ld> vld;

const int INF = int(1e9);
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
using namespace std;

const int mod = (int) 1e9 + 7;
const int maxn = 1010;
int dp[maxn][maxn][2], N, M, K, L, R, p[maxn];
string A, B, X;

int solve(int i, int j, int flag) {
    //debug3(i, j, flag);
    //flag = 0 -> matches upto i. can use only upto >= X[i] now
    //flag = 1 -> mismatch somewhere before i. can use 0-9 now
    if (dp[i][j][flag] != -1)
        return dp[i][j][flag];
    int &ret = dp[i][j][flag];
    ret = 0;
    if (i == N+1) {
        if (j == 0) ret = 1;
        return ret;
    }
    int curr = stoi(string{X[i-1]});
    if (i % K == 0) {
        int x = (j - ((p[N - i] * L) % M) + M) % M;
        if (!flag && L > curr) ret = 0;
        else if (L == curr) ret += solve(i + 1, x, 0);
        else ret += solve(i + 1, x, 1);
    }
    else {
        int limit = 9;
        if (!flag) limit = curr;
        for (int k = 0; k <= limit; k++) {
            if (i == 1 && !k) continue;
            if (k != L) {
                int x = (j - ((p[N - i] * k) % M) + M) % M;
                if (k == limit && !flag)
                    ret += solve(i + 1, x, 0);
                else
                    ret += solve(i + 1, x, 1);
            }
        }
    }
    return ret;
}
int main() {

    cin >> K >> L >> M >> R;
    p[0] = 1;
    for (int i = 1; i <= 1000; i++)
        p[i] = (p[i-1] * 10) % M;
    cin >> A >> B;

    N = (int)A.size();
    string Y = A;
    X = "";
    bool done = false;
    for (int i = (int)Y.size()-1; i >= 0; i--) {
        if (!done) {
            if (Y[i] == '0')
                X += "9";
            else {
                //if (!i && !(stoi(string{Y[i]}) - 1)) break;
                X += to_string(stoi(string{Y[i]}) - 1);
                done = true;
            }
        }
        else {
            X += Y[i];
        }
    }
    reverse(X.begin(), X.end());

    memset(dp, -1, sizeof(dp));
    int p1 = solve(1, R, 0);

    X = B;
    memset(dp, -1, sizeof(dp));
    int p2 = solve(1, R, 0);

    //debug2(p2, p1);
    cout << p2-p1 << endl;
}