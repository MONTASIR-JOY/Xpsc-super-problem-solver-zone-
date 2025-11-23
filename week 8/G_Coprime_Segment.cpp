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
    long long l = 2 * n;                 /*    / \     */
    long long r = 2 * n + 1;            //    l   r
    build(l, b, mid);
    build(r, mid + 1, e);
    t[n] = __gcd(t[l] , t[r]);    // change this
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
    return __gcd(query(l, b, mid, i, j), query(r, mid + 1, e, i, j));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;
    for (long long i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    build(1, 1, n);

    auto ok = [&](long long mid)
    {
        bool found = false;
        for (int i = 1; i <= n-mid+1;i++)
        {
            if(query(1,1,n,i,i+mid-1)==1)
            {
                found = true;
                break;
            }
        }
        return found;
    };
    long long l = 1;
    long long r = n;
    long long mid;
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

    cout << ans << endl;
    return 0;
}
