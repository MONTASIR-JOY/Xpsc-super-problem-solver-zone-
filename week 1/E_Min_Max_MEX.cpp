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
        long long n, k;
        cin >> n >> k;
        vector<long long> v(n);
        for (long long i = 0; i < n;i++)
        {
            cin >> v[i];
        }
        auto ok = [&](long long mid)
        {
            bool trc[mid] = {false};
            long long cnt = 0;
            long long curr = 0;
            for (long long i = 0; i < n; i++)
            {
                if (v[i] < mid && trc[v[i]] == false)
                {
                    curr++;
                    trc[v[i]] = true;
                }
                if (curr == mid)
                {
                    cnt++;
                    curr = 0;
                    memset(trc, false, sizeof(trc));
                }
            }
            return cnt >= k;
        };
        long long l = 0;
        long long r = n;
        long long ans, mid;
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
    }
    return 0;
}