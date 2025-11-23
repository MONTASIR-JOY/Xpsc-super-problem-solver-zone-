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
        long long a, b;
        cin >> a >> b;
        long long xk, yk;
        cin >> xk >> yk;
        long long xq, yq;
        cin >> xq >> yq;
        vector<pair<long long, long long>> king;
        vector<pair<long long, long long>> queen;

        king.push_back({xk+a, yk+b});
        king.push_back({xk+a, yk-b});
        king.push_back({xk-a, yk+b});
        king.push_back({xk-a, yk-b});
        king.push_back({xk+b, yk+a});
        king.push_back({xk-b, yk+a});
        king.push_back({xk-b, yk-a});
        king.push_back({xk+b, yk-a});

        queen.push_back({xq+a, yq+b});
        queen.push_back({xq+a, yq-b});
        queen.push_back({xq-a, yq+b});
        queen.push_back({xq-a, yq-b});
        queen.push_back({xq+b, yq+a});
        queen.push_back({xq-b, yq+a});
        queen.push_back({xq-b, yq-a});
        queen.push_back({xq+b, yq-a});

        long long ans = 0;

        map<pair<long long, long long>, bool> mp;
        
        for (long long i = 0; i < 8; i++)
        {
            for (long long j = 0; j < 8; j++)
            {
                if(king[i].first == queen[j].first && king[i].second == queen[j].second && mp[{king[i].first,king[i].second}]==false)
                {
                    mp[{king[i].first, king[i].second}] = true;
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}