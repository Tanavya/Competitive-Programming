//Problem Link: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=651&page=show_problem&problem=422
//Problem type: 2 Methods: Dynamic Programming and Greedy + D&C (Binary Search)
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
    /*
    int n;
    scanf("%d", &n);
    int A[n], DP[n], prev[n], max_len = 0, last;
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
        prev[i] = -1;
        DP[i] = 1;
    }
    */
    vector <long> A, DP, prev;
    int max_len = 0;
    long last, tmp;
    while (scanf("%ld", &tmp) != EOF) {
        A.push_back(tmp);
        //prev.push_back(LONG_MIN);
        //DP.push_back(1);
    }
    int n = A.size();
    /*
    for (ll i = 1; i < n; i++) {
        for (ll j = 0; j < i; j++) {
            if (A[j] < A[i]) {
                if (DP[i] <= DP[j] + 1) {
                    prev[i] = j;
                    DP[i] = DP[j] + 1;
                }
            }
        } 
        if (DP[i] >= max_len) {
            max_len = DP[i];
            last = i;
        }
    }
    vector <ll> seq = {A[last]};
    while (last != LONG_MIN) {
        last = prev[last];
        seq.push_back(A[last]);
    }
    printf("%d\n-\n", max_len);
    for (ll i = max_len-1; i >= 0; i--) printf("%lld\n", seq[i]);
    */
    //printf("Answer calculated by DP Method: { ");
    //for (int i = max_len-1; i >= 0; i--) printf("%d ", seq[i]);
    //printf("} Length = %d\n", max_len);
    
    vector <vector <long>> sequences;
    //set <long> L;
    vector <long> L;
    L.push_back(A[0]);
    sequences.push_back({A[0]});
    max_len = 1;
    for (int i = 1; i < n; i++) {
        auto it = lower_bound(L.begin(), L.end(), A[i]);
        if (it != L.end()) {
            *it = A[i];
            int j = distance(L.begin(), it);
            if (j) sequences[j] = sequences[j-1];
            else sequences[j] = {};
            sequences[j].push_back(A[i]);
        }
        else {
            sequences.push_back(sequences[sequences.size()-1]);
            max_len++;
            sequences[sequences.size()-1].push_back(A[i]);
            L.push_back(A[i]);
        }
    }
    printf("%d\n-\n", max_len);
    for (int i = 0; i < max_len; i++) {
        printf("%ld\n", sequences[max_len-1][i]);
    } 
    //printf("Answer calculated by Optimal Method: Length = %d\n", max_len);
    
}
