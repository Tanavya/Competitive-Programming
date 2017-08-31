//Problem Link: http://opc.iarcs.org.in/index.php/problems/TILINGS
//Problem type: Dynamic Programming

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
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << "\n";

typedef long long int ll;
typedef long double ld;
typedef std::pair <int, int> ii;
typedef std::vector <int> vi;
typedef std::vector <ll> vll;
const int INF = int(1e9);
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

using namespace std;

int dpFinal[1000007], dpTop[1000007], dpBottom[1000007];

int main() {

    int N;
    scanf("%d", &N);
    dpFinal[0] = dpFinal[1] = 1;
    for (int i = 2; i <= N; i++) {
        dpTop[i] = (dpFinal[i-2] + dpBottom[i-1]) % 10000;
        dpBottom[i] = (dpFinal[i-2] + dpTop[i-1]) % 10000;
        dpFinal[i] = (dpFinal[i-2] + dpTop[i-1] + dpBottom[i-1] + dpFinal[i-1]) % 10000;
    }
    cout << (dpFinal[N] % 10000) << endl;

}