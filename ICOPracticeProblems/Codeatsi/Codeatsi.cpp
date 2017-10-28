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
 
struct person
{
  string nm;
  int first, second;
};
map<string, int> pcode;
map<string, int> user;
vector< person > points;
int arr[1005][1005];
vector<int> tm;
struct usort
{
  bool operator()(const person &a, const person &b)
  {
    if(a.first==b.first)
    {
      return tm[a.second] < tm[b.second];
    }
    return a.first>b.first;
  }
};
 
void solve()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int t;
  cin >> t;
  while(t--)
  {
    pcode.clear();
    user.clear();
    points.clear();
    tm.clear();
    person temp;
    points.push_back(temp);
    tm.push_back(0);
    for(int i = 0; i <= 1001; i++)
    {
        for(int j = 0; j <= 1001; j++)
        {
            arr[i][j]=0;
        }
    }
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
      string s;
      cin >> s;
      pcode[s]=i;
    }
    int users=1;
    for(int i = 1; i <= n; i++)
    {
      string u, p;
      int uind, pind, score;
      cin >> u >> p >> score;
      if(user.find(u)==user.end())
      {
        user[u]=users;
        person temp;
        temp.first=0;
        temp.second=users;
        temp.nm=u;
        points.push_back(temp);
        tm.push_back(0);
        users++;
       // cout << points[users-1].nm << endl;
      }
      uind=user[u];
      pind=pcode[p];
      if(score>arr[uind][pind])
      {
        points[uind].first+=score-arr[uind][pind];
        arr[uind][pind]=score;
        tm[uind]=i;
      }
    }
    sort(points.begin()+1, points.end(), usort());
    cout << users-1 << "\n";
    for(int i = 1; i < points.size(); i++)
    {
      cout << points[i].nm << " " << points[i].first << "\n";
    }
  }
}

string rand_string(int L) {
	string ret = "";
	for (int i = 0; i < L; i++) {
		ret += char((rand() % 26) + 65);
	}
	return ret;
}

void gentc(int t) {
	int T = 10;
	if (t == 0) T = 3;
	cout << T << endl;
	while (T--) {
		int N, M;
		if (t == 0) {
			N = (rand() % 5) + 1;
			M = (rand() % 10) + 1;
		}
		else if (t < 5) {
			N = (rand() % 9) + 1;
			M = (rand() % 1000) + 1;
		}
		else {
			N = (rand() % 800) + 200;
			M = (rand() % 800) + 200;
		}
		cout << N << " " << M << endl;
		vector <string> problems;
		for (int i = 0; i < M; i++) {
			string prob = rand_string((rand() % 8) + 1);
			problems.pb(prob);
			cout << prob << " ";
		}
		cout << endl;
		int u = (rand() % 600) + 400;
		vector <string> users;
		for (int i = 0; i < u; i++) {
			users.pb(rand_string((rand() % 8) + 1));
		}
		for (int i = 0; i < N; i++) {
			cout << users[i % u] << " " << problems[rand() % M] << " " << (rand() % 100) + 1 << endl;
		}
	}
}
int main() {
	srand(time(NULL));
    
    for (int i = 0; i < 10; i++) {
        string loc = "input/input" + to_string(i) + ".txt";
        freopen(loc.c_str(), "w", stdout);
        gentc(i);
    }
    for (int i = 0; i < 10; i++) {
        string loc = "input/input" + to_string(i) + ".txt";
        freopen(loc.c_str(), "r", stdin);
        loc = "output/output" + to_string(i) + ".txt";
        freopen(loc.c_str(), "w", stdout);
        solve();
    }

}