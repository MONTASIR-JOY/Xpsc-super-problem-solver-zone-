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
        vector<long long> v(n);
        map<long long, long long> mp;
        for (long long i = 0; i < n;i++)
        {
            cin >> v[i];
            mp[v[i]]++;
        }
        long long ans = n - mp[1];
        for(auto i:mp)
        {
            ans = min(ans, n - i.second + 1);
        }
        cout << ans << endl;
    }
    return 0;
}