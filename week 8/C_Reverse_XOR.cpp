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
        string s;
        for (long long i = 0; i < __lg(n)+1;i++)
        {
            if((n>>i)&1)
            {
                s.push_back('1');
            }
            else{
                s.push_back('0');
            }
        }
        string t;
        bool x = true;
        for (long long i = 0; i < s.size();i++)
        {
            if(s[i]=='0' && x==true)
            {
                continue;
            }
            else{
                x = false;
                t.push_back(s[i]);
            }
        }
        // cout << s << endl;
        reverse(t.begin(), t.end());
        if(t.size()%2==1 && t[t.size()/2]=='1')
        {
            cout << "NO" << endl;
            continue;
        }
        bool ans = true;
        for (long long i = 0; i < t.size();i++)
        {
            if(t[i]!=t[t.size()-i-1])
            {
                ans = false;
                break;
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