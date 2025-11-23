#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
      
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> v;
        map<int, int> mp;
        for (int i = 0; i < n;i++)
        {
            int x;
            cin >> x;
            mp[x % 10]++;
            if(mp[x%10]<4)
            {
                v.push_back(x % 10);
            }
        }
        n = v.size();
        sort(v.begin(), v.end());
        bool ans = false;
        for (int i = 0; i < n;i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; k < n;k++)
                {
                    if((v[i]+v[j]+v[k])%10==3)
                    {
                        ans = true;
                    }
                }
            }
        }
        if(ans)
        {
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}