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
        vector<long long> v(n+2);
        for (long long i = 1; i <= n;i++)
        {
            cin >> v[i];
        }

        vector<long long> pre(n + 2);
        pre[0] = 0;
        for (long long i = 1; i <= n;i++)
        {
            pre[i] = pre[i - 1] + v[i];
            
        }
        long long ans = 0;
        long long gcd = 0;
        for (long long i = 1; i <= n-1; i++)
        {
            gcd = __gcd(pre[i], pre[n] - pre[i]);
            ans = max(ans, gcd);
        }
        cout << ans << endl;
    }
    return 0;
}