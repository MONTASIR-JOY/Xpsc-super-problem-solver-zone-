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
        long long a, b;
        cin >> a >> b;

        long long n = a - 1;
        //cout << n << endl;
        //cout << a << " " << b << endl;

        if(n%4==0)
        {
            n = n;
        }
        else if(n%4==1)
        {
            n = 1;
        }
        else if(n%4==2)
        {
            n = n + 1;
        }
        else if(n%4==3)
        {
            n = 0;
        }
        //cout << n << endl;
        if(n==b)
        {
            cout << a << endl;
            continue;
        }
        n^=b;
        if(n==a)
        {
            cout << a + 2 << endl;
        }
        else
        {
            cout << a + 1 << endl;
        }
    }
    return 0;
}