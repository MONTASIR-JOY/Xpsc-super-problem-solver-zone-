
#include<bits/stdc++.h>
using namespace std;

const long long mod = 998244353;
long long PowerMod(long long a, long long n)
{
   if(n==0) return 1;
   long long x=PowerMod(a,n/2);
   if(n%2==0) return (x*x)%mod;
   return ((x*x)%mod*a)%mod;
}
long long InverseMod(long long a)
{
   return PowerMod(a%mod,mod-2);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
      
    long long n, m;
    cin >> n >> m;

    long long quotient = 1;
    long long dhorlam_nai = 1;
    vector<long long> jodi_thake(n + 1);
    vector<vector<pair<long long,long long>>> ekhane_shesh(m + 1);

    for(long long i = 1; i <= n; i++)
    {
        long long l, r, p, q;
        cin >> l >> r >> p >> q;

        quotient = (quotient * q) % mod;
        long long diff = q - p;
        dhorlam_nai = (dhorlam_nai * diff) % mod;
        jodi_thake[i] = (p * InverseMod(diff)) % mod;
        ekhane_shesh[r].push_back({i, l});
    }

    vector<long long> dp(m + 1, 0);
    dp[0] = 1;

    for(long long i = 1; i <= m; i++)
    {
        for(auto [idx, l]: ekhane_shesh[i])
        {
            dp[i] += (jodi_thake[idx] * dp[l - 1]);
            dp[i] %= mod;
        }
    }
    cout << (((dp[m] * dhorlam_nai) % mod) * InverseMod(quotient)) % mod << endl;
    return 0;
}