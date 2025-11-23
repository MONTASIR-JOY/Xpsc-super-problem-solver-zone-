#include<bits/stdc++.h>
using namespace std;

const long long maxN = 1e5 + 9;
long long t[4 * maxN];

void build(long long n,long long b,long long e)
{
    if(b==e)
    {
        t[n] = 0;
        return;
    }
    long long mid = (b + e) / 2;         //     n
    long long l = 2 * n;                 /*    / \     */ 
    long long r = 2 * n + 1;            //    l   r
    build(l, b, mid);
    build(r, mid + 1, e);
    t[n] = t[l] + t[r];    // change this
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
    t[n] = t[l] + t[r];   // change this
}

long long query(long long n,long long b,long long e,long long i,long long j)
{
    if(e<i || j<b)
    {
        return 0;         // return right value
    }
    if(b>=i && e<=j)
    {
        return t[n];
    }
    long long mid = (b + e) / 2;
    long long l = 2 * n;
    long long r = 2 * n + 1;
    return query(l, b, mid, i, j) + query(r, mid + 1, e, i, j); // change this
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    cin >> t;
    while(t--)
    {
        long long n, m;
        cin >> n >> m;
        vector<pair<long long, long long>> a(m);
        for (long long i = 0; i < m;i++)
        {
            cin >> a[i].first >> a[i].second;
        }
        long long x;
        cin >> x;
        vector<long long> q(x);
        for (long long i = 0; i < x;i++)
        {
            cin >> q[i];
        }

        auto ok = [&](long long mid)
        {
            build(1, 1, n);
            bool found = false;
            for (long long i = 0; i <= mid;i++)
            {
                update(1, 1, n, q[i], 1);
            }
            for (long long i = 0; i < m;i++)
            {
                long long l = a[i].first;
                long long r = a[i].second;
                long long sz = (r-l) + 1;
                long long one = query(1, 1, n, l, r);
                long long zero = sz - one;

                if(one>zero)
                {
                    found = true;
                    break;
                }
            }
            return found;
        };
        long long l = 0;
        long long r=x-1;
        long long ans = -1;
        while(l<=r)
        {
            long long mid = l + (r - l) / 2;
            if(ok(mid))
            {
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        if(ans!=-1)
        {
            ans++;
        }
        cout << ans << endl;
    }    
    return 0;
}
