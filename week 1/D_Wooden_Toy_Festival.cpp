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
        long long n;
        cin >> n;
        vector<long long> v(n);
        for (long long i = 0; i < n;i++)
        {
            cin >> v[i];
        }
        sort(v.begin(), v.end());

        auto ok = [&](long long time)
        {
            long long cnt = 1;
            long long l = 0;
            long long r = 0;
            while(r<n)
            {
                if(v[r]-v[l]>2*time)
                {
                    cnt++;
                    l = r;
                }
                r++;
            }
            return cnt <= 3;
        };

        long long l = 0;
        long long r = 1e9;
        long long mid, ans;
        while(l<=r)
        {
            mid = l + (r - l) / 2;
            if(ok(mid))
            {
                ans = mid;
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