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
        long long h, n;
        cin >> h >> n;

        vector<pair<long long,long long>>v(n);
        vector<long long> a(n);
        vector<long long> b(n);
        long long firstheat = 0;

        for (long long i = 0; i < n;i++)
        {
            cin >> a[i];
        }
        for (long long i = 0; i < n;i++)
        {
            cin >> b[i];
        }
        for (long long i = 0; i < n; i++)
        {
            v[i].first = a[i];
            v[i].second = b[i];
            firstheat += v[i].first;
        }
        if(firstheat>=h)
        {
            cout << 1 << endl;
            continue;
        }
        auto ok = [&](long long time)
        {
            long long heats = firstheat;
            for (long long i = 0; i < n;i++)
            {
                heats += (time / v[i].second) * v[i].first;
            }
            return heats >= h;
        };
        long long l = 1;
        long long r = 1e12;
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
        cout << ans+1 << endl;
    }
    return 0;
}