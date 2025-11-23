#include<bits/stdc++.h>
using namespace std;
const long long mxn = 1e6 + 9;
vector<long long> dp(mxn,-1);

long long f(long long n)
{
    if(n<0)
    {
        return LLONG_MAX;
    }
    if(n==0)
    {
        return 0;
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    string s = to_string(n);
    vector<long long> v;
    for(char i:s)
    {
        v.push_back(i - '0');
    }
    long long ans = LLONG_MAX;
    for(long long i:v)
    {
        if(i<=n && i>0)
        {
            ans = min(ans, f(n - i) + 1);
        }
    }
    return dp[n] = ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;
    cout << f(n) << endl;
    return 0;
}