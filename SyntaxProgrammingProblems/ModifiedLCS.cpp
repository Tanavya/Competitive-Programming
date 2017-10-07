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

string A, B;
int K;

void solve() {
	int T;
	scanf("%d", &T);
	while (T--) {
        scanf("%d", &K);
        cin >> A;
        cin >> B;
		int k = K, dp[1005][1005], i, j, xlen, ylen, c;
		string x = A, y = B;

		xlen = x.size();
		ylen = y.size();

		for(i=0; i<=xlen; i++){
			for(j=0; j<=ylen; j++){
				dp[i][j] = 0;
				if(i==0 || j==0)
					continue;

				c = 1;
				while(i-c>=0 && j-c>=0 && x[i-c]==y[j-c]){
					if(c>=k)
						dp[i][j] = MAX(dp[i][j], c+dp[i-c][j-c]);
					c++;
				}
				dp[i][j] = MAX(dp[i][j], dp[i-1][j]);
				dp[i][j] = MAX(dp[i][j], dp[i][j-1]);
			}
		}
		cout << dp[xlen][ylen] << endl;
	}
}


string rand_string(int len) {
	string S = "";
	for (int i = 0; i < len; i++) {
		S += char((rand() % 26) + 97);
	}
	return S;
}

string choose_rand(vector <string> opt) {
	return opt[(rand() % opt.size())];
}
int choose_rand(vector <int> opt) {
	return opt[(rand() % opt.size())];
}
void tc2() {
	cout << "1\nmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb\nllllllllllllllbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaavaaaaaaaaaaaaaaaaaaaaaaaa\n";
}

void gen_tcs(int i) {
	if (i == 10) {
		cout << 10 << endl;
		for (int t = 0; t < 5; t++) {
			int K = 1;
			int N = (rand() % 350) + 50, M = (rand() % 350) + 50;
			string A = rand_string(N);
			string B = rand_string(M);
			cout << K << endl;
			cout << A << endl;
			cout << B << endl;
		}
		for (int t = 0; t < 5; t++) tc2();
	}
	else if (i > 6) { 
		//somewhat meaningful answers
		cout << 10 << endl;
		for (int tt = 0; tt < 6; tt++) {
			int K, N, M;
			N = 400, M = 400;
			vector <string> blocks;
			vector <int> sizes;
			int rem = N;
			while (rem) {
				int x = (rand() % (N/5)) + 1;
				string r = rand_string(x);
				blocks.pb(r);
				sizes.pb(x);
				rem -= x;
				if (rem < 0) break;
			}
			string A = "", B = "";
			for (int i = 0; i < blocks.size(); i++) {
				A += choose_rand(blocks);
				B += choose_rand(blocks);
			}

			K = choose_rand(sizes);
			cout << K << endl;
			cout << A << endl;
			cout << B << endl;
		}
		for (int t = 0; t < 4; t++) tc2();
	}
	else if (i > 5) {
		//to get TLE
		cout << 10 << endl;
		for (int t = 0; t < 3; t++) {
			int K = 100;
			int N = (rand() % 350) + 50, M = (rand() % 350) + 50;
			string A = rand_string(N);
			string B = rand_string(M);
			cout << K << endl;
			cout << A << endl;
			cout << B << endl;
		}
		for (int t = 0; t < 7; t++) tc2();
	}
	else {
		cout << 10 << endl;
		for (int t = 0; t < 10; t++) {
			int K = (rand() % 3) + 1;
			int N = (rand() % 8) + 2, M = (rand() % 8) + 2;
			string A = "", B = "";
			for (int i = 0; i < N; i++) {
				A += char((rand() % 5) + 97);
			}
			for (int i = 0; i < M; i++) {
				B += char((rand() % 5) + 97);
			}
			cout << K << endl;
			cout << A << endl;
			cout << B << endl;
		}
	}
}

int main() {
	
	srand(time(NULL));
	#ifndef ONLINE_JUDGE 
		freopen("inp.txt", "r", stdin); 
	#endif
	/*
    for (int i = 0; i <= 10; i++) {
    	string loc = "ModifiedLCS/input/input" + to_string(i) + ".txt";
        freopen(loc.c_str(), "w", stdout);
    	if (!i) {
    		cout << "4\n3\nlovxxelyxxxxx\nxxxxxxxlovely\n1\nlovxxelyxxxxx\nxxxxxxxlovely\n3\nlovxxxelxyxxxx\nxxxlovelyxxxxxxx\n4\nlovxxxelyxxx\nxxxxxxlovely\n";
    	}
        else {
        	gen_tcs(i);
        }
	}*/
	for (int i = 0; i <= 8; i++) {
		string loc = "ModifiedLCS/input/input" + to_string(i) + ".txt";
		freopen(loc.c_str(), "r", stdin);
		loc = "ModifiedLCS/output/output" + to_string(i) + ".txt";
		freopen(loc.c_str(), "w", stdout);
		solve();
	}
}