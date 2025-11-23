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
        long long n, k, a, b;
        cin >> n >> k >> a >> b;
        pair<long long, long long> st;
        pair<long long, long long> en;
        vector<pair<long long, long long>> v;
        for (long long i = 0; i < n;i++)
        {
            long long x, y;
            cin >> x >> y;
            v.push_back({x, y});
            if(i==a-1)
            {
                st = {x, y};
            }
            if(i==b-1)
            {
                en = {x, y};
            }
        }
        if(a<=k && b<=k)
        {
            cout << 0 << endl;
            continue;
        }
        long long one = 1e12;
        if(a<=k)
        {
            one = 0;
        }
        else
        {
            for (long long i = 0; i < k;i++)
            {
                one = min(one, abs(v[i].first - st.first) + abs(v[i].second - st.second));
            }
        }
        long long two = 1e12;
        if(b<=k)
        {
            two = 0;
        }
        else
        {
            for (long long i = 0; i < k;i++)
            {
                two = min(two, abs(v[i].first - en.first) + abs(v[i].second - en.second));
            }
        }
        cout << min(one + two, abs(st.first - en.first) + abs(st.second - en.second)) << endl;
    }
    return 0;
}