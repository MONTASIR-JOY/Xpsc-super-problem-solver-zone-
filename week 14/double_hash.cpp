#include<bits/stdc++.h>
using namespace std;

const long long N = 1e5 + 9;
const long long p1 = 137;
const long long mod1 = 127657753;
long long pw1[N];

const long long p2 = 277;
const long long mod2 = 987654319;
long long pw2[N];

void prec()
{
    pw1[0] = 1;
    pw2[0] = 1;
    for (long long i = 1; i < N;i++)
    {
        pw1[i] = 1LL * pw1[i - 1] * p1 % mod1;
        pw2[i] = 1LL * pw2[i - 1] * p2 % mod2;
    }
}

pair<int,int> get_hash(string s)
{
    long long n = s.size();
    long long hs1 = 0;
    long long hs2 = 0;
    for (long long i = 0; i < n;i++)
    {
        hs1 += 1LL * s[i] * pw1[i] % mod1;
        hs1 %= mod1;
        hs2 += 1LL * s[i] * pw2[i] % mod2;
        hs2 %= mod2;
    }
    return {hs1, hs2};
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    prec();
    
    return 0;
}