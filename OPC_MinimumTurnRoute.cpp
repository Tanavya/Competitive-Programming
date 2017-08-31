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

int m,n;
string a,b,c,d;
string line;
string grid[1007][1007];
int D[1007][1007];
bool visited[1007][1007]; 
priority_queue <pair<int, ii >, vector<pair<int, ii > >, greater<pair<int, ii > > > pq;


int turns_req(string disc1, string disc2, int dir) {
	//BGRY -> YBGR -> RYBG -> GRYB
	//GYBR
	//dir = 2
	//dir 1 = up, 2 = right, 3 = down, 4  == left
	int turns = 0;
	while (disc1[dir-1] != disc2[(dir+1)%4]) {
		disc1 = string(1,disc1[3]) + string(1,disc1[0]) + string(1,disc1[1]) + string(1,disc1[2]);
		//cout << disc1 << endl;
		turns++;
	}
	return turns;
}

int main() {
	ios::sync_with_stdio(false) ;
    cin.tie(0) ;
	cin >> m >> n;
	//m = rows
	//n = columns
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a >> b >> c >> d;
			line = a+b+c+d;
			grid[i][j] = line;
			//cout << line << endl;
		}
	}
	for (int i = 0; i < 1007; i++) {
		for (int j = 0; j < 1007; j++) {
			D[i][j] = INT_MAX;
		}
	}
	D[0][0] = 0;

	//cout << turns_req("BGRY", "GYBR", 2) << endl;
	pq.push(make_pair(0,make_pair(0,0)));
	while (!pq.empty()) {
		pair <int, ii> closest = pq.top();
        pq.pop();
        int a = (closest.second).first;
        int b = (closest.second).second;
        int dist = closest.first;
        if (a == m-1 && b == n-1) {
        	cout << dist << endl;
        	break;
        }
        if (visited[a][b]) continue;
        visited[a][b] = true;
        if (a < m-1) { //down
        	int turns = turns_req(grid[a][b], grid[a+1][b], 3);
        	if (dist+turns < D[a+1][b]) {
        		D[a+1][b] = dist+turns;
        		pq.push(make_pair(dist+turns, make_pair(a+1,b)));
        	}
        }
        if (a > 0) { //up
        	int turns = turns_req(grid[an][b], grid[a-1][b], 1);
        	if (dist+turns < D[a-1][b]) {
        		D[a-1][b] = dist+turns;
        		pq.push(make_pair(dist+turns, make_pair(a-1,b)));
        	}
        }
        if (b < n-1) { //right
        	int turns = turns_req(grid[a][b], grid[a][b+1], 2);
        	if (dist+turns < D[a][b+1]) {
        		D[a][b+1] = dist+turns;
        		pq.push(make_pair(dist+turns, make_pair(a,b+1)));
        	}
        }
        if (b > 0) { //left
        	int turns = turns_req(grid[a][b], grid[a][b-1], 4);
        	if (dist+turns < D[a][b-1]) {
        		D[a][b-1] = dist+turns;
        		pq.push(make_pair(dist+turns, make_pair(a,b-1)));
        	}
        }
	}
	return 0;
}
/*
2 4
G Y B R
B G R Y
G Y B R
G R B Y
B Y G R
G B R Y
B R G Y
B R G Y
*/