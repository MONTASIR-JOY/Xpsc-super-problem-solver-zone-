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
        long long mx = LLONG_MIN;
        map<long long, long long> mp;
        for (long long i = 0; i < n;i++)
        {
            cin >> v[i];
            mp[v[i]]++;
            mx = max(mx, v[i]);
        }
        if(n==1)
        {
            cout << 1 << endl;
            continue;
        }
        long long x = 0;
        for (long long i = 0;i<n;i++)
        {
            x = __gcd(mx - v[i],x);
        }
        long long ans = 0;
        for (long long i = 0; i < n;i++)
        {
            long long diff = mx - v[i];
            ans += (diff / x);
        }
        long long val = mx - x;
        while(mp[val]!=0)
        {
            val -= x;
        }
        ans += (mx - val) / x;
        cout << ans << endl;
    }
    return 0;
}