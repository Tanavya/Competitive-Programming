//STUPID QUESTION. Should have mentioned we have only ONE set of Winter and Summer tires. Wastedforeveronthis. :(
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
    #ifndef ONLINE_JUDGE
        freopen("inp.txt", "r", stdin);
    #endif
    int N, K, temp;
    scanf("%d %d", &N, &K);
    vi A (N + 7, -INF);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &temp);
        A[i] = (temp >= 0);
    }
    int max_pos = 0, tire = 1, k = 0, changed = 0, impossible = 0, k_here = 0;
    //1 -> summer tire
    //0 -> winter tire
    for (int i = 1; i <= N; i++) {
        if (tire) {
            if (!A[i]) {
                tire = 0;
                k = 1;
                changed ++;
            }
        }
        else {
            if (A[i]) {
                max_pos = max(i, max_pos);
            }
            if (k == K) {
                if (A[i]) {
                    changed ++;
                    tire = 1;
                    k = 0;
                }
                else {
                    cout << k_here << endl;
                    changed += 2;
                    k = k_here + i - max_pos;
                    if (k >= K) {
                        impossible = true;
                        break;
                    }
                }
            }
            if (!A[i] && k != K) k_here = k;
            k++;
        }
    }
    if (impossible) cout << -1 << endl;
    else printf("%d\n", changed);
}