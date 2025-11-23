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
        vector <pair<long long, long long>> v;
        vector <pair<long long, long long>> dupv;
        for (long long i = 0; i < n;i++)
        {
            long long x;
            cin >> x;
            v.push_back({x, i+1});
        }
        dupv = v;
        sort(v.begin(), v.end());

        long long r = n;
        vector<long long> ans(n);
        for (long long i = 0; i < n;i++)
        {
            ans[i] = v[i].second;
        }
        reverse(ans.begin(), ans.end());
        long long x = 0;
        long long val = 1;
        vector<long long> cor(n+1);
        cor[0] = 0;
        for (long long i = 1; i < n+1;i++)
        {
            if(i%2==1)
            {
                x++;
                cor[ans[i-1]] = x;
            }
            else{
                cor[ans[i-1]] = -x;
            }
        }
        long long time = 0;
        for (long long i = 1; i <= n;i++)
        {
            time += 2 * abs(cor[i]) * (dupv[i - 1].first);
        }
        cout << time << endl;
        for(long long i:cor)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}