#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, x, y;
    cin >> n >> x >> y;
    long long t = min(x, y);
    n--;

    auto ok = [&](long long time)
    {
        long long cnt = time / x + time / y;
        return cnt >= n;
    };
    long long l = 0;
    long long r = 1e9;
    long long mid, ans;
    while(l<=r)
    {
        mid = l + (r - l) / 2;
        if(ok(mid))
        {
            r = mid - 1;
            ans = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << ans+t << endl;
    return 0;
}