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

const int maxn = 100010;
int trie[30*maxn][2];
int buffer = 0, A[maxn];

void insert(int n) {
    int x = 0;
    for (int i = 30; i >= 0; i--) {
        int j = 0;
        if (n & (1 << i))
            j = 1;
        if (!trie[x][j]) {
            buffer++;
            trie[x][j] = buffer;
        }
        x = trie[x][j];
    }
}

int findMax(int n) {
    int x = 0, ret = 0;
    for (int i = 30; i >= 0; i--) {
        int j = 0;
        if (n & (1 << i))
            j = 1;
        if (trie[x][!j]) {
            x = trie[x][!j];
            ret |= (1 << i);
        }
        else if (trie[x][j]) {
            x = trie[x][j];
        }
        else assert(false);
    }
    return ret;
}


int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int T, N;
    cin >> T;
    while (T--) {
        memset(trie, 0, sizeof(trie));
        buffer = 0;
        cin >> N;
        int x = 0, ans = 0;
        insert(x);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
            x ^= A[i];
            insert(x);
            ans = max(ans, findMax(x));
        }
        cout << ans << endl;
    }
}