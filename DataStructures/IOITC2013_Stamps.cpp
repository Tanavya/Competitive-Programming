#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <assert.h>
#include <queue>
#include <bitset>
#include <map>

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << endl;
#define debug(x) cout << x << endl;
#define debug2(x,y) cout << x << " " << y << endl;
#define debug3(x,y,z) cout << x << " " << y << " " << z << endl;
#define debug4(a,b,c,d) cout << a << " " << b << " " << c << " " << d << endl;
#define debug5(a,b,c,d,e) cout << a << " " << b << " " << c << " " << d << " " << e << endl;
#define trace(x) cout << #x << ": " << x << endl;

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

const int maxn = 100007, maxm = 10007;
char S[maxn], stamps[11][maxm];
int M[11];
vi MAP[11][30];

int find(int s, int L, char c) {
    auto it = lower_bound(all(MAP[s][c-97]), L);
    if (it == MAP[s][c-97].end()) return INF;
    return *it;
}

int main() {
    int K, N;
    scanf("%d %d", &K, &N);
    scanf("%s", S);
    for (int i = 0; i < K; i++) {
        scanf("%d", &M[i]);
        scanf("%s", stamps[i]);
        for (int j = 0; j < M[i]; j++) {
            MAP[i][stamps[i][j]-97].pb(j);
        }
    }
    int pointer = -1, ans = 0;
    while (pointer+1 < N) {
        int best = 0;
        for (int s = 0; s < K; s++) {
            int j = 0, i = pointer;
            while (j < M[s] && i+1 < N) {
                j = find(s, j, S[i+1]);
                if (j < M[s] && i+1 < N) {
                    i++; j++;
                }
            }
            best = max(best, i);
        }
        if (pointer == best) {
            printf("-1\n");
            return 0;
        }
        pointer = best;
        ans++;
    }
    printf("%d\n", ans);
}
/*
3
15 indianteamtoioi
5 india
8 topcoder
11 mathematics
 */