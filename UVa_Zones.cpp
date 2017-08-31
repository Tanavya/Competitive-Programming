//Problem Link: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=644&page=show_problem&problem=3488
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
 
#define MAXN 1007
#define mp make_pair
#define ii pair<int, int>
#define PI 3.14159265
#define INF 1000000000000000000LL
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << "\n";
typedef long long int ll;
using namespace std;

inline bool overlaps(set <int> s, vector <int> v) {
    //returns true if at least 1 element of v is present in s
    for (int each: v) {
        if (s.find(each) != s.end()) return true;
    }
    return false;
}
int main() {
    int tc = 0;
    int n,b,t,m;
    while (true) {
        scanf("%d %d", &n, &b);
        if (!n && !b) break;
        tc++;
        int towers[n], ind[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &towers[i]);
            ind[i] = towers[i];
        }
        scanf("%d", &m);
        vector <pair<vector<int>, int>> common(m);
        for (int i = 0; i < m; i++) {
            scanf("%d", &t);
            int tmp;
            for (int j = 0; j < t; j++) {
                scanf("%d", &tmp);
                common[i].first.push_back(tmp-1);
            }
            scanf("%d", &common[i].second);
        }
        for (int i = 0; i < m; i++) {
            for (int each: common[i].first) {
                ind[each] -= common[i].second;
            }
        }
        //for (int i = 0; i < n; i++) cout << ind[i] << " ";
        //cout << endl;
        string bitmask(b, 1);
        bitmask.resize(n, 0);
        ll best = -1;
        set <int> ans;
        do {
            ll check = 0, count = 0;;
            set <int> present;
            for (int i = 0; i < n; i++) {
                if (bitmask[i]) {
                    check += towers[i];
                    count += ind[i];
                    present.insert(i);
                }
            }
            if (check < best) continue;
            
            for (int i = 0; i < m; i++) {
                if (overlaps(present, common[i].first)) count += common[i].second;
            }
            if (count > best) {
                best = count;
                ans = present; 
            }
        } while(prev_permutation(bitmask.begin(), bitmask.end()));
        printf("Case Number  %d\nNumber of Customers: %lld\nLocations recommended:", tc, best);
        for (auto it = ans.begin(); it != ans.end(); ++it) {
            printf(" %d", *it+1);
        }
        printf("\n\n");
    }
}
/*
5 3
15 20 25 30 24 
5
2 1 2 7
3 1 2 3 3
2 2 3 2 
2 3 4 5 
2 4 5 6
5 3
25 25 25 25 25
4
2 1 2 5 
2 2 3 5 
2 3 4 5 
2 4 5 5 
5 3
25 25 25 25 25 
0
0 0
*/