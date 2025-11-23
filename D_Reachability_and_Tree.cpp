#include<bits/stdc++.h>
using namespace std;
const long long mx = 1e6 + 5;
vector<long long> g[mx];
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

        for (long long i = 0; i <= n;i++)
        {
            g[i].clear();
        }
        for (long long i = 0; i < n-1;i++)
        {
            long long u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        long long f = -1;
        for (long long i = 1; i <= n;i++)
        {
            if(g[i].size()==2)
            {
                f = i;
                break;
            }
        }
        if(f==-1)
        {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        queue<long long> q;
        vector<long long> ans(n + 2, -1);
        ans[f] = 0;
        ans[g[f][0]] = 0;
        ans[g[f][1]] = 1;

        cout << f << " " << g[f][0] << endl;
        cout << g[f][1] << " " << f << endl;

        q.push(g[f][0]);
        q.push(g[f][1]);
    
        while(q.size())
        {
            auto v = q.front();
            q.pop();
            for(auto c: g[v])
            {
                if(ans[c] != -1)
                continue;
                
                if(ans[v])
                {
                    cout << v << " " << c << endl;
                }
                else
                {
                    cout << c << " " << v << endl;
                }
                ans[c] = (ans[v] ^ 1);
                q.push(c);
            }
        }
    }
    return 0;
}