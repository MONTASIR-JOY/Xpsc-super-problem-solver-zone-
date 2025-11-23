#include<bits/stdc++.h>
using namespace std;
const long long mxn = 1e5 + 5;
vector<long long> g[mxn];
vector<long long> type(mxn, -1);
vector<bool> vis(mxn, false);

void dfs(long long n, long long c)
{
    vis[n] = true;
    type[n] = c;
    for(long long child : g[n])
    {
        if(!vis[child])
        {
            dfs(child, 1 - c);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;
    for (long long i = 0; i < n-1; i++)
    {
        long long u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, 0);
    long long o = 0;
    long long z = 0;
    for (long long i = 1; i <= n; i++)
    {
        if(type[i]==0)
        {
            z++;
        }
        else{
            o++;
        }
    }
    cout << z * o - (n - 1) << endl;
    return 0;
}