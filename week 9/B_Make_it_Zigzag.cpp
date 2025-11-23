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
        long long n;
        cin >> n;
        vector<long long> v(n+1);
        v[0] = 0;
        long long mx = LLONG_MIN;
        for (long long i = 1; i <= n;i++)
        {
            cin >> v[i];
        }
        for (long long i = 1; i <= n;i++)
        {
            mx = max(mx, v[i]);
            if(i%2==0)
            {
                v[i] = mx;
            }
        }
        long long ans = 0;
        if(n>=2)
        {
            if(v[2]==v[1])
            {
                ans++;
                v[1]--;
            }
        }

        for (long long i = 2; i <= n-1;i++)
        {
            if(i%2==1)
            {
                long long val = max(v[i] == v[i - 1]+1, v[i] == v[i + 1]+1);
                ans += max(max(v[i] - v[i - 1]+1, v[i] - v[i + 1]+1),val);
                v[i] -= max(max(v[i] - v[i - 1]+1, v[i] - v[i + 1]+1), val);
            }
        }
        if(n%2==1)
        {
            long long val = 0;
            if(v[n-1]==v[n])
            {
                val++;
            }
            ans += max(v[n]-v[n-1]+1, val);
            v[n] -= max(v[n] - v[n - 1]+1, val);
        }
        // for(long long i:v)
        // {
        //     cout << i << " ";
        // }
        // cout << endl;
        cout << ans << endl;
    }
    return 0;
}