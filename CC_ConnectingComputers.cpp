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
 
 
using namespace std;
unsigned long long s[2];
unsigned long long xorshift128plus() {
	unsigned long long x = s[0];
	const unsigned long long y = s[1];
	x ^= x << 23;
	s[1] = x ^ y ^ (x >> 17) ^ (y >> 26);
	return s[0] = y;
}
 
const int MX = 1000;
/*
int C[MX][MX];
int H[MX][MX];
*/
int size[1007], parent[1007];
vector <pair<int, ii>> edges;
ll answer = 0;
int ans[1007][1007];
vector <set <ii>> graph;
int root(int x) {
    while (parent[x] != x) {
        x = parent[x] = parent[parent[x]];
    }
    return x;
}
 
bool Find(int a, int b) {
    return root(a) == root(b);
}
 
void Union(int a, int b) {
    int root_a = root(a), root_b = root(b);
    if (root_a != root_b) {
        if (size[root_a] < size[root_b]) {
            parent[root_a] = root_b;
            size[root_b] += size[root_a];
        }
        else {
            parent[root_b] = root_a;
            size[root_a] += size[root_b];
        }
    }
}
void kruskals() {
    sort(edges.begin(), edges.end());
    for (pair <int, ii> edge: edges) {
        int w = edge.x, a = edge.y.x, b  = edge.y.y;
        if (!Find(a, b)) {
            Union(a, b);
            answer += w;
            ans[a][b] = ans[b][a] = 1;
            graph[a].erase(mp(w, b));
            graph[b].erase(mp(w, a));
        }
    }
}
 
 
int main() {
 
	#ifndef ONLINE_JUDGE 
		freopen("inp.txt", "r", stdin);
	#endif
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		int n, Cmax, Hmax;
		scanf("%d %d %d", &n, &Cmax, &Hmax);
		vector <vector <int>> C(n, vi(n, 0)), H (n, vi(n, 0));
 
		memset(size, 0, sizeof(size));
		memset(parent, 0, sizeof(parent));
		memset(ans, 0, sizeof(ans));
		edges.clear();
		graph.clear();
		graph.resize(n+7);
		answer = 0;
 
		for (int i = 0; i < n; i++) {
			C[i][i] = 0;
			scanf("%llu %llu", &s[0], &s[1]);
			for (int j = i + 1; j < n; j++) {
				C[i][j] = C[j][i] = xorshift128plus() % (Cmax + 1);
 
			}
		}
 
		for (int i = 0; i < n; i++) {
			scanf("%llu %llu", &s[0], &s[1]);
			for (int j = 0; j < n; j++) {
				H[i][j] = xorshift128plus() % (Hmax + 1);
	            if (i != j) {
		            graph[i].insert(mp(C[i][j],j));
	            }
			}
		}
 
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				edges.push_back(mp(C[i][j], mp(i, j)));
			}
		}
		for (int i = 0; i < n; i++) {
        	size[i] = 1;
        	parent[i] = i;
    	}
		kruskals();
 
		for (int i = 0; i < n; i++) {
			int curr = 0, cnt = 0;
			for (int j = 0; j < n; j++) {
				if (ans[i][j]) {
					curr += C[i][j];
					cnt++;
				}
			}
			int org_cnt = cnt;
			curr += H[i][org_cnt];
			int best = curr, best_pos = 0;
			vector <int> pre(graph[i].size() + 5, 0);
			int j = 1;
			for (ii edge : graph[i]) {
				int w = edge.x, k = edge.y;
				pre[j] = pre[j-1] + w;
				int temp = curr - H[i][org_cnt] + H[i][cnt+1] + pre[j] - H[k][graph[k].size()] + H[k][graph[k].size()+1];
				if (temp < best) {
					best = temp;
					best_pos = j; 
				}
				cnt++;
				j++;
			}
			if (best_pos) {
				int j = 1;
				for (ii edge : graph[i]) {
					if (j > best_pos) break;
					int w = edge.x, k = edge.y;
					assert(i != k);
					ans[i][k] = 1;
					ans[k][i] = 1;
					j++;
				}
			}
		}
 
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << ans[i][j] << "";
			}
			cout << endl;
		}
		
	}
	
	return 0;
} 