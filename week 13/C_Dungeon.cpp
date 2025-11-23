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
        long long n,m;
        cin >> n >> m;
        vector<long long> v(n);
        long long mx = LLONG_MIN;
        for (long long i = 0; i < n;i++)
        {
            cin >> v[i];
            mx = max(v[i], mx);
        }
        vector<long long> a(m);
        for (long long i = 0; i < m;i++)
        {
            cin >> a[i];
        }
        
        vector<long long> b(m);
        for (long long i = 0; i < m;i++)
        {
            cin >> b[i];
        }

        vector<pair<long long, long long>> p(m);
        for (long long i = 0; i < m;i++)
        {
            p[i] = {a[i], b[i]};
        }
        sort(a.begin(), a.end());
        sort(p.begin(), p.end());

        auto it=lower_bound(a.begin(),a.end(),mx)-a.begin();
        long long ans = it + 1;
        if(ans>=m)
        {
            cout << m << endl;
            continue;
        }
        // cout << ans << endl;
        // cout << mx << endl;
        for (long long i = 0; i < min(ans,m);i++)
        {
            mx = max(mx, p[i].second);
        }
        long long id = min(ans, m);
        for (long long i = id; i < m;i++)
        {
            if(p[i].first<=mx)
            {
                ans++;
            }
            else{
                break;
            }
            mx = max(mx, p[i].second);
        }
        cout << ans << endl;
    }
    return 0;
}