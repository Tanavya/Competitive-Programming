//Problem Link: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=647&page=show_problem&problem=3703
//Problem type: Complete Search
//Learning Exp: DUPLICATE passwords may occur as well.
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

string perm, ans;
vector <string> final_grid;
int t, k, n;
/*
bool rec(int i) {
    if (n == k && i == 5) {
        ans = perm;
        return true;
    }
    if (n > k) return false;
    for (int j = 0; j < final_grid[i].size(); j++) {
        perm += final_grid[i][j];
        if (perm.size() == 5) n++;
        if (rec(i+1)) return true;;
        perm.pop_back();
    }
    return false;
}
*/
void rec(int i) {
    if (n == k && i == 5) {
        ans = perm;
        return;
    }
    if (n > k || i >= 5) return;
    for (char ch: final_grid[i]) {
        perm += ch;
        if (perm.size() == 5) n++;
        rec(i+1);
        perm.pop_back();
    }
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &k);
        string row, col[5];
        final_grid.clear();
        final_grid.resize(5);
        bitset <100> mask[5], mask2[5];
        
        for (int i = 0; i < 6; i++) {
            cin >> row;
            for (int j = 0; j < 5; j++) {
                col[j] += row[j]; 
                mask[j][int(row[j])] = 1;
            }
        }
        for (int i = 0; i < 6; i++) {
            cin >> row;
            for (int j = 0; j < 5; j++) {
                if (mask[j][int(row[j])] && !mask2[j][int(row[j])]) {
                    final_grid[j] += row[j];
                    mask2[j][int(row[j])] = 1;
                }            
            }
        }
        for (int i = 0; i < 5; i++) {
            sort(final_grid[i].begin(), final_grid[i].end());
        }
        //cout << "NO" << endl;
        /*
        cout << "\n";
        for (int i = 0; i < 5; i++) {
            cout << final_grid[i] << endl;
        }
        cout << "\n";
        */
        
        ans = "";
        perm = "";
        n = 0;
        rec(0);
        if (ans != "") cout << ans << "\n";
        else printf("NO\n");
        
    }

}