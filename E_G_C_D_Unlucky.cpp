#include<bits/stdc++.h>
using namespace std;
long long l(long long a,long long b)
{
    return (a / __gcd(a, b)) * b;
}
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
        for (long long i = 0; i < n;i++)
        {
            cin >> v[i];
        }
        vector<long long> v1(n);
        for (long long i = 0; i < n;i++)
        {
            cin >> v1[i];
        }
        bool ans = true;
        vector<long long> lcm(n);
        for (long long i = 0; i < n;i++)
        {
            lcm[i] = l(v[i], v1[i]);
        }
        long long x = lcm[0];
        for (long long i = 0; i < n;i++)
        {
            x = __gcd(x, lcm[i]);
            if(x!=v[i])
            {
                ans = false;
                break;
            }
        }
        x = lcm[n - 1];
        for (long long i = n - 1; i >= 0;i--)
        {
            x = __gcd(x, lcm[i]);
            if(x!=v1[i])
            {
                ans = false;
                break;
            }
        }
        if(ans)
        {
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}