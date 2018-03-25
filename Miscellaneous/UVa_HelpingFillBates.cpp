//Problem Link: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=661&page=show_problem&problem=1508
//Problem type: D&C Binary Search
//Learning Exp: How to do upper_bound binary search
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

int upper_bound(vector <int> vec, int val) {
    int n = vec.size();
    //cout << n << endl;
    int hi = n-1, lo = 0, mid;
    int fin = -1;
    while (hi >= lo) {
        //cout << lo << " " << hi << endl;
        mid = (hi+lo)/2;
        if (vec[mid] > val) {
            hi = mid-1;
            fin = mid;
        }
        else lo = mid+1;
    }
    //cout << lo << " " << hi << endl;
    return (fin == -1 ? -1: vec[fin]);
}
int main() {



    //cout << upper_bound({1,2,2,4,5,10,16,19,20,21,22}, 3);
    //return 0;
    string S, SS;
    cin >> S;
    int n = (int) S.size(), Q;
    vector <vector <int>> seq(100);
    for (int i = 0; i < n; i++) {
        seq[int(S[i])-65].push_back(i);
    }
    //vector <int> x = seq[int('Z')];
    //cout << "yo";
    scanf("%d", &Q);
    while (Q--) { 
        cin >> SS;
        int t = -1;
        vector <int> ans = {};
        bool match = true;
        for (int i = 0; i < SS.size(); i++) {
            vector <int> s = seq[int(SS[i])-65];
            t = upper_bound(s, t);
            if (t == -1) match = false;
            else ans.push_back(t);
        }
        if (match) printf("Matched %d %d\n", ans[0], ans[ans.size()-1]);
        else printf("Not matched\n");
    }
    
}