//Problem Link: http://codeforces.com/contest/789/problem/C
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

ll A[100007];
vector <ll> diff;
int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
    }
    int mult = 1;
    for (int i = 1; i < N; i++) {
        diff.push_back(mult * abs(A[i] - A[i-1]));
        mult = mult == 1 ? -1: 1;
    }
    ll ans = diff[0];
    for (int i = 1; i < N-1; i++) {
        diff[i] = max(diff[i], diff[i-1]+diff[i]);
        ans = max(ans, diff[i]);
    }
    diff.clear();
    mult = -1;
    for (int i = 1; i < N; i++) {
        diff.push_back(mult * abs(A[i] - A[i-1]));
        mult = mult == 1 ? -1: 1;
    }
    ans = max(ans, diff[0]);
    for (int i = 1; i < N-1; i++) {
        diff[i] = max(diff[i], diff[i-1]+diff[i]);
        ans = max(ans, diff[i]);
    }
    cout << ans << endl;
}