#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <stdio.h>
#include <queue>
#include <set>
#include <list>
#include <cmath>
#include <assert.h>
#include <bitset>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip> 
using namespace std;
 
 
#define debug(x) cout << x << endl;
#define debugV(v) for (auto x : v) cout << x << " "; cout << endl;
#define debug2(x,y) cout << x << " " << y << endl;
#define mp make_pair
#define pb push_back
 
typedef pair <int, int> ii;   
typedef long long int ll;
typedef vector <int> vi;
 
const int INF = 1e9;
const ll INF64 = 1e18;
 
const int maxn = 2e5+7;
map <char, int> trieNeg[maxn], triePos[maxn];
int bufferPos = 0, bufferNeg = 0,endPos[maxn], endNeg[maxn];
int insert(string &s, int type) {
    int x = 0;
    if (type == 1) {
        for (char c : s) {
            if (!triePos[x][c])
                triePos[x][c] = ++bufferPos;
            x = triePos[x][c];
 
        }
    }
    else {
        for (char c : s) {
            if (!trieNeg[x][c])
                trieNeg[x][c] = ++bufferNeg;
            x = trieNeg[x][c];
        }
    }
    return x;
}
vector <string> ans;
string path = "";
bool ans_exists = true;
/*
4
- codeforces
- youtube
+ c
+ google
*/
bool rec(int x, int y) {
    if (endNeg[x]) {
        ans_exists = false;
        return false;
    }
    //if (path.size() && triePos[]) ans.pb(path);
    for (auto child : trieNeg[x]) {
        char c = child.first;
        int next = child.second;
        
        path += string{c};
        if (!triePos[y][c]) {
            ans.pb(path);
        }
        else {
            if (!rec(next, triePos[y][c]))
                return false;
        }
        path.pop_back();
        
    }
    return true;
}
 
int main() {
 
    int N;
    string S;
    char type;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        cin >> type >> S;
        if (type == '-') {
            endNeg[insert(S, 0)] = true;
        }
        else {
            endPos[insert(S, 1)] = true;
        }
    }
    if (rec(0, 0)) {
        assert(ans_exists);
        sort(ans.begin(), ans.end());
        printf("%d\n", (int) ans.size());
        for (string s : ans) {
            cout << s << endl;
        }
    }
    else {
        printf("%d\n", -1);
    }
}
 