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
 
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << endl;
#define debug(x) cout << x << endl;
#define debug2(x,y) cout << x << " " << y << endl;
typedef long long int ll;
typedef long double ld;
typedef std::pair <int, int> ii;
typedef std::vector <int> vi;
typedef std::vector <ll> vll;
const int INF = int(1e9);
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
using namespace std;

const int nmax = 100007;
int L[nmax][3], R[nmax][3], A[nmax];
int main() {
    memset(L, 0, sizeof(L));
    memset(R, 0, sizeof(R));
    memset(A, -1, sizeof(A));
    freopen("hps.in","r",stdin);
    freopen("hps.out","w",stdout);
    int N;
    char c;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        cin >> c;
        L[i][0] = L[i-1][0];
        L[i][1] = L[i-1][1];
        L[i][2] = L[i-1][2];
        if (c == 'H') A[i] = 0;
        else if (c == 'P') A[i] = 1;
        else A[i] = 2;
        L[i][A[i]]++;
    }
    int ans = 0;
    for (int i = N; i >= 1; i--) {
        R[i][0] = R[i+1][0];
        R[i][1] = R[i+1][1];
        R[i][2] = R[i+1][2];
        R[i][A[i]]++;
    }
    for (int i = 1; i <= N; i++) {
        int t1 = max(max(R[i][0], R[i][1]), R[i][2]);
        int t2 = max(max(L[i-1][0], L[i-1][1]), L[i-1][2]);
        ans = max(ans, t1 + t2); 
    }
    cout << ans << endl;
}