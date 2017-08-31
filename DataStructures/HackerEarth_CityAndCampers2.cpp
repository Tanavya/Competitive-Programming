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
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << endl;
 
typedef long long int ll;
typedef long double ld;
typedef std::pair <int, int> ii;
typedef std::vector <int> vi;
typedef std::vector <ll> vll;
const int INF = int(1e9);
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
using namespace std;

int size[100007], parent[100007], size_count[100007], min_difference = 0;
set <int> sizes_set;

int root(int x) {
    while (parent[x] != x) {
        x = parent[x] = parent[parent[x]];
    }
    return x;
}

void UpdateSize(int a, int b) {

    int &size_a = size[a], &size_b = size[b];
    size_count[size_a]--;
    size_count[size_b]--;
    size_count[size_a + size_b]++;
    if (size_count[size_a] == 0) sizes_set.erase(size_a);
    if (size_count[size_b] == 0) sizes_set.erase(size_b);
    if (size_count[size_a + size_b] == 1) sizes_set.insert(size_a + size_b);
    size_a += size_b;
    
    if (sizes_set.size() == 1) {
        min_difference = 0;
        return;
    }
    min_difference = INF;
    for (auto it = sizes_set.begin(); it != prev(sizes_set.end()); ++it) {
        if (size_count[*it] > 1) {
            min_difference = 0;
            return;
        }
        min_difference = min(min_difference, *next(it) - *it);
    }
}
int Find(int a, int b) {
    return root(a) == root(b);
}
void Union(int a, int b) {
    int root_a = root(a), root_b = root(b);
    if (root_a != root_b) {
        if (size[root_a] < size[root_b]) {
            parent[root_a] = root_b;
            UpdateSize(root_b, root_a);
        }
        else {
            parent[root_b] = root_a;
            UpdateSize(root_a, root_b);
        }
    }
}

int main() {
    int N, Q, a, b;
    scanf("%d %d", &N, &Q);
    sizes_set.insert(1);
    size_count[1] = N;
    for (int i = 1; i <= N; i++) {
        size[i] = 1;
        parent[i] = i;
    }
    for (int q = 0; q < Q; q++) {
        scanf("%d %d", &a, &b);
        Union(a, b);
        printf("%d\n", min_difference);
    }
}