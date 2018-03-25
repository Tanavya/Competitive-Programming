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

const int maxn = (int) 1e5+10, maxblock = 400, maxai = 1 << 20;
int N, A[maxn], update[maxblock], pref[maxn], block_size;
int cnt[maxblock][maxai];
/*
int B[maxn], pre[maxn];
void brute_update(int i, int x) {
    B[i] = x;
    for (int j = 0; j < N; j++) {
        pre[j] = B[j];
        if (j) pre[j] ^= pre[j-1];
    }
}
int brute_query(int i, int k) {
    int ret = 0;
    for (int j = 0; j <= i; j++) {
        if (pre[j] == k)
            ret++;
    }
    return ret;
}
*/
int main() {
    int Q;
    scanf("%d %d", &N, &Q);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
        pref[i] = A[i];
        if (i) pref[i] ^= pref[i-1];
    }

    block_size = (int)sqrt(N);
    for (int i = 0; i < N; i++) {
        cnt[i/block_size][pref[i]]++;
    }

    while (Q--){
        int type;
        scanf("%d", &type);
        if (type == 1) {
            int i, x;
            scanf("%d %d", &i, &x);
            i--;
            int block = i/block_size;
            int tmp = x;
            x ^= A[i];
            A[i] = tmp;
            for (; i < N && i % block_size != 0; i++) {
                cnt[block][pref[i]]--;
                pref[i] ^= x;
                cnt[block][pref[i]]++;
            }
            for (; i < N; i += block_size) {
                update[i/block_size] ^= x;
            }
        }
        else {
            int i, k;
            scanf("%d %d", &i, &k);
            i--;
            int block = i/block_size, ans = 0;
            for (int b = 0; b < block; b++) {
                ans += cnt[b][k^update[b]];
            }
            for (int j = block*block_size; j <= i; j++) {
                int val = pref[j] ^ update[block];
                if (val == k) ans++;
            }
            printf("%d\n", ans);
        }
    }
}