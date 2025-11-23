#include<bits/stdc++.h>
using namespace std;
const long long mx = 3e5 + 9;
vector<long long> g[mx];
vector<long long> dp(mx);
string s;
void dfs(long long u)
{
    if(g[u][0]!=0)
    {
        long long v = g[u][0];
        if(s[u-1]!='L')
        {
            dp[v] = dp[u] + 1;
        }
        else
        {
            dp[v] = dp[u];
        }
        dfs(v);
    }
    if(g[u][1]!=0)
    {
        long long v = g[u][1];
        if(s[u-1]!='R')
        {
            dp[v] = dp[u] + 1;
        }
        else
        {
            dp[v] = dp[u];
        }
        dfs(v);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    cin >> t;
    while(t--)
    {
        long long n;
        cin >> n;
        cin >> s;
        for (long long i = 1; i <= n;i++)
        {
            g[i].clear();
            dp[i] = 0;
        }
        for (long long i = 1; i <= n; i++)
        {
            long long a, b;
            cin >> a >> b;
            g[i].push_back(a);
            g[i].push_back(b);
        }

        dfs(1);
        long long ans = LLONG_MAX;
        for (long long i = 1; i <= n;i++)
        {
            if(g[i][0]==0 && g[i][1]==0)
            {
                ans = min(ans, dp[i]);
            }
        }

        cout << ans << endl;
    }
    return 0;
}