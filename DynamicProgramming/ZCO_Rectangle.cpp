//Problem Link: https://www.codechef.com/ZCOPRAC/problems/ZCO15004
//Problem type: Dynamic Programming
 
#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;
 
vector <vector <int>> grid(507, vector <int> (100007, 1));
int main() {
 
    int N, a, b;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &a, &b);
        grid[b][a] = 0;
    }
    int ans = 0;
    for (int i = 0; i < 500; i++) {
        int best = 0, curr = 0;
        for (int j = 0; j < 100000; j++) {
       	    if (i > 0 && grid[i-1][j] == 0) grid[i][j] = 0;
            if (grid[i][j] == 1) curr++;
            else {
                best = max(best, curr);
                curr = 1;
            }
        }
        best = max(best, curr);
        ans = max(ans, best * (i+1));
    }
    cout << ans << endl;
}