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
        string s;
        cin >> s;
        int l = 0;
        int r = 0;
        int cnt = 0;
        int mx1 = INT_MIN;

        while(r<n)
        {
            if(s[r]=='<')
            {
                cnt++;
                mx1 = max(mx1, cnt);
            }
            else{
                cnt = 0;
            }
            r++;
        }
        l = 0;
        r = 0;
        cnt = 0;
        int mx2 = INT_MIN;

        while(r<n)
        {
            if(s[r]=='>')
            {
                cnt++;
                mx2 = max(mx2, cnt);
            }
            else
            {
                cnt = 0;
            }
            r++;
        }
        cout << max(mx1,mx2)+1 << endl;
    }
    return 0;
}