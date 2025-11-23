#include<bits/stdc++.h>
using namespace std;
const long long mx = 2e5 + 10;
vector<long long> g[mx];
vector<bool> vis(mx);
vector<long long> dp(mx, 0);
long long dfs(long long n)
{
    if(vis[n])
    {
        return dp[n];
    }
    vis[n] = true;
    
    for(long long child:g[n])
    {
        if(!vis[child])
        {
            dp[n] += dfs(child);
        }
    }
    dp[n] = max(1LL, dp[n]);
    return dp[n];
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
        for (long long i = 0; i <= n+1;i++)
        {
            g[i].clear();
            vis[i] = false;
            dp[i] = 0;
        }

        for (long long i = 0; i < n - 1;i++)
        {
            long long u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1);
        long long q;
        cin >> q;
        while(q--)
        {
            long long x, y;
            cin >> x >> y;
            long long a = dp[x];
            long long b = dp[y];
            cout << a * b << endl;
        }
    }
    return 0;
}