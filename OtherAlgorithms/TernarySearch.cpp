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
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << endl;

typedef long long int ll;
typedef long double ld;
typedef std::pair <int, int> ii;
typedef std::vector <int> vi;
typedef std::vector <ll> vll;
const int INF = int(1e9);
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
using namespace std;

int f(int x) {
    return x*x + 10;
}
int main() {

    int left = -10, right = 10, ans, leftThird, rightThird;

    for (int i = 0; i < 200; i++) {
        if (abs(left - right) < EPS) {
            ans = (left+right)/2;
            break;
        }
        leftThird = (left*2 + right) / 3;
        rightThird = (left + right*2) / 3;

        if (f(leftThird) > f(rightThird)) {
            left = leftThird;
        }
        else {
            right = rightThird;
        }
    }
    cout << "Minimum of f(x) is when x = " << ans << " -> " << f(ans) << endl;
}