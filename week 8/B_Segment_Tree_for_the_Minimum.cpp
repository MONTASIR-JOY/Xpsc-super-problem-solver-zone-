#include<bits/stdc++.h>
using namespace std;

const long long maxN = 1e5 + 9;
long long a[maxN], t[4 * maxN];

void build(long long n,long long b,long long e)
{
    if(b==e)
    {
        t[n] = a[b];
        return;
    }
    long long mid = (b + e) / 2;         //     n
    long long l = 2 * n;                 /*    / \  */
    long long r = 2 * n + 1;            //    l   r
    build(l, b, mid);
    build(r, mid + 1, e);
    t[n] = min(t[l] , t[r]);
}

void update(long long n,long long b,long long e,long long i,long long v)
{
    if(i<b || i>e)
    {
        return;
    }
    if(b==e)
    {
        t[n] = v;
        return;
    }
    long long mid = (b + e) / 2;
    long long l = 2 * n;
    long long r = 2 * n + 1;
    update(l, b, mid, i, v);
    update(r, mid + 1, e, i, v);
    t[n] = min(t[l] , t[r]);
}

long long query(long long n,long long b,long long e,long long i,long long j)
{
    if(e<i || j<b)
    {
        return LONG_LONG_MAX;
    }
    if(b>=i && e<=j)
    {
        return t[n];
    }
    long long mid = (b + e) / 2;
    long long l = 2 * n;
    long long r = 2 * n + 1;
    return min(query(l, b, mid, i, j), query(r, mid + 1, e, i, j));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m;
    cin >> n >> m;
    for (long long i = 1; i <= n;i++)
    {
        cin >> a[i];
    }
    build(1, 1, n);

    while(m--)
    {
        long long t;
        cin >> t;
        if(t==1)
        {
            long long idx, v;
            cin >> idx >> v;
            idx++;
            update(1, 1, n, idx, v);
        }
        else
        {
            long long l, r;
            cin >> l >> r;
            l++;
            long long ans = query(1, 1, n, l, r);
            cout << ans << endl;
        }
    }
    return 0;
}


