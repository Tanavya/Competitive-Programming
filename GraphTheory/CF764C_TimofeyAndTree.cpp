//Problem Link: http://codeforces.com/problemset/problem/161/D
//Problem type: Graph Theory (Trees)
//Learning Exp: 

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
#include <iomanip> //cout << setprecision(node) << fixed << num

#define mp make_pair
#define ii pair<int, int>
#define PI 3.14159265
#define INF 1000000000000000000LL
#define MAX 1e9
#define MAXN 10000010
#define EPS 1e-5
#define MOD 1000000007
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << "\n";
typedef long long int ll;
using namespace std;

vector <vector <int>> tree(100007);
int N, color[100007];

int dfs(int n, int par, int col) {
    int ret = col;
    for (auto it = tree[n].begin(); it != tree[n].end(); ++it) {
        if (*it != par) {
            if (dfs(*it, n, color[*it]) != col) {
                ret = 0;
            }
        }
    }
    return ret;
}
inline bool checkRoot(int n) {
    for (auto it = tree[n].begin(); it != tree[n].end(); ++it) {
        if (dfs(*it, n, color[*it]) == 0) return false;
    }
    return true;
}

int main() {
    scanf("%d", &N);
    int a, b;
    for (int i = 0; i < N-1; i++) {
        scanf("%d %d", &a, &b);
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    for (int i = 1; i <= N; i++) {
        scanf("%d", &color[i]);
    }
    dfs(1, 0, color[1]); 
    bool found = false;
    for (int n = 1; n <= N && !found; n++) {
        for (auto it = tree[n].begin(); it != tree[n].end() && !found; ++it) {
            if (color[n] != color[*it]) {
                found = true;
                if (checkRoot(n)) {
                    cout << "YES\n" << n;
                }
                else if (checkRoot(*it)) {
                    cout << "YES\n" << *it;
                }
                else {
                    cout << "NO\n";
                }
                break;
            }
        }
    }
    if (!found) cout << "YES\n1";
}
/*
4
1 2
2 3
3 4
1 2 1 1
*/