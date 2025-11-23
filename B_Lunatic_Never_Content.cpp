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
        for (long long i = 0; i < n;i++)
        {
            cin >> v[i];
        }
        long long gcd = 0;
        for (long long i = 0; i <= n / 2;i++)
        {
            gcd = __gcd(gcd, abs(v[n - i - 1] - v[i]));
        }
        cout << gcd << endl;
    }
    return 0;
}