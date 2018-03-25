//Problem Link: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=649&page=show_problem&problem=1625
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
#define EPS 1e-9
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << "\n";
typedef long long int ll;
using namespace std;

int main() {
    int n;
    while (true) {
        scanf("%d", &n);
        if (!n) break;
        vector <int> A(n);
        for (int i = 0; i < n; i++) scanf("%d", &A[i]);
        int ans = A[0];
        for (int i = 1; i < n; i++) {
            A[i] = max(A[i], A[i-1] + A[i]);
            ans = max(ans, A[i]);
        }
        if (ans <= 0) printf("Losing streak.\n");
        else printf("The maximum winning streak is %d.\n", ans);
    }
}