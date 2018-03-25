#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <stdio.h>
#include <queue>
#include <set>
#include <list>
#include <cstring>
#include <cmath>
#include <assert.h>
#include <bitset>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip> //cout << setprecision(node) << fixed << num

#define mp make_pair
#define pb push_back
#define x first
#define y second
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << "\n";

typedef long long int ll;
typedef long double ld;
typedef std::pair <int, int> ii;
typedef std::vector <int> vi;
typedef std::vector <ll> vll;
const int INF = int(1e9);
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

using namespace std;

int main() {


    int T, N;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        vector <string> grid(2);
        int occupied_count = 0;
        vi M(N+7, 0);
        for (int i = 0; i < 2; i++) {
            cin >> grid[i];
            /*
            for (int j = 0; j < N; j++) {
                int x = rand() % 2;
                if (x) grid[i][j] = '*';
                else grid[i][j] = '.';
                cout << grid[i][j];
            }
            cout << endl;
            */
            bool row_occupied = false;
            for (int j = 0; j < N; j++) {
                if (grid[i][j] == '*') {
                    row_occupied = true;
                    M[j]++;
                }
            }
            if (row_occupied) occupied_count++;
        }
        vector <string> new_grid(2);
        for (int i = 0; i < N; i++) {
            if (grid[0][i] == '*' || grid[1][i] == '*') {
                new_grid[0].append(string{grid[0][i]});
                new_grid[1].append(string{grid[1][i]});
            }
        }
        N = new_grid[0].size();
        assert(new_grid[0].size() == new_grid[1].size());
        grid = new_grid;
        int walls = 0;
        if (occupied_count == 2) walls++;
        bool prev_mark = false;
        for (int i = 0; i < N-1; i++) {
            bool mark = false;
            if (grid[0][i] == '*' && grid[0][i+1] == '*') 
                mark = true;
            if (grid[1][i] == '*' && grid[1][i+1] == '*')
                mark = true;
            if (i) {
                if (grid[0][i] == '*' && grid[1][i+1] == '*' && grid[1][i-1] == '*' && !prev_mark)
                    mark = true;
                if (grid[1][i] == '*' && grid[0][i+1] == '*' && grid[0][i-1] == '*' && !prev_mark)
                    mark = true;
            }
            if (mark) walls++;
            prev_mark = mark;
        }
        cout << walls << endl;
        
    }
}
/*
1
6
***...
....**
*/