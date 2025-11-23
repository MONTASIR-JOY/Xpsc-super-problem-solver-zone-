#include<bits/stdc++.h>
using namespace std;
const long long mxn = 1e5 + 7;
long long h[mxn];
long long dp[mxn];
long long n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    cin >> n;

    for (long long i = 1; i <= n;i++)
    {
        cin >> h[i];
    }

    dp[1] = 0;
    dp[2] = abs(h[2]-h[1]);

    for (long long i = 3; i <= n;i++)
    {
        dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]));
    }
    cout << dp[n];
    return 0;
}