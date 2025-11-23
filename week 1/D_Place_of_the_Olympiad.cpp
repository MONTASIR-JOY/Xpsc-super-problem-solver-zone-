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
        long long n, m, k;
        cin >> n >> m >> k;
        auto ok = [&](long long min)
        {
            long long per = ((m) / (min + 1));
            per *= min;
            per += m % (min + 1);
            per *= n;
            return per >= k;
        };

        long long l = 0;
        long long r = 1e12;
        long long mid, ans;

        while(l<=r)
        {
            mid = l + (r - l) / 2;
            //cout << mid << endl;
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
        cout << ans << endl;
    }
    return 0;
}