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
        long long n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        auto ok = [&](long long mid)
        {
            long long split = 0;
            long long sorted = 0;
            long long zero = 0;

            for (long long i = 0; i < n;i++)
            {
                if(s[i]=='0')
                {
                    zero++;
                }
                else{
                    sorted++;
                }
                sorted = max(sorted, zero);
                if(sorted>=mid)
                {
                    split++;
                    sorted = 0;
                    zero = 0;
                }
            }
            if(split>=k)
            {
                return true;
            }
            else
            {
                return false;
            }
        };
        long long l = 0;
        long long r = n+2;
        long long ans = 0;
        while(l<=r)
        {
            long long mid = l + (r - l) / 2;
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
        cout << ans << endl;
    }
    return 0;
}