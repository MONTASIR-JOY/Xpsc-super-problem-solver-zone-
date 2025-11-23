#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;
    vector<long long> v(n);
    map<long long, long long> mp;
    for (long long i = 0; i < n;i++)
    {
        cin >> v[i];
        mp[v[i]]++;
    }

    vector<long long> ans;
    if(mp[1]==0)
    {
        while(n--)
        {
            ans.push_back(2);
        }
    }
    else if(mp[2]==0)
    {
        while(n--)
        {
            ans.push_back(1);
        }
    }
    else
    {
        ans.push_back(2);
        ans.push_back(1);
        mp[2]--;
        mp[1]--;
        while(mp[2]!=0)
        {
            mp[2]--;
            ans.push_back(2);
        }
        while(mp[1]!=0)
        {
            mp[1]--;
            ans.push_back(1);
        }
    }
    for(long long i:ans)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}