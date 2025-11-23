#include<bits/stdc++.h>
using namespace std;
const long long mx = 1e6 + 5;
long long dp[mx];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (long long i = 1;i < mx;i++) 
    {
        for (long long j = i;j < mx;j += i)
        {
           dp[j]++;
        }
    }

    long long t;
    cin >> t;
    while(t--)
    {
        long long n;
        cin >> n;
        cout << dp[n] << endl;
    }
    return 0;
}