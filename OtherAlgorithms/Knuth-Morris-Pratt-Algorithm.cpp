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


#define MAX(a,b) ((a)>(b)?(a):(b))
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << endl;
#define debug(x) cout << x << endl;
#define debug2(x,y) cout << x << " " << y << endl;
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

const int maxn = (int)1e5+10;
int b[maxn];

string T, P; //P is pattern, T is text
int n, m; //n is length of T, m is length of P

void kmpPreprocess() {
    int i = 0;
    int j = -1;
    b[0] = -1;
    while (i < m) {
        while (j >= 0 && P[i] != P[j])
            j = b[j];
        i++;
        j++;
        b[i] = j;
    }
    for (int i = 0; i < m; i++) cout << setw(2) << i << " ";
    cout << endl;

    for (int i = 0; i < m; i++) cout << setw(2) << b[i] << " ";
    cout << endl;
}
void kmpSearch() {
    int i = 0, j = 0;
    while (i < n) {
        while (j >= 0 && T[i] != P[j])
            j = b[j];
        i++;
        j++;
        if (j == m) {
            printf("P is found at index %d in T\n", i-j);
            j = b[j];
        }
    }
}
int main() {
    T = "I DO NOT LIKE SEVENTY SEV BUT SEVENTY SEVENTY SEVEN";
    P = "SEVENTY SEVEN";
    n = (int)T.size();
    m = (int)P.size();
    kmpPreprocess();
    kmpSearch();
}