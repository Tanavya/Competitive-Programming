//Problem Link: http://codeforces.com/problemset/problem/4/D
//Problem type: Dynamic Programming
//Learning Exp: 

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


int  W, H, N, dp[10007];
vector <int> pre(10007, -1);
inline bool cmp (ii a, ii b) {
    return (a.second < b.second);
}
inline bool isGreater(ii a, ii b) {
    return (a.first > b.first && a.second > b.second);
}
int main() {
    scanf("%d %d %d", &N, &W, &H);
    vector <ii> envolopes(N), original;
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &envolopes[i].first, &envolopes[i].second);
    }
    original = vector <ii> (envolopes);
    sort(envolopes.begin(), envolopes.end());

    int ans = 0, last = -1;
    for (int i = 0; i < 10007; i++) {
        dp[i] = 1;
    }
    if (isGreater(envolopes[0], mp(W, H))) {
        ans = 1;
        dp[0] = 1;
        last = 0;
    }
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if(!isGreater(envolopes[i],mp(W, H)))continue;
            if (isGreater(envolopes[i], envolopes[j]) && isGreater(envolopes[j], mp(W, H))) {
                if (dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    pre[i] = j;
                }
            }
            if (dp[i] > ans) {
                ans = dp[i];
                last = i;
            }
        }
    }
    list <int> indexes;
    while (last != -1) {
        indexes.push_front(last);
        last = pre[last];
    }
    cout << ans << endl;
    for (int index : indexes) {
        auto it = find(original.begin(), original.end(), envolopes[index]);
        cout << distance(original.begin(), it) + 1 << " ";
    }


}
/*
5 10 10
2 6
2 6
2 6
2 6
2 6



*/

