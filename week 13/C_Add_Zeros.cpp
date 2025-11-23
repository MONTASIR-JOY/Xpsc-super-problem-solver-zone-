#include<bits/stdc++.h>
using namespace std;

map<long long, long long> dp;
map<long long, vector<long long>> mp;

long long ans;
long long f(long long size)
{
    ans = max(ans, size);
    if(dp[size]>0)
    {
        return dp[size];
    }
    for(auto i:mp[size])
    {
        if(i>0)
        {
            ans = max(ans, f(size + i));
        }
    }
    return dp[size] = ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    cin >> t;
    while(t--)
    {
        mp.clear();
        dp.clear();
        long long n;
        cin >> n;
        vector<long long> v(n);
        for (long long i = 0; i < n;i++)
        {
            cin >> v[i];
        }
        for (long long i = 0; i < n;i++)
        {
            mp[v[i] + i].push_back(i);
        }
        ans = n;
        for(auto i:mp[n])
        {
            if(i>0)
            {
                f(n+i);
            }
        }
        cout << ans << endl;
    }
    return 0;
}