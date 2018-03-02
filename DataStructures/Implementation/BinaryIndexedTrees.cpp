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

/*
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define mp make_pair
using namespace std;
using namespace __gnu_pbds;
typedef pair<int, int> pii;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> OST;

const int N = 100001;

OST bit[N];

void insert(int x, int y)
{
	for(int i = x; i < N; i += i & -i)
		bit[i].insert(mp(y, x));
}

void remove(int x, int y)
{
	for(int i = x; i < N; i += i & -i)
		bit[i].erase(mp(y, x));
}

int query(int x, int y)
{
	int ans = 0;
	for(int i = x; i > 0; i -= i & -i)
		ans += bit[i].order_of_key(mp(y+1, 0));
	return ans;
}
 */