//http://codeforces.com/blog/entry/18169#comment-395019

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


#define isOn(S, j) (S & (1 << j))
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
#define toggleBit(S, j) (S ^= (1 << j))
#define lowBit(S) (S & (-S))
#define setAll(S, n) (S = (1 << n) - 1)

#define modulo(S, N) ((S) & (N - 1))   // returns S % N, where N is a power of 2
#define isPowerOfTwo(S) (!(S & (S - 1)))
#define nearestPowerOfTwo(S) ((int)pow(2.0, (int)((log((double)S) / log(2.0)) + 0.5)))
#define turnOffLastBit(S) ((S) & (S - 1))
#define turnOnLastZero(S) ((S) | (S + 1))
#define turnOffLastConsecutiveBits(S) ((S) & (S + 1))
#define turnOnLastConsecutiveZeroes(S) ((S) | (S - 1))

int count_on(int x) {
    int cnt = 0;
    for (int i = (int)ceil(log2(x)); i >= 0 && x; i--) {
        if ((1 << i) <= x) {
            x -= (1 << i);
            cnt++;
        }
    }
    return cnt;
}

int cnt_on(int msk) {
    return __builtin_popcount(msk);
}

void print_mask(int mask) {
    bitset<10> bs(mask);
    string str_mask = bs.to_string();
    reverse(str_mask.begin(), str_mask.end());
    cout << str_mask << endl;
}

int main() {

    int mask = 0;
    mask |= (1 << 3);
    mask |= (1 << 2);
    mask |= (1 << 5);

    cout << cnt_on(mask) << endl;
    for (int submask = mask; submask >= 0; submask = ( mask & (submask-1) )) {
        print_mask(submask);
        if (!submask) break;
    }

    while (mask) {
        int pos = (mask & (-mask));
        cout << pos << endl;
        mask &= ~pos;
    }

    //return 0;

}