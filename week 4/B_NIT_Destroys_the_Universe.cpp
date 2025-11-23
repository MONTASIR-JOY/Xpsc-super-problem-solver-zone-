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
        vector<long long> v(n);
        long long z = 0;
        for (long long i = 0; i < n;i++)
        {
            cin >> v[i];
            if(v[i]==0)
            {
                z++;
            }
        }
        if(z==n)
        {
            cout << 0 << endl;
            continue;
        }
        long long l = 0;
        while(v[l]==0)
        {
            l++;
        }
        long long r = n - 1;
        while(v[r]==0)
        {
            r--;
        }

        long long cnt = 0;
        bool x = true;
        for (long long i = l; i <= r;i++)
        {
            if(v[i]==0)
            {
                x = false;
                break;
            }
        }
        if(x)
        {
            cout << 1 << endl;
        }
        else{
            cout << 2 << endl;
        }
    }
    return 0;
}