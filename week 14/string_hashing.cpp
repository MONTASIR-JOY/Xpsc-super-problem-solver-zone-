#include<bits/stdc++.h>
using namespace std;
const long long p = 137;
const long long mod = 1e9 + 7;
const long long N = 1e5 + 9;
long long pw[N];

void prec()
{
    pw[0] = 1;
    for (long long i = 1; i < N;i++)
    {
        pw[i] = 1LL * pw[i - 1] * p % mod;
    }
}
long long get_hash(string s)
{
    long long n = s.size();
    long long hs = 0;
    for (long long i = 0; i < n;i++)
    {
        hs += 1LL * s[i] * pw[i] % mod;
        hs %= mod;
    }
    return hs;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    prec();
    string a, b;
    cin >> a >> b;
    cout << get_hash(a) << " " << get_hash(b) << endl;
    return 0;
}