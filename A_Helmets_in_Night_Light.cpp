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
        long long ans=k;
        vector<long long> v1(n);
        vector<long long> v2(n);
        vector<pair<long long, long long>> v(n);
        for (long long i = 0; i < n;i++)
        {
            cin >> v1[i];
        }
        for (long long i = 0; i < n;i++)
        {
            cin >> v2[i];
        }
        for (long long i = 0; i < n;i++)
        {
            v[i].first = v2[i];
            v[i].second = v1[i];
        }

        sort(v.begin(), v.end());

        long long rem = n - 1;
        for (long long i = 0; i < n;i++)
        {
            if(rem==0)
            {
                break;
            }
            if(v[i].first<=k)
            {
                ans += ((min(rem, v[i].second)) * v[i].first);
                rem -= min(rem, v[i].second);
            }
        }
        cout << ans + rem * k << endl;
    }
    return 0;
}