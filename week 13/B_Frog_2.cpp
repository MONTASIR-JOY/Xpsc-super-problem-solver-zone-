#include<bits/stdc++.h>
using namespace std;
vector<long long> v;
map<long long, long long> dp;
long long n, k;

long long f(long long pos)
{
    if(pos>=n)
    {
        return 0;
    }

    if(dp[pos]!=-1)
    {
        return dp[pos];
    }
    long long ans = LLONG_MAX;
    for (long long i = 1; i <= k;i++)
    {
        if(i+pos<=n)
        {
            ans = min(ans, f(pos + i) + abs(v[pos + i] - v[pos]));
        }
    }
    return dp[pos] = ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

   
    cin >> n >> k;
    v.push_back(0);
    for (long long i = 0; i < n;i++)
    {
        long long x;
        cin >> x;
        v.push_back(x);
        dp[i] = -1;
    }
    dp[n] = -1;

    cout << f(1) << endl;
    return 0;
}