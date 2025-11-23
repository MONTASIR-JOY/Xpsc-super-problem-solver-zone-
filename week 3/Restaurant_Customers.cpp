#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;
    map<long long, long long> dp;
    for (long long i = 0; i < n;i++)
    {
        long long l, r;
        cin >> l >> r;

        dp[l]++;
        dp[r + 1]--;
    }
    long long sum = 0;
    long long mx = LLONG_MIN;
    for (auto val:dp)
    {
        sum += val.second;
        mx = max(sum, mx);
    }
    cout << mx << endl;
    return 0;
}