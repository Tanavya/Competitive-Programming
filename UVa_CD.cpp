//Problem Link: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=645&page=show_problem&problem=565
//Problem type: Complete Search / DP

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
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << "\n";
typedef long long int ll;
using namespace std;

int N, T, best = -1;
vector <int> tracks(20), ans, curr;
void rec(int n, int w) {
    if (n == 0) {
        if (N-w > best) {
            best = N-w;
            ans = curr;
        }
    }
    else if (tracks[n-1] > w) rec(n-1, w); //not possible to take this track
    else {
        curr.push_back(tracks[n-1]); //take this track
        rec(n-1, w - tracks[n-1]);
        curr.pop_back();
        rec(n-1, w); //see if it is better to ignore this track
    }
}

int main() {
    while (scanf("%d", &N) != EOF) {
        best = -1;
        ans = {};
        scanf("%d", &T);
        for (int i = 0; i < T; i++) {
            scanf("%d", &tracks[i]);
        }
        rec(T, N);
        reverse(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i++) {
            printf("%d ", ans[i]);
        }
        printf("sum:%d\n", best);
    }
}