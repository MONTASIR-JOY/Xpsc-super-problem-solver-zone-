#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long l, r, x, y;
    cin >> l >> r >> x >> y;
    if(y%x!=0)
    {
        cout<<0<<endl;
        return 0;
    }
    long long n = y / x;
    long long cnt = 0;
    for (long long i = 1; i * i <= n;i++)
    {
        if(n%i==0 && i*x>=l && (n/i)*x<=r && __gcd(i,n/i)==1)
        {
            if(i==n/i)
            {
                cnt++;
            }
            else
            {
                cnt+=2;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}