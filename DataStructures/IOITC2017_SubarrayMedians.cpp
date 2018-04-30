#include <vector>
#include <algorithm>
#include <stdio.h>
#include <assert.h>
#include <cmath>
#include <cstring>

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
typedef std::vector <ii> vii;
typedef std::vector <ll> vll;
typedef std::vector <ld> vld;

const int INF = int(1e9);
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
using namespace std;

const int maxn = (int)1e5+10, size = 300, OFFSET = 300;
int N, total[500], cnt[500][1000], val[maxn], rev_A[maxn];

ll brute(vi A) {
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        int cnt = 0;
        ans++;
        for (int j = i+1; j < N; j++) {
            if (A[j] < A[i]) cnt++;
            else cnt--;
            if (cnt == 0 || cnt == 1) ans++;
        }
        cnt = 0;
        for (int j = i-1; j >= 0; j--) {
            if (A[j] < A[i]) cnt++;
            else cnt--;
            if (cnt == 0 || cnt == 1) ans++;
        }
    }
    return ans;
}

void build_block(int b) {
    memset(cnt[b], 0, sizeof(cnt[b]));
    int sum = 0;
    for (int j = b*size; j < (b+1)*size && j < N; j++) {
        sum += val[j];
        cnt[b][sum+OFFSET]++;
    }
    total[b] = sum;
}

int get(int b, int k) {
    if (abs(k) > size) return 0;
    return cnt[b][k+OFFSET];
}

ll calc(vi A) {
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        rev_A[A[i]] = i;
    }
    memset(val, -1, sizeof(val));
    for (int i = 0; i < N; i += size) {
        build_block(i/size);
    }
    for (int v = 1; v <= N; v++) {
        int i = rev_A[v];
        int b = i/size;
        int sum = 0;
        for (int j = i; j < (b+1) * size && j < N; j++) {
            sum += val[j];
            if (sum == 0 || sum == -1) ans++;
        }
        for (int j = (b+1) * size; j < N; j += size) {
            b = j/size;
            ans += get(b, -sum) + get(b, -sum-1);
            sum += total[b];
        }
        val[i] = 1;
        build_block(i/size);
    }
    return ans;
}

int main() {
    //freopen("inp.txt", "r", stdin);
    scanf("%d", &N);
    vi A(N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    ll ans = calc(A);
    reverse(all(A));
    ans += calc(A) - N;
    printf("%lld\n", ans);
}