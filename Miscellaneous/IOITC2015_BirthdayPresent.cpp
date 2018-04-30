#include <iostream>
#include <vector>
#include <stdio.h>
#include <set>
#include <queue>
#include <assert.h>


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

const int INF = 2147483647;
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
using namespace std;

const int maxn = 10007;
char S[maxn];
int A[maxn], cnt2[maxn], cnt[30], ans[maxn][30];

void add(int ch) {
    cnt[ch]++;
    cnt2[cnt[ch]]++;
}

void rem(int ch) {
    cnt2[cnt[ch]]--;
    cnt[ch]--;
}

int main() {
    int N;
    scanf("%d", &N);
    scanf("%s", S);
    for (int i = 1; i <= N; i++) {
        A[i] = int(S[i-1]) - 97;
    }
    for (int i = 1; i <= N; i++) {
        add(A[i]);
        for (int t = 1; t <= N; t++) {
            ans[t][cnt2[t]] += i;
        }
        for (int j = 1; j < i; j++) {
            int c_old = cnt[A[j]];
            ans[c_old][cnt2[c_old]] -= (i-j);
            rem(A[j]);
            ans[c_old][cnt2[c_old]] += (i-j);
        }
        for (int j = 1; j < i; j++) {
            add(A[j]);
        }
    }
    int Q;
    scanf("%d", &Q);
    while (Q--) {
        int t;
        scanf("%d", &t);
        for (int i = 0; i <= 26; i++) printf("%d ", ans[t][i]); printf("\n");
    }
}
/*
6
aabccc
6
1 2 3 4 5 6
 */