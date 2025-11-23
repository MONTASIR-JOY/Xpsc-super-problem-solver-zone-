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
        string s;
        cin >> s;
        long long found = false;
        long long ans = 0;
        for (long long i = 2; i < n;i++)
        {
            if(s[i-2]=='.' && s[i-1]=='.' && s[i]=='.')
            {
                found = true;
                break;
            }
        }
        for (long long i = 0; i < n;i++)
        {
            if(s[i]=='.')
            {
                ans++;
            }
        }
        if (found == true && ans >= 2)
        {
            cout << 2 << endl;
        }
        else{
        cout << ans << endl;
        }
    }
    return 0;
}