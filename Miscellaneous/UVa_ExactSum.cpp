//Problem Link: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=661&page=show_problem&problem=1998
//Problem type: D&C Binary Search
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
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << "\n";
typedef long long int ll;
using namespace std;

int main() {
    int n, k;
    while (scanf("%d", &n) != EOF) {
        vector <int> arr(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        scanf("%d", &k);
        sort(arr.begin(), arr.end());        
        for (int i = n-2; i >= 0; i--) {
            if (binary_search(arr.begin() + i+1, arr.end(), k-arr[i] )) {
                printf("Peter should buy books whose prices are %d and %d.\n\n", arr[i], k-arr[i]);
                break;
            }
        }
        
    }

}