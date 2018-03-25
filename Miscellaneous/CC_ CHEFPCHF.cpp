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
	int T;
	scanf("%d", &T);
	while (T--) {
		int N, K, a, b;
		scanf("%d %d", &N, &K);
		vi S(N);
		for (int i = 0; i< K; i++) {
			scanf("%d %d", &a, &b);
			S[a-1] = b;
		}
		

		vi T;
		for (int i = 0; i < N; i++) {
			T.pb(-1);
			T.pb(S[i]);
		}
		T.pb(-1);
		//print(T);
		vi P(T.size(), 0);

		int center=0,boundary=0,maxLen=0,resCenter=0;
        for(int i=1;i<T.size()-1;i++) {
            int iMirror=2*center-i; // calc mirror i = center-(i-center)
            P[i]=(boundary>i)?min(boundary-i,P[iMirror]):0; // shortcut
            while(i-1-P[i]>=0&&i+1+P[i]<=T.size()-1&&T[i+1+P[i]] == T[i-1-P[i]]) // Attempt to expand palindrome centered at i
                P[i]++;
            if(i+P[i]>boundary) { // update center and boundary
                center = i;
                boundary = i+P[i];
            }
            if(P[i]>maxLen) { // update result
                maxLen = P[i];
                resCenter = i;
            }    
        }
		ll cnt = 0;
		for (int i = 0; i < P.size(); i++) {
			if (P[i] % 2 == 1) {
				cnt += (P[i] / 2 + 1);
			} 
		}
		cout << cnt << endl;
	}
}