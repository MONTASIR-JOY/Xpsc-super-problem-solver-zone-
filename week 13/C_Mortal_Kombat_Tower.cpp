#include<bits/stdc++.h>
using namespace std;
const long long mxn = 2e5 + 9;
vector<long long> v(mxn);
long long n;
long long dp[mxn][2][2];

long long f(long long i,long long trc,long long cnt)
{
    if(i>n)
    {
        return 0;
    }
    if(i==n)
    {
        if(trc==1)
        {
            if(v[i]==1)
            {
                return 1;
            }
        }
    }
    if(dp[i][trc][cnt]!=-1)
    {
        return dp[i][trc][cnt];
    }
    if(trc==1)
    {
        if(cnt==0)
        {
            long long ans1 = f(i + 1, trc,1) + (v[i] == 1);
            long long ans2 = f(i + 1, trc ^ 1,0) + (v[i] == 1);
            return dp[i][trc][cnt] = min(ans1, ans2);
        }
        else
        {
            return dp[i][trc][cnt] = f(i + 1, trc ^ 1, 0) + (v[i] == 1);
        }
     
    }
    else
    {
        if(cnt==0)
        {
            long long ans1 = f(i + 1, trc, 1);
            long long ans2 = f(i + 1, trc ^ 1, 0);
            return dp[i][trc][cnt] = min(ans1, ans2);
        }
        else
        {
            return dp[i][trc][cnt] = f(i + 1, trc ^ 1, 0);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    cin>>t;
    while(t--)
    {
        cin >> n;
        for (long long i = 0; i <= n + 5; i++)
        {
            for (long long j = 0; j < 2; j++)
            {
                for (long long k = 0; k < 2; k++)
                {
                    dp[i][j][k] = -1;
                }
            }
        }
        for (long long i = 1; i <= n; i++)
        {
            cin >> v[i];
        }
        cout << f(1, 1, 0) << endl;
    }
    return 0;
}