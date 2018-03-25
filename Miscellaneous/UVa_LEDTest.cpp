//Problem Link: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=647&page=show_problem&problem=357
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

string digits[10] = {"YYYYYYN", "NYYNNNN", "YYNYYNY", "YYYYNNY", "NYYNNYY", "YNYYNYY", "YNYYYYY", "YYYNNNN", "YYYYYYY", "YYYYNYY"};
vector <string> vals;
bitset <7> burnedOut;
int inpN;
inline bool isMatch(string actual, string curr) {
    bool match = true;
    for (int i = 0; i < 7; i++) {
        if ((curr[i] == 'Y' && actual[i] == 'N') || (curr[i] == 'Y' && burnedOut[i])) match = false;
        if (curr[i] == 'N' && actual[i] == 'Y') burnedOut[i] = 1;
        
    }
    return match;
}
bool rec(int n, int i) {
    if (i == inpN) return true;
    //if (n < 0) return false;
    if (isMatch(digits[n], vals[i])) return rec(n-1, i+1);
    else return false;
}

int main() {

    string inp;
    while (true) {
        scanf("%d", &inpN);
        if (!inpN) break;
        vals.clear();
        for (int i = 0; i < inpN; i++) {
            cin >> inp;
            vals.push_back(inp);
        }
        bool match = false;
        for (int n = 9; n >= max(inpN-1, 1); n--) {
            burnedOut.reset();
            if (inpN == 1) {
                if (isMatch(digits[n], vals[0])) {
                    match = true;
                    break;
                }
            }
            else if (isMatch(digits[n], vals[0])) {
                if (rec(n-1, 1)) {
                    match = true;
                    break;
                }
            }
        }
        if (match) printf("MATCH\n");
        else printf("MISMATCH\n");
    }
}