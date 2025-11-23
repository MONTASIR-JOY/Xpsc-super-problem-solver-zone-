#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
      
    long long t;
    cin>>t;
    while(t--)
    {
        long long n;
        cin >> n;
        vector<pair<long long,long long>> v;
        for (long long i = 0; i < n;i++)
        {
            long long x;
            cin >> x;
            v.push_back({x, i + 1});
        }
        sort(v.begin(), v.end());

        // for(auto i:v)
        // {
        //     cout << i.first << " " << i.second << endl;
        // }
        long long ans = 0;
        for (long long i = 0; i < n-1;i++)
        {
            for (long long j = i + 1; j < n;j++)
            {
                long long val = v[i].first;
                long long val1 = v[j].first;
                long long id1 = v[i].second;
                long long id2 = v[j].second;
                if(val*val1>2*n)
                {
                    break;
                }
                if(val*val1==id1+id2)
                {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}