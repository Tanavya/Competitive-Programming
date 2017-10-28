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
 
const int mod = 1e9+7;

void solve() {

    int T;
    scanf("%d", &T);
    while (T--) {

        int N, l, b, h;
        scanf("%d %d %d %d", &N, &l, &b, &h);
        
        vll x(N), y(N), z(N);
        for (int i = 0; i < N; i++) {
            scanf("%lld %lld %lld", &x[i], &y[i], &z[i]);
        }

        x.pb(l);
        x.pb(0);

        y.pb(b);
        y.pb(0);

        z.pb(h);
        z.pb(0);

        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        sort(z.begin(), z.end());


        ll A, B, C;
        A = B = C = 0;
        for (int i = 0; i < x.size() - 1; i++) {
            A = max(A, x[i+1] - x[i]);
            B = max(B, y[i+1] - y[i]);
            C = max(C, z[i+1] - z[i]);
        }

        ll ans = (((A*B) % mod) * C) % mod;
        printf("%lld\n", ans);

    }
}


void solveIstashit() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin>>t;
    while(t--)
    {
        int n, l, b, h;
        cin>>n>>l>>b>>h;
        vector<int> x(n), y(n), z(n);
        x.push_back(0);
        x.push_back(l);
        y.push_back(0);
        y.push_back(b);
        z.push_back(0);
        z.push_back(h);
        for(int i = 0;i<n;i++)
            cin>>x[i]>>y[i]>>z[i];
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        sort(z.begin(), z.end());
        int a, c;
        a = b = c = 0;
        for(int i = 1;i<=n+1;i++)
            a = max(a, x[i]-x[i-1]), b = max(b, y[i]-y[i-1]), c = max(c, z[i]-z[i-1]);
        cout<<a*b*c<<endl;

    }
}

void gentc(int t) {
    int T = 5;
    cout << T << endl;
    const int maxl = 1e9;
    const int maxn = 1e5 - 100;
    while (T--) {
        int n, l, b, h;
        if (t == 0) {
            n = (rand() % 5) + 1;
            if (n == 1) n++;
            l = (rand() % 10) + 1;
            b = (rand() % 10) + 1;
            h = (rand() % 10) + 1;
        }
        else if (t < 5) {
            if (T == 1 && t == 1) n = 1;
            else n = (rand() % 10) + 10;
            l = (rand() % 100) + 1;
            b = (rand() % 100) + 1;
            h = (rand() % 100) + 1;
        }
        else if (t < 10) {
            n = (rand() % 290) + 10;
            l = (rand() % maxl) + 1;
            b = (rand() % maxl) + 1;
            h = (rand() % maxl) + 1;
        }
        else if (t < 15) {
            n = (rand() % maxn) + 100;
            l = (rand() % maxl) + 1;
            b = (rand() % maxl) + 1;
            h = (rand() % maxl) + 1;
        }
        printf("%d %d %d %d\n", n, l, b, h);
        for (int i = 0; i < n; i++) {
            printf("%d %d %d\n", (rand() % l) + 1, (rand() % b) + 1, (rand() % h) + 1);
        }
    }
}

int main() {

    for (int i = 0; i < 15; i++) {
        string loc = "input/input" + to_string(i) + ".txt";
        freopen(loc.c_str(), "w", stdout);
        gentc(i);
    }
    for (int i = 0; i < 15; i++) {
        string loc = "input/input" + to_string(i) + ".txt";
        freopen(loc.c_str(), "r", stdin);
        loc = "output/output" + to_string(i) + ".txt";
        freopen(loc.c_str(), "w", stdout);
        solve();
    }
}