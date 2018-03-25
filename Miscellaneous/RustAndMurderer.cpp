#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <bitset>
#include <unordered_map>
#include <queue> //queueueuueueueheuheuehuehuequeueheu kyu

using namespace std;

vector <vector<int> > graph (200001);
vector <vector<int> > graph_copy (200001);
vector <bitset <200001> > mat (200001);
vector <bitset <200001> > mat_copy (200001);


int T, M, N, a, b, s, curr;
bitset <200001> visited;
vector <int> D (200001, 0);
vector <int> D_copy (200001, 0);
int main() {

    scanf("%d", &T);
    while (T--) {
        
        scanf("%d %d", &N, &M);
        for (int i = 0; i < M; i++) {
            scanf("%d %d", &a, &b);
            mat[a][b] = 1;
            mat[b][a] = 1;
        }
        scanf("%d", &s);
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (!mat[i][j]) graph[i].push_back(j);
            }
        }
        queue <int> kyu;
        visited.reset();
        visited[s] = true;
        kyu.push(s);
        while (!kyu.empty()) {
            curr = kyu.front();
            kyu.pop();
            for (auto it = graph[curr].begin(); it != graph[curr].end(); ++it) {
                if (!visited[*it]) {
                    visited[*it] = true;
                    kyu.push(*it);
                    D[*it] = D[curr]+1;
                }
            }
        }
        for (int i = 1; i <= N; i++) {
            if (i != s) printf("%d ", D[i]);
        }
        printf("\n");
        graph = graph_copy;
        mat = mat_copy;
        D = D_copy;

    }
   
    return 0;
}