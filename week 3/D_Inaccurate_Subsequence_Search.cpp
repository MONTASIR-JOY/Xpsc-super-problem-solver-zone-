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

        vector<long long> v(n);
        vector<long long> v1(m);

        map<long long, long long> mp1;
        map<long long, long long> mp2;
        
        for (long long i = 0; i < n;i++)
        {
            cin >> v[i];
        }
        for (long long i = 0; i < m;i++)
        {
            cin >> v1[i];
            mp1[v1[i]]++;
        }

        long long l = 0;
        long long r = 0;
        long long cnt = 0;
        long long ans = 0;
        while(r<n)
        {
            mp2[v[r]]++;
            if(mp1[v[r]]>0 && mp1[v[r]]>=mp2[v[r]])
            {
                cnt++;
            }
            if(r-l+1==m)
            {
                if(cnt>=k)
                {
                    ans++;
                }
                mp2[v[l]]--;
                if(mp1[v[l]]>mp2[v[l]])
                {
                    cnt--;
                }
                l++;
            }
            r++;
        }
        cout << ans << endl;
    }
    return 0;
}