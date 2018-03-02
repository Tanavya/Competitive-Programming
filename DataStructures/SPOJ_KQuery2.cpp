//Refer to CC Give Away for other possible solutions
//This is M-block decomposition + BIT
//each query is O(M * log(1e4) + N/M)

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

const int maxai = (int) 1e4 + 10, maxn = 30010;
int A[maxn], N, BIT[100][maxn], block_size;

void update(int block, int i, int val) {
    for (; i < maxai; i += (i & -i)) {
        BIT[block][i] += val;
    }
}

int query(int block, int k) {
    int ret = 0;
    for (int i = k; i >= 1; i -= (i & -i))
        ret += BIT[block][i];
    return ret;
}

inline int calc_time(int x) {
    return (int)(x * 13.3f + 2*N/x);
}

int main() {

    scanf("%d", &N);

    int num_blocks = 0;
    int best = INF;
    for (int x = 1; x < 100; x++) {
        int t = calc_time(x);
        if (t < best) {
            best = t;
            num_blocks = x;
        }
    }
    block_size = N/num_blocks;
    //cout << block_size << endl;
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
        update(i/block_size, A[i], 1);
    }
    int Q;
    scanf("%d", &Q);
    while (Q--) {
        int type;
        scanf("%d", &type);
        if (type == 0) {
            int i, x;
            scanf("%d %d", &i, &x);
            i--;
            update(i/block_size, A[i], -1);
            A[i] = x;
            update(i/block_size, x, 1);
        }
        else {
            int L, R, k;
            scanf("%d %d %d", &L, &R, &k);
            L--; R--;
            int ans = 0;
            int i = L;
            for (; i <= R && i % block_size != 0; i++) {
                if (A[i] > k) ans++;
            }
            for (; i + block_size <= R; i += block_size) {
                ans += (block_size - query(i/block_size, k));

            }
            for (; i <= R; i++) {
                if (A[i] > k) ans++;
            }
            printf("%d\n", ans);
        }
    }
}