#include<bits/stdc++.h>
using namespace std;
const long long mxn = 1005;
const long long mxm = 1005;
long long mat[mxn][mxm];
vector<vector<bool>> vis(mxn, vector<bool>(mxm, false));
vector<pair<long long, long long>> p = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool valid(long long i,long long j,long long n,long long m)
{
    if(i>=0 && i<n && j>=0 && j<m)
    {
        return true;
    }
    return false;
}
long long dfs(long long i,long long j,long long n,long long m)
{
    vis[i][j] = true;
    long long val = mat[i][j];
    for (long long k = 0;k<4;k++)
    {
        long long childi = i + p[k].first;
        long long childj = j + p[k].second;
        if(valid(childi,childj,n,m) && vis[childi][childj]==false && mat[childi][childj]!=0)
        {
            val += dfs(childi, childj, n, m);
        }
    }
    return val;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    cin>>t;
    while(t--)
    {
        long long n, m;
        cin >> n >> m;
        
        for (long long i = 0; i < n;i++)
        {
            for (long long j = 0; j < m;j++)
            {
                long long x;
                cin >> x;
                mat[i][j] = x;
                vis[i][j] = false;
            }
        }
        long long ans = LLONG_MIN;
        for (long long i = 0; i < n;i++)
        {
            for (long long j = 0; j < m;j++)
            {
                if(vis[i][j]==false && mat[i][j]!=0)
                {
                    long long go = dfs(i, j,n,m);
                    ans=max(ans,go);
                }
            }
        }
        cout << max(1LL*0,ans) << endl;
    }
    return 0;
}
