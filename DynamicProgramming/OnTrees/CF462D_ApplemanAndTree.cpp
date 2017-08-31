//Problem Link: http://codeforces.com/contest/462/problem/D
//Problem type: Dynamic Programming On Trees

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
#define pb push_back
#define x first
#define y second
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << "\n";

typedef long long int ll;
typedef long double ld;
typedef std::pair <int, int> ii;
typedef std::vector <int> vi;
typedef std::vector <ll> vll;
const int INF = int(1e9);
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

using namespace std;
    
int N;
vector <vi> tree(100007);
vll dp1(100007), dp2(100007); //dp1 = num ways to split with only 1 black node, dp2 = num ways to split, with top most sub tree having 0 black nodes
int color[100007];
const int MOD = 1000000007;

void rec(int node, int parent) {
    int n = 0;
    if (color[node]) dp1[node] = 1;
    for (auto it = tree[node].begin(); it != tree[node].end(); ++it) {
        if (*it != parent) {
            rec(*it, node);
            if (!dp1[*it]) continue;
            if (n == 0) {
                dp1[node] = ((dp2[*it] % MOD) * (dp1[node] % MOD) + (dp1[*it] % MOD)) % MOD;
                if (!color[node]) dp2[node] = ((dp1[*it] % MOD) + (dp2[*it] % MOD)) % MOD;  
            }
            else {
                dp1[node] = ((dp1[node] % MOD) * (dp1[*it] % MOD) + (dp1[node] % MOD) * (dp2[*it] % MOD) + (dp2[node] % MOD) * (dp1[*it] % MOD)) % MOD;
                if (!color[node]) dp2[node] = ((dp2[node] % MOD) * (((dp1[*it] % MOD) + (dp2[*it] % MOD)) % MOD)) % MOD;  
            }
            //printf("dp1[%d] = %d\n", node, dp1[node]);
            //printf("dp2[%d] = %d\n", node, dp2[node]);
            n++;
        }
    }
}

int main() {
    scanf("%d", &N); 
    
    int a;
    for (int i = 1; i < N; i++) {
        scanf("%d", &a);
        tree[a].push_back(i);
        tree[i].push_back(a);
    }
    /*
    int a, b;
    for (int i = 0; i < N-1; i++) {
        scanf("%d %d", &a, &b);
        tree[a].push_back(b);
        tree[b].push_back(a);
    }*/
    for (int i = 0; i < N; i++) {
        scanf("%d", &color[i]);
    }
    rec(0, -1);
    cout << dp1[0] << endl;
}
/*
4
0 1
0 2
0 3
0 1 1 1
Ans: 3

3
0 1
0 2
1 0 1
Ans: 1

3
0 1
0 2
1 1 1
Ans: 1

5
0 1
0 2
1 3
2 4
1 0 0 1 1
Ans: 4

5
0 1
0 2
0 3
0 4
0 0 1 1 1
Ans: 3

4
0 1
0 2
0 3
0 1 1 1
Ans: 3

10
0 1
0 8
1 2
1 4
8 9
2 3
4 5
4 6
4 7
0 0 0 1 0 1 1 0 0 1
Ans: 27

7
0 1
0 2
0 3
1 4
2 5
3 6
0 0 0 0 1 1 1
Ans: 12
*/