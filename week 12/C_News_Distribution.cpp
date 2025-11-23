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
      
    long long n, k;
    cin >> n >> k;
    DSU d(n);
    

    for (long long i = 0; i < k;i++)
    {
        long long ki;
        cin >> ki;
        vector<long long> v(ki);
        for (long long j = 0; j < ki;j++)
        {
            cin >> v[j];
            //cout << v[j] << " ";
        }
        cout << endl;
        for (long long j = 1; j < ki;j++)
        {
            d.merge(v[j - 1], v[j]);
        }
        if(ki>=2)
        {
            d.merge(v[0], v[ki - 1]);
        }
    }

    for (long long i = 1; i <= n;i++)
    {
        cout << d.getsize(i) << " ";
    }
    //cout << endl;
    return 0;
}