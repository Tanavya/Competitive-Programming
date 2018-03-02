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
#include <stack>
#include <sstream>

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << endl;
#define debug(x) cout << x << endl;
#define debug2(x,y) cout << x << " " << y << endl;
#define debug3(x,y,z) cout << x << " " << y << " " << z << endl;

typedef long long int ll;
typedef long double ld;
typedef unsigned long long int ull;
typedef std::pair <int, int> ii;
typedef std::vector <int> vi;
typedef std::vector <ll> vll;
typedef std::vector <ld> vld;

const int INF = int(1e9);
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
using namespace std;

struct node {
    int cnt, left_val, right_val, dp[2][2];
    node *left, *right;
    node() {
        cnt = 0, left_val = 0, right_val = 0;
        dp[1][1] = INF;
        dp[0][1] = dp[1][0] = dp[0][0] = 0;
        left = NULL;
        right = NULL;
    }
};

#define null new node()

void merge(node *ret, node *left, node *right) {
    if (left->cnt == 0 && right->cnt == 0) {
        *ret = node();
    }
    else if (left->cnt == 0) {
        ret->left_val = right->left_val;
        ret->right_val = right->right_val;
        ret->dp[0][0] = right->dp[0][0];
        ret->dp[0][1] = right->dp[0][1];
        ret->dp[1][0] = right->dp[1][0];
        ret->dp[1][1] = right->dp[1][1];
    }
    else if (right->cnt == 0) {
        ret->left_val = left->left_val;
        ret->right_val = left->right_val;
        ret->dp[0][0] = left->dp[0][0];
        ret->dp[0][1] = left->dp[0][1];
        ret->dp[1][0] = left->dp[1][0];
        ret->dp[1][1] = left->dp[1][1];
    }
    else {
        int nw = right->left_val - left->right_val;
        for (int i = 0; i < 2; i++) {
            for (int __j = 0; __j < 2; __j++) {
                ret->dp[i][__j] = min(min(min(nw + left->dp[i][0] + right->dp[0][__j], nw + left->dp[i][0] + right->dp[1][__j]), nw + left->dp[i][1] + right->dp[0][__j]), left->dp[i][1] + right->dp[1][__j]);
            }
        }
        ret->left_val = left->left_val;
        ret->right_val = right->right_val;
    }
    ret->cnt = left->cnt + right->cnt;
}

void update(node *curr, int L, int R, int idx, int val) {
    if (L == R) {
        *curr = node();
        if (val == 1) {
            curr->cnt = 1;
            curr->left_val = curr->right_val = idx;
        }
    }
    else {
        int mid = (L+R)/2;
        if (curr->left == nullptr)
            curr->left = null;
        if (curr->right == nullptr)
            curr->right = null;
        if (idx <= mid)
            update(curr->left, L, mid, idx, val);
        else
            update(curr->right, mid+1, R, idx, val);

        merge(curr, curr->left, curr->right);
    }
}

const int maxai = (int) 1e9+1;

int main() {
    int TC;
    scanf("%d", &TC);
    while (TC--) {
        int N, Q;
        node *tree = null;
        scanf("%d %d", &N, &Q);
        for (int i = 0; i < N; i++) {
            int x;
            scanf("%d", &x);
            update(tree, 1, maxai, x, 1);
        }
        while (Q--) {
            int type, x;
            scanf("%d %d", &type, &x);
            if (type == 1) {
                update(tree, 1, maxai, x, 1);
                N++;
            }
            else {
                update(tree, 1, maxai, x, -1);
                N--;
            }
            if (N <= 1) cout << 0 << endl;
            else cout << tree->dp[1][1] << endl;
        }
    }
}