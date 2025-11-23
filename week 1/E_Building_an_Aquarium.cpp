#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
      
    long long t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        vector<long long> v(n);
        for (long long i = 0;i<n;i++)
        {
            cin >> v[i];
        }
        auto ok = [&](long long mid)
        {
            long long cnt = 0;
            for(long long i:v)
            {
                cnt += min(mid, i);
            }
            long long water = n * mid - cnt;
            return water <= k;
        };
        long long l = 0;
        long long r = 1e12;
        long long mid, ans;
        while(l<=r)
        {
            mid = l + (r - l) / 2;
            if(ok(mid))
            {
                ans = mid;
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}