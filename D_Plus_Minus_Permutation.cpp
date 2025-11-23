#include<bits/stdc++.h>
using namespace std;
long long l(long long a,long long b)
{
    return a / __gcd(a, b) * b;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
      
    long long t;
    cin >> t;
    while(t--)
    {
        long long n, x, y;
        cin >> n >> x >> y;
        long long lcm = l(x, y);
        long long val = n / lcm;
        x = n / x;
        y = n / y;
        x -= val;
        y -= val;
        //cout << y << endl;
        long long plus = n * (n + 1) / 2 - (n-x) * (n-x + 1) / 2;
        long long minus = (y) * (y + 1) / 2;
        long long ans = plus - minus;
        //cout << plus << " " << minus << endl;
        cout << ans << endl;

    }
    return 0;
}