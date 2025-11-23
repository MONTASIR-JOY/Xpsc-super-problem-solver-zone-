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
        long long n, m;
        cin >> n >> m;
        if(m<n || m>((1+n)*n)/2)
        {
            cout << -1 << endl;
            continue;
        }
        if(m<2*n)
        {
            cout << m - n + 1 << endl;
            for (long long i = 2; i <= n;i++)
            {
                cout << 1 << " " << i << endl;
            }
            continue;
        }
        cout << n << endl;
        cout << 1 << " " << n << endl;
        m -= (2 * n - 1);
        for (long long i = n - 1; i >= 2;i--)
        {
            if(m>=i-1)
            {
                cout << i << " " << n << endl;
                m -= (i - 1);
            }
            else{
                cout << 1 << " " << i << endl;
            }
        }
    }
    return 0;
}