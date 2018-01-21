//small bug. x = 0 will give wrong answer
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

const int maxn = (int) 1e5+10;
int block_size;
vll blocks, mark;
ll A[maxn], B[maxn], pref[maxn];

int main() {
    int N, Q;
    //scanf("%d %d", &N, &Q);
    N = 10000; Q = 100;
    for (int i = 0; i < N; i++) {
        //scanf("%lld", &A[i]);
        A[i] = (rand() % 5000000) + 1; cout << A[i] << " ";
        B[i] = A[i];
    }
    cout << endl;
    block_size = (int)round(sqrt(N));
    //cout << "BLOCK SIZE: " << block_size << endl;
    for (int i = 0; i < N; i += block_size) {
        ll s = 0;
        for (int j = i; j < i + block_size && j < N; j++) {
            s += A[j];
        }
        blocks.pb(s);
        mark.pb(0);
    }
    //print(blocks);
    int type, L, R;
    ll x;
    while (Q--) {
        //scanf("%d", &type);
        type = (rand() % 2) + 1; cout << type << " ";
        if (type == 1) {
            //query
            //scanf("%d %d", &L, &R);
            L = (rand() % N) + 1; R = (rand() % N) + 1; if (L > R) swap(L, R); debug2(L, R);
            L--; R--;
            ll ans = 0;
            for (int i = L; i <= R; i++) {
                ans += B[i];
            }
            ll sum = 0;
            while (L < R && L % block_size != 0) {
                if (mark[L/block_size]) sum += mark[L/block_size];
                else sum += A[L];
                L++;
            }
            //cout << sum << endl;
            while (L + block_size <= R) {
                sum += blocks[L/block_size];
                L += block_size;
            }
            //cout << sum << endl;
            while (L <= R) {
                if (mark[L/block_size]) sum += mark[L/block_size];
                else sum += A[L];
                L++;
            }
            //cout << sum << endl;
            //cout << "Mine : " << sum << endl; cout << "Brute: " << ans << endl;
            assert(sum == ans);
        }
        else {
            //update
            //scanf("%d %d %lld", &L, &R, &x);
            L = (rand() % N) + 1; R = (rand() % N) + 1; x = (rand() % 500000000) + 1; if (L > R) swap(L, R); cout << L << " " << R << endl;
            L--; R--;
            for (int i = L; i <= R; i++) {
                B[i] = x;
            }
            int li = (L/block_size) * block_size;
            for (int i = li; i < li + block_size && i < N; i++) {
                if (mark[i / block_size]) {
                    A[i] = mark[i/block_size];
                }
                if (i >= L && i <= R) {
                    blocks[i/block_size] += x - A[i];
                    A[i] = x;
                }
            }
            mark[L/block_size] = 0;
            L = li + block_size;
            while (L + block_size <= R) {
                mark[L/block_size] = x;
                blocks[L/block_size] = block_size * x;
                L += block_size;
            }
            int ri = (R/block_size) * block_size;
            for (int i = ri; i < ri + block_size && i < N; i++) {
                if (mark[i / block_size]) {
                    A[i] = mark[i/block_size];
                }
                if (i >= L && i <= R) {
                    blocks[i/block_size] += x - A[i];
                    A[i] = x;
                }
            }
            mark[R/block_size] = 0;
        }
    }
}