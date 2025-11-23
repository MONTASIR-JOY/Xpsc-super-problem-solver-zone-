#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long k, n;
    cin >> k >> n;
    vector<long long> v(n);
    for (long long i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    auto ok = [&](long long x)
    {
        long long total = 0;
        for (long long i = 0; i < n; i++)
        {
            total += min(v[i], x);
        }
        long long council=total/k;
        return council >= x;
    };

    
    long long l = 0, r = 1e18, ans = 0;
    while (l <= r)
    {
        long long mid = l + (r - l) / 2;
        if (ok(mid))
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
    return 0;
}