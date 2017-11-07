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

int main() {
  
  	#ifndef ONLINE_JUDGE
	  freopen("inp.txt", "r", stdin);
	#endif
	
	int M;
	while (true) {
		cin >> M;
    cin.ignore();
		if (!M) break;

		string word, line;
		vector <string> insig(M+1);
		map <string, int> insig_words;

		for (int i = 1; i <= M; i++) {
			getline(cin, insig[i]);
			insig_words[insig[i]] = i;
		}
		
		while (true) {

			string abv;
			vector <string> words;
			
			getline(cin, line);
			istringstream iss(line);
  
			//cout << line << endl;
			iss >> word;
			if (word == "LAST") {
				abv = word;
				iss >> word;
				if (word == "CASE") {
					break;
				}
				else {
					words.pb(word);
				}
			}
			else {
				abv = word;
			}
			
			int L = 0;
			while (iss >> word) {
				if (!insig_words[word]) {
				  words.pb(word);
				  L = max(L, (int)word.size());
				}
			}

			int N = words.size();
			int K = abv.size();
  
      
			ll dp[N][L+7][K];
			memset(dp, 0, sizeof(dp));

			for (int i = 0; i < N; i++) {
				word = words[i];
				//cout << word << endl;
				 for (int k = 0; k < K; k++) {
				for (int j = 0; j < word.size(); j++) {
				 
		            
		            dp[i][j][k] = 0;
				    if (j) dp[i][j][k] = dp[i][j-1][k];
				    //if (i) dp[i][j][k] += dp[i-1][words[i-1].size()-1][k];
				    
						if (word[j] == tolower(abv[k])) {
							if (!i && !k) dp[i][j][k] += 1;
							else if (!i && k && j) dp[i][j][k] += dp[i][j-1][k-1];
							else if (i && k) {
							  //cout << i << " " << j << " " << k << endl;
							  dp[i][j][k] += dp[i-1][words[i-1].size()-1][k-1];
							  if (j) dp[i][j][k] += dp[i][j-1][k-1];
							}
						}
				
						//cout << "dp[" << i << "][" << j << "][" << k << "] = " << dp[i][j][k] << "\n";
					}
				}
			}
			
			if (!dp[N-1][words[N-1].size()-1][K-1]) cout << abv << " is not a valid abbreviation\n";
			else cout << abv << " can be formed in " << dp[N-1][words[N-1].size()-1][K-1] << " ways\n";
		}
	}

}