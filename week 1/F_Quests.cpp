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
        long long n, c, d;
        cin >> n >> c >> d;
        vector<long long>v(n);
        for (long long i = 0; i < n;i++)
        {
            cin >> v[i];
        }
        sort(v.rbegin(), v.rend());
        auto ok = [&](long long k)
        {
            long long coin = 0;
            long long day = d;
            long long pre = 0;
            for (int i = 0; i < min(n,k);i++)
            {
                pre += v[i];
            }
            coin += (d / k) * pre;
            long long rep = d % k;
            for (int i = 0; i < min(n, rep); i++)
            {
                coin += v[i];
            }
            return coin >= c;
        };
        long long l = 1;
        long long r = 1e18;
        long long mid, ans=-1;
        while(l<=r)
        {
            mid = l + (r - l) / 2;
            if(ok(mid))
            {
                ans = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        if(ok(1e18+1))
        {
            cout << "Infinity" << endl;
            continue;
        }
        else if(ans==-1)
        {
            cout << "Impossible" << endl;
            continue;
        }
        cout << ans - 1 << endl;
    }
    return 0;
}