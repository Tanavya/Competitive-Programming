#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n,a,b;
    scanf("%d", &n);
    vector<int>vals;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a, &b);
        vals.push_back(min(a,b));
    }
    int exclude = 0;
    int prev = 0;
    sort(vals.begin(), vals.end());
    for (int i = 0; i < n; i++) {
        int curr = prev + 1;
        if (vals[i] < curr) exclude++;
        else prev = curr;
    }
    cout << n-exclude << endl;
}