#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long k, n;
    cin >> k >> n;
    
    vector<tuple<long long, long long, long long>> v(n);
    for (long long i = 0; i < n; i++) 
    {
        long long x, y, z;
        cin >> x >> y >> z;
        v[i] = make_tuple(x, y, z);
    }

    vector<long long> can(n);

    auto ok = [&](long long mid)
    {
        vector<long long> may(n);
        long long left = k;
        for (long long i = 0; i < n; i++)
        {
            long long t = get<0>(v[i]);
            long long z = get<1>(v[i]);
            long long y = get<2>(v[i]);
            long long total = t * z + y;
            long long cycles = mid / total;
            long long rem = mid % total;
            long long curr = cycles * z + min(z, rem / t);
            curr = min(left, curr);
            left -= curr;
            may[i] = curr;
        }
        if (left == 0)
        {
            for (long long i = 0; i < n; i++) 
            {
                can[i] = may[i];
            }
        }
        return left == 0;
    };

    long long l = 0, r = 1e9, ans;
    while (l <= r) 
    {
        long long mid = l + (r - l) / 2;
        if (ok(mid)) 
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
    for (long long i = 0; i < n; i++) 
    {
        cout << can[i] << " ";
    }
    cout << endl;
    return 0;
}