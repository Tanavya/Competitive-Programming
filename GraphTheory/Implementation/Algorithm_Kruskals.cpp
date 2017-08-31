//Tutorial Link: https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/tutorial/

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

int size[10007], parent[10007], N, M;
ll answer = 0;
vector <pair<int, ii>> edges;

int root(int x) {
    while (parent[x] != x) {
        x = parent[x] = parent[parent[x]];
    }
    return x;
}

bool Find(int a, int b) {
    return root(a) == root(b);
}

void Union(int a, int b) {
    int root_a = root(a), root_b = root(b);
    if (root_a != root_b) {
        if (size[root_a] < size[root_b]) {
            parent[root_a] = root_b;
            size[root_b] += size[root_a];
        }
        else {
            parent[root_b] = root_a;
            size[root_a] += size[root_b];
        }
    }
}
void kruskals() {
    sort(edges.begin(), edges.end());
    for (pair <int, ii> edge: edges) {
        int w = edge.x, a = edge.y.x, b  = edge.y.y;
        if (!Find(a, b)) {
            Union(a, b);
            answer += w;
        }
    }
}

int main() {

    int a, b, w;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &a, &b, &w);
        edges.pb(mp(w, mp(a,b)));
    }
    for (int i = 1; i <= N; i++) {
        size[i] = 1;
        parent[i] = i;
    }
    kruskals();
    printf("%lld\n", answer);
}