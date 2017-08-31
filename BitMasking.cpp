#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <stdio.h>
#include <queue>
#include <set>
#include <cmath>
#include <assert.h>

using namespace std;

int main() {
	int mask = 0;
	for (int i = 2; i <= 10; i += 2) {
		mask |= (1 << i);
	}
	cout << mask << endl;
}