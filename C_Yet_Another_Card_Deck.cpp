#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
      
    long long n,k;
    cin >> n>>k;
    vector<long long> v(n);
    map<long long, long long> mp;
    for (long long i = 0; i < n;i++)
    {
        cin >> v[i];
        if(mp[v[i]]==0)
        {
            mp[v[i]] = i + 1;
        }
    }
    while(k--)
    {
        long long val;
        cin >> val;
        long long idx = mp[val];
        cout << idx << " ";
        mp[val] = 1;
        for(auto v:mp)
        {
            if(v.second<idx && v.first!=val)
            {
                mp[v.first]++;
            }
        }
    }
    cout << endl;
    return 0;
}