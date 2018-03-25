//Problem Link: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=647&page=show_problem&problem=129
//Problem type: Complete Search
//IMP LEARNING EXP: When using bitmasks, ALWAYS see the upper bound. Isme 100 tha, 2^100 is fugging impossible UGH x_x
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <stdio.h>
#include <queue>
#include <set>
#include <cmath>
#include <assert.h>
#include <bitset>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip> //cout << setprecision(n) << fixed << num

#define mp make_pair
#define ii pair<int, int>
#define PI 3.14159265
#define INF 1000000000000000000LL
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << "\n";
typedef long long int ll;
using namespace std;

int t, n, m;
bitset<107> mat[107];
vector <int> colored, best;
bitset<107> visited;

void rec() {
    bool found = false;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            found = true;
            colored.push_back(i);
            bitset <107> cpy = visited;
            visited[i] = 1;
            visited |= mat[i];
            rec();
            colored.pop_back();
            visited = cpy;
        }
    }
    if (!found) if (best.size() < colored.size()) best = colored;

}
int main() {
    scanf("%d", &t);
    int a,b;
    while (t--) {

        scanf("%d %d", &n, &m);

        best.clear();
        colored.clear();
        visited.reset();
        for (int i = 0; i <= n; i++) {
            mat[i] = bitset<107>();
        }
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &a, &b);
            mat[a][b] = 1;
            mat[b][a] = 1;
        }
        rec();
        int size = best.size();
        printf("%d\n", size);
        for (int i = 0; i < size; i++) {
            if (i) printf(" ");
            printf("%d", best[i]);
        }
        printf("\n");
    }
}