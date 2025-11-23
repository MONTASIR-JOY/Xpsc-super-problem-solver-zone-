#include<bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
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
        long long cnt = ((n % mod * (4 * n - 1) % mod) * (n + 1) % mod * 337) % mod;
        cnt %= mod;
        cout << cnt << endl;
    }
    return 0;
}