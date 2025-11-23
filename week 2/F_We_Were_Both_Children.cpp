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
        vector<long long> v(n + 1, 0);
        vector<long long> trc(n + 1, 0);
        for(long long i = 0; i < n; i++)
        {
            long long x;
            cin >> x;
            if(x <= n)
            {
                v[x]++;
            }
        }
        for(long long i = 1; i <= n; i++)
        {
            if(v[i] != 0)
            {
                for(long long j = i; j <= n; j += i)
                {
                    trc[j] += v[i];
                }
            }
        }
        long long mx=0;
        for(long long i = 1; i <= n; i++)
        {
            mx = max(mx, trc[i]);
        }
        cout << mx << endl;
    }
    return 0;
}