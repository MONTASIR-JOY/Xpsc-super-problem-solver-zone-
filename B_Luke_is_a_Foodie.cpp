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
        long long n, x;
        cin >> n >> x;
        vector<long long> v(n);
        for (long long i = 0; i < n;i++)
        {
            cin >> v[i];
        }

        vector<pair<long long, long long>> seg;
        for (long long i = 0; i < n;i++)
        {
            seg.push_back({v[i]-x,v[i]+x});
        }
        long long ans = 0;
        long long l = seg[0].first;
        long long r = seg[0].second;
        for (long long i = 1;i<n;i++)
        {
            l = max(l,seg[i].first);
            r = min(r,seg[i].second);
            
            if(l>r)
            {
                ans++;
                l = seg[i].first;
                r = seg[i].second;
            }
        }
        cout << ans << endl;
    }
    return 0;
}