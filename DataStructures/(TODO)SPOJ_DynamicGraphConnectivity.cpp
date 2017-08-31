//Problem Link : http://www.spoj.com/problems/DYNACON2/

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

int size[100007], parent[100007];

int root(int x) {
    while (parent[x] != x) {
        x = parent[x] = parent[parent[x]];
    }
    return x;
}

void onion(int a, int b) {
    int ra = root(a), rb = root(b);
    if (ra != rb) {
        if (size[ra] < size[rb]) {
            parent[ra] = rb;
            size[rb] += ra;
        }
        else {
            parent[rb] = ra;
            size[ra] += rb;
        }
    }
}
bool find(int a, int b) {
    return root(a) == root(b);
}

int main() {
    
    int N, Q, a, b, sqrtt; 
    string type;
    scanf("%d %d", &N, &Q);
    vector <pair<int, ii>> queries (Q);
    sqrtt = ceil(sqrt(Q));
    int block = 1;
    for (int q = 0; q < Q; q++) {
        cin >> type;
        scanf("%d %d", &a, &b);
        if (type == "add") queries.pb(mp(0, mp(a, b)));
        else if (type == "rem") queries.pb(mp(1, mp(a, b)));
        else queries.pb(mp(2, mp(a, b)));
        if (q > block * sqrtt) {
            block++;
        }
    }
    for (int q = 0; q < Q; q += sqrtt) {

    }

}