#include<bits/stdc++.h>
using namespace std;
const long long mxn = 1e6 + 5;

vector<long long> g[mxn];
vector<bool> vis(mxn, false);
long long ans = 0;

long long dfs(long long n)
{
    vis[n] = true;
    vector<long long> v;
    for(long long child : g[n])
    {
        if(!vis[child])
        {
            long long depth = dfs(child);
            v.push_back(depth);
        }
    }
    if(v.empty())
    {
        return 1;
    }
    sort(v.rbegin(), v.rend());
    if(v.size() == 1)
    {
        ans = max(ans, v[0]);
        return v[0] + 1;
    }
    else
    {
        ans = max(ans, v[0] + v[1]);
        return v[0] + 1;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m;
    cin >> n >> m;
    for (long long i = 0; i < m;i++)
    {
        long long l, r;
        cin >> l >> r;
        g[l].push_back(r);
        g[r].push_back(l);
    }
    // for (long long i = 0; i < n + 1;i++)
    // {
    //     cout << i << " -> ";
    //     for(long long j:g[i])
    //     {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }
    dfs(1);
    cout << ans << endl;
    return 0;
}