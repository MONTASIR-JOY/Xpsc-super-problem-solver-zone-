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
        vector<long long> v(n);
        long long mx = 0;
        long long mn = LLONG_MAX;
        for (long long i = 0; i < n;i++)
        {
            cin >> v[i];
            mx = max(mx, v[i]);
            mn = min(mn, v[i]);
        }
        long long ans = mx - mn;
        vector<long long> div;
        for (long long i = 2; i * i <= n;i++)
        {
            if(n%i==0)
            {
                div.push_back(i);
                div.push_back(n / i);
            }
        }
        vector<long long> pre(n+1);
        pre[0] = 0;
        for (long long i = 1; i <= n;i++)
        {
            pre[i] = pre[i - 1] + v[i - 1];
        }
        for (long long i = 0; i < div.size(); i++)
        {
            long long part = div[i];
            mn = LLONG_MAX;
            mx = LONG_MIN;

            for (long long j = part; j <= n; j += part)
            {
                long long val = pre[j] - pre[j - part];
                mn = min(mn, val);
                mx = max(mx, val);
            }
            ans = max(ans, mx - mn);
        }
        cout << ans << endl;
    }
    return 0;
}