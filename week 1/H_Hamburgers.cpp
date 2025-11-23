#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string st;
    cin >> st;
    long long b, s, c;
    cin >> b >> s >> c;
    long long pb, ps, pc;
    cin >> pb >> ps >> pc;

    map<char, long long> mp;
    
    for(char i:st)
    {
        mp[i]++;
    }
    long long total;
    cin >> total;

    auto ok = [&](long long x)
    {
        long long price = 0;
        long long bcount = x * mp['B'];
        long long scount = x * mp['S'];
        long long ccount = x * mp['C'];

        if(bcount>b)
        {
            long long pl = (bcount - b) * pb;
            price += pl;
        }
        if(scount>s)
        {
            long long pl = (scount - s) * ps;
            price += pl;
        }
        if(ccount>c)
        {
            long long pl = (ccount - c) * pc;
            price += pl;
        }
        return price <= total;
    };

    long long l = 0;
    long long r = 1e13;
    long long ans, mid;
    
    while(l<=r)
    {
        mid = l + (r - l) / 2;
        if(ok(mid))
        {
            l = mid + 1;
            ans = mid;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}