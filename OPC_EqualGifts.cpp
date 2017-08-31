//Problem Link: http://opc.iarcs.org.in/index.php/problems/EQGIFTS
//Problem type: DP

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
#include <iomanip> //cout << setprecision(n) << fixed << num

#define mp make_pair
#define ii pair<int, int>
#define PI 3.14159265
#define INF 1000000000000000000LL
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << "\n";
typedef long long int ll;
using namespace std;

int DP[23000][160] = {};
int main() {
    
    int N;
    int a,b;
    int sum = 0;
    cin >> N;
    vector <int> differences;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        differences.push_back(abs(a-b));
        sum += abs(a-b);
    }
    for (int i = 0; i <= sum/2; i++) {
        for (int j = 0; j <= N; j++) {
            if (i == 0 || j == 0) DP[i][j] = 0;
            else if (differences[j-1] > i) DP[i][j] = DP[i][j-1];
            else DP[i][j] = max(DP[i][j-1], DP[i-differences[j-1]][j-1] + differences[j-1]);
        }
    }
    cout << abs(sum - 2*DP[sum/2][N]) << endl;
} 