#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long t;
    long long n;
    cin >> t;
    while (t--) 
    {
        cin >> n;

        long long a[n];
        long long b[n];
        for (long long i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (long long i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        long long d = 0;
        long long id = -1;
        for (long long i = 0; i < n; i++) 
        {
            if (a[i] < b[i]) 
            {
                d = b[i] - a[i];
                id = i;
                break;
            }
        }

        bool x = 0;
        for (long long i = 0; i < n; i++) 
        {
            if (i==id)
            {
                continue;
            }
            if (a[i]-d<b[i]) 
            {
                x = 1;
                break;
            }
        }

        if(x)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}