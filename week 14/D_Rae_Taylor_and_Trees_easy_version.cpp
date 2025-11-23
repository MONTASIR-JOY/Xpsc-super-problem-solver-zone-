#include<bits/stdc++.h>
using namespace std;
struct DSU
{
    vector<long long> par, rnk, siz;
    long long c;
    DSU(long long n) : par(n + 1, 1), rnk(n + 1, 0), siz(n + 1, 1), c(n)
    {
        for (long long i = 1; i <= n;i++)
        {
            par[i] = i;
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
        return siz[find(u)];
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
    }
};

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
        vector<long long> v(n);
        for (long long i = 0; i < n;i++)
        {
            cin >> v[i];
        }

        DSU d(n);
        long long mn = v[0];
        vector<pair<long long, long long>> graph;
        for (long long i = 1; i < n;i++)
        {
            if(mn<v[i])
            {
                d.merge(mn, v[i]);
                graph.push_back({mn, v[i]});
            }
            else{
                mn = v[i];
            }
        }
        long long prev = 0;
        long long suf = 0;
        long long cur = 0;
        for (long long i = n - 1; i >= 0;i--)
        {
            if(d.find(v[i])!=prev)
            {
                suf = max(suf, cur);
                prev = d.find(v[i]);
            }
            if(suf>v[i])
            {
                if(d.find(suf)!=d.find(v[i]))
                {
                    d.merge(suf, v[i]);
                    prev = d.find(v[i]);
                }
            }
            cur = max(cur, v[i]);
        }
        long long par = d.find(1);
        bool f = true;
        for (long long i = 1; i <= n;i++)
        {
            if(d.find(i)!=d.find(par))
            {
                f = false;
                break;
            }
        }
        if(f)
        {
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
    return 0;
}