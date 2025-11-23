#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
      
    long long t;
    cin >>t;
    while(t--)
    {
        long long n;
        cin >> n;
        vector < pair<pair<long long, long long>, pair<long long, long long>>> v(n);
        for (long long i = 0;i<n;i++)
        {
            cin >> v[i].first.first >> v[i].first.second >> v[i].second.first >> v[i].second.second;
        }
        long long ans = 0;
        for (long long i = 0; i < n;i++)
        {
            if(v[i].second.first<v[i].first.first)
            {
                ans += (v[i].first.first - v[i].second.first);
            }
        }
        for (long long i = 0; i < n;i++)
        {
            if(v[i].second.second<v[i].first.second)
            {
                ans += (v[i].first.second - v[i].second.second);
                ans += min(v[i].first.first, v[i].second.first);
            }
        }
        cout << ans << endl;
    }
    return 0;
}