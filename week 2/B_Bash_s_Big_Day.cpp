#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;
    vector<long long> a(n);

    for (long long i = 0; i < n;i++)
    {
        cin >> a[i];
    }
    vector<long long> v = a;
    map<long long, long long> mp;
    for (long long i = 0; i < n;i++)
    {
        long long val = v[i];
        for (long long j = 2; j*j <= v[i];j++)
        {
            if(val%j==0)
            {
                mp[j]++;
                while(val%j==0)
                {
                    val /= j;
                }
            }
        }
        if(val>1)
        {
            mp[val]++;
        }
    }
    long long mx = 1;

    for(auto val:mp)
    {
        mx = max(val.second, mx);
    }
    
    cout  << mx << endl;
    return 0;
}