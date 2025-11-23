#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n;i++)
        {
            cin >> v[i];
        }
        map<int, int> mp;
        for (int i = 0; i < n;i++)
        {
            map<int, int> cnt;
            for (int j = 2; j * j <= v[i];j++)
            {
                if(v[i]%j==0)
                {
                    while(v[i]%j==0)
                    {
                        cnt[j]++;
                        v[i] /= j;
                    }
                }
            }
            if(v[i]>1)
            {
                cnt[v[i]]++;
            }
            for(auto val:cnt)
            {
                mp[val.first] += val.second;
            }
        }
        bool ans = true;
        for(auto val:mp)
        {
            if(val.second % n!=0)
            {
                ans = false;
                break;
            }
        }
        if(ans)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    } 
    return 0;
}