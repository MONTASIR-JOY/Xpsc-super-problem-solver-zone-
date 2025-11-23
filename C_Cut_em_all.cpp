#include<bits/stdc++.h>
using namespace std;
const long long mx = 1e5 + 5;
vector<long long> g[mx];
vector<long long> dp(mx, 1);

void dfs(long long node, long long par)
{
    for(auto it: g[node])
    {
        if(it==par) continue;
        dfs(it, node);
        dp[node] += dp[it];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;
    for(long long i = 0; i < n-1; i++)
    {
        long long u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    if(n % 2 == 1)
    {
        cout << -1 << endl;
        return 0;
    }

    dfs(1, -1);
    long long ans = 0;
    for(long long i = 2; i <= n; i++)
    {
        if(dp[i] % 2 == 0) ans++;
    }
    cout << ans << endl;
    return 0;
}