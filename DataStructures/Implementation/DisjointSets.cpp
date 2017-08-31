#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <stdio.h>
#include <queue>
#include <set>
#include <list> //lol
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

int parent[100], size[100];

void init(int x) {
    parent[x] = x;
    size[x] = 1;
}
int root(int x) {
    while (parent[x] != x) {
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
    return x;
}
bool Find(int a, int b) {
    return root(a) == root(b);
}
void Union(int a, int b) {
    int root_a = root(a), root_b = root(b);
    if (root_a == root_b) return;
    if (size[root_a] < size[root_b]) {
        parent[root_a] = root_b;
        size[root_b] += size[root_a];
    }
    else {
        parent[root_b] = root_a;
        size[root_a] += size[root_b];
    }
}

int main() {
    for (int i = 1; i <= 10; i++) {
        init(i);
    }
    Union(1,2);
    Union(3,4);
    Union(2,3);
    //creates the set {1,2,3,4}

    Union(5,6);
    Union(5,7);
    //creates the set {5,6,7};

    cout << Find(4,7) << endl;
    //prints 0, i.e false, as 4 and 7 are not in the same set

    cout << Find(5,7) << endl;
    //prints 1

}