//Problem Link: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=661&page=show_problem&problem=3344
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
    //vector <int> x = {1,7,9,11};
    //cout << distance(x.begin(), lower_bound(x.begin(), x.end(), 35));
    int n, m, q;
    while (true) {
        scanf("%d %d", &n, &m);
        if (n == 0 && m == 0) break;
        //int grid[n][m];
        vector <vector <int> > grid (n, vector <int> (m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &grid[i][j]);
            }
        }
        scanf("%d", &q);
        int l, u;
        while (q--) {
            scanf("%d %d", &l, &u);
            int start, end, dist, ans = 0, found = 0;
            vector <int> curr;
            for (int i = 0; i < n; i++) {
                curr = grid[i];
                start =  distance(curr.begin(), lower_bound(curr.begin(), curr.end(), l));
                //cout << start << endl;
                if (start < m) {
                    for (int j = i+ans; j < n && start+j-i < m; j++) {
                        dist = j-i;
                        if (grid[j][start+dist] <= u) {
                            //cout << i << " " << start << "->" << j << " " << start+dist << " dist = " << dist << endl;
                            found = 1;
                            ans = max(ans, dist);
                        }
                    }
                }
            }
            if (found) printf("%d\n", ans+1);
            else printf("0\n");
        }
        printf("-\n");
    }
    /*
    4 5
13 21 25 33 34 16 21 33 35 35 16 33 33 45 50 23 51 66 83 93 3
22 90
33 35
20 100

4 4
1 7 9 11
5 8 10 12
7 10 15 17
11 19 30 41
4
6 20
7 9
10 10
13 14
*/
    
}