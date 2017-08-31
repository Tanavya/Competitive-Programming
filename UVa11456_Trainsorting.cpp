//Problem Link: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=651&page=show_problem&problem=2451
//Problem type: Dynamic Programming
//Learning Exp: Fucking constraints. N <= 0 <= 2000 !!!!! I HAD SET ANS = 1 initially, should have been 0, ugh D:

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
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip> //cout << setprecision(n) << fixed << num

#define mp make_pair
#define ii pair<int, int>
#define PI 3.14159265
#define INF 1000000000000000000LL
#define EPS 1e-9
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << "\n";
typedef long long int ll;
using namespace std;

int main() {
    //srand(time(NULL));
    int T, n;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        //n = 10;
        int wts[2*n], DP[2*n], prev[2*n], ans = 0, last = 0;
        
        //bitset <55> seen;
        for (int i = 0; i < n; i++) {
            scanf("%d", &wts[n - i - 1]);
            /*
            do {
                wts[n-i-1] = rand() % 50;
            } while (seen[wts[n-i-1]]);
            seen[wts[n-i-1]] = true;
            prev[i] = -10000000;
            */
            DP[i] = 1;

        }
        for (int i = n; i < 2*n; i++) {
            wts[i] = wts[n - (i % n) - 1];
            DP[i] = 1;
            //prev[i] = -10000000;
        }
        //for (int i = n; i < 2*n; i++) printf("%d ", wts[i]);
        //printf("\n");

        for (int i = 1; i < 2*n; i++) {
            for (int j = 0; j < i; j++) {
                if (wts[j] > wts[i]) {
                    //DP[i] = max(DP[i], DP[j] + 1);
                    if (DP[i] < DP[j] + 1) {
                        DP[i] = DP[j] + 1;
                        //prev[i] = j;
                    }
                }
            }
            //ans = max(ans, DP[i]);
            if (DP[i] >= ans) {
                //last = i;
                ans = DP[i];
            }
        }
        
        printf("%d\n", ans);
        /*
        vector <int> seq;
        
        while (last != -10000000) {
            seq.push_back(wts[last]);
            last = prev[last];
        }
        sort(seq.rbegin(), seq.rend());
        assert(seq.size() == ans);
        printf("Selected seq: "); //print(seq);
        seen.reset();
        for (int i = 0; i < seq.size(); i++) {
            cout << seq[i] << " ";
            seen[seq[i]] = true;
        }
        cout << endl;
        list <int> train;
        for (int i = n; i < 2*n; i++) {
            if (seen[wts[i]]) {
                if (train.size() == 0) train.push_back(wts[i]);
                else if (wts[i] < train.back()) train.push_back(wts[i]);
                else if (wts[i] > train.front()) train.push_front(wts[i]);
                else assert(false);
            }
        }
        print(train);
        assert(vector <int> (train.begin(), train.end()) == seq);
        assert(train.size() == seq.size());
        printf("Length: %d\n", ans);

        int max_len = 0;
        vector <int> new_vec;
        for (int i = n; i < 2*n; i++) {
            new_vec.push_back(wts[i]);
        }
        for (int i = 1; i < (1 << n); i++) {
            vector <int> tmp_vec;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    tmp_vec.push_back(new_vec[j]);
                }
            }
            //cout << "TMP Vec: "; print(tmp_vec);
            train.clear();
            for (int j = 0; j < tmp_vec.size(); j++) {
                if (train.size() == 0) train.push_back(tmp_vec[j]);
                else if (tmp_vec[j] < train.back()) train.push_back(tmp_vec[j]);
                else if (tmp_vec[j] > train.front()) train.push_front(tmp_vec[j]);
                //else assert(false);
                //print(train);
            }
            max_len = max(max_len, (int)train.size());
        }
        cout << "Max Length by Brute Force: " << max_len << endl;
        assert(max_len == ans);
        */
    }
    
}