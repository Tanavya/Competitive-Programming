#include <algorithm>
#include <iostream>
#include <vector>
#include <bitset>
#include <set>
#include <climits>
#include <stdio.h>
#include <assert.h>
#include <map>

using namespace std;
int main() {

    int N,a=0,b=0,c,d;
    int M = 0;
    cin >> N;
    while (N--) {
        cin >> c >> d;
        a += c;
        b += d;
        if (abs(a-b) > abs(M)) {
            M = a-b;
        }
    }
    if (M < 0) cout << 2 << " " << abs(M) << endl;
    else cout << 1 << " " << abs(M) << endl;

}