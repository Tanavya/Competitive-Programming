//Problem Link: http://codeforces.com/problemset/problem/628/B
//Problem type: Dynamic Programming (not really)
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

int main() {

    string S;
    cin >> S;
    int n = string(S).size();
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (stoi(string{S[i]}) % 4 == 0) ans++;
        if (i > 0) {
            if (stoi(string{S[i-1]} + string{S[i]}) % 4 == 0) ans += i; 
        }
    }
    printf("%lld\n", ans);
}