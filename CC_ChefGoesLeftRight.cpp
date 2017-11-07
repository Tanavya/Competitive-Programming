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

int main() {
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
#endif
    int T, N, R;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &N, &R);
        vector <int> ratings(N);
        for (int i = 0; i < N; i++) {
            scanf("%d", &ratings[i]);
        }
        int i = 0;
        int dir = 0; //0 = left, 1 = right
        int l = -INF, r = 2*INF;
        if (ratings[0] > R) {
            dir = 0;
        }
        else if (ratings[0] < R) {
            dir = 1;
        }
        else {
            assert(N == 1);
            cout << "YES" << endl;
            continue;
        }
        bool ok = true;
        while (i < N-1) {
            if (dir == 0) {
                if (ratings[i+1] < ratings[i]) {
                    if (ratings[i+1] < l) {
                        ok = false;
                        break;
                    }
                    else {
                        r = ratings[i];
                    }
                }
                else {
                    dir = 1;

                    if (ratings[i+1] > r) {
                        ok = false;
                        break;
                    }
                    else {
                        l = ratings[i];
                    }
                }
            }
            else {
                if (ratings[i+1] > ratings[i]) {
                    if (ratings[i+1] > r) {
                        ok = false;
                        break;
                    }
                    else {
                        l = ratings[i];
                    }
                }
                else {
                    dir = 0;

                    if (ratings[i+1] < l) {
                        ok = false;
                        break;
                    }
                    else {
                        r = ratings[i];
                    }
                }
            }
            i++;
        }
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }

}