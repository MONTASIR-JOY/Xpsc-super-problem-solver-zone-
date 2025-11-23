#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, k;
    cin >> n >> k;
    vector<long long> v(n);
    for (long long i = 0; i < n;i++)
    {
        cin >> v[i];
    }
    
    auto ok = [&](long long sec)
    {
        long long cnt = 0;
        for (long long i = 0; i < n;i++)
        {
            cnt += sec / v[i];
            if(cnt>=k)
            {
                return true;
            }
        }
        return cnt >= k;

    };

    long long l = 1;
    long long r = 1e18;
    long long mid=0;
    long long ans;

    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if(ok(mid))
        {
            r = mid - 1;
            ans = mid;
        }
        else{
            l = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}