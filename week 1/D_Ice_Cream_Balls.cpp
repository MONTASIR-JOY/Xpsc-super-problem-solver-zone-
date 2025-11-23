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

        auto ok = [&](long long m)
        {
            return m *(m - 1) / 2  > n;
        };
        long long l = 0;
        long long r = 2e9;
        long long ans = -1, mid;
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
        ans--;
        long long pl = n - ans * (ans - 1) / 2;
        cout << ans + pl << endl;
    }
    return 0;
}