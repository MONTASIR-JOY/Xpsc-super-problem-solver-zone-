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
        cin >> s;
        long long n = s.size();
        long long mn = LLONG_MAX;
        for (char i = 'a'; i <= 'z';i++)
        {
            long long cnt = 0;
            long long mx = 0;
            for (long long j = 0; j < n;j++)
            {
                if(s[j]!=i)
                {
                    cnt++;
                    mx = max(mx, cnt);
                }
                else
                {
                    cnt = 0;
                }
            }
            mn = min(mx, mn);
        }
        long long ans = 0;
        while(mn)
        {
            mn /= 2;
            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}