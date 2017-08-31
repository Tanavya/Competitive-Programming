#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <stdio.h>
#include <queue>
#include <set>
#include <cmath>
#include <assert.h>

#define PI 3.14159265
using namespace std;
int main() {
	int T,p,x,y;

	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		string ans;
		scanf("%d %d %d", &p, &x, &y);
		if (sqrt(pow(x-50.0,2)+pow(y-50.0,2)) > 50.0) ans = "white";
		else if (p == 0) ans = "white";
		else {
			double angle = atan(((double)x-50.0) / ((double)y-50.0)) * 180.0/PI;
			cout << angle << endl;
			double angle2 = (double)p/100.0 * 360.0; 
			//WRONG ANS HAI YEH
			if (angle > angle2) ans = "white";
			else ans = "black";
		}
		cout << "Case #" << i << ": " << ans << endl;
	}
}
