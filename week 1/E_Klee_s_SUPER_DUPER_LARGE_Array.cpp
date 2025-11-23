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
        long long n, k;
        cin >> n >> k;
        long long pre = (k - 1) * k / 2;
        long long total = (n+k-1) * (n + k) / 2;

        auto fun = [&](long long idx)
        {
            long long i = idx + k - 1;
            long long val = i * (i + 1) / 2 - pre;
            long long rightval = total - pre - val;
            return abs(val - rightval);
        };

        auto ok = [&](long long idx)
        {
            long long i = idx + k - 1;
            long long val = i * (i + 1) / 2 - pre;
            long long rightval = total - pre - val;
            return rightval > val;
        };

        long long l = 0;
        long long r = n;
        long long mid, ans;
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
        cout << min(fun(ans),min(fun(ans+1),fun(ans-1))) << endl;
    }
    return 0;
}