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
#include <cstring>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip> //cout << setprecision(node) << fixed << num
 
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << endl;
#define debug(x) cout << x << endl;
#define debug2(x,y) cout << x << " " << y << endl;
typedef long long int ll;
typedef long double ld;
typedef std::pair <int, int> ii;
typedef std::vector <int> vi;
typedef std::vector <ll> vll;
const int INF = int(1e9);
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
using namespace std;

int alike[130][130];
int s;
string S;

bool isPalindrome() {
    for (int i = 0; i < s/2; i++) {
        if (!alike[int(S[i])][int(S[s-1-i])]) {
            return false;
        }
    }
    return true;
}

int main() {
    int T,m;
    scanf("%d", &T);
    while (T--) {
        memset(alike, 0, sizeof(alike));
        for (int i = 0; i < 130; i++) {
            alike[i][i] = 1;
        }
        scanf("%d %d", &s, &m);
        char a, b;
        cin >> S;
        while (m--) {
            int len;
            scanf("%d", &len);
            vector <int> alike_chars(len);
            for (int x = 0; x < len; x++) {
                char temp;
                cin >> temp;
                alike_chars[x] = int(temp);
            }
            for (int i = 0; i < len; i++) {
                for (int j = 0; j < len; j++) {
                    alike[alike_chars[i]][alike_chars[j]] = 1;
                    alike[alike_chars[j]][alike_chars[i]] = 1;
                }
            }
        }
        if (isPalindrome()) cout << "Impersonating" << endl;
        else cout << "Not Impersonating" << endl;
    }
}