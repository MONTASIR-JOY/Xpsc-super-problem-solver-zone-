#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    string t;
    cin >> s;
    long long n = s.size();
    cin>>t;
    if(s.size()!=t.size())
    {
        cout << "No" << endl;
        return 0;
    }
    string mp = "aeiou";
    bool ans = true;
    for (long long i = 0; i < n;i++)
    {
        if(s[i]!=t[i])
        {
            bool x = false;
            for (long long j = 0; j < mp.size();j++)
            {
                if(s[i]==mp[j])
                {
                    x = true;
                }
            }
            bool y = false;
            for (long long j = 0; j < mp.size();j++)
            {
                if(t[i]==mp[j])
                {
                    y = true;
                }
            }

            if(x!=y)
            {
                ans = false;
                break;
            }
        }
        if(ans==false)
        {
            break;
        }
    }
    if(ans)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}