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
        vector<long long> a(n);
        vector<long long> b(n);
        for (long long i = 0; i < n;i++)
        {
            cin >> a[i];
        }
        for (long long i = 0; i < n;i++)
        {
            cin >> b[i];
        }
        vector<pair<long long, long long>> p;
        for (long long i = 0; i < n;i++)
        {
            p.push_back({a[i], b[i]});
        }
        long long mx = 0;
        for (long long i = 0; i <= 102;i++)
        {
            long long ans = 0;
            for (long long j = 0; j < n;j++)
            {
                if(p[j].first>0 && p[j].second<=i)
                {
                    ans += p[j].first;
                }
            }
            mx = max(ans - i, mx);
        }
        cout << mx << endl;
    }
    return 0;
}