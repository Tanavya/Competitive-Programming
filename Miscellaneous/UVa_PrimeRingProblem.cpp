//Problem Link: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=646&page=show_problem&problem=465
//Problem type: Complete Search

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

int n;
bitset <33> isPrime;
bitset <17> used;
vector <int> ring;
vector <vector <int>> ans;

void rec(int i) {
    if (i == n-1) {
        for (int j = 0; j < ring.size(); j++) {
            if (j > 0) printf(" ");
            printf("%d", ring[j]);
        }
        printf("\n");
    }
    else {
        for (int j = 2; j <= n; j++) {
            if (i == n-2 && !isPrime[j+ring[0]]) continue;
            if (!used[j] && isPrime[j+ring[i]]) {
                used[j] = true;
                ring.push_back(j);
                rec(i+1);
                ring.pop_back();
                used[j] = false;
            }
        } 
    }
}
int main() {
    for (int p: {2,3,5,7,11,13,17,19,23,29,31}) isPrime[p] = 1;
    int tc = 0;
    while (scanf("%d", &n) != EOF) {
        if (tc) printf("\n");
        tc++;
        ring = {1};
        used.reset();
        printf("Case %d:\n", tc);
        rec(0);
    }
}