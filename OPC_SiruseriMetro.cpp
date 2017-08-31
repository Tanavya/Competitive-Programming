#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <stdio.h>
#include <queue>
#include <map>
#include <cmath>
#include <assert.h>

#define ii pair<int, int>
using namespace std;

int m,n,start_time,a,b,st,c,d;
string train_type;
vector <ii> row_trains(51);
vector <ii> col_trains(51);
map <string, int> key;// = {{"F",1}, {"O",2}, {"S", 3}};
priority_queue <pair<int, ii >, vector<pair<int, ii > >, greater<pair<int, ii > > > pq;
int D[57][57] = {0};


vector <ii > train_times(int length, int target_time, int speed, int start, int pos) {
    /*
    cout << "LENGTH: " << length << endl;
    cout << "TARGET TIME: " << target_time << endl;
    cout << "SPEED : " << speed << endl;
    cout << "START: " << start << endl;
    cout << "POS: " << pos << endl;
    */
    vector<ii > ret;
    int cnt = 0;
    int time_taken = start; 
    if (pos == 0) cnt++;
    if (pos == length-1) cnt++;
    while (cnt < 2) {
        for (int i = 1; i < length && cnt < 2; i++) {
            time_taken += speed;
            if (time_taken >= target_time && i == pos+1) {
                ret.push_back(make_pair(time_taken, i));
                cnt++;
            }
        }
        //assert(cnt <= 2);
        if (cnt == 2) break;;
        for (int i = length-2; i >= 0 && cnt < 2; i--) {
            time_taken += speed;
            if (time_taken >= target_time && i == pos-1) {
                ret.push_back(make_pair(time_taken, i));
                cnt++;
            }
        }
    }
    return ret;
}
int main() {
    key["F"] = 1;
    key["O"] = 2;
    key["S"] = 3;
	scanf("%d %d", &m, &n);
    //cout << index(n, 11, fwd) << endl;
    //cout << fwd << endl;
	for (int i = 0; i < m; i++) {
		cin >> train_type >> start_time;
		row_trains[i] = make_pair(key[train_type],start_time);
	}
	for (int i = 0; i < n; i++) {
		cin >> train_type >> start_time;
		col_trains[i] = make_pair(key[train_type],start_time);
	}
	cin >> a >> b >> st >> c >> d;
    a--;b--;c--;d--;
	//a,c = row
	//b,d = col
    //row_train[a].second+(row_train[a].first*n*b)>=st
    //start + n * speed >= st

    for (int i = 0; i <= 51; i++) {
        for (int j = 0; j <= 51; j++) {
            D[i][j] = INT_MAX;
        }
    }

    int train_speed = row_trains[a].first, train_start = row_trains[a].second;
    vector <ii > times = train_times(n, st, train_speed, train_start, b);

    for (int i = 0; i < times.size(); i++) {
        pq.push(make_pair(times[i].first, make_pair (a, times[i].second)));
        D[a][times[i].second] = times[i].first;

    }

    train_speed = col_trains[b].first, train_start = col_trains[b].second;
    times = train_times(m, st, train_speed, train_start, a);
    for (int i = 0; i < times.size(); i++) {
        pq.push(make_pair(times[i].first, make_pair (times[i].second, b)));
        D[times[i].second][b] = times[i].first;
    }

    bool found = false;
    while (!found) {
        pair <int, ii> closest = pq.top();
        pq.pop();
        int a = (closest.second).first;
        int b = (closest.second).second;
        int time = closest.first;
        //cout << time << endl;
        //cout << a << " " << b << endl;
        if (a == c && b == d) {
            cout << time << endl;
            found = true;
            break;
        }
        int train_speed = row_trains[a].first, train_start = row_trains[a].second;
        vector <ii > times = train_times(n, time, train_speed, train_start, b);

        for (int i = 0; i < times.size(); i++) {
            if (times[i].first < D[a][times[i].second]) {
                pq.push(make_pair(times[i].first, make_pair (a, times[i].second)));
                D[a][times[i].second] = times[i].first;
            }
        }

        train_speed = col_trains[b].first, train_start = col_trains[b].second;
        times = train_times(m, time, train_speed, train_start, a);
        for (int i = 0; i < times.size(); i++) {
            if (times[i].first < D[times[i].second][b]) {
                pq.push(make_pair(times[i].first, make_pair (times[i].second, b)));
                D[times[i].second][b] = times[i].first;
            }
        }
            
        }
}
/*
3 4
F 3 
S 2
O 2
S 1
F 2
O 2
F 4
2 3 8 1 1
*/