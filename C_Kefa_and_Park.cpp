#include<bits/stdc++.h>
using namespace std;
const long long mx = 1e5 + 5;
vector<long long> g[mx];
vector<long long> cat(mx);
long long n,m;
vector<bool> vis(mx, false);
long long ans = 0;
void dfs(long long n,long long consecutive,bool x)
{
    vis[n] = true;
    if(cat[n]==1 && n!=1)
    {
        consecutive++;
        if(consecutive>m)
        {
            x = false;
        }
        // << n << " " << consecutive << endl;
    }
    else if(n!=1)
    {
        consecutive = 0;
    }

    if(g[n].size()==1 && n!=1)
    {
        if(x)
        {
            ans++;
            //cout << n << " " << consecutive << endl;
        }
        return;
    }

    for(long long child:g[n])
    {
        if(!vis[child])
        {
            dfs(child, consecutive, x);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    cat[0] = -1;

    for (long long i = 1; i <= n;i++)
    {
        cin >> cat[i];
    }

    for (long long i = 0; i < n - 1;i++)
    {
        long long u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    dfs(1,cat[1],cat[1]<=m);
    cout << ans << endl;
    return 0;
}