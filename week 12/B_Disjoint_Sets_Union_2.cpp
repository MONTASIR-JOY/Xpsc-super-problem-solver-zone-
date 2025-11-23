#include<bits/stdc++.h>
using namespace std;
struct DSU
{
    vector<long long> par, rnk, siz, mx, mn;
    long long c;
    DSU(long long n) : par(n + 1, 1), rnk(n + 1, 0), siz(n + 1, 1), c(n),mx(n+1,-1),mn(n+1,-1)
    {
        for (long long i = 1; i <= n;i++)
        {
            par[i] = i;
            mn[i] = mx[i] = i;
        }
    }
    long long find(long long i)
    {
        return (par[i] == i ? i : (par[i] = find(par[i])));
    }
    bool same(long long u,long long v)
    {
        return find(u) == find(v);
    }
    long long getsize(long long u)
    {
        return siz[u];
    }
    long long cnt()
    {
        return c;
    }
    void merge(long long u,long long v)
    {
        if((u=find(u))==(v=find(v)))
        {
            return;
        }
        else{
            c--;
        }
        if(rnk[u]>rnk[v])
        {
            swap(u, v);
        }
        else if(rnk[u]==rnk[v])
        {
            rnk[v]++;
        }
        par[u] = par[v];
        siz[v] += siz[u];
        mn[v] = min(mn[u], mn[v]);
        mx[v] = max(mx[u], mx[v]);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
      
    long long n,m;
    cin >> n >> m;
    DSU d(n);
    while(m--)
    {
        string q;
        cin >> q;
        if(q=="union")
        {
            long long u, v;
            cin >> u >> v;
            d.merge(u, v);
        }
        else
        {
            long long v;
            cin >> v;
            v = d.find(v);
            cout << d.mn[v] << " " << d.mx[v] << " " << d.getsize(v) << endl;
        }
    }
    return 0;
}