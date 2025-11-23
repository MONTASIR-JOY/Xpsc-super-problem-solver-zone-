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
        string s;
        cin>>s;
        long long n = s.size();
        long long z = 0;
        long long o = 0;
        if(n==1)
        {
            cout << 1 << endl;
            continue;
        }
        for (long long i = 0;i<n;i++)
        {
            if(s[i]=='0')
            {
                z++;
            }
            else{
                o++;
            }
        }
        if(o==z)
        {
            cout << 0 << endl;
            continue;
        }
        long long ans = 0;
        for (long long i = 0; i < n;i++)
        {
            if(s[i]=='0')
            {
                if(o==0)
                {
                    ans = i;
                    break;
                }
                o--;
            }
            else{
                if(z==0)
                {
                    ans = i;
                    break;
                }
                z--;
            }
        }
        cout << n-ans << endl;
    }
    return 0;
}