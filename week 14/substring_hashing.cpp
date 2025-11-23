#include<bits/stdc++.h>
using namespace std;

const long long p1 = 137, mod1 = 127657753, p2 = 277, mod2 = 987654319;
const long long N = 1e6 + 9;

long long power(long long x, long long n, long long MOD)
{
    long long ans = 1 % MOD;
    while(n>0)
    {
        if(n&1)
        {
            ans = 1LL * ans * x % MOD;
        }
        x = 1LL * x * x % MOD;
        n >>= 1;
    }
    return ans;
}

pair<long long, long long> pw[N], ipw[N];

void prec()
{
    pw[0] = {1, 1};
    for (long long i = 1; i < N; i++)
    {
        pw[i].first = 1LL * pw[i-1].first * p1 % mod1;
        pw[i].second = 1LL * pw[i-1].second * p2 % mod2;
    }
    long long ip1 = power(p1, mod1 - 2, mod1);
    long long ip2 = power(p2, mod2 - 2, mod2);
    ipw[0] = {1, 1};
    for (long long i = 1; i < N; i++)
    {
        ipw[i].first = 1LL * ipw[i-1].first * ip1 % mod1;
        ipw[i].second = 1LL * ipw[i-1].second * ip2 % mod2;
    }
}

pair<long long, long long> string_hash(string s)
{
    long long n = s.size();
    pair<long long, long long> hs({0, 0});
    for (long long i = 0; i < n; i++)
    {
        hs.first = (hs.first % mod1 + 1LL * s[i] * pw[i].first % mod1) % mod1;
        hs.second = (hs.second % mod2 + 1LL * s[i] * pw[i].second % mod2) % mod2;
    }
    return hs;
}

pair<long long, long long> pref[N];
void build(string s)
{
    long long n = s.size();
    for (long long i = 0; i < n; i++)
    {
        pref[i].first = 1LL * s[i] * pw[i].first % mod1;
        if(i) pref[i].first = (pref[i].first + pref[i-1].first) % mod1;
        pref[i].second = 1LL * s[i] * pw[i].second % mod2;
        if(i) pref[i].second = (pref[i].second + pref[i-1].second) % mod2;
    }
}

pair<long long, long long> get_hash(long long i, long long j)
{
    pair<long long, long long> hs({0, 0});
    hs.first = pref[j].first;
    if(i) hs.first = (hs.first - pref[i-1].first + mod1) % mod1;
    hs.first = 1LL * hs.first * ipw[i].first % mod1;

    hs.second = pref[j].second;
    if(i) hs.second = (hs.second - pref[i-1].second + mod2) % mod2;
    hs.second = 1LL * hs.second * ipw[i].second % mod2;

    return hs;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    prec();
    string a, b;
    cin >> a;
    cin >> b;
    build(a);

    auto hs = string_hash(b);
    long long ans = 0, n = a.size(), m = b.size();
    for (long long i = 0; i + m - 1 < n;i++)
    {
        if(hs == get_hash(i, i + m - 1))
        {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}