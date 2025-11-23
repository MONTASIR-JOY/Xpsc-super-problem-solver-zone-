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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int ans = 0;
        map<int, int> mp;
        mp[1] = 0;
        for (int i = 0; i < n;i++)
        {
            if(s[i]=='1' && mp[1]<=0)
            {
                ans++;
            }
            if(s[i]=='1')
            {
                mp[1]++;
            }
            if(i>=k-1)
            {
                if(s[i-k+1]=='1')
                {
                    mp[1]--;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}