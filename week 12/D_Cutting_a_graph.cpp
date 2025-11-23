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
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m , k;
    cin >> n >> m >> k;

    DSU d(n);
    for (long long i = 0; i < m;i++)
    {
        long long u, v;
        cin >> u >> v;
    }
    vector<tuple<string, long long, long long>> q;

    for (long long i = 0; i < k; i++)
    {
        string s;
        long long a, b;
        cin >> s >> a >> b;
        q.push_back({s, a, b});
    }

    reverse(q.begin(), q.end());
    vector<string> res;
    for(auto [query,u,v]:q)
    {
        if(query=="cut")
        {
            d.merge(u, v);
        }
        else
        {
            if(d.same(u,v))
            {
                res.push_back("YES");
            }
            else{
                res.push_back("NO");
            }
        }
    }
    reverse(res.begin(), res.end());
    for(string i:res)
    {
        cout << i << endl;
    }
    return 0;
}