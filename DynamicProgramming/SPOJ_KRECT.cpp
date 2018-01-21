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


#define all(x) x.begin(), x.end()
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

const int maxn = 107;
int dp[maxn][maxn][maxn][maxn], grid[maxn][maxn];

int num_on(int msk) {
    int cnt = 0;
    for (int i = 0; i < 26; i++) {
        if (msk & (1 << i))
            cnt++;
    }
    return cnt;
}
void print_mask(int mask) {
    bitset<26> bs(mask);
    string str_mask = bs.to_string();
    reverse(str_mask.begin(), str_mask.end());
    cout << str_mask << endl;
}

int brute_check(int i, int j, int k, int l) {
    set <int> S;
    for (int a = i; a <= k; a++) {
        for (int b = j; b <= l; b++) {
            S.insert(grid[a][b]);
        }
    }
    return (int)S.size();
}
int main() {

    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);

    string line;
    for (int i = 1; i <= N; i++) {
        cin >> line;
        for (int j = 1; j <= M; j++) {
            grid[i][j] = int(line[j-1]) - 65;
        }
    }
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            for (int k = i; k <= N; k++) {
                for (int l = j; l <= M; l++) {
                    dp[i][j][k][l] = (((1 << grid[k][l]) | dp[i][j][k-1][l]) | dp[i][j][k][l-1]);
                    //cout << i << " " << j << " " << k << " " << l << " "; print_mask(dp[i][j][k][l]);
                    if (num_on(dp[i][j][k][l]) == K)
                        cnt++;
                }
            }
        }
    }
    printf("%d\n", cnt);
}