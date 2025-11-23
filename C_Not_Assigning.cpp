#include<bits/stdc++.h>
using namespace std;
const int mx = 1e5 + 5;
vector<int> g[mx];
vector<bool> vis(mx);
bool ans;

int edge;
map<pair<int, int>, int> dp;

void dfs(int n)
{
    vis[n] = true;
    if(g[n].size() > 2)
    {
        ans = false;
    }
    if(g[n].size() == 1)
    {
        edge = n;
    }
    for(int child : g[n])
    {
        if(!vis[child])
        {
            dfs(child);
        }
    }
}

void f(int n, int weight)
{
    vis[n] = true;
    for(int child : g[n])
    {
        if(!vis[child])
        {
            dp[{n, child}] = 7 - weight;
            dp[{child, n}] = 7 - weight;
            f(child, 7 - weight);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
      
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n + 2; i++)
        {
            g[i].clear();
            vis[i] = false;
        }
        dp.clear();
        vector<pair<int, int>> p;
        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            p.push_back({u, v});
            g[u].push_back(v);
            g[v].push_back(u);
        }
        ans = true;
        dfs(1);

        if(ans)
        {
            dp[{edge, g[edge][0]}] = 2;
            for (int i = 0; i < n + 2; i++)
            {
                vis[i] = false;
            }
            f(edge, 2);

            for (int i = 0; i < n - 1; i++)
            {
                cout << dp[{p[i].first, p[i].second}] << " ";
            }
            cout << endl;
        }
        else
        {
            cout << "-1" << endl;
        }
    }
    return 0;
}