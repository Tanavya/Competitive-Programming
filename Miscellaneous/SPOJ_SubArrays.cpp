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
 
const int maxn = 1e6;
int A[maxn+7];
int main() {

    int N, K;
    scanf("%d", &N);
    deque <int> dq;
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    scanf("%d", &K);
    for (int i = 0; i < N; i++) {
        while (!dq.empty()) {
            if (A[dq.front()] < A[i]) dq.pop_front();
            else break;
        }
        if (!dq.empty()) while (dq.back() < i-K+1) {
            dq.pop_back();
        }
        dq.push_front(i);
        if (i+1 >= K) printf("%d ", A[dq.back()]);
    }
    printf("\n");
    
}