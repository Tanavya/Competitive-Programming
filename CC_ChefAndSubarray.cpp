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
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <iomanip> 
using namespace std;
 
 
#define debug(x) cout << x << endl;
#define debugV(v) for (auto x : v) cout << x << " "; cout << endl;
#define debug2(x,y) cout << x << " " << y << endl;
#define mp make_pair
#define pb push_back
 
typedef long long int ll;
typedef long double ld;
typedef std::pair <int, int> ii;
typedef std::vector <int> vi;
typedef std::vector <ll> vll;
const int INF = int(1e9);
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
using namespace std;
 
const int maxn = 1e5;
int A[maxn*2+7];
vi dp(maxn*3+7, -INF);
int tree[maxn*8+7];
inline int left(int x) { return (x << 1); }
inline int right(int x) { return (x << 1) + 1; }
 
void build(int p, int L, int R) {
    if (L == R) {
        tree[p] = A[L];
    }
    else {
        build(left(p), L, (L+R)/2);
        build(right(p), (L+R)/2+1, R);
        tree[p] = max(tree[left(p)], tree[right(p)]);
    }
}
int query(int p, int L, int R, int li, int ri) {
    if (ri < L || li > R)  
        return 0;
    if (ri >= R && li <= L)
        return tree[p];
    return max(query(left(p), L, (L+R)/2, li, ri), query(right(p), (L+R)/2+1, R, li, ri));
}
 
int main() {
 
    int N, K, P;
    scanf("%d %d %d", &N, &K, &P);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
        A[N+i] = A[i];
    }
    int sum = 0;
    for (int i = N*2; i >= 0; i--) {
        if (i+K < N*2) sum -= A[i+K];
        sum += A[i];
        dp[i] = sum;
    }
    
    for (int i = 0; i < N*2; i++) {
        A[i] = dp[i];
        //cout << dp[i] << " ";
    }
    //cout << endl;
    K = N-K+1;
    deque <int> dq;
    for (int i = 0; i < 2*N; i++) {
        while (!dq.empty()) {
            if (A[dq.front()] < A[i]) dq.pop_front();
            else break;
        }
        while (!dq.empty()) {
            if (dq.back() < i-K+1) dq.pop_back();
            else break;
        }
        dq.push_front(i);
        dp[i] = A[dq.back()];
        //printf("%d ", dp[i]);
    }

    //cout << endl;
    
    
    int pos = N;
    build(1, 1, N*2);
    string inp;
    cin >> inp;
    for (char Q : inp) {
        if (Q == '?') {
            //if (K >= N) printf("%d\n", dp[N]);
            //else printf("%d\n", query(1, 1, N*2, pos, pos+N-K));
            if (K >= N) printf("%d\n", dp[N-1]);
            else printf("%d\n", dp[pos+K-1]);
        }
        else {
            pos--;
            if (pos == 0) {
                pos = N;
            }
        }
    }
}   
