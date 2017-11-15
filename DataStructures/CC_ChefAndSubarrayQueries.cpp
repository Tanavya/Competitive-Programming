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

const int maxn = (int)5e5+10;
ll tree[maxn*4], lazy[maxn*4], A[maxn], dp[maxn];
int stree[maxn*4], B[maxn];

int N, Q, L, R;

inline int right(int i) { return i << 1; }
inline int left(int i ) { return (i << 1) + 1; }

//sum segtree

void build(int i, int L, int R) {
    if (L == R) {
        stree[i] = B[L];
    }
    else {
        int mid = (L+R)/2;
        build(left(i), L, mid);
        build(right(i), mid+1, R);
        stree[i] = stree[left(i)] + stree[right(i)];
    }
}
void update(int i, int L, int R, int idx, int val) {
    if (L == R) {
        assert(L == idx);
        B[L] = val;
        stree[i] = B[L];
    }
    else {
        int mid = (L+R)/2;
        if (mid >= idx) {
            update(left(i), L, mid, idx, val);
        }
        else {
            update(right(i), mid+1, R, idx, val);
        }
        stree[i] = stree[left(i)] + stree[right(i)];
    }
}
int query(int i, int L, int R, int li, int ri) {
    if (L > ri || R < li)
        return 0;
    else if (li <= L && ri >= R)
        return stree[i];
    else {
        int mid = (L+R)/2;
        return query(left(i), L, mid, li, ri) + query(right(i), mid+1, R, li, ri);
    }
}


//lazy seg tree
void propagate(int i, int L, int R, ll val) {
    tree[i] += (R - L + 1) * val;
    if (L != R) {
        lazy[left(i)] += val;
        lazy[right(i)] += val;
    }
}

void updateRange(int i, int L, int R, int li, int ri, ll val) {
    if (lazy[i]) {
        propagate(i, L, R, lazy[i]);
        lazy[i] = 0;
    }
    if (li > R || ri < L)
        return;
    else if (li <= L && ri >= R) {
        propagate(i, L, R, val);
        return;
    }
    int mid = (L+R)/2;
    updateRange(left(i), L, mid, li, ri, val);
    updateRange(right(i), mid+1, R, li, ri, val);
    tree[i] = tree[left(i)] + tree[right(i)];
}

ll queryRange(int i, int L, int R, int li, int ri) {
    if (lazy[i]) {
        propagate(i, L, R, lazy[i]);
        lazy[i] = 0;
    }
    if (li > R || ri < L)
        return 0 ;
    else if (li <= L && ri >= R) {
        return tree[i];
    }
    int mid = (L+R)/2;
    ll p1 = queryRange(left(i), L, mid, li, ri);
    ll p2 = queryRange(right(i), mid+1, R, li, ri);
    return p1 + p2;
}

ll brute(int li, int ri) {
    for (int i = 1; i <= N; i++) dp[i] = 0;
    ll ret = 0, cnt = 0;
    for (int i = li; i <= ri; i++) {
        if (A[i] >= L && A[i] <= R)
            dp[i] = dp[i-1] + 1;
        else if (A[i] <= R)
            dp[i] = dp[i-1];
        else
            dp[i] = 0;
        if (A[i] >= L && A[i] <= R)
            dp[i] += cnt;
        ret += dp[i];
        if (A[i] < L)
            cnt++;
        else
            cnt = 0;
    }
    return ret;
}
ll bruteworse(int li, int ri) {
    ll ret = 0;
    for (int i = li; i <= ri; i++) {
        ll hi = 0;
        for (int j = i; j <= ri; j++) {
            hi = max(hi, A[j]);
            if (hi >= L && hi <= R) {
                ret++;
            }
        }
    }
    return ret;
}

void checkErrors() {
    srand(time(NULL));
    scanf("%d %d %d %d", &N, &Q, &L, &R);
    int type, i, li, ri;
    ll r;
    while (Q--) {
        cout << "A: ";
        for (int i = 1; i <= N; i++)
            cout << A[i] << " ";
        cout << endl;
        //scanf("%d", &type);
        type = (rand() % 2) + 1;
        if (type == 1) {
            //scanf("%d %lld", &i, &r);
            i = (rand() % N) + 1;
            r = ((rand()) % (2 * R)) + 1;
            A[i] = r;
            cout << type << " " << i << " " << r << endl;
        } else {
            //scanf("%d %d", &li, &ri);
            li = (rand() % N) + 1;
            ri = (rand() % N) + 1;
            if (li > ri) swap(li, ri);
            cout << type << " " << li << " " << ri << endl;
            printf("Brute correct: %lld\n", bruteworse(li, ri));
            printf("Brute wrong  : %lld\n", brute(li, ri));
            assert(brute(li, ri) == bruteworse(li, ri));
        }
    }
}

void solveBrute() {
    scanf("%d %d %d %d", &N, &Q, &L, &R);
    int type, i, li, ri;
    ll r;
    while (Q--) {
        scanf("%d", &type);
        if (type == 1) {
            scanf("%d %lld", &i, &r);
            A[i] = r;
        } else {
            scanf("%d %d", &li, &ri);
            printf("%lld\n", brute(li, ri));
        }
    }
}

int binsearch(int L, int R) {
    int ret = -1;
    while (L<R) {
        int mid = (L+R)/2;
        int x = query(1, 1, N, mid, R);
        //cout << "L: " << L << ", R: " << R << endl;
        //cout << "mid: " << mid <<", x: " << x << endl;
        if (x == (R-mid+1)) {
            R = mid;
            ret = mid;
        }
        else {
            L = mid+1;
        }
    }
    if (L == R && B[L] == 1)
        return L;
    else
        return ret;
}

int main() {
    /*
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int c;
        cin >> c;
        update(1, 1, N, i, c);
    }
    for (int i = 1; i <= N; i++) cout << query(1, 1, N, i, i) << " "; cout << endl;
    cout << binsearch(1, 3) << endl;
    */


    scanf("%d %d %d %d", &N, &Q, &L, &R);
    int type, i, li, ri;
    ll r;
    for (int j = 1; j <= N; j++) {
        B[j] = 1;
    }
    build(1, 1, N);
    cout << stree[1] << endl;

    vector <ii> future_updates;

    while (Q--) {

        //cout << "A:  "; for (int j = 1; j <= N; j++) cout << A[j] << " "; cout << endl;
        //cout << "B:  "; for (int j = 1; j <= N; j++) cout << B[j] << " "; cout << endl;
        //cout << "dp: "; for (int j = 1; j <= N; j++) cout << queryRange(1, 1, N, j, j) << " "; cout << endl;
        //scanf("%d", &type);
        type = (rand() % 2) + 1;
        if (type == 1) {

            i = (rand() % N) + 1; r = ((rand()) % (2 * R)) + 1; cout << type << " " << i << " " << r << endl;
            //scanf("%d %lld", &i, &r);
            int u;
            if (r < L)
                u = 1;
            else
                u = 0;

            update(1, 1, N, i, u);

            if (r < L) {
                if (A[i] >= L && A[i] <= R) {
                    updateRange(1, 1, N, i, N, -1);
                }
                else if (A[i] > R) {
                    updateRange(1, 1, N, i, N, 1);
                }
                else {
                    assert (A[i] < L);
                }
                A[i] = r;

            }
            else if (r > R) {
                future_updates.pb({i, r});
            }
            else {
                assert(r >= L && r <= R);
                if (A[i] < L || A[i] > R) {
                    //for (int j = 1; j <= N; j++) cout << query(1, 1, N, j, j) << " "; cout << endl;
                    ll inc = 1;
                    if (i == 2) inc += queryRange(1, 1, N, 1, i-1);
                    else if (i > 2) inc += queryRange(1, 1, N, 1, i-1) - queryRange(1, 1, N, 1, i-2);
                    if (i == 1)
                        updateRange(1, 1, N, i, N, 1);
                    else {
                        int last = binsearch(1, i - 1);
                        if (last != -1) {
                            updateRange(1, 1, N, i, N, inc + i - last);
                        }
                    }
                }
                A[i] = r;

            }
        }
        else {
            while (!future_updates.empty()) {
                ii top = future_updates[(int)future_updates.size()-1];
                future_updates.pop_back();
                i = top.x, r = top.y;
                if (A[i] <= R) {
                    ll rem;
                    if (i == 1) rem = queryRange(1, 1, N, 1, i);
                    else rem = queryRange(1, 1, N, 1, i) - queryRange(1, 1, N, 1, i - 1);

                    updateRange(1, 1, N, i, N, -rem);
                }
                A[i] = r;
            }
            li = (rand() % N) + 1; ri = (rand() % N) + 1; if (li > ri) swap(li, ri); cout << type << " " << li << " " << ri << endl;

            //scanf("%d %d", &li, &ri);

            cout << "A:  "; for (int j = 1; j <= N; j++) cout << setw(2) << A[j] << " "; cout << endl;
            cout << "B:  "; for (int j = 1; j <= N; j++) cout << setw(2) << B[j] << " "; cout << endl;
            cout << "dp: "; for (int j = 1; j <= N; j++) cout << setw(2) << queryRange(1, 1, N, j, j) << " "; cout << endl;

            ll ans;
            if (li == 1) ans = queryRange(1, 1, N, 1, ri);
            else ans = queryRange(1, 1, N, 1, ri) - queryRange(1, 1, N, 1, li-1) * (ri-li+2);
            printf("AC  : %lld\n", brute(li, ri));
            printf("Mine: %lld\n", ans);
            assert(ans == brute(li, ri));
        }
     }
}
//0 0 3 3 5 5
//
/*
6 100 1 10
1 1 15
1 2 0
1 3 7
1 4 0
1 5 0
1 6 4
2 1 5
 */