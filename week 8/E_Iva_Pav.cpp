#include<bits/stdc++.h>
using namespace std;

const long long maxN = 2*1e5 + 9;
long long a[maxN], t[4 * maxN];

void build(long long n,long long b,long long e)
{
    if(b==e)
    {
        t[n] = a[b];
        return;
    }
    long long mid = (b + e) / 2;         //     n
    long long l = 2 * n;                 /*    / \     */ 
    long long r = 2 * n + 1;            //    l   r
    build(l, b, mid);
    build(r, mid + 1, e);
    t[n] = t[l] & t[r];    // change this
}

long long query(long long n,long long b,long long e,long long i,long long j)
{
    if(e<i || j<b)
    {
        return (1LL << 60) - 1;  // return right value
    }
    if(b>=i && e<=j)
    {
        return t[n];
    }
    long long mid = (b + e) / 2;
    long long l = 2 * n;
    long long r = 2 * n + 1;
    return (query(l, b, mid, i, j) & query(r, mid + 1, e, i, j)); // change this
}

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
        for (long long i = 1; i <= n;i++)
        {
            cin >> a[i];
        }
        build(1, 1, n);
        
        long long q;
        cin >> q;
        while(q--)
        {
            long long l, k;
            cin >> l >> k;
            auto ok = [&](long long r)
            {
                return query(1, 1, n, l, r)>=k;
            };
            long long lo = l;
            long long hi = n;
            long long mid;
            long long ans = -1;
            while(lo<=hi)
            {
                mid = lo + (hi - lo) / 2;
                if(ok(mid))
                {
                    ans = mid;
                    lo = mid + 1;
                }
                else{
                    hi = mid - 1;
                }
            }
            cout << ans << " ";
        }
        cout << endl;
    }
    return 0;
}