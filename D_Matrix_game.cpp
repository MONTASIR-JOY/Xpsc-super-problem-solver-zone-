#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define N 500005
long long Fact[N];

void FactMod()
{
   Fact[0]=1;
   for (long long i = 1; i < N; i++)
   {
       Fact[i] = ((Fact[i - 1] * i) % mod);
   }
}
long long PowerMod(long long a, long long n)
{
   if(n==0)
   {
       return 1;
   }
   long long x = PowerMod(a, n / 2);
   if(n%2==0)
   {
       return (x * x) % mod;
   }
   return ((x * x) % mod * a) % mod;
}
long long InverseMod(long long a)
{
    return PowerMod(a % mod, mod - 2);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    FactMod();

    long long t;
    cin >> t;
    while(t--)
    {
        long long a, b, k;
        cin >> a >> b >> k;
    
        long long n = (a - 1) * k + 1;
        
        long long m = 1;
        for(long long i = 0; i < a; i++)
        {
            m *= ((n - i) % mod);
            m %= mod;
        }
    
        m *= InverseMod(Fact[a]);
        m %= mod;
        m = (m * k) % mod;
        m = (m * (b - 1)) % mod;
        m = (m + 1) % mod;

        cout << n % mod << " " << m << endl;
    }
    return 0;
}