//Problem type: Greedy
//Algorithm:
/*
http://stackoverflow.com/questions/40613908/optimal-algorithm-for-the-greedy-algorithm-interval-scheduling-scheduling-all
"Instead of looping through all n intervals, loop through all 2n interval endpoints in increasing order. Maintain a heap (priority queue) 
of available colours ordered by colour, which initially contains n colours; every time we see an interval start point, extract the smallest 
colour from the heap and assign it to this interval; every time we see an interval end point, reinsert its assigned colour into the heap. Each 
endpoint (start or end) processed is O(log n) time, and there are 2n of them. This matches the time complexity for sorting the intervals, so 
the overall time complexity is also O(n log n)."
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
    return (a.first < b.first);
}
int main() {
    
    int num_intervals;
    scanf("%d", &num_intervals);
    vector <ii> intervals(num_intervals), endpoints;
    vector <int> schedule;
    priority_queue <int, vector <int>, greater <int>> heap;
    for (int i = 0; i < num_intervals; i++) {
        scanf("%d %d", &intervals[i].first, &intervals[i].second);
        endpoints.push_back(mp(intervals[i].first, i));
        endpoints.push_back(mp(intervals[i].second, i));
        schedule.push_back(-1);
        heap.push(i);
    }
    sort(endpoints.begin(), endpoints.end(), cmp);
    
    for (int i = 0; i < 2*num_intervals; i++) {
        ii endpoint = endpoints[i];
        if (endpoint.first == intervals[endpoint.second].first) { //means it is a start point
            int curr = heap.top();
            schedule[endpoint.second] = curr;
            heap.pop();
        }
        else { //means it is an end point
            heap.push(schedule[endpoint.second]);
        }
    }
    printf("Intervals and assigned schedule colour..\n");
    for (int i = 0; i < num_intervals; i++) {
        printf("Interval (%d, %d) is scheduled at %d\n", intervals[i].first, intervals[i].second, schedule[i]);
    }

}