//Problem type: Greedy
//Steps: 
/*
1. Sort based on finishing time
2. Select first interval from sorted intervals
3. Select next interval that does not overlap with the first interval
4. Mark this interval as last interval
5. Continue
*/

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
#define EPS 1e-9
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << "\n";
typedef long long int ll;
using namespace std;

inline bool cmp(ii a, ii b) {
    if (a.second < b.second) return true;
    else if (a.second == b.second) return (a.first > b.first);
    else return false;
}

int main() {

    int num_intervals;
    scanf("%d", &num_intervals);
    vector <ii> intervals(num_intervals);
    for (int i = 0; i < num_intervals; i++) {
        scanf("%d %d", &intervals[i].first, &intervals[i].second);
    }
    sort(intervals.begin(), intervals.end(), cmp);
    printf("After sorting..\n");
    for (int i = 0; i < num_intervals; i++) {
        printf("%d %d\n", intervals[i].first, intervals[i].second);
    }
    
    vector <ii> non_overlapping = {intervals[0]};
    int last = 0;
    for (int i = 1; i < num_intervals; i++) {
        if (intervals[i].first >= intervals[last].second) {
            last = i;
            non_overlapping.push_back(intervals[i]);
        }
    }
    printf("Chosen intervals..\n");
    for (int i = 0; i < non_overlapping.size(); i++) {
        printf("%d %d\n", non_overlapping[i].first, non_overlapping[i].second);
    }
}
/*
6
1 14
2 4
5 7
8 10
11 13
3 4
*/