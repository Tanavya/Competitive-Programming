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

int BIT[10007], N, A[10007];

void update(int x, int val) {
    for (; x <= N; x += x&-x) 
        BIT[x] += val;
}
int query(int x) {
    int ret = 0;
    for (; x >= 1; x-= x&-x) {
        ret += BIT[x];
    }
    return ret;
}

int main() {
    
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &A[i]);
        update(i, A[i]);
    }

    int Q, x, val;
    string type;
    scanf("%d", &Q);
    while (Q--) {
        cin >> type;
        if (type == "query") {
            scanf("%d", &x);
            printf("%d\n", query(x));
        }
        else if (type == "update") {
            scanf("%d %d", &x, &val);
            update(x, val);
        }
    }
}
