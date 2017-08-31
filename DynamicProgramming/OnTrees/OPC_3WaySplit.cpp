#include <algorithm>
#include <iostream>
#include <vector>
#include <bitset>
#include <map>
#include <climits>
#include <stdio.h>
#include <assert.h>
#include <queue>
typedef long long int ll;
using namespace std;
#define print(arr) for(auto pos = arr.begin(); pos != arr.end(); ++pos) cout << *pos << " "; cout << endl;
 
 
vector <vector <int> > tree (3001);
vector <vector <int> > new_tree (3001);
vector <int> weights (3001);
int D[3001] = {0};
bitset <3001> visited;
vector <int> parent(3001);
 
 
int set_D(int n) {
    int result = weights[n];
    for (vector<int>::iterator it = tree[n].begin(); it != tree[n].end(); ++it) {
        if (!visited[*it]) {
            visited[*it] = true;
            new_tree[n].push_back(*it);
            parent[*it] = n;
            result += set_D(*it);
        }
    }
    D[n] = result;
    return result;
}
void dfs(int n) {
    for (vector<int>::iterator it = tree[n].begin(); it != tree[n].end(); ++it) {
        if (!visited[*it]) {
            visited[*it] = true;
            dfs(*it);
        }
    }
}
int main() {
 
    int N,a,b;
    scanf("%d", &N);
 
    for (int i = 0; i < N; i++) {
        scanf("%d", &weights[i+1]);
    }
    for (int i = 0; i < N-1; i++) {
        scanf("%d %d", &a, &b);
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
 
    visited[1] = true;
    set_D(1);
    tree = new_tree;
 
    int best = INT_MAX;
    for (int i = 2; i <= N; i++) {
        int curr = i;
        int result = INT_MAX;
        visited.reset();
        visited[i] = true;
        while (parent[curr] != 1) {
            curr = parent[curr];
            result = min(result, max(max(D[1]-D[curr], D[i]), D[curr]-D[i]));
            visited[curr] = true;
        }
        dfs(i);
        for (int j = 2; j <= N; j++) {
            if (!visited[j]) result = min(result, max(max(D[i],D[j]), D[1]-D[i]-D[j]));
        }
        best = min(best, result);
    }
    cout << best << endl;
}