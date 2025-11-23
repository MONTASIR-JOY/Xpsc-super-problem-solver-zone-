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
    sort(v.begin(), v.end());

    auto ok = [&](long long val)
    {
        long long cnt = 0;
        for(long long i = n/2; i < n;i++)
        {
            if(val>v[i])
            {
                cnt += (val - v[i]);
            }
        }
        return cnt <= k;
    };

    long long l = 1;
    long long r = 2e9;
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
    return 0;
}