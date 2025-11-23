#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;
    long long cnt = 0;
    for (long long i = 1; i <= n;i++)
    {
        map<long long, long long> mp;
        long long val = i;
        for (long long j = 2; j * j <= val;j++)
        {
            while(val%j==0)
            {
                mp[j]++;
                val /= j;
            }
        }
        if(val>1)
        {
            mp[val]++;
        }
        if(mp.size()==2)
        {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}