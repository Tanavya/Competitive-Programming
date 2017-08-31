//Problem Link: http://codeforces.com/problemset/problem/385/C
//Problem type: Dynamic Programming

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
#include <list>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip> //cout << setprecision(node) << fixed << num

#define mp make_pair
#define ii pair<int, int>
#define PI 3.14159265
#define INF 1000000000000000000LL
#define MAX 1e9
#define MAXN 10000010
#define EPS 1e-5
#define MOD 1000000007
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << "\node";
typedef long long int ll;
using namespace std;

vector <ii> requests;
int N, K, dp[1007][1007];
int step[1007][1007];
list <int> org_req[1007][1007], org_tables[1007];
vector <int> tables;
int rec(int n, int k, int taken) {
    if (dp[n][k] != -1) {
        return dp[n][k];
    }
    int ret = 0;
    if (n < N && k < K) {
        if (requests[n].first > tables[k]) {
            int x = rec(n+1, k, taken), y = rec(n, k+1, taken);
            ret = max(x, y);
            if (x > y) step[n][k] = 1;
            else step[n][k] = 2;
            
        }
        else {
            int x = rec(n+1, k, taken), y = rec(n, k+1, taken), z = requests[n].second + rec(n+1, k+1, taken+1);
            ret = max(x, max(y, z));
            if (ret == x) step[n][k] = 1;
            else if (ret == y) step[n][k] = 2;
            else if (ret == z) step[n][k] = 3;
        }
    }
    dp[n][k] = ret;
    return ret;

}
int main() {
    scanf("%d", &N);
    requests.resize(N);

    for (int i = 0; i < N; i++) {
        scanf("%d %d", &requests[i].first, &requests[i].second);
        org_req[requests[i].first][requests[i].second].push_back(i+1);
    }

    scanf("%d", &K);
    tables.resize(K);
    for (int i = 0; i < K; i++) {
        scanf("%d", &tables[i]);
        org_tables[tables[i]].push_back(i+1);
    }
    sort(requests.begin(), requests.end());
    sort(tables.begin(), tables.end());
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= K; j++) {
            dp[i][j] = -1;
            step[i][j] = -1;
        }
    }
    int ans = rec(0, 0, 0);
    int n = 0, k = 0, taken = 0;
    while (n < N && k < K) {
        if (step[n][k] == 1) n++;
        else if (step[n][k] == 2) k++;
        else if (step[n][k] == 3) {
            n++;
            k++;
            taken++;
        }
    }
    cout << taken << " " << ans << endl;
    n = 0, k = 0;
    while (n < N && k < K) {
        if (step[n][k] == 1) n++;
        else if (step[n][k] == 2) k++;
        else if (step[n][k] == 3) {
            
            cout << org_req[requests[n].first][requests[n].second].front() << " ";
            org_req[requests[n].first][requests[n].second].pop_front();
            cout << org_tables[tables[k]].front() << endl;
            org_tables[tables[k]].pop_front();
            n++;
            k++;
            
        }
    }
}

/*
3
10 100
10 100
10 100
3
10 10 10
*/