#include<bits/stdc++.h>
using namespace std;
 
const long long mxn = 1e2 + 9, m = 1e5 + 9;
long long n;
long long dp[mxn][m];
vector<long long> v(mxn);
long long f(long long i,long long sum)
{
    if(i>n)
    {
        return sum==0;
    }
    if(dp[i][sum]!=-1)
    {
        return dp[i][sum];
    }
    long long ans = 0;
    if(v[i]<=sum)
    {
        ans += f(i + 1, sum - v[i]);
    }
    ans += f(i + 1, sum);
    return dp[i][sum] = ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    long long sum = 0;
    for (long long i = 1; i <= n;i++)
    {
        cin >> v[i];
        sum += v[i];
    }
 
    for (long long i = 1; i <= n;i++)
    {
        for (long long j = 0; j <= sum;j++)
        {
            dp[i][j] = -1;
        }
    }
 
    vector<long long> ans;
    for (long long i = 1; i <= sum;i++)
    {
        if(f(1,i))
        {
            ans.push_back(i);
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(long long i:ans)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << endl;
    return 0;
}
