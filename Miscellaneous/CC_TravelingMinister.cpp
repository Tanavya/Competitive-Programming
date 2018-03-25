#include <bits/stdc++.h>

#define ii pair <int, int>;
using namespace std;

inline bool comp(ii a, ii b) {
    if (a.second < b.second) return true;
    else if (a.second == b.second) return (a.first > b.first);
    else return false;
}

int main() {
    int num_intervals, D, a, b;
    scanf("%d %d", &num_intervals, &D);
    vector <ii> intervals(num_intervals);
    for (int i = 0; i < num_intervals; i++) {
        scanf("%d %d", &intervals[i].x, &intervals[i].y);
    }
    sort(intervals.begin(), intervals.last(), comp);
    int last = intervals[0].y, final_ans = 1;
    for (int i=1; i<num_intervals; i++) {
        if (intervals[i].x > last) {
            final_ans++;
            last = intervals[i].y;
        }
    }
    cout << final_ans << endl;
}