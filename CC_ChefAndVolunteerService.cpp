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

string rem1(string &S, int a) {
	//remove a "a" characters from S
	string S2 = "";
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == 'a' && a > 0) a--;
		else S2 += S[i];
	}

	return S2;
}
string rem2(string &S, int b) {
	//remove a "a" characters from S
	string S2 = "";
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == 'b' && b) b--;
		else S2 += S[i];

	}
	return S2;
}
void print_v(vector <string> S) {
	string ss = "";
	for (string lol : S) {
		ss += lol;
	}
	cout << ss << endl;
}

int main() {
	#ifndef ONLINE_JUDGE 
		freopen("inp.txt", "r", stdin);
	#endif
	int T;
	scanf("%d", &T);
	while (T--) {
		int x, y;
		string S;
		cin >> S;
		scanf("%d %d", &x, &y);
		int N = S.size();
		int a = 0, b = 0;
		for (int i = 0; i < N; i++) {
			if (S[i] == 'a') a++;
			else b++;
		}
		int block_n = max(int(ceil(float(a)/x)), int(ceil(float(b)/y)));
		string block = "";
		if (a > b) {
			for (int i = 0; i < x; i++) {
				block += "a";
			}
			for (int i = 0; i < y; i++) {
				block += "b";
			}
		}
		else {
			for (int i = 0; i < y; i++) {
				block += "b";
			}			for (int i = 0; i < x; i++) {
				block += "a";
			}
		}
		vector <string> blocks;

		for (int i = 0; i < block_n; i++) {
			blocks.pb(block);
		}

		//print_v(blocks);

		int cnt_a = block_n * x;
		int cnt_b = block_n * y;
		int rem_a = cnt_a - a, rem_b = cnt_b - b;
		assert(rem_a >= 0 && rem_b >= 0);
		
		int avg_a = rem_a / block_n;
		int extra_a = rem_a % block_n;

		int avg_b = rem_b / block_n;
		int extra_b = rem_b % block_n;

		//cout << rem_a << " " << rem_b << endl;
		//cout << avg_a << " " << avg_b << endl;
		string ans = "";
		for (int i = 0; i < block_n; i++) {
			blocks[i] = rem1(blocks[i], avg_a);
			blocks[i] = rem2(blocks[i], avg_b);
		}

		for (int i = block_n - 1; i >= 0; i--) {
			if (extra_a > 0) {
				blocks[i] = rem1(blocks[i], 1);
				extra_a--;
				if (1 + avg_a >= x) blocks[i] += "*";
			}
			if (extra_b > 0) {
				blocks[i] = rem2(blocks[i], 1);	
				extra_b--;
				if (1 + avg_b >= y) blocks[i] += "*";
			}
			if (avg_a >= x) blocks[i] += "*";
			if (avg_b >= y) blocks[i] += "*"; 
		}
		string temp = "";
		for (string lol : blocks) {
			temp += lol;
		}
		for (int i = temp.size() - 1; i >= 0; i--) {
			if (temp[i] != '*') break;
			temp[i] = '-';
		}
		for (char c : temp) {
			if (c != '-') ans += c;
		}
		cout << ans << endl;
	}
}