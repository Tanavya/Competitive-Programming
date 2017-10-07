#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#define print(arr) for (auto i = arr.begin(); i != arr.end(); ++i) cout << *i << " "; cout << endl;
using namespace std;
typedef unordered_map <long, vector <long>> graph ;
long int n = 0;
const int mod = 1e9+7;
void PrintGraph(graph G) {
  for (auto it = G.begin(); it != G.end(); ++it) {
    vector <long> neighbours = it->second;
    cout << it->first << ": ";
    print(neighbours);
  }
}

bool DFS(graph &G, int node, int target, vector <bool> &visited) {
  if (node == target) return true;
  for (auto it = G[node].begin(); it != G[node].end(); ++it) {
      if (visited[*it]) continue;
      visited[*it] = true;
      if (DFS(G, *it, target, visited)) return true;
   }
  return false;
}


bool ContainsCycle(graph &G, int node, vector <bool> &visited, vector <bool> &recursiveStack, vector <int> &finishing_time) {
   for (auto it = G[node].begin(); it != G[node].end(); ++it) {
       
        if (recursiveStack[*it]) {
            vector <bool> new_visited (n,false);         
            if (DFS(G,node,2,new_visited)) {
              return true;
            }
        }
        
        if (!visited[*it]) {
           visited[*it] = true;
           recursiveStack[*it] = true;
           if (ContainsCycle(G, *it, visited, recursiveStack, finishing_time)) return true;
        }
    }
    recursiveStack[node] = false;
    finishing_time.push_back(node);
    return false;
  }

int main() {
  freopen("HowManyRoutes/input/input11.txt", "r", stdin);
  freopen("HowManyRoutes/output/output11.txt", "w", stdout);
  graph G;
  long m, a, b;
  scanf("%ld %ld", &n, &m);
  while (m--) {
    scanf("%ld %ld", &a, &b);
    G[a].push_back(b);
  }

  vector <bool> visited (n+1, false);
  vector <bool> recStack (n+1, false);
  vector <int> finishing_time;
  if (ContainsCycle(G,1,visited,recStack, finishing_time)) {
    cout << "inf" << endl;
    return 0;
  }
  vector <long long int> num_paths (n+1, 0);

  reverse(finishing_time.begin(), finishing_time.end());
  num_paths[1] = 1;

  for (auto i = finishing_time.begin(); i != finishing_time.end(); ++i) {
     for (auto j = G[*i].begin(); j != G[*i].end(); ++j) {
         num_paths[*j] += (num_paths[*i] % mod);
         num_paths[*j] %= mod;
     } 
  }
  cout << num_paths[2] % mod << endl;
  
}