#include<bits/stdc++.h>
using namespace std;
bool primes(int n)
{
    if(n<=3)
    {
        return true;
    }
    for (int i = 2; i * i <= n;i++)
    {
        if(n%i==0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> prime;
    for (int i = 2; i <= 2 * 100000; i++)
    {
        if(primes(i))
            prime.push_back(i);
    }
    long long t;
    cin >> t;
    while(t--)
    {
        long long d;
        cin >> d;
        int fir;
        for (int i = 0; i < prime.size();i++)
        {
            if(prime[i]-1>=d)
            {
                fir = prime[i];
                break;
            }
        }
        int sec;
        for (int i = 0; i < prime.size();i++)
        {
            if(prime[i]-fir>=d)
            {
                sec = prime[i];
                break;
            }
        }
        cout << fir * sec << endl;
    }
    return 0;
}