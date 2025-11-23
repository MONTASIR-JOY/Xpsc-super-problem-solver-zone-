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
        vector<long long> v(n+2);

        for(long long i = 1; i <= n; i++)
        {
            cin >> v[i];
        }
        long long left, right;
        auto ok = [&](long long mid)
        {
            vector<long long> prefix(n + 1, 0);

            for(long long i = 1; i <= n; i++)
            {
                if(v[i] >= mid)
                {
                    prefix[i] = prefix[i - 1] + 1;
                }
                else
                {
                    prefix[i] = prefix[i - 1] - 1;
                }
            }

            long long mn = 0;
            long long mnidx = 1;

            for(long long i = k, j = 1; i <= n; i++, j++)
            {
                if(prefix[i] >= mn)
                {
                    left = mnidx;
                    right = i;
                    return true;
                }
                if(prefix[j] < mn)
                {
                    mn = prefix[j];
                    mnidx = j + 1;
                }
            }
            return false;
        };

        long long l = 0;
        long long r = n + 1;
        long long mid;
        while(l+1<r)
        {
            mid = l + (r - l) / 2;
            if(ok(mid))
            {
                l = mid;
            }
            else
            {
                r = mid;
            }
        }
        cout << l << " " << left << " " << right << endl;
    }
    return 0;
}