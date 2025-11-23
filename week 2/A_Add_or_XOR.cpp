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
        long long a, b, x, y;
        cin >> a >> b >> x >> y;
        if(abs(a-b)==0)
        {
            cout << 0 << endl;
            continue;
        }
        if(a>b+1)
        {
            cout << -1 << endl;
            continue;
        }
        else if(a==b+1)
        {
            if((a&1)==1)
            {
                cout << y << endl;
            }
            else
            {
                cout << -1 << endl;
            }
            continue;
        }
        int ans = 0;
        while(a<b)
        {
            if(a%2==0 && y<x)
            {
                ans += y;
                a++;
                continue;
            }
            a++;
            ans += x;
        }
        cout << ans << endl;
    }
    return 0;
}