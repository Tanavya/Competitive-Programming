//TODO UGH fuggit
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <stdio.h>
#include <queue>
#include <set>
#include <bitset>
#include <cmath>
#include <assert.h>
typedef long long int ll;
using namespace std;
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << "\n";

int main() {
    int n;
    ll l, r;
    scanf("%d %lld %lld", &n, &l, &r);
    vector <ll> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    sort(a.begin(), a.end());

    int cnt = 0;
    for (int i = 0; i < n-1 && !cnt; i++) {
        if (a[i] == a[i+1]) cnt = 1;
    }
    vector <int> ans_set;
    for (int i = 0; i < n && cnt; i++) {
        if (a[i] == 1) ans_set.push_back(1);
        else break;
    }
    for (int i = 0; i < n; i++) {
        if (((i < n-2 && a[i] + a[i+1] > a[i+2]) || (i > 0 && i < n-1 && a[i] + a[i-1] > a[i+1]) || (i > 1 && a[i-2] + a[i-1] > a[i])) && a[i] <= r && a[i] >= l)  ans_set.push_back(a[i]);
    }
    printf("%d\n", (int)ans_set.size());
}
