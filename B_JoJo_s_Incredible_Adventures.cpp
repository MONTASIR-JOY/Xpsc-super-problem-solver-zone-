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
        string b;
        cin >> b;
        long long z = 0;
        long long o = 0;
        for (long long i = 0; i < b.size();i++)
        {
            if(b[i]=='0')
            {
                z++;
            }
        }
        o = b.size() - z;
        if(o==b.size())
        {
            cout << b.size() * b.size() << endl;
            continue;
        }
        long long n = 3 * b.size();
        string s = b + b + b;
        long long l = 0;
        long long r = 0;
        long long ans = 0;
        long long cnt = 0;
        while(r<n)
        {
            if(s[r]=='1')
            {
                cnt++;
                ans = max(ans, cnt);
            }
            else
            {
                cnt = 0;
                l = r;
            }
            r++;
        }
        if(ans==0)
        {
            cout << 0 << endl;
            continue;
        }
        if(ans==1)
        {
            cout << 1 << endl;
            continue;
        }
        long long mx = -1;
        for (int i = 1; i <= ans+1;i++)
        {
            mx = max(mx, i * (ans + 1 - i));
        }
        cout << mx << endl;
    }
    return 0;
}