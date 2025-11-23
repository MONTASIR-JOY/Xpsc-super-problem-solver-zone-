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

    long long n, m;
    cin >> n >> m;
    DSU d(n);
    long long extraedge = 0;
    while(m--)
    {
        long long u, v;
        cin >> u >> v;
        if(d.same(u,v))
        {
            extraedge++;
        }
        else
        {
            d.merge(u, v);
        }

        vector<long long> cnt(n+1);
        for (long long i = 1; i <= n;i++)
        {
            cnt[d.find(i)]++;
        }

        vector<long long>cc;
        for (long long i = 1; i <= n;i++)
        {
            cc.push_back(cnt[i]);
        }
        sort(cc.rbegin(), cc.rend());
        for(int i:cc)
        {
            cout << i << " ";
        }
        cout << endl;
        long long ans = cc[0];
        for (long long i = 1; i < min((long long)cc.size(), extraedge +1);i++)
        {
            ans += cc[i];
        }
        cout << ans-1 << endl;
    }
    return 0;
}