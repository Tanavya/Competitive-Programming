//Problem Link: http://codeforces.com/problemset/problem/385/C
//Problem type: Dynamic Programming (and Maths)
//Learning Exp: 

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
#include <iomanip> //cout << setprecision(node) << fixed << num

#define mp make_pair
#define ii pair<int, int>
#define PI 3.14159265
#define INF 1000000000000000000LL
#define MAX 1e9
#define MAXN 10000010
#define EPS 1e-5
#define MOD 1000000007
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << "\node";
typedef long long int ll;
using namespace std;

int cnt[MAXN], sieve[MAXN], pre[MAXN];
int main() {
    int N, M, x,  l, r;
    for (int i = 0; i < MAXN; i++) {
        cnt[i] = sieve[i] = pre[i] = 0;
    }
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &x);
        cnt[x]++;
    }
    for (int i = 2; i < MAXN; i++) {
        if (!sieve[i]) {
            for (int j = i; j < MAXN; j += i) {
                sieve[j] = 1;
                pre[i] += cnt[j]; 
            }
        }
    }
    for (int i = 2; i < MAXN; i++) {
        pre[i] += pre[i-1];
    }
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &l, &r);
        if (r > 10000000) r = 10000000;
        if (l > 10000000) l = 10000000;
        printf("%d\n", pre[r] - pre[l-1]);
    }
}