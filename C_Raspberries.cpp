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
        long long n,k;
        cin >> n >> k;

        vector<long long> v(n);
        map<long long, long long> mp;
        for (long long i = 0; i < n;i++)
        {
            long long x;
            cin >> x;
            v[i] = x % k;
            mp[v[i]]++;
        }
        long long ans = LLONG_MAX;
        for (long long i = 0; i < n;i++)
        {
            if(v[i]==0)
            {
                ans = 0;
                break;
            }
            if(k-v[i]>0)
            {
                ans = min(ans, k - v[i]);
            }
        }

        if(k==4)
        {
            if(mp[3]>=1)
            {
                ans = min(ans, 1LL*1);
            }
            if(mp[2]>=2)
            {
                ans = min(ans, 1LL*0);
            }
            if(mp[2]>0 && mp[1]>0)
            {
                ans = min(ans, 1LL*1);
            }
            if(mp[1]>=2)
            {
                ans = min(ans, 1LL*2);
            }
        }
        cout << ans << endl;
    }
    return 0;
}