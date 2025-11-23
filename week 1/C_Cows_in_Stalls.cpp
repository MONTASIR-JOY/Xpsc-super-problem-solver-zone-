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
    auto ok = [&](long long dis)
    {
        long long cnt = 1;
        long long d = v[0];
        for (long long i = 0; i < n;i++)
        {
            if(v[i]-d>=dis)
            {
                cnt++;
                d = v[i];
            }
        }
        return cnt >= k;
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
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}