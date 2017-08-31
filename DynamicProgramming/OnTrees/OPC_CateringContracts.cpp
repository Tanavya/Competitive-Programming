//Problem Link: http://opc.iarcs.org.in/index.php/problems/CATERCONT
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

vector <vi> tree(100007);
vll dp1(100007), dp2(100007); //dp1 = best if we take node, dp2 = best if we ignore this node
vll values(100007);
int N;

void rec(int node, int parent) {

    ll sum1 = 0, sum2 = 0;
    for (auto it = tree[node].begin(); it != tree[node].end(); ++it) {
        if (*it != parent) {
            rec(*it, node);
            sum1 += dp2[*it]; 
            sum2 += max(dp2[*it], dp1[*it]);
        }
    }
    dp1[node] = values[node] + sum1;
    dp2[node] = sum2;
}

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%lld", &values[i]);
    }
    int a,b;
    for (int i = 0; i < N-1; i++) {
        scanf("%d %d", &a, &b);
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    rec(1, 0);
    cout << max(dp1[1], dp2[1]) << endl;
}