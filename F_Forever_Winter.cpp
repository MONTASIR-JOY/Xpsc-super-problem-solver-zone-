#include<bits/stdc++.h>
using namespace std;
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
        map<long long,set<long long>>g;
        
        for (long long i = 0; i < m;i++)
        {
            long long a, b;
            cin >> a >> b;
            g[a].insert(b);
            g[b].insert(a);
        }

        long long leaf = -1;
        for (long long i = 0; i <= n;i++)
        {
            if(g[i].size()==1)
            {
                leaf = i;
                break;
            }
        }
        long long parentofleaf = -1;
        long long x, y;
        for (long long i = 0; i <= n;i++)
        {
            if(g[i].find(leaf)!=g[i].end())
            {
                parentofleaf = i;
                y = g[i].size() - 1;
                break;
            }
        }

        long long root = -1;
        for (long long i = 0; i <= n;i++)
        {
            if(g[i].find(parentofleaf)!=g[i].end() && g[i].size()!=1)
            {
                root = i;
                x = g[i].size();
                break;
            }
        }

        cout<<x<<" "<<y<<endl;
    }
    return 0;
}