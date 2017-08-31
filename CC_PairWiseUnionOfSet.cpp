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
    int T, N, K;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &N, &K);
        vector <vi> A(N);
        for (int i = 0; i < N; i++) {
            int len, tmp;
            scanf("%d", &len);
            for (int j = 0; j < len; j++) {
                scanf("%d", &tmp);
                A[i].pb(tmp);
            }
            sort(A[i].begin(), A[i].end());
        }
        int cnt = 0;
        bitset <2501> mark;
        for (int i = 0; i < N; i++) {
            for (int j = i+1; j < N; j++) {
                if (A[i].size() + A[j].size() < K) continue;
                int tmp_cnt = A[i].size();
                mark.reset();
                for (int x : A[i]) {
                    mark[x] = true;
                }
                for (int y : A[j]) {
                    if (!mark[y]) 
                        tmp_cnt++;
                }
                if (tmp_cnt == K) cnt++;
            }
        }
        printf("%d\n", cnt);
    }
}