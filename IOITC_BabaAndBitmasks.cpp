#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <stdio.h>
#include <stack>
#include <set>
#include <list>
#include <cmath>
#include <assert.h>
#include <bitset>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip> //cout << setprecision(node) << fixed << num

#define mp make_pair
#define pb push_back
#define x first
#define y second
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << "\n";

typedef long long int ll;
typedef long double ld;
typedef std::pair <int, int> ii;
typedef std::vector <int> vi;
typedef std::vector <ll> vll;
const int INF = int(1e9);
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

using namespace std;

inline int f(int m1, int m2) {
    return ((m1|m2) * (m1|m2)) - ((m1&m2) * (m1&m2));
}

int main() {
    int T, N;
    scanf("%d", &T);
    while (T--) {
        int ans = 0;
        scanf("%d", &N);
        int A[N];
        for (int i = 0; i < N; i++)
            scanf("%d", &A[i]);
        stack <int> st;
        st.push(A[0]);
        for (int i = 1; i < N; i++) {
            if (A[i] < st.top()) {
                ans = max(ans, f(A[i], st.top));
                st.push(A[i]);
            }
        }
    }

}