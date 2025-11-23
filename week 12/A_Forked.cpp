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
        long long qa, qb;
        cin >> qa >> qb;
        long long ka, kb;
        cin >> ka >> kb;
        map<pair<long long, long long>, long long> mp;
        vector<pair<long long, long long>> gr= {{a, b}, {a, -b}, {-a, b}, {-a, -b},{b, a}, {b, -a}, {-b, a}, {-b, -a}};

        long long ans = 0;
        for (long long i = 0; i < 8;i++)
        {
            long long u, v;
            u = qa + gr[i].first;
            v = qb + gr[i].second;

            bool found = false;
            for (long long i = 0; i < 8;i++)
            {
                long long x, y;
                x = u + gr[i].first;
                y=v+gr[i].second;
                if(x==ka && y==kb && mp[{u,v}]==0)
                {
                    ans++;
                    mp[{u, v}] = 1;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}