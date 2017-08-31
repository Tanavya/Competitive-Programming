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
 
int main() {
    int T;
    string S;
    scanf("%d", &T);
    while (T--) {
        cin >> S;
        string tmp = "";
        for (char sign : S) {
            if (sign != '=') 
                tmp += string{sign};
        }
        S = tmp;
        int N = S.size();
        if (N == 0) {
            cout << 1 << endl;
            continue;
        }
        int up = 1, down = 1, ans = 1;
        for (int i = 0; i < N; i++) {
            char sign = S[i];
            if (sign == '<') {
                up++;
                down = 1;
            }
            else {
                down++;
                up = 1;
            }
            ans = max(ans, max(up, down));
        }
        cout << ans << endl;
    }
} 