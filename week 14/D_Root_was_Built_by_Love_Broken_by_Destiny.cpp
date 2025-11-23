#include<bits/stdc++.h>
using namespace std;
const long long mxn = 2e5 + 5;
const long long MOD = 1e9 + 7;
vector<long long> g[mxn];
vector<long long> fact(mxn);

long long bfs(long long n)
{
    vector<bool> vis(n, false);
    queue<long long> q;
    q.push(0);
    vis[0] = true;
    long long vis_cnt = 1;
    while(!q.empty()) 
    {
        long long u = q.front();
        q.pop();
        for(long long v : g[u])
        {
            if(!vis[v])
            {
                vis[v] = true;
                vis_cnt++;
                q.push(v);
            }
        }
    }
    return vis_cnt;
}

void fun()
{
    fact[0] = 1;
    fact[1] = 1;
    for (long long i = 2; i < mxn;i++)
    {
        fact[i] = i * fact[i - 1] % MOD;
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
      
    long long t;
    cin>>t;
    fun();
    while(t--)
    {
        
        long long n, m;
        cin >> n >> m;
        for(long long i = 0; i < n; i++) 
        {
            g[i].clear();
        }

        for (long long i = 0; i < m;i++)
        {
            long long u, v;
            cin >> u >> v;
            u--;
            v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        if(m!=n-1)
        {
            cout << 0 << endl;
            continue;
        }

        if(bfs(n)!=n)
        {
            cout << 0 << endl;
            continue;
        }
 
        vector<vector<long long>> newadj(n);
        long long cnt = 0;
        for (long long i = 0; i < n;i++)
        {
            if(g[i].size()==1) continue;
            cnt++;
            for(auto x : g[i])
            {
                if(g[x].size()!=1)
                {
                    newadj[i].push_back(x);
                }
            }
        }

        bool found = false;
        for(long long i = 0; i < n;i++)
        {
            if(newadj[i].size() >= 3)
            {
                cout << 0 << endl;
                found = true;
                break;
            }
        }
        if(found)
        {
            continue;
        }
        long long ans;
        if(cnt>=2)
        {
            ans = 4;
        }
        else
        {
            ans = 2;
        }
    
        for(long long i = 0; i < n;i++) 
        {
            long long cntleaf = 0;
            if(g[i].size()>1) 
            {
                for(auto x:g[i]) 
                {
                    if(g[x].size() == 1)
                    {
                        cntleaf++;
                    }
                }
                ans = ans * fact[cntleaf] % MOD;
            }
        }
    
        cout << ans << endl;
    }
    return 0;
}