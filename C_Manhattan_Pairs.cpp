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
        vector<pair<pair<long long, long long>, long long>> p;
        for (long long i = 0; i < n; i++)
        {
            long long x, y;
            cin >> x >> y;
            p.push_back({{x, y}, i + 1});
        }

        sort(p.begin(), p.end());
        vector<pair<pair<long long, long long>, long long>> xs;
        vector<pair<pair<long long, long long>, long long>> xb;

        for (long long i = 0; i < n / 2;i++)
        {
            long long x = p[i].first.first;
            long long y = p[i].first.second;
            xs.push_back({{y, x}, p[i].second});
        }
        for (long long i = n/2; i < n;i++)
        {
            long long x = p[i].first.first;
            long long y = p[i].first.second;
            xb.push_back({{y, x}, p[i].second});
        }
        sort(xs.begin(), xs.end());
        sort(xb.rbegin(), xb.rend());

        for (long long i = 0; i < n/2;i++)
        {
            cout << xs[i].second << " " << xb[i].second << endl;
        }
    }
    return 0;
}