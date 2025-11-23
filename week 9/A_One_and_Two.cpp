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
        vector<long long>v(n+1);
        map<int, int> mp;
        v[0] = 1;
        for (long long i = 1; i <= n;i++)
        {
            cin >> v[i];
            mp[i] = mp[i-1] + (v[i] == 2);
        }
        //cout << mp[2] << endl;
        //cout << total_mul << endl;
        long long ans = -1;
        for (long long i = 1; i <= n;i++)
        {
            if(mp[i]==mp[n]-mp[i])
            {
                ans = i;
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}