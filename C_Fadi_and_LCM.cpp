#include<bits/stdc++.h>
using namespace std;
long long lcm(long long a,long long b)
{
    return a / (__gcd(a, b)) * b;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;
    vector<long long> div;
    for (long long i = 1; i * i <= n;i++)
    {
        if(n%i==0)
        {
            div.push_back(i);
            div.push_back(n/i);
        }
    }

    long long mx = n;
    long long ansa = 1;
    long long ansb = n;
    for (long long i = 0; i < div.size();i++)
    {
        if(lcm(div[i],n/div[i])==n)
        {
            if(mx>=max(div[i],(n/div[i])))
            {
                ansa = div[i];
                ansb = n / div[i];
                mx = max(div[i], (n / div[i]));
            }
        }
    }
    swap(ansa, ansb);
    cout << ansa << " " << ansb << endl;
    return 0;
}