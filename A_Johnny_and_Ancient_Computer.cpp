#include<bits/stdc++.h>
using namespace std;
long long f(long long n)
{
    if(n==0)
    {
        return 0;
    }
    for (long long i = 0; i < n;i++)
    {
        if((n>>i)&1)
        {
            return i;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
      
    long long t;
    cin >> t;
    while(t--)
    {
        long long a, b;
        cin >> a >> b;
        long long lefta = __lg(a);
        long long leftb = __lg(b);
        if(leftb>=lefta)
        {
            long long dif = leftb - lefta;
            a = a << dif;
            if(a==b)
            {
                cout << (dif + 2) / 3 << endl;
            }
            else
            {
                cout << -1 << endl;
            }
        }
        else
        {
            long long dif = lefta - leftb;

            long long rightbitofa = f(a);
            if(dif>rightbitofa)
            {
                cout << -1 << endl;
                continue;
            }
            a = a >> dif;
            if(a==b)
            {
                cout << (dif + 2) / 3 << endl;
            }
            else{
                cout << -1 << endl;
            }
        }
    }
    return 0;
}