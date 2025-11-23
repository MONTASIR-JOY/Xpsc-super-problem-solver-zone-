#include<bits/stdc++.h>
using namespace std;

const long long mxn = 1e3 + 5;
const long long mxm = 1e3 + 5;
long long dp[mxn][mxn];
long long n,m,l;
string a, b, c;

long long f(long long i,long long j,long long k)
{
    if(k>=l)
    {
        return 0;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    long long ans = LLONG_MAX;
    if(i<n)
    {
        if(a[i]==c[k])
        {
            ans = min(ans, f(i + 1, j, k + 1));
        }
        else{
            ans = min(ans, 1 + f(i + 1, j, k + 1));
        }
    }
    if(j<m)
    {
        if(b[j]==c[k])
        {
            ans = min(ans, f(i, j+1, k + 1));
        }
        else{
            ans = min(ans, 1 + f(i, j+1, k + 1));
        }
    }
    return dp[i][j] = ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    cin >> t;
    while(t--)
    {
        cin >> a >> b >> c;
        n = a.size();
        m = b.size();
        l = c.size();

        for (long long i = 0; i <= n;i++)
        {
            for (long long j = 0; j <= m;j++)
            {
                dp[i][j] = -1;
            }
        }
        cout << f(0, 0, 0) << endl;
    }
    return 0;
}