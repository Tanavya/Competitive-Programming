#include <bits/stdc++.h>
using namespace std;
#define int long long int
 
const int mod = 1e9+7;

long double cross(pair<int, int> a, pair<int, int> b)
{
    return abs((a.first*b.second)-(b.first*a.second))/2.;
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector< pair<int, int> > v(n);
        for(int i = 0;i<n;i++)
            cin>>v[i].first>>v[i].second;
        long double dp[1<<n][n+1];
        memset(dp, 0, sizeof(dp));
        for(int i = 0;i < (1<<n);i++)
            for(int j = 0;j<n;j++)
                if(i&(1<<j))
                    for(int k = 0;k<n;k++)
                        if((i&(1<<k))&&k!=j)
                            dp[i][j] = max(dp[i][j], dp[i^(1<<j)][k]+cross(v[j], v[k]));
        long double ans = 0;
        for(int i = 0;i<n;i++)
            ans = max(ans, dp[(1<<n)-1][i]);
        cout<<fixed<<setprecision(4)<<ans<<endl;
    }

    return 0;
}