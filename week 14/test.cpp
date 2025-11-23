#include<bits/stdc++.h>
using namespace std;
const long long mxn = 1e7 + 9;
vector<long long> primes;
vector<bool> isPrime(mxn, true);

void sieve()
{
    isPrime[0] = isPrime[1] = false;
    primes.push_back(2);

    for (long long i = 4; i < mxn;i+=2)
    {
        isPrime[i] = false;
    }

    for (long long i = 3; i * i < mxn;i+=2)
    {
        if(isPrime[i])
        {
            for (long long j = i * i; j < mxn;j+=2*i)
            {
                isPrime[j] = false;
            }
        }
    }

    for (long long i = 3; i < mxn;i+=2)
    {
        if(isPrime[i])
        {
            primes.push_back(i);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
      
    
    return 0;
}