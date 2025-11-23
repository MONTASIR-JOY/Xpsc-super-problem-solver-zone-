#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
      
    long long t;
    cin >> t;
    while(t--)
    {
        long long n, c;
        cin >> n >> c;
        vector<long long> v(n);
        for (long long i = 0; i < n;i++)
        {
            cin >> v[i];
        }

        auto ok = [&](long long mid)
        {
            long long ans = 0;
            for (long long i = 0; i < n;i++)
            {
                ans += ((v[i] + 2 * mid) * (v[i] + 2 * mid));
                if(ans>c)
                {
                    break;
                }
            }
            return ans;
        };
        long long l = 0;
        long long r = 1e9;
        long long ans = -1;
        long long mid;
        while(l<=r)
        {
            mid = l + (r - l) / 2;
            long long val = ok(mid);
            if(val==c)
            {
                ans = mid;
                break;
            }
            else if(val>c)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}