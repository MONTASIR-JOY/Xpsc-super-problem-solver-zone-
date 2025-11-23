#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, a, b;
    cin >> n >> a >> b;
    //cout << n << a << b << endl;
    long long x = min(a, b);
    long long y = max(a, b);
    long long mx = LLONG_MIN;
    for (long long i = 1; i <= n;i++)
    {
        if(n-i==0)
        {
            if(x/i>=mx)
            {
                mx = x / i;
            }
            continue;
        }
        if(min(x/i,y/(n-i))>=mx)
        {
            mx = min(x / i, y / (n - i));
        }
    }
    cout << mx << endl;
    return 0;
}