//Problem type: Data Structures (Disjoint Sets)
 
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
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " ";
 
typedef long long int ll;
typedef long double ld;
typedef std::pair <int, int> ii;
typedef std::vector <int> vi;
typedef std::vector <ll> vll;
const int INF = int(1e9);
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
using namespace std;

int leader[100007], parent[100007];

int root(int x) {
    while (parent[x] != x) {
        x = parent[x] = parent[parent[x]];
    }
    return x;
}
int Find(int a, int b) {
    return root(a) == root(b);
}
void Union(int a, int b) {
    int root_a = root(a), root_b = root(b);
    if (root_a == root_b) return;
    parent[root_a] = root_b;
    leader[root_a] = leader[root_b];
}

int main() {
    int N, Q, type, a, b;
    scanf("%d %d", &N, &Q);
    for (int i = 1; i <= N; i++) {
        leader[i] = parent[i] = i;
    }
    while (Q--) {
        scanf("%d", &type);
        if (type == 1) {
            scanf("%d %d", &a, &b);
            Union(a, b);    
        }
        else if (type == 2) {
            scanf("%d", &a);
            leader[root(a)] = a;
        }
        else if (type == 3) {
            scanf("%d", &a);
            printf("%d\n", leader[root(a)]);
        }
    }
}