#include<bits/stdc++.h>
using namespace std;

long long n;
const long long mxn = 1e5 + 7;
long long dp[mxn][3];
long long a[mxn], b[mxn], c[mxn];
long long f(long long i,long long last)
{
    if(i>n)
    {
        return 0;
    }
    if(dp[i][last]!=-1)
    {
        return dp[i][last];
    }
    long long ans = 0;
    for (long long k = 0; k < 3;k++)
    {
        if (k == last)
        {
            continue;
        }
        if(k == 0) 
        {
            ans = max(ans, a[i] + f(i + 1, k));
        }
        else if (k == 1)
        {
            ans = max(ans, b[i] + f(i + 1, k));
        }
        else
        {
            ans = max(ans, c[i] + f(i + 1, k));
        }
    }

    return dp[i][last] = ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (long long i = 1; i <= n;i++)
    {
        cin >> a[i] >> b[i] >> c[i];
    }

    memset(dp, -1, sizeof(dp));
    cout << f(1, 3) << endl;                     
    return 0;
}