#include<bits/stdc++.h>
using namespace std;

long long gcd(long long a,long long b)
{
    if(b==0)
    {
        return a;
    }
    return gcd(b, a % b);
}
long long lcm(long long a,long long b)
{
    return (a / gcd(a, b)) * b;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
      
    long long t;
    cin>>t;
    while(t--)
    {
        long long n;
        cin >> n;
        vector<long long> v(n);
        for (long long i = 0; i < n;i++)
        {
            cin >> v[i];
            // cout << v[i] << " ";
        }
        // cout << endl;

        vector<long long> mul;
        for (long long i = 0; i < n-1;i++)
        {
            if(v[i+1]%v[i]==0)
            {
                continue;
            }
            
            mul.push_back(lcm(v[i], v[i + 1]) / v[i + 1]);
            v[i + 1] = lcm(v[i], v[i + 1]);
        }
        if(mul.size()==0)
        {
            cout << 1 << endl;
            continue;
        }
        long long ans = mul[0];
        for (long long i = 1; i < mul.size();i++)
        {
            ans = lcm(ans, mul[i]);
        }
        cout << ans << endl;
    }
    return 0;
}