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
#include <cstring>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip> //cout << setprecision(node) << fixed << num
#include <stack>
#include <sstream>


#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << endl;
#define debug(x) cout << x << endl;
#define debug2(x,y) cout << x << " " << y << endl;
#define debug3(x,y,z) cout << x << " " << y << " " << z << endl;

typedef long long int ll;
typedef long double ld;
typedef unsigned long long int ull;
typedef std::pair <int, int> ii;
typedef std::vector <int> vi;
typedef std::vector <ll> vll;
typedef std::vector <ld> vld;

const int INF = int(1e9);
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
using namespace std;

const int maxn = (int) 1e6 + 7;
map <char, int> trie[maxn];
int buffer = 0, dp[maxn], weight[maxn];

int insert(string &s) {
    int x = 0;
    for (char c : s) {
        if (!trie[x][c]) {
            buffer++;
            trie[x][c] = buffer;
        }
        x = trie[x][c];
    }
    return x;
}
int query(string &s) {
    int x = 0;
    for (char c : s) {
        if (!trie[x][c])
            return -1;
        x = trie[x][c];
    }
    return dp[x];
}
void dfs(int node) {
    //cout << node << endl;
    dp[node] = weight[node];
    for (auto it : trie[node]) {
        dfs(it.second);
        dp[node] = max(dp[node], dp[it.second]);
    }
}

int main() {
    int N, Q, x;
    string s;
    scanf("%d %d", &N, &Q);
    for (int i = 0; i < N; i++) {
        cin >> s;
        scanf("%d", &x);
        int pos = insert(s);
        //cout << pos << endl;
        weight[pos] = x;
    }
    dfs(0);
    while (Q--) {
        cin >> s;
        printf("%d\n", query(s));
    }
}