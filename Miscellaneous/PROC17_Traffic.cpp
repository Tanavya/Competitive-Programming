#include <bits/stdc++.h>

using namespace std;
#define ll long long int

int main() {
   int T, n, m;
   scanf("%d", &T);
   while (T--) {
       scanf("%d %d", &n, &m);
       ll sum_initial = 0;
       int beg[m+1], fin[m+1], speed[m+1], acc[m+1];
       vector <vector <int>> beg_time(n+1), fin_time(n+1);

       for (int i = 1; i <= m; i++) {
           scanf("%d %d %d %d", &beg[i], &fin[i], &speed[i], &acc[i]);
           beg_time[beg[i]].push_back(i);
           fin_time[fin[i]].push_back(i);
       }
       ll total_acc = 0, total_speed = 0;
       for (int i = 1; i <= n; i++) {
           for (int x : beg_time[i]) {
               total_speed += speed[x] - acc[x];
               total_acc += acc[x];
           }
           total_speed += total_acc;
           printf("%d ", total_speed);
           for (int x : fin_time[i]) {
               total_acc -= acc[x];
               total_speed -= (speed[x] + acc[x] * (i - beg[x]));
           }
       }
       printf("\n");
   }
}
/*
2
10 1
2 6 3 1
*/